#include<stdio.h>
//Solution function
//A dp based approach , done in O(n) time complexity
int maximumProduct(int* nums, int numsSize){
        int p1,p2;
        int max1,max2,max3,small1,small2;
        max1=max2=max3=-1001;
         small1=small2=1001;
        for(int i=0;i<numsSize;i++){
            if(nums[i]>=max3){
                max1=max2;
                max2=max3;
                max3=nums[i];
            }else if(nums[i]>=max2){
                max1=max2;
                max2=nums[i];
            }else if(nums[i]>=max1){
                max1=nums[i];
            }
            
            if(nums[i]<=small1){
                small2=small1;
                small1=nums[i];
            }else if(nums[i]<=small2){
                small2=nums[i];
            }
        }
        p1=max1*max2*max3;
        p2 = small1*small2*max3;
        if(p1>p2)
            return p1;
        else
            return p2;
}
//Driver code
int main(){
   int nums[3] = {1,2,3};
   int ans = maximumProduct(nums,3);
   printf("%d",ans);
return 0;
}