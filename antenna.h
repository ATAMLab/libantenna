#ifndef LIBANTENNA
#define LIBANTENNA

#ifdef __cplusplus
extern "C" {
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

ANT_API unsigned short int ant_ver_major();
ANT_API unsigned short int ant_ver_minor();
ANT_API unsigned short int ant_ver_patch();



ANT_API double ant_freq2wavelen(double freq);
ANT_API double ant_wavelen2freq(double wavelen);

ANT_API double ant_gamma2swr(double s11);
ANT_API double ant_swr2gamma(double swr);

/**
 * Antenna far-field (Fraunhofer) starting range
 * @param D antenna maxiumum cross-section size
 * @param freq frequency of interest
 * @return Range start for far-field
 */
ANT_API double ant_ffdist(double D, double freq);

/**
 * Antenna radiating near-field (Fresnel) starting range
 * @param D antenna maxiumum cross-section size
 * @param freq frequency of interest
 * @return Range start for propagating near-field
 */
ANT_API double ant_nfdist(double D, double freq);

ANT_API double ant_meas_nf_sepdist(double freq);
ANT_API size_t ant_meas_nf_pnf_sspace(double freq);
ANT_API size_t ant_meas_nf_pnf_scount(double freq, double L);
ANT_API double ant_meas_nf_pnf_slength(double freq, double L);

#ifdef __cplusplus
}
#endif

#endif //  LIBANTENNA