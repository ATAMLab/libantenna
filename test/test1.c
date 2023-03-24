#include "../antenna.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>
#include <math.h>


int main()
{
  int test = 1;
  // int tests = 30;

  // printf("1..%i\n", tests);

  assert(ant_ver_major() || ant_ver_minor() || ant_ver_patch());
  printf("%d. [PASSED] Project version is %hu.%hu.%hu\n", test++, ant_ver_major(), ant_ver_minor(), ant_ver_patch());

  {
    double freq = 8.2E9;
    assert(ceil(ant_meas_nf_sepdist(freq)*1e3)/1e3 == 0.110);
    printf("%d. [PASSED] Near field minimum seperation distance at '%G'Hz: %f\n", test++, freq, ant_meas_nf_sepdist(freq));
  }
  {
    double freq = 8.2E9;
    assert(ant_meas_nf_pnf_sspace(freq) == 18);
    printf("%d. [PASSED] Near field sampling spacing at '%G'Hz: %zumm\n", test++, freq, ant_meas_nf_pnf_sspace(freq));
  }
  {
    double freq = 8.2E9;
    double L    = 1.0;
    assert(ant_meas_nf_pnf_scount(freq, L) == 57);
    printf("%d. [PASSED] Near field sampling count at '%G'Hz for '%f'm: %zu\n", test++, freq, L, ant_meas_nf_pnf_scount(freq, L));
  }
  {
    double freq = 8.2E9;
    double L    = 1.0;
    assert(ant_meas_nf_pnf_slength(freq, L) == 1.026);
    printf("%d. [PASSED] Near field sampling length at '%G'Hz for '%f'm: %fm\n", test++, freq, L, ant_meas_nf_pnf_slength(freq, L));
  }
}