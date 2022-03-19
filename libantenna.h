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
#define LA_API __declspec(dllexport)
#elif LIBANTENNA_MSBUILD_STATIC
#define LA_API
#else
/* Using the library - need to import DLL symbols */
#define LA_API __declspec(dllimport)
#endif
#else
/* Some other compiler in use */
#ifndef LIBANTENNA_ATBUILD
/* Not building the library itself - don't need any special prefixes. */
#define LA_API
#endif
#endif

#define LA_CONSTANT_C0 299792458

  LA_API void la_freq2wavelen(double *freq, size_t size, double *wavelen);

#ifdef __cplusplus
}
#endif

#endif
