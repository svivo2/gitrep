__global__ void MatrixMulKernel(float* Md, float* Nd, float* Pd,int width)
{
  // Calculate the row index of the Pd element and M
  int Row = blockIdx.y*TILE_WIDTH + threadIdx.y;
  // Calculate the column index of Pd and N
  int Col = blockIdx.x*TILE_WIDTH + threadIdx.x;
  float Pvalue = 0;
  // each thread computes one element of the block sub-matrix
  for (int k = 0; k < width; ++k) {
    Pvalue += Md[Row*width+k] * Nd[k*width+Col];
  }
  Pd[Row*width+Col] = Pvalue;
}

// Matrix multiplication kernel
// -- per thread code
__global__ void MatrixMulKernel(float* Md, float* Nd, float* Pd,int width)
{
  int tx = threadIdx.x;
  int ty = threadIdx.y;
  // Pvalue is used to store the
  // element of the matrix
  // that is computed by the thread
  float Pvalue = 0;
  for (int k = 0; k < width; ++k) {
    float Melement = Md[ty*width+k];
    float Nelement = Nd[k*width+tx];
    Pvalue += Melement * Nelement;
  }
  Pd[ty*width+tx] = Pvalue;
}

// Setup the execution configuration
dim3 dimGrid(width/TILE_WIDTH, width/TILE_WIDTH);
dim3 dimBlock(TILE_WIDTH, TILE_WIDTH);
// Launch the device computation threads!
MatrixMulKernel<<<dimGrid, dimBlock>>>(Md, Nd, Pd, width);

void MatrixMultiplication(float* M, float* N, float* P, int width)
{
  int size = width*width*sizeof(float);
  float* Md, Nd, Pd;
  // 1. Allocate and Load M, N to device memory
  cudaMalloc((void**)&Md, size);
  cudaMemcpy(Md, M, size, cudaMemcpyHostToDevice);
  cudaMalloc((void**)&Nd, size);
  cudaMemcpy(Nd, N, size, cudaMemcpyHostToDevice);
  // Allocate P on the device
  cudaMalloc((void**)&Pd, size);
  // 2. Kernel invocation code -- to be shown later
  // 3. Read P from the device
  cudaMemcpy(P, Pd, size, cudaMemcpyDeviceToHost);
  // Free device matrices
  cudaFree(Md); cudaFree(Nd); cudaFree (Pd);
}
