#include <stdio.h>
#include <cmplx.h>

// Code for finding the real part of a complex number

int main(void) {
    printf("\n\t---TEST 05---\n");
    printf("Code for finding the real part of a complex number.\n");
    printf("Test number: 1+2i\n");

    cmplx_t a = {1,2};

    printf("Expected result: 1.00\n");
    printf("Calculated result: %.2lf\n", cmplx_real(cmplx_mag(a), cmplx_phs(a)));
    
    return 0;
}