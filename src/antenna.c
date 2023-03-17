#include "antenna.h"

#include "consts_phys_mks.h"

#include <math.h>

#define C0 299792458

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
  return C0/freq;
}

double ant_wavelen2freq(double wavelen)
{
  return ant_freq2wavelen(wavelen); // uses reciprocity
}

double ant_s11dbtoswr(double s11)
{
  return (1+pow(10.0,s11/20))/(1-pow(10.0,s11/20));
}

double ant_swrtos11db(double swr)
{
  return 20*log10((swr-1)/(swr+1));
}

double ant_ffdist(double D, double freq)
{
  return MAX(2*D*D/ant_freq2wavelen(freq),MAX(1.6*ant_freq2wavelen(freq),5*D));
}

// struct ant_thetaphi ant_azel2phitheta(double az, double el)
// {
//   double theta = acos(cos(az)*cos(el));
//   double phi   = atan2(tan(el),sin(az));
//   return (struct ant_thetaphi){theta,phi};
// }