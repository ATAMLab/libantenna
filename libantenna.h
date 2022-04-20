#ifndef LIBANTENNA_LIBANTENNA_H
#define LIBANTENNA_LIBANTENNA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

#ifdef _MSC_VER
/* Microsoft Visual C/C++ compiler in use */
#ifdef LIBANTENNA_MSBUILD_SHARED
/* Building the library - need to export DLL symbols */
#define AP_API __declspec(dllexport)
#elif LIBANTENNA_MSBUILD_STATIC
#define AP_API
#else
/* Using the library - need to import DLL symbols */
#define AP_API __declspec(dllimport)
#endif
#else
/* Some other compiler in use */
#ifndef LIBANTENNA_ATBUILD
/* Not building the library itself - don't need any special prefixes. */
#define AP_API
#endif
#endif

#define AP_CONSTANT_C0 299792458

#define AP_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define AP_MAX(a, b) (((a) > (b)) ? (a) : (b))

  struct ap_thetaphi
  {
    double theta, phi;
  };

  AP_API double ap_freq2wavelen(double freq);
  AP_API double ap_wavelen2freq(double wavelen);

  AP_API char *ap_wavelength_hr(double wavelength, char *buff, size_t buff_len);
  AP_API char *ap_frequency_hr(double frequency, char *buff, size_t buff_len);

  AP_API double ap_s11dbtoswr(double s11);
  AP_API double ap_swrtos11db(double swr);

  AP_API double ap_ffdist(double freq, double D);
  AP_API struct ap_thetaphi ap_azel2phitheta(double az, double el);

#ifdef __cplusplus
}
#endif

#endif
