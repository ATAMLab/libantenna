#include "libantenna.h"

#include <math.h>

void la_freq2wavelen(double *freq, size_t size, double *wavelen)
{
  for (size_t i = 0; i < size; i++)
    wavelen[i] = LA_CONSTANT_C0 / freq[i];
}

void la_wavelen2freq(double *wavelen, size_t size, double *freq)
{
  la_freq2wavelen(wavelen, size, freq);
}

void la_s11dbtoswr(double *s11, size_t size, double *swr)
{
  for (size_t i = 0; i < size; i++)
    swr[i] = (1 + pow(10.0, s11[i] / 20)) / (1 - pow(10.0, s11[i] / 20));
}

void la_swrtos11db(double *swr, size_t size, double *s11)
{
  for (size_t i = 0; i < size; i++)
    s11[i] = 20*log10((swr[i]-1)/(swr[i]+1));
}