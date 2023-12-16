/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int *retArr = (int *)malloc(2 * sizeof(int));
   for (int index1 = 0; index1 < numsSize - 1; ++index1)
   {
      for (int index2 = index1 + 1; index2 < numsSize; ++index2)
      {
         if (nums[index1] + nums[index2] == target)
         {
            retArr[0] = index1;
            retArr[1] = index2;
            *returnSize = 2;
            return retArr;
         }
      }
   }
   return retArr;
}