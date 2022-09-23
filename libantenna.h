#ifndef LIBANTENNA_LIBANTENNA_H
#define LIBANTENNA_LIBANTENNA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>


#ifdef MSVC_DLL
    #ifdef MSVC_DLL_EXPORT
        #define ANT_API __declspec(dllexport)
    #else
        #define ANT_API __declspec(dllimport)
    #endif
#else
    #define ANT_API
#endif

#define ANT_CONSTANT_C0 299792458

#define ANT_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ANT_MAX(a, b) (((a) > (b)) ? (a) : (b))

  struct ant_thetaphi
  {
    double theta, phi;
  };

  ANT_API double ant_freq2wavelen(double freq);
  ANT_API double ant_wavelen2freq(double wavelen);

  ANT_API char *ant_wavelength_hr(double wavelength, char *buff, size_t buff_len);
  ANT_API char *ant_frequency_hr(double frequency, char *buff, size_t buff_len);

  ANT_API double ant_s11dbtoswr(double s11);
  ANT_API double ant_swrtos11db(double swr);

  ANT_API double ant_ffdist(double freq, double D);
  ANT_API struct ant_thetaphi ant_azel2phitheta(double az, double el);

#ifdef __cplusplus
}
#endif

#endif
