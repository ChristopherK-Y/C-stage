/*
����һ������ n�����㷵��һ���� n ���ַ����ַ���������ÿ���ַ��ڸ��ַ����ж�ǡ�ó��������Ρ�
���ص��ַ�������ֻ��СдӢ����ĸ��������ڶ��������ĿҪ����ַ������򷵻���������һ�����ɡ�

ʾ�� 1��

���룺n = 4
�����"pppz"
���ͣ�"pppz" ��һ��������ĿҪ����ַ�������Ϊ 'p' ���� 3 �Σ��� 'z' ���� 1 �Ρ���Ȼ�����кܶ������ַ���Ҳ������ĿҪ�󣬱��磺"ohhh" �� "love"��
ʾ�� 2��

���룺n = 2
�����"xy"
���ͣ�"xy" ��һ��������ĿҪ����ַ�������Ϊ 'x' �� 'y' ������ 1 �Ρ���Ȼ�����кܶ������ַ���Ҳ������ĿҪ�󣬱��磺"ag" �� "ur"��
ʾ�� 3��

���룺n = 7
�����"holasss"


��ʾ��
1 <= n <= 500

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include"public.h"


/**
* ���ܣ�����һ������n,���㷵��һ����n���ַ����ַ���,����ÿ���ַ��ڸ��ַ����ж�ǡ�ó��������Ρ�
* ����ֵ��char ������ָ��
* ����������n
*/
char* generateTheString_mine(int n) {
	char* result = (char*)malloc(sizeof(char) * (n + 1));
	result[n] = '\0';
	if (n & 1) {
		memset(result, 'a', n);
	}
	else {
		memset(result, 'a', n - 1);
		result[n - 1] = 'b';
	}
	return result;
}

/**
* ������д�Ĵ��룬��Ϊ���
*/
char* generateTheString_others(int n)
{
	char* ret;
	ret = (char*)malloc(sizeof(char) * (n + 1));
	ret[n] = '\0';
	memset(ret, 'b', n);
	ret[n - 1] = 'b' + (n % 2 == 0);
	return ret;
}
/*
���ߣ�yxyy3604
���ӣ�https ://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/solution/1374-sheng-cheng-mei-chong-zi-fu-du-shi-qi-shu-ge-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/