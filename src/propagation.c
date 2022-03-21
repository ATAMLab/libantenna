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
 * @return ffdist  Far-field (Fraunhofer) distance of an aperture [m].
 *
 * @since 0.1.1
 */
double ap_ffdist(double freq, double D)
{
  // for (size_t i = 0; i < size; i++)
  //   wavelen[i] = AP_CONSTANT_C0 / freq[i];
}
