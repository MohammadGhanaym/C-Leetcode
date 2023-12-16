#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum
{
   false,
   true
} bool;

bool isPalindrome(int x) {
   if (0 > x)
   {
      return false;
   }
   else
   {
      int arrSize = 0;
      int *arr = NULL;
      int tempX = x;
      double sum = 0;
      while (tempX != 0)
      {
         arrSize++;
         arr = (int *)realloc(arr, arrSize * sizeof(int));
         arr[arrSize - 1] = tempX % 10;
         tempX = tempX / 10;
      }
      for (int index = 0; index < arrSize; index++)
      {
         sum += arr[index] * pow(10, arrSize - (index + 1));
      }

      if (sum == x)
      {
         return true;
      }
      else
      {
         return false;
      }
      free(arr);
   }
}