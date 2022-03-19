#include "libantenna.h"

#include "stdio.h"

#define BUFF_SIZE 250

#define Nfreq 5

int main()
{
  char buff2[BUFF_SIZE];
  char buff[BUFF_SIZE];

  // freq2wavelen
  double freqs[Nfreq] = {1E3, 1E6, 300E6, 2.4E9, 94E9};
  double wavelens[Nfreq];

  la_freq2wavelen(freqs, Nfreq, wavelens);
  for (size_t i = 0; i < Nfreq; i++)
    printf("%s: %s\n", la_frequency_hr(freqs[i], buff, BUFF_SIZE), la_wavelength_hr(wavelens[i], buff2, BUFF_SIZE));

  return 0;
}