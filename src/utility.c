
#include "libantenna.h"

#include <stdio.h>



char* ant_wavelength_hr(double wavelength, char *buff, size_t buff_len)
{
  if (wavelength >= 1E3)
    snprintf(buff, buff_len - 1, "%.1f km", wavelength / 1E3);
  else if (wavelength >= 1)
    snprintf(buff, buff_len - 1, "%.1f m", wavelength / 1E0);
  else if (wavelength >= 1E-2)
    snprintf(buff, buff_len - 1, "%.1f cm", wavelength * 1E2);
  else
    snprintf(buff, buff_len - 1, "%.1f mm", wavelength * 1E3);
  return buff;
}

char* ant_frequency_hr(double frequency, char *buff, size_t buff_len)
{
  if (frequency >= 1E12)
    snprintf(buff, buff_len - 1, "%.1f THz", frequency/1E12);
  else if (frequency >= 1E9)
    snprintf(buff, buff_len - 1, "%.1f GHz", frequency / 1E9);
  else if (frequency >= 1E6)
    snprintf(buff, buff_len - 1, "%.1f MHz", frequency / 1E6);
  else if (frequency >= 1E3)
    snprintf(buff, buff_len - 1, "%.1f kHz", frequency / 1E3);
  else
    snprintf(buff, buff_len - 1, "%.1f Hz", frequency / 1E0);
  return buff;
}
