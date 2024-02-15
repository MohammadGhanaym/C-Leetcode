#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum
{
   false = 0,
   true
} bool;

#define ARR_SIZE 6
signed int search_for_bracket(char bracket)
{
   char brackets[ARR_SIZE] = {'(', '{', '[', ')', '}', ']'};
   signed int bracket_index = -1;
   unsigned int index = 0;
   for (index = 0; index < ARR_SIZE; index++)
   {
      if (bracket == brackets[index])
      {
         bracket_index = index;
         break;
      }
   }

   return bracket_index;
}

bool isValid(char *s)
{
   char *stack = NULL;
   unsigned int stack_size = 0;
   int last_bracket_index = -1;
   int next_bracket_index = -1;

   while (*s != '\0')
   {
      next_bracket_index = search_for_bracket(*s);
      if (next_bracket_index < 3)
      {
         stack_size++;
         stack = (char *)realloc(stack, sizeof(char) * stack_size);
         stack[stack_size - 1] = *s;
         last_bracket_index = next_bracket_index;
      }
      else
      {
         if (next_bracket_index - last_bracket_index == 3)
         {
            stack_size--;
            if (stack_size == 0)
            {
               free(stack);
               stack = NULL;
               last_bracket_index = -1;
               next_bracket_index = -1;
            }
            else
            {
               stack = (char *)realloc(stack, sizeof(char) * stack_size);
               last_bracket_index = search_for_bracket(stack[stack_size - 1]);
            }
         }
         else
         {
            return false;
         }
      }
      s++;
   }

   if (0 == stack_size)
   {
      return true;
   }
   return false;
}