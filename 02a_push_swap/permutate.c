#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
  char t = *a; *a = *b; *b = t;
}

void permute(char *a, int i, int n) {
   // If we are at the last letter, print it
   if (i == (n-1))
    {
      printf("ARG=\"");
      for (int k = 0; k < n; k++)
      {
        printf("%c", a[k]);
        if (k != n - 1)
          printf(" ");
      }
      printf("\"; ./push_swap $ARG | wc -l\n");
    }
   else {
     // Show all the permutations with the first i-1 letters fixed and 
     // swapping the i'th letter for each of the remaining ones.
     for (int j = i; j < n; j++) {
       swap((a+i), (a+j));
       permute(a, i+1, n);
       swap((a+i), (a+j));
     }
  }
}

int  main(void)
{
  char s[100];
  strcpy(s, "01234");
  permute(s, 0, strlen(s));
  return (1);
}
