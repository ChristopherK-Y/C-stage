/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1, 2, 3]
输出 : 6
示例 2 :

输入 : [1, 2, 3, 4]
输出 : 24
注意 :

给定的整型数组长度范围是[3, 104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/maximum-product-of-three-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
* 功能：快速排序
* 返回值：无
* 参数：int* arr(数组指针)为目标数组
*		int left为排序时选则的最左边标
*		int right为排序时选择的最右边下标志
*/
void quickSort(int* nums, int left, int right) {
	if (left < right) {
		int l = left, r = right, x = nums[left];
		while (l < r) {
			while (l < r && nums[r] >= x) {
				r--;
			}
			if (l < r) {
				nums[l++] = nums[r];
			}
			while (l < r && nums[l] < x) {
				l++;
			}
			if (l < r) {
				nums[r--] = nums[l];
			}
		}
		nums[l] = x;
		quickSort(nums, left, l-1);
		quickSort(nums, l+1, right);
	}
}


/**
* 功能：返回一个数组中，任意三个数的最大乘积
* 返回值：int
* 参数：int* 数组指针，int 数组大小
* result1和result2为什么要比较？
* 因为这个数组中有可能包含2个以上的负数（乘积可能会很大）
* 所以需要将前两个数和最后一个数相乘然后和倒数的3个数相乘的结果进行比较
*/
int maximumProduct2(int* nums, int numsSize) {
	int left = 0;
	int right = numsSize - 1;
	int result1, result2;
	quickSort(nums, left, right);
	result1 = nums[0] * nums[1] * nums[numsSize - 1];
	result2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
	if (result1 > result2) {
		return result1;
	}
	return result2;
}