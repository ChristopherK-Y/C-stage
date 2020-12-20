#include"public.h"
/*
������ռ�ȳ���һ���Ԫ�س�֮Ϊ��ҪԪ�ء�����һ���������飬�ҵ�������ҪԪ�ء���û�У����� - 1�� 

ʾ�� 1��

���룺[1, 2, 5, 9, 5, 9, 5, 5, 5]
�����5

ʾ�� 2��

���룺[3, 2]
����� - 1

ʾ�� 3��

���룺[2, 2, 1, 1, 1, 2, 2]
�����2

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/find-majority-element-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


//����һ��
/**
* ����ֵ��һ�� int���ڴ���������ռ�ȳ���һ������֣� ���򷵻�-1
* ��  ������������ָ�룬�����С
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
}//������Ϊ������ı�����ⷨ��ʱ�临�Ӷȹ���Ϊn^2;


//������
/**
* ����ֵ��һ�� int���ڴ���������ռ�ȳ���һ������֣� ���򷵻�-1
* ��  ������������ָ�룬�����С
*/
int majorityElement(int* nums, int numsSize) {//Ħ���㷨
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
	if (count == 0) {//û�г���һ�룬��[1��2��1��2]
		return -1;
	}
	else {//count>0,���ǣ���һ�����������[1��2��3] count=1,Ҫ�ж��Ƿ�Ϊһ������
		for (int i = 0; i < numsSize; i++) {
			if (major == nums[i]) {
				majorCount++;
			}
		}
		return majorCount > halfSize ? major : -1;
	}
}