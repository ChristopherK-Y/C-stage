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


/**
* ���ܣ������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ������
* ����ֵ���ַ���ָ��
* �������ַ���ָ��
*/

int nums(int count) {
	int result = 0;
	while (count) {
		count /= 10;
		result++;
	}
	return result;
}

char* compressString(char* S) {
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
				while(count){
					*(tail + number - 1) = (count % 10) + '0';
					count /= 10;
					tail--;
				}
				tail += number;
				count = 1;
			}
		}
	}

	if (strlen(target) < strlen(S)) {
		return target;
	}
	return S;
}

int main() {
	char a[] = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
	printf("%s", compressString(a));
	return 0;
}