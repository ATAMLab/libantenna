#include "libantenna.h"

#include <math.h>

/**
 * @brief Convert frequency to wavelength. 
 * 
 * \f$f = c0/\lambda \f$ where \f$c0\f$ is speed of light in vacuum
 *
 * @param freq frequency in Hertz [Hz] 
 * @return wavelength in meters [m]
 * 
 */
double ant_freq2wavelen(double freq)
{
  return ANT_CONSTANT_C0 / freq;
}

/**
 * @brief Convert wavelength to frequency.
 * 
 * \f$\lambda = c0/f \f$ where \f$c0\f$ is speed of light in vacuum
 * 
 * @param wavelen wavelength in meters [m]
 * @return frequency in Hertz [Hz] 
 */
double ant_wavelen2freq(double wavelen)
{
  return ant_freq2wavelen(wavelen);
}

/**
 * @brief Cpnvert reflection coefficient (\f$S_{11}\f$) to standing wave ratio (SWR)
 * 
 * \f$SWR = \dfrac{1+S_{11}}{1-S_{11}}\f$
 * 
 * @param S11: reflection coefficient in decibel [dB]
 * @return SWR 
 */
double ant_s11dbtoswr(double s11)
{
  return (1 + pow(10.0, s11 / 20)) / (1 - pow(10.0, s11 / 20));
}

/**
 * @brief Convert standing wave ratio (SWR) to reflection coefficient (\f$S_{11}\f$) 
 * 
 * \f$S_{11} = \dfrac{SWR-1}{SWR+1}\f$
 * 
 * @param SWR: standing wave ratio
 * @return S11 
 */
double ant_swrtos11db(double swr)
{
    return 20 * log10((swr - 1) / (swr + 1));
}