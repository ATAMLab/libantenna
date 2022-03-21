#include "libantenna.h"

#include <math.h>


/**
 * Calculates far-field (Fraunhofer) distance of an aperture.
 * 
 * The name returned is whatever is normally used to refer to a port on the
 * current operating system; e.g. for Windows it will usually be a "COMn"
 * device name, and for Unix it will be a device path beginning with "/dev/".
 *
 * @param[in]  freq    Frequency in Hertz [Hz].
 * @param[in]  D       Aperture cross-sectional size in meters [m].
 * 
 * @return Far-field (Fraunhofer) distance of an aperture [m].
 * 
 */
double ap_ffdist(double freq, double D)
{
  return AP_MAX(2 * D * D / ap_freq2wavelen(freq), AP_MAX(1.6 * ap_freq2wavelen(freq), 5 * D));
}
