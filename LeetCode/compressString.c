/*
�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���aabcccccaaa���Ϊa2b1c5a3��
����ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ����ַ�����ֻ������СдӢ����ĸ��a��z����

ʾ��1 :

���룺"aabcccccaaa"
�����"a2b1c5a3"
ʾ��2 :

���룺"abbccd"
�����"abbccd"
���ͣ�"abbccd"ѹ����Ϊ"a1b2c2d1"����ԭ�ַ������ȸ�����
��ʾ��

�ַ���������[0, 50000]��Χ�ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/compress-string-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include"public.h"

//############################################################     ����1���������     #######################################################################################


/**
* ���ܣ�����һ���������ֵ�λ��
* ����ֵ��int
* ������int
*/
int nums(int count) {
	int result = 0;
	while (count) {
		count /= 10;
		result++;
	}
	return result;
}

/**
* ���ܣ������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ������
* ����ֵ���ַ���ָ��
* �������ַ���ָ��
*/
char* compressString_mine(char* S) {
	char* ptr = S;
	char* target = (char*)malloc(sizeof(char)*100000);
	memset(target, '\0', 100000);
	char* tail = target;
	int count = 1;
	int number = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == S[i + 1]) {
			count++;
		}
		else {
			if (count < 10) {
				*tail++ = S[i];
				*tail++ = count + '0';
				count = 1;
			}
			else {
				*tail++ = S[i];
				number = nums(count);
				tail = tail + number - 1;
				while(count){
					*tail-- = (count % 10) + '0';
					count /= 10;
				}
				tail += number + 1;
				count = 1;
			}
		}
	}

	if (strlen(target) < strlen(S)) {
		return target;
	}
	return S;
}

//############################################################     ����2�����׷���     #######################################################################################
char* compressString_others(char* S) {
	int size = strlen(S);
	if (size <= 2) return S;
	char* str = (char*)malloc(sizeof(char) * (2 * size));
	str[0] = S[0];
	int count = 1, index = 1;
	for (int i = 1; i < size + 1; i++) {
		if (S[i] == S[i - 1]) {
			count++;
		}
		else {
			int num = (int)log10(count) + index;
			index = num;
			while (count) {
				str[num--] = count % 10 + '0';
				count /= 10;
			}
			str[++index] = S[i];
			count = 1;
			++index;
		}
	}
	if (index >= size + 1) return S;
	return str;
}
/*
���ߣ�PonderYao
���ӣ�https ://leetcode-cn.com/problems/compress-string-lcci/solution/cyu-yan-yi-dong-jie-fa-4msde-9211yu-61mde-100-by-b/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/