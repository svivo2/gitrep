/******************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ******************************************************************************/

#include <stdio.h>

#define TILE_SIZE 16

__global__ void mysgemm(int m, int n, int k, const float *A, const float *B, float* C) {

  /********************************************************************
   *
   * Compute C = A x B
   *   where A is a (m x k) matrix
   *   where B is a (k x n) matrix
   *   where C is a (m x n) matrix
   *
   * Use shared memory for tiling
   *
   ********************************************************************/

  // INSERT KERNEL CODE HERE

  // Calculate the row index of the Pd element and M
  __shared__ float A_ds[TILE_WIDTH][TILE_WIDTH];
  __shared__ float B_ds[TILE_WIDTH][TILE_WIDTH];
  int bx = blockIdx.x;
  int by = blockIdx.y;
  int tx = threadIdx.x;
  int ty = threadIdx.y;
  // Identify the row and column of the Pd element to work on
  int Row = by * TILE_WIDTH + ty; 6. int Col = bx * TILE_WIDTH + tx;
  float Pvalue = 0;
  // Loop over the Md and Nd tiles required to compute the Pd element
  for (int i = 0; i < k/TILE_WIDTH; ++i) {
    // Collaborative loading of Md and Nd tiles into shared memory
    A_ds[ty][tx] = A[Row*k + (i*TILE_WIDTH + tx)];
    B_ds[ty][tx] = A[(i*TILE_WIDTH + ty)*n + Col];
    __syncthreads();

    for (int j = 0; j < TILE_WIDTH; ++j) {
      Pvalue += B_ds[ty][j] * Nds[j][tx];
    }
    __syncthreads();
  }
  C[Row*n + Col] = Pvalue;
}

void basicSgemm(char transa, char transb, int m, int n, int k, float alpha, const float *A, int lda, const float *B, int ldb, float beta, float *C, int ldc)
{
    if ((transa != 'N') && (transa != 'n')) {
	printf("unsupported value of 'transa'\n");
    	return;
    }

    if ((transb != 'N') && (transb != 'n')) {
	printf("unsupported value of 'transb'\n");
	return;
    }

    if ((alpha - 1.0f > 1e-10) || (alpha - 1.0f < -1e-10)) {
	printf("unsupported value of alpha\n");
	return;
    }

    if ((beta - 0.0f > 1e-10) || (beta - 0.0f < -1e-10)) {
	printf("unsupported value of beta\n");
	return;
    }

    // Initialize thread block and kernel grid dimensions ---------------------

    const unsigned int BLOCK_SIZE = TILE_SIZE;

    //INSERT CODE HERE

    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
    dim3 dimGrid((m*n*k/BLOCK_SIZE),(m*n*k/BLOCK_SIZE));


    // Invoke CUDA kernel -----------------------------------------------------

    //INSERT CODE HERE

    mysgemm<<<dimGrid, dimBlock>>>(m, n, k, A, B, C);


}
