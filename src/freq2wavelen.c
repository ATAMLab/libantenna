
#include "libantenna.h"

void la_freq2wavelen(double *freq, size_t size, double *wavelen)
{
  for (size_t i = 0; i < size; i++)
    wavelen[i] = LA_CONSTANT_C0 / freq[i];
}
