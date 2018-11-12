//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

#include<stdio.h>
#include<Windows.h>
#include<malloc.h>

/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** threeSum(int* nums, int numsSize, int* returnSize) {
	int i = 0;
	int j = 1;
	int k = 2;
	static int *array[] = { NULL };
	if (numsSize <= 2)
	{
		(*returnSize) = 0;
		int *ret = NULL;
		return &ret;
	}
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			for (k = j + 1; k < numsSize; k++)
			{
				if ((nums[i] + nums[j] + nums[k]) == 0)
				{
					int *ptr = malloc(sizeof(int)* 3);
					ptr[0] = nums[i];
					ptr[1] = nums[j];
					ptr[2] = nums[k];
					array[(*returnSize)++] = ptr;
				}
			}
		}
	}
	return array;
}

int main()
{
	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int input = 0;
	int *returnSize = &input;
	int **ret = threeSum(nums, numsSize, returnSize);
	int *cur = NULL;
	while ((*ret) != NULL)
	{
		cur = *ret;
		for (int i = 0; i < 3; i++)
		{
			printf("%d ", cur[i]);
		}
		printf("\n");
		ret++;
	}
	system("pause");
	return 0;
}