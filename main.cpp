#include "stdio.h"
int max(int a,int b,int c)
{
    if(a>=b&&a>c)
    {
        return a;
    }
    if(c>=b&&c>a)
    {
        return c;
    }
    if(b>=a&&b>c)
    {
        return b;
    }
}
int max_middle(int*nums,int first,int last)
{
    int mid=(first+last)/2;
    int sum1=nums[mid+1];
    int sum2=nums[mid];
    int max1=nums[mid+1];
    int max2=nums[mid];
    for(int i=mid+2;i<=last;i++)
    {
        sum1=sum1+nums[i];
        if(sum1>max1)
        {
            max1=sum2;
        }
    }
    for(int i=mid-1;i>=first;i--)
    {
        sum2=sum2+nums[i];
        if(sum2>max2)
        {
            max2=sum2;
        }
    }
    return max1+max2;
}
int max_divide(int*nums,int first,int last)
{
    if(first==last)
    {
        return nums[first];
    }
    int mid=max_middle(nums,first,last);
    int a=max_divide(nums,first,(first+last)/2);
    int b=max_middle(nums,(first+last)/2+1,last);
    int Max=max(a,b,mid);
    return Max;
}
int maxSubArray(int* nums, int numsSize){
    int mid;
    mid=numsSize/2;
    int a=max_divide(nums,0,mid);
    int b=max_divide(nums,mid+1,numsSize-1);
    int Mid=max_middle(nums,0,numsSize-1);
    return max(a,b,Mid);
}
int main()
{
    int nums[]={-2,1,-3,4,-1,2,1,-5,4};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    printf("%d",maxSubArray(nums,numsSize));
    return 0;
}