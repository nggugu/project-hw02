#include <stdio.h>
#include <cmplx.h>

// Code for testing complex multiplication

int main(void) {
    printf("\n\t---TEST 02---\n");
    printf("Code for testing complex multiplication.\n");
    printf("Test numbers:\n");
    printf("\ta = 1 + 2i\n");
    printf("\tb = 3 + 4i\n");

    cmplx_t a = {1, 2};
    cmplx_t b = {3, 4};
    cmplx_t c = {0, 0};

    cmplx_mul(a, b, c);

    printf("Expected result: -5.00 + 10i\n");
    printf("Calculated result: %.2f + %.2fi\n", c[0], c[1]);

    return 0;
}