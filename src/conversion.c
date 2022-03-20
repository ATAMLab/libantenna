#include "libantenna.h"

void la_freq2wavelen(double *freq, size_t size, double *wavelen)
{
  for (size_t i = 0; i < size; i++)
    wavelen[i] = LA_CONSTANT_C0 / freq[i];
}

void la_wavelen2freq(double *wavelen, size_t size, double *freq)
{
  la_freq2wavelen(wavelen, size, freq);
}
