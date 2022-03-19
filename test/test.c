#include "libantenna.h"

#include "stdio.h"

#define Nfreq 5

int main()
{

  // freq2wavelen
  double freqs[Nfreq] = {1E3, 1E6, 300E6, 2.4E9, 94E9};
  double wavelens[Nfreq];

  la_freq2wavelen(freqs, Nfreq, wavelens);
  for (size_t i = 0; i < Nfreq; i++)
    printf("%.16G: %.16G\n", freqs[i], wavelens[i]);

  return 0;
}