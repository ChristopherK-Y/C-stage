/*
����һ���������飬���������ҳ�����������ɵ����˻������������˻���

ʾ�� 1:

����: [1, 2, 3]
��� : 6
ʾ�� 2 :

���� : [1, 2, 3, 4]
��� : 24
ע�� :

�������������鳤�ȷ�Χ��[3, 104]�����������е�Ԫ�ط�Χ��[-1000, 1000]��
����������������������ĳ˻����ᳬ��32λ�з��������ķ�Χ��

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/maximum-product-of-three-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
* ���ܣ���������
* ����ֵ����
* ������int* arr(����ָ��)ΪĿ������
*		int leftΪ����ʱѡ�������߱�
*		int rightΪ����ʱѡ������ұ��±�־
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
* ���ܣ�����һ�������У����������������˻�
* ����ֵ��int
* ������int* ����ָ�룬int �����С
* result1��result2ΪʲôҪ�Ƚϣ�
* ��Ϊ����������п��ܰ���2�����ϵĸ������˻����ܻ�ܴ�
* ������Ҫ��ǰ�����������һ�������Ȼ��͵�����3������˵Ľ�����бȽ�
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