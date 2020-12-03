/*����һ�����ظ�Ԫ�ص������������� nums ��
����ǡ�ø����������������ֵ���С�������䷶Χ�б�Ҳ����˵��nums��ÿ��Ԫ�ض�ǡ�ñ�ĳ�����䷶Χ�����ǣ����Ҳ���������ĳ����Χ��������nums������x ��
�б��е�ÿ�����䷶Χ[a, b] Ӧ�ð����¸�ʽ�����

"a->b" ����� a != b
"a" ����� a == b


ʾ�� 1��

���룺nums = [0, 1, 2, 4, 5, 7]
�����["0->2", "4->5", "7"]
���ͣ����䷶Χ�ǣ�
[0, 2] -- > "0->2"
[4, 5] -- > "4->5"
[7, 7] -- > "7"
ʾ�� 2��

���룺nums = [0, 2, 3, 4, 6, 8, 9]
�����["0", "2->4", "6", "8->9"]
���ͣ����䷶Χ�ǣ�
[0, 0] -- > "0"
[2, 4] -- > "2->4"
[6, 6] -- > "6"
[8, 9] -- > "8->9"
ʾ�� 3��

���룺nums = []
�����[]
ʾ�� 4��

���룺nums = [-1]
�����["-1"]
ʾ�� 5��

���룺nums = [0]
�����["0"]


��ʾ��

0 <= nums.length <= 20
- 231 <= nums[i] <= 231 - 1
nums �е�����ֵ�� ������ͬ

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/summary-ranges
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/


#include"public.h"

//����������������������    ����1    ��������������������������������������������������    ����1    ��������������������������������������������������    ����1    ����������������������������

void write(int* nums, int l, int r, char** ret, int now) {//д�뺯��
	if (l != r) {
		ret[now] = (char*)malloc(sizeof(char) * 5);
		ret[now][0] = '0' + nums[l];
		ret[now][1] = '-';
		ret[now][2] = '>';
		ret[now][3] = '0' + nums[r];
		ret[now][4] = '\0';
		return;
	}
	else {
		ret[now] = (char*)malloc(sizeof(char) * 2);
		ret[now][0] = '0' + nums[l];
		ret[now][1] = '\0';
		return;
	}
}


/**
 * ���ܣ�����ֵ������������2
 * 
 * ˼·�������Դ˼����ҵ�˼·��
 * ���ܲ�δʵ�֣�����̫�������҆��£���ӹ����if
 * �ڵ���write�������Լ�ʵ�֣���ʱ��ֻ��д��һλ��ʮ��������
 */
char** summaryRanges_mine(int* nums, int numsSize, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * numsSize);
	int l = 0, r = 1, now = 0;

	if (numsSize == 1) {
		*returnSize = 1;
		write(nums, 0, 0, ret, now);
		return realloc(ret, sizeof(char*) * 1);
	}

	if (numsSize == 0) {
		return NULL;
	}


	while (r < numsSize) {
		if (nums[r] == (nums[r - 1] + 1) && r != numsSize - 1) {
			r++;
		}
		else{
			write(nums, l, r - 1, ret, now);
			now++, r++;
			l = r - 1;
		}
		if (r == numsSize - 1) {
			if (nums[r] == (nums[r - 1] + 1)) {
				write(nums, l, r, ret, now);
				now++;
			}
			else {
				write(nums, l, r - 1, ret, now);
				now++;
				write(nums, r, r, ret, now);
			}
		}
	}
	*returnSize = now;
	return realloc(ret, sizeof(char*) * now);
}


//����������������������    ����2    ��������������������������������������������������    ����2    ��������������������������������������������������    ����2    ����������������������������

/**
* ���ܣ����룺nums = [0, 2, 3, 4, 6, 8, 9]�������["0", "2->4", "6", "8->9"]
* ����ֵ��һ��char**���ڲ�Ԫ��Ϊchar*ָ��һ���ַ�����
* ������nums���������������
*		numsSize�������Ԫ�ظ���
*		returnSize�����ص������Ԫ�ظ�����char*�ĸ����������ַ����ĸ�����
* 
* ˼·��
* �����ȿ���һ��Ԫ�ظ�������������һ����С��char*���飨����ÿһ��Ԫ�ض��ǵ����Ĳ������ģ�
* �ڶ��壺left��ָ�룬right��ָ�룬now�����ж��ٸ��ַ�����
* ˼�룺
* ����һ��ѭ������һ��������ָ�����ָ��ָ��һ���ĵ�Ԫ��Ȼ��һֱ������һ��Ԫ�أ���Ԫ�ص���һԪ�غ͸�Ԫ�ز�������ֱ���ҵ�һ������Ҫ���Ԫ��
* �ڶ������������ָ��ָ��ͬһ��Ԫ�أ���ô�Ϳ��ٿռ䣬Ȼ��ʹ��sprintfд�룬�����д������һ�ָ�ʽ%d->%d
* ����*returnSize��ֵ,Ȼ�󷵻��¿��ٵ�ָ��
*/
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * numsSize);
	int left = 0;
	int right = 0;
	int now = 0;

	for (; right < numsSize; right++) {
		left = right;
		while (right < numsSize - 1 && (nums[right] + 1) == nums[right + 1]) {
			right++;
		}

		if (left == right) {
			ret[now] = (char*)calloc(30, sizeof(char));
			sprintf(ret[now++], "%d", nums[left]);
		}
		else {
			ret[now] = (char*)calloc(30, sizeof(char));
			sprintf(ret[now++], "%d->%d", nums[left], nums[right]);
		}
	}
	*returnSize = now ;
	return ret;
}





//int main() {//���Դ���ģ��
//	int nums[] = { 0, 1, 2, 4, 5, 7 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int returnSize = 0;
//	char** sss = summaryRanges(nums, numsSize, &returnSize);
//
//	return 0;
//}


