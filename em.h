#ifndef LIBANTENNA
#define LIBANTENNA



#include <stddef.h>

double em_freq2wavelen(double freq);
double em_wavelen2freq(double wavelen);

double em_gamma2swr(double s11);
double em_swr2gamma(double swr);


#endif //  LIBANTENNA