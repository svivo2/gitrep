/******************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ******************************************************************************/

__global__ void vecAddKernel(float* A_d, float* B_d, float* C_d, int n) {

    // Calculate global thread index based on the block and thread indices ----

    //INSERT KERNEL CODE HERE

    int tx = threadIdx.x;


    // Use global index to determine which elements to read, add, and write ---

    //INSERT KERNEL CODE HERE

    C_d[n*tx] = A_d[tx*n] + B_H[tx*n]


}
