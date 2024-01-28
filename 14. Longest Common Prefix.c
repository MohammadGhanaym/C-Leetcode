#include <stdlib.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
   char *first_word = strs[0];
   char *longest_prefix = NULL;
   unsigned int prefixSize = 0;

   while (*first_word != '\0')
   {
      int index = 1;
      for (index = 1; index < strsSize; index++)
      {
         if (*first_word != strs[index][prefixSize])
         {
            break;
         }
      }
      if (index == strsSize) // this means there is a match between the letters in all words
      {
         longest_prefix = (char *)realloc(longest_prefix, sizeof(char) * (prefixSize + 1));
         prefixSize++;
         longest_prefix[prefixSize - 1] = *first_word;
         first_word++;
      }
      else
      {
         break;
      }
   }
   if (NULL == longest_prefix)
   {
      return "";
   }
   else
   {
      longest_prefix = (char *)realloc(longest_prefix, sizeof(char) * (prefixSize + 1));
      longest_prefix[prefixSize] = '\0';
      return longest_prefix;
   }
}


