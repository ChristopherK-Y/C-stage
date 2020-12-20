#include"public.h"
/*
数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回 - 1。 

示例 1：

输入：[1, 2, 5, 9, 5, 9, 5, 5, 5]
输出：5

示例 2：

输入：[3, 2]
输出： - 1

示例 3：

输入：[2, 2, 1, 1, 1, 2, 2]
输出：2

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/find-majority-element-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//方法一：
/**
* 返回值：一个 int（在传入数组中占比超过一半的数字） 否则返回-1
* 参  数：整形数组指针，数组大小
*/
int majorityElement_old(int* nums, int numsSize) {
	int halfsize = numsSize / 2;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		for (int j = 0; j < numsSize; j++) {
			if (nums[j] == nums[i]) {
				count++;
			}
		}
		if (count > halfsize) {
			return nums[i];
		}
		count = 0;
	}
	return -1;
}//本方法为最基本的暴力求解法，时间复杂度过高为n^2;


//方法二
/**
* 返回值：一个 int（在传入数组中占比超过一半的数字） 否则返回-1
* 参  数：整形数组指针，数组大小
*/
int majorityElement(int* nums, int numsSize) {//摩尔算法
	int major = nums[0];
	int count = 0;
	int majorCount = 0;
	int halfSize = numsSize / 2;
	for (int i = 0; i < numsSize; i++) {
		if (count == 0) {
			major = nums[i];
		}
		if (major == nums[i]) {
			count++;
		}
		else {
			count--;
		}
	}
	if (count == 0) {//没有超过一半，例[1，2，1，2]
		return -1;
	}
	else {//count>0,但是，有一种情况。例：[1，2，3] count=1,要判断是否为一半以上
		for (int i = 0; i < numsSize; i++) {
			if (major == nums[i]) {
				majorCount++;
			}
		}
		return majorCount > halfSize ? major : -1;
	}
}