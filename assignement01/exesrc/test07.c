#include <stdio.h>
#include <cmplx.h>

// Code to test complex discrete fourier transform

int main(void) {
    printf("\n\t---TEST 07---\n");
    printf("Code to test complex discrete fourier transform.\n");
    printf("Test signal: f[n]={3,1,6,2}\n");

    int N = 4;
    cmplx_t input[4] = {{3.0,0.0}, {1.0,0.0}, {6.0,0.0}, {2.0,0.0}};
    cmplx_t output[4];

    cmplx_dft(input, output, N);

    printf("Expected result:\n");
    printf("\tF_0 = 12.00 + 0.00i\n");
    printf("\tF_1 = -3.00 + 1.00i\n");
    printf("\tF_2 = 6.00 + 0.00i\n");
    printf("\tF_3 = -3.00 - 1.00i\n");
    
    printf("Calculated result:\n");
    for(int i = 0; i < N; i++) {
        printf("\tF_%d = %.2lf + %.2lfi\n", i,output[i][0], output[i][1]);
    }

    return 0;
}