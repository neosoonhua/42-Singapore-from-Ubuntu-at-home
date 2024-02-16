#include <stdio.h>

void  main(void)
{
  for (int k = 500; k > 0; k--)
    printf("%d ", k);
  printf(" | wc -l\n");
}
