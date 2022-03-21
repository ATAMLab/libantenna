#include "../libantenna.h"

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

  printf("\n=================== frequency <-> wavelength ====================\n");
  for (size_t i = 0; i < Nfreq; i++)
    printf("%s: %s\n", ap_frequency_hr(freqs[i], buff, BUFF_SIZE), ap_wavelength_hr(ap_freq2wavelen(freqs[i]), buff2, BUFF_SIZE));

  // s11 to swr
  printf("\n========================= s11 <-> swr ===========================\n");
  double s11[Nfreq] = {-8.0, -10.0, -12.0, -20.0, -30.0};
  double swr[Nfreq];
  printf(" s11    swr\n");
  printf("-----  -----\n");
  for (size_t i = 0; i < Nfreq; i++)
    printf("%5.1f: %.3f\n", s11[i], ap_s11dbtoswr(s11[i]));
  printf("\n");
  printf(" swr    s11\n");
  printf("-----  -----\n");
  for (size_t i = 0; i < Nfreq; i++)
    printf("%.3f: %5.1f\n", ap_s11dbtoswr(s11[i]), ap_swrtos11db(ap_s11dbtoswr(s11[i])));

  return 0;
}