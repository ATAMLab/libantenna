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
