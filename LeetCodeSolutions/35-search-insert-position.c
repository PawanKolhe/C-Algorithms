#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int i,index=numsSize;
    for(i=0;i<numsSize;i++){
        if(nums[i]>=target){
            index = i;
            break;
        }
    }
    return index;
}
 int main(){
   int nums[50],target,numsSize,i;
   printf("Enter the size of the nums integer array: ");
   scanf("%d",&numsSize );

   printf("Enter the numbers:\n");
   for ( i = 0; i < numsSize; i++) {
     scanf("%d",&nums[i] );
   }
   printf("Enter the number to be searched: ");
   scanf("%d",&target );

   printf("Output : the index is : %d\n",searchInsert(nums,numsSize,target) );
   return 0;
 }
