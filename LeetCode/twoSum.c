/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回[0, 1]

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include"public.h"//头文件

/**
 * 功能：给定一个整数数组和一个目标值，找出和为目标值的那两个整数，并返回他们的数组下标
 * 返回值：整形数组的首地址
 * 参数：传入数组的首地址nums，传入数组的元素个数numsSize，目标值target，返回数组的元素个
 * 
 * 思路：暴力求解：
 * 两层for循环遍历整个数组，第一层for从下标0开始到numsSize-2
 * 第二层for从下标i+1开始，到numsSize-1
 * 如果遇到俩个下标的和等于target，给动态开辟的数组进行赋值，然后直接返回ret（题目作者提供：有且仅有一个答案）
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* ret = (int*)calloc(2, sizeof(int));
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}


/*int main() {//测试代码块
	int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize = 0;
	int ret[2];
	int* sss = twoSum(nums, numsSize, 19, &returnSize);
	ret[0] = sss[0];
	ret[1] = sss[1];
	return 0;
}*/