#include "em.h"

#include <math.h>

#define C0 2.997924580000e+08

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

double em_freq2wavelen(double freq)
{
  return C0/freq;
}

double em_wavelen2freq(double wavelen)
{
  return em_freq2wavelen(wavelen); // uses reciprocity
}

double em_gamma2swr(double s11)
{
  return (1+pow(10.0,s11/20))/(1-pow(10.0,s11/20));
}

double em_swr2gamma(double swr)
{
  return 20*log10((swr-1)/(swr+1));
}
