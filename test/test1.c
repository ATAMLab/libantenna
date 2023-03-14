#include "../antenna.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>


int main()
{
  int test = 1;
  // int tests = 30;

  // printf("1..%i\n", tests);

  assert(ant_ver_major() || ant_ver_minor() || ant_ver_patch());
  printf("%d. [PASSED] Project version is %hu.%hu.%hu\n", test++, ant_ver_major(), ant_ver_minor(), ant_ver_patch());

}