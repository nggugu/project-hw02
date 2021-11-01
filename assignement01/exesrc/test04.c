#include <stdio.h>
#include <cmplx.h>

// Code for finding the phase of a complex number

int main(void) {
    printf("\n\t---TEST 04---\n");
    printf("Code for finding the phase of a complex number.\n");
    printf("Test number: 1 + 1i\n");

    cmplx_t a = {1,1};
    
    printf("Expected result: 0.79\n");
    printf("Calculated result: %.2lf\n", cmplx_phs(a));

    return 0;
}