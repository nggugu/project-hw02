#include <stdio.h>
#include <cmplx.h>

// Code to test complex inverse discrete fourier transform

int main(void) {
    printf("\n\t---TEST 08---\n");
    printf("Code to test complex inverse discrete fourier transform.\n");
    printf("Test signal: f[n]={12.00 + 0.00i,-3.00 + 1.00i,6.00 + 0.00i,-3.00 - 1.00i}\n");

    int N = 4;
    cmplx_t input[4] = {{12.0,0.0}, {-3.0,1.0}, {6.0,0.0}, {-3.0,-1.0}};
    cmplx_t output[4];

    cmplx_idft(input, output, N);

    printf("Expected result:\n");
    printf("\tf(0) = 3.00 + 0.00i\n");
    printf("\tf(1) = 1.00 + 0.00i\n");
    printf("\tf(2) = 6.00 + 0.00i\n");
    printf("\tf(3) = 2.00 + 0.00i\n");
    
    printf("Calculated result:\n");
    for(int i = 0; i < N; i++) {
        printf("\tf_%d = %.2lf + %.2lfi\n", i,output[i][0], output[i][1]);
    }

    return 0;
}