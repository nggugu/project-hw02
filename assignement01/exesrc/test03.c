#include <stdio.h>
#include <cmplx.h>

// Code for finding magnitude of a complex number

int main(void) {
    printf("\n\t---TEST 03---\n");
    printf("Code for finding magnitude of a complex number.\n");
    printf("Test number: 1 + 1i\n");

    cmplx_t a = {1,1};

    printf("Expected result: 1.41\n");
    printf("Calculated result: %.2lf\n", cmplx_mag(a));

    return 0;
}