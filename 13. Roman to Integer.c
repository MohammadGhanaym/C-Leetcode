int romanToInt(char* s) {
   char roman[7] = "IVXLCDM";
   int romanInt[7] = {1, 5, 10, 50, 100, 500, 1000};
   int num = 0;
   int val_Ind1 = 0;
   int val_Ind2 = 0;
   while (*s != '\0')
   {
      for (int index = 0; index < 7; index++)
      {
         if (roman[index] == *s)
         {
            val_Ind1 = index;
         }
         if (roman[index] == *(s + 1))
         {
            val_Ind2 = index;
         }
      }

      if ((*(s + 1) != '\0') && (romanInt[val_Ind1] < romanInt[val_Ind2]))
      {
         num -= romanInt[val_Ind1];
      }
      else
      {
         num += romanInt[val_Ind1];
      }
      s++;
   }
   return num;   
}