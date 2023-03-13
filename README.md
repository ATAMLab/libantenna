# libantenna: Antennas and Propagation Library
C language toolkit library for fundamental computations related to electormagnetics, antennas and radio (RF) propagation.

## Dependencies
- [libconst](https://github.com/yigithsyn/libconst): Physical and Mathematical Constants Library

## Building
### MSVC on Windows
``` shell
SET CMAKE=".."                 # set cmake executable path
RMDIR /Q /S build > NUL 2>&1 
MKDIR build 
CD build
```
- 32 Bit 
`%CMAKE% -DBUILD_SHARED_LIBS=ON -T host=x86 -A win32 ..`
- 64 Bit 
`%CMAKE% -DBUILD_SHARED_LIBS=ON -T host=x64 -A x64 ..`
``` shell
%CMAKE% --build . --config Release
```
### GCC on Linux
```
rm -rf build
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=ON
cmake --build . --config Release
```

 

## Index
The following functions are implemented in this library:

-   [freq2wavelen]  - Frequency to wavelength convert for free space
-   [wavelen2freq]  - Frequency to wavelength convert for free space
-   [frequency_hr]  - Frequency to human readable string format like 1.3 kHz, 3.1GHz
-   [wavelength_hr] - Wavelength to human readable string format like 2 mm, 9.5 cm
-   [s11dbtoswr]    - Microwave/RF S11 [dB] parameters to standing wave ratio (SWR) convert
-   [swrtos11db]    - Standing wave ratio (SWR) convert to microwave/RF S11 [dB] convert 
-   [ffdist]        - Far-field distance of an antenna/aperture 

[freq2wavelen]:  https://github.com/yigithsyn/libantenna/blob/master/src/conversion.c
[wavelen2freq]:  https://github.com/yigithsyn/libantenna/blob/master/src/conversion.c
[frequency_hr]:  https://github.com/yigithsyn/libantenna/blob/master/src/utility.c
[wavelength_hr]: https://github.com/yigithsyn/libantenna/blob/master/src/utility.c
[s11dbtoswr]:    https://github.com/yigithsyn/libantenna/blob/master/src/conversion.c
[swrtos11db]:    https://github.com/yigithsyn/libantenna/blob/master/src/conversion.c
[ffdist]:        https://github.com/yigithsyn/libantenna/blob/master/src/propagation.c

/**
 * @brief Convert frequency to wavelength. 
 * 
 * \f$f = c0/\lambda \f$ where \f$c0\f$ is speed of light in vacuum
 *
 * @param freq frequency in Hertz [Hz] 
 * @return wavelength in meters [m]
 * 
 */

 /**
 * @brief Convert wavelength to frequency.
 * 
 * \f$\lambda = c0/f \f$ where \f$c0\f$ is speed of light in vacuum
 * 
 * @param wavelen wavelength in meters [m]
 * @return frequency in Hertz [Hz] 
 */

 /**
 * @brief Cpnvert reflection coefficient (\f$S_{11}\f$) to standing wave ratio (SWR)
 * 
 * \f$SWR = \dfrac{1+S_{11}}{1-S_{11}}\f$
 * 
 * @param S11: reflection coefficient in decibel [dB]
 * @return SWR 
 */

 /**
 * @brief Convert standing wave ratio (SWR) to reflection coefficient (\f$S_{11}\f$) 
 * 
 * \f$S_{11} = \dfrac{SWR-1}{SWR+1}\f$
 * 
 * @param SWR: standing wave ratio
 * @return S11 
 */

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
