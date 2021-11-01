#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <cmplx.h>
#include <io.h>
#include <errno.h>

int main(void) {
    printf("\n\t---TEST IDFT---\n");
    // Signal settings
    float T_s = 0.005;
    float frequency = 50.0;
    float Omega = 2 * PI * frequency;

    // Determining the size of a saved signal
    int size = ((1/frequency)/T_s) + 1;
    cmplx_t signal[size];
    cmplx_t signal_idft[size];
    cmplx_t signal_sampled[size];

    int fd = open("./data.binary", O_RDONLY | O_APPEND);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            int value_ieee = read_word(fd);
            void *a = (void *) &value_ieee;
            float value = *((float *) a);
            
            signal[i][j] = value;
        }
    }

    // Reconstructing the signal
    cmplx_idft(signal, signal_idft, size);

    printf("Reconstructed signal is:\n");
    for (int i = 0; i < size; i++) {
        printf("\t%f + %fi\n", signal_idft[i][0], signal_idft[i][1]);
    }

    printf("Generated signal is:\n");
    for (int i = 0; i < size; i++) {
        signal_sampled[i][0] = sin(Omega * i * T_s);
        signal_sampled[i][1] = 0.0;
        printf("\t%f + %fi\n", signal_sampled[i][0], signal_sampled[i][1]);
    }
}
