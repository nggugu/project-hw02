#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <cmplx.h>
#include <io.h>
#include <errno.h>

int main(void) {
    printf("\n\t---TEST DFT---\n");
    // Signal settings
    float T_s = 0.005;
    float frequency = 50.0;
    float Omega = 2 * PI * frequency;

    // Determining the size of a sampled signal
    int size = ((1/frequency)/T_s) + 1;
    cmplx_t signal[size];
    cmplx_t signal_dft[size];

    // Generate and sample a signal
    printf("Generated signal is:\n");
    for (int i = 0; i < size; i++) {
        signal[i][0] = sin(Omega * i * T_s);
        signal[i][1] = 0.0;
        printf("\t%f + %fi\n", signal[i][0], signal[i][1]);
    }

    // DFT
    cmplx_dft(signal, signal_dft, size);

    int fd = open("./data.binary", O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            float value = signal_dft[i][j];
            void *a = (void *) &value;
            int value_ieee = *((int *) a);
            write_word(fd, value_ieee);
        }
    }

    return 0;
}
