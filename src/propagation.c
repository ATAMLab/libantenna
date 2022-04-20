#include "libantenna.h"

#include <math.h>

/**
 * Calculates far-field (Fraunhofer) distance of an aperture
 *
 * \f$R_{ff} = Max\left(\dfrac{2D^2}{\lambda},5D,1.6\lambda\right)\f$
 *
 * @param  freq: frequency in Hertz [Hz]
 * @param  D: aperture cross-sectional size in meters [m]
 *
 * @return far-field (Fraunhofer) distance of an aperture [m]
 *
 */
double ap_ffdist(double freq, double D)
{
  return AP_MAX(2 * D * D / ap_freq2wavelen(freq), AP_MAX(1.6 * ap_freq2wavelen(freq), 5 * D));
}

/**
 * Convert angles from azimuth-elevation form to phi-theta form
 *
 * \f$\theta = \arccos(w) = \arccos\left(\cos(Az)\cos(El)\right)\f$
 *
 * \f$\phi = \arccos(v/u) = \arctan\left(\dfrac{\tan(El)}{\sin(Az)}\right)\f$
 * 
 * \ref Theory and Practive of Modern Antenna Measurements
 *
 * @param  az: azimuth angle in degrees [\f$\circ\f$]
 * @param  el: elevation angle in degrees [\f$\circ\f$]
 *
 * @return phi and theta angle pair in degrees [\f$\circ\f$]
 *
 */
struct ap_thetaphi ap_azel2phitheta(double az, double el)
{
  double theta = acos(cos(az) * cos(el));
  double phi = atan2(tan(el), sin(az));
  return (struct ap_thetaphi){theta, phi};
}

