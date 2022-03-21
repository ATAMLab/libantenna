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
  printf("\n=================== frequency <-> wavelength ====================\n");
  for (size_t i = 0; i < Nfreq; i++)
    printf("%s: %s\n", la_frequency_hr(freqs[i], buff, BUFF_SIZE), la_wavelength_hr(wavelens[i], buff2, BUFF_SIZE));

  // s11 to swr
  printf("\n========================= s11 <-> swr ===========================\n");
  double s11[Nfreq] = {-8.0, -10.0, -12.0, -20.0, -30.0};
  double swr[Nfreq];
  printf(" s11    swr\n");
  printf("-----  -----\n");
  la_s11dbtoswr(s11, Nfreq, swr);
  for (size_t i = 0; i < Nfreq; i++)
    printf("%5.1f: %.3f\n", s11[i], swr[i]);
  printf("\n");
  printf(" swr    s11\n");
  printf("-----  -----\n");
  la_swrtos11db(swr, Nfreq, s11);
  for (size_t i = 0; i < Nfreq; i++)
    printf("%.3f: %5.1f\n", swr[i], s11[i]);

  return 0;
}