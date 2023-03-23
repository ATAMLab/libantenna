# libantenna: Antennas and Propagation Library

C language toolkit library for fundamental computations related to electormagnetics, antennas and radio (RF) propagation.

## Building

```shell
cd build
cmake .. 
cmake --build . --config Release
```  

For shared libraries use option switch `-DBUILD_SHARED_LIBS=ON`

## Index

The following functions are implemented in this library:

| Category | Function     | Description                                    |
| -------- | ------------ | ---------------------------------------------- |
|          | freq2wavelen | Frequency to wavelength convert for free space |
|          | wavelen2freq | Wavelength to frequency convert for free space |
|          | ffdist       | Far-field distance of an antenna/aperture      |

