# libantenna: Antennas and Propagation Library

C language toolkit library for fundamental computations related to electormagnetics, antennas and radio (RF) propagation.

## Dependencies for command line program
- Argtable2 `sudo apt install libargtable2-dev`

## Building

```shell
mkdir build
cd build
cmake .. 
cmake --build . --config Release
```  

For shared libraries use option switch `-DBUILD_SHARED_LIBS=ON`

## Index

The following functions are implemented in this library:

| Category                     | Function            | Description                                                                            |
| ---------------------------- | ------------------- | -------------------------------------------------------------------------------------- |
|                              | freq2wavelen        | Frequency to wavelength convert for free space                                         |
|                              | wavelen2freq        | Wavelength to frequency convert for free space                                         |
|                              | ffdist              | Far-field distance of an antenna/aperture                                              |
|                              | nfdist              | Near-field starting distance of an antenna/aperture                                    |
|                              | gamma2swr           | Reflection coefficient to standing-wave-ratio convert                                  |
|                              | swr2gamma           | Standing-wave-ratio to reflection coefficient convert                                  |
| measurement/nearfield/planar | meas_nf_pnf_sspace  | Planar near-field sampling size in mm                                                  |
| measurement/nearfield/planar | meas_nf_pnf_scount  | Planar near-field sampling count for scanner travel length                             |
| measurement/nearfield/planar | meas_nf_pnf_slength | Planar near-field sampling updated length according optimum sampling spacing and count |
