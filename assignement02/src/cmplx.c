#include <math.h>
#include <cmplx.h>

// c = a / b
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = (a[0] * b[0] + a[1] * b[1]) / (b[0] * b[0] + b[1] * b[1]);
    c[1] = (a[1] * b[0] - a[0] * b[1]) / (b[0] * b[0] + b[1] * b[1]);
}
// c = a * b
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = a[0] * b[0] - a[1] * b[1];
    c[1] = a[0] * b[1] + a[1] * b[0];
}

// returns |a|
double cmplx_mag(cmplx_t a) {
    return sqrt(a[0]*a[0] + a[1]*a[1]);
}

// returns phase in radians of a
double cmplx_phs(cmplx_t a) {
   return atan2(a[1], a[0]); 
}

// return real part of mag/_phs
double cmplx_real(double mag, double phs) {
    return mag * cos(phs);
}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs) {
    return mag * sin(phs);
}

// returns dft of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
    cmplx_t sol = {0,0}, temp = {0,0};
    double phi = 0.0;

    for (int i = 0; i < N; i++) {
        output[i][0] = 0;
        output[i][1] = 0;

        for (int j = 0; j < N; j++) {
            phi = (-2) * PI * (1.0 / N) * i * j;
            temp[0] = cmplx_real(1, phi);
            temp[1] = cmplx_imag(1, phi);
            cmplx_mul(input[j], temp, sol);

            output[i][0] += sol[0];
            output[i][1] += sol[1];
        }
    }
}

// returns inverse dft of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
    cmplx_t sol = {0,0}, temp = {0,0};
    double phi = 0.0;

    for (int i = 0; i < N; i++) {
        output[i][0] = 0;
        output[i][1] = 0;

        for (int j = 0; j < N; j++) {
            phi = 2 * PI * (1.0 / N) * i * j;
            temp[0] = cmplx_real(1, phi);
            temp[1] = cmplx_imag(1, phi);
            cmplx_mul(input[j], temp, sol);

            output[i][0] += sol[0];
            output[i][1] += sol[1];
        }

        output[i][0] *= (1.0 / N);
        output[i][1] *= (1.0 / N);
    }
}
