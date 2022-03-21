#include "libantenna.h"

#include <math.h>

double ap_freq2wavelen(double freq)
{
  return AP_CONSTANT_C0 / freq;
}

double ap_wavelen2freq(double wavelen)
{
  ap_freq2wavelen(wavelen);
}

double ap_s11dbtoswr(double s11)
{
  return (1 + pow(10.0, s11 / 20)) / (1 - pow(10.0, s11 / 20));
}

double ap_swrtos11db(double swr)
{
    return 20 * log10((swr - 1) / (swr + 1));
}