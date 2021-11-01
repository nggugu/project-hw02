#include <stdio.h>
#include <cmplx.h>

// Code for finding the imaginary part of a complex number

int main(void) {
    printf("\n\t---TEST 06---\n");
    printf("Code for finding the imaginary part of a complex number.\n");
    printf("Test number: 1 + 2i\n");

    cmplx_t a = {1,2};

    printf("Expected result: 2.00\n");
    printf("Calculated result: %.2lf\n", cmplx_imag(cmplx_mag(a), cmplx_phs(a)));

    return 0;
}