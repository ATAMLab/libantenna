#include "antenna.h"

#include <math.h>

#define CONSTS_PHYS_MKS_SPEED_OF_LIGHT	          2.997924580000e+08

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

unsigned short int ant_ver_major()
{
#ifdef PROJECT_VERSION_MAJOR
  return PROJECT_VERSION_MAJOR;
#else
  return 0;
#endif
}
unsigned short int ant_ver_minor()
{
#ifdef PROJECT_VERSION_MINOR
  return PROJECT_VERSION_MINOR;
#else
  return 0;
#endif
}
unsigned short int ant_ver_patch()
{
#ifdef PROJECT_VERSION_PATCH
  return PROJECT_VERSION_PATCH;
#else
  return 0;
#endif
}

double ant_freq2wavelen(double freq)
{
  return CONSTS_PHYS_MKS_SPEED_OF_LIGHT/freq;
}

double ant_wavelen2freq(double wavelen)
{
  return ant_freq2wavelen(wavelen); // uses reciprocity
}

double ant_gamma2swr(double s11)
{
  return (1+pow(10.0,s11/20))/(1-pow(10.0,s11/20));
}

double ant_swrtogamma(double swr)
{
  return 20*log10((swr-1)/(swr+1));
}

double ant_ffdist(double D, double freq)
{
  return MAX(2*D*D/ant_freq2wavelen(freq),MAX(1.6*ant_freq2wavelen(freq),5*D));
}
double ant_nfdist(double D, double freq)
{
  /* IEEE 149-2021 IEEE Recommended Practice for Antenna Measurements, p.176 B.16 */
  double lambda = ant_freq2wavelen(freq); 
  return MAX(D,MAX(lambda,0.62*D*sqrt(D/lambda)));
}

ANT_API double ant_meas_nf_sepdist(double freq)
{
  /*IEEE 1720-2012 IEEE Recommended Practice for Near-Field Antenna Measurements, p.27 */
  return 3*ant_freq2wavelen(freq);
}
ANT_API size_t ant_meas_nf_pnf_sspace(double freq)
{
  /*IEEE 1720-2012 IEEE Recommended Practice for Near-Field Antenna Measurements, p.23 Eq.25 */
  return (size_t)floor(ant_freq2wavelen(freq)/2*1E3);
}
ANT_API size_t ant_meas_nf_pnf_scount(double freq, double L)
{
  size_t scount = (size_t)ceil(L*1E3/ant_meas_nf_pnf_sspace(freq));
  return scount%2 ? scount+2 : scount+1;
}
ANT_API double ant_meas_nf_pnf_slength(double freq, double L)
{
  return ant_meas_nf_pnf_sspace(freq)*ant_meas_nf_pnf_scount(freq, L)/1E3;
}
