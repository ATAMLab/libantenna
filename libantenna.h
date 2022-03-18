#ifndef LIBANTENNA_LIBANTENNA_H
#define LIBANTENNA_LIBANTENNA_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

/*
 * Package version macros (can be used for conditional compilation).
 */

/** The libantenna package 'major' version number. */
#define LA_PACKAGE_VERSION_MAJOR 0

/** The libantenna package 'minor' version number. */
#define LA_PACKAGE_VERSION_MINOR 0

/** The libantenna package 'micro' version number. */
#define LA_PACKAGE_VERSION_MICRO 1

/** The libantenna package version ("major.minor.micro") as string. */
#define LA_PACKAGE_VERSION_STRING "0.0.1"

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

  LA_API void freq2wavelen(double *freq, size_t size, double *wavelen);

#ifdef __cplusplus
}
#endif

#endif
