#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize);
int main()
{
    char a;
    int n=0, k = 0;
    int num[100] = { 0 };
    while ((a = getchar()) && a != '\n') {
        ungetc(a, stdin);
        scanf("%d", &k);
        num[n++] = k;
    }
    printf("连续子数组最大和为：%d", maxSubArray(num,n));
	system("pause");
    return 0;
}
int maxSubArray(int* nums, int numsSize) {
    int pre = 0, maxA = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if((pre + nums[i])>=nums[i])
		{
			pre=pre + nums[i];
		}
		else if((pre + nums[i])<=nums[i])
		{
			pre=nums[i];
		}
		if(maxA>=pre)
		{
			maxA=maxA;
		}
		else if(maxA<=pre)
		{
			maxA=pre;
		}
    }
    if (maxA < 0)
    {
        maxA = 0;
    }
    return maxA;
}
