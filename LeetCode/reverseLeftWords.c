/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

ʾ�� 1��

���� : s = "abcdefg", k = 2
��� : "cdefgab"
ʾ�� 2��

���� : s = "lrloseumgh", k = 6
��� : "umghlrlose"

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include"public.h"
/**
* ���ܣ����ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β��
* ����ֵ���ַ�ָ��char*
* �������ַ�ָ��char*����Ҫ�������ַ�����
*/
char* reverseLeftWords(char* s, int n) {
	char* another = (char*)malloc(sizeof(char) * (strlen(s)));//����һ���ԭ�ַ�����1Byte�Ŀռ�//��Ϊ���������ÿ�β����������ָ�붼����ƣ�Ϊ�˱���Խ����ʣ����Ƕ࿪��1��Byte�Ŀռ�
	char* first = s + n;//firstָ��ƫ��n����λ��ֱ��ָ��������ƺ��ַ�����ͷԪ��
	char* second = s;//ָ����Ҫ�����Ƶ��ַ�����ͷԪ�أ���Ϊ��һ��Ԫ�أ�
	char* ano = another;
	while (*first) {
		*ano++ = *first++;//�ѵ�n+1��Ԫ�ؿ�ʼ����β��another��������д
	}
	for (int i = 0; i < n; i++) {
		*ano++ = *second++;//��ǰn���ַ���another�ַ�������д
	}
	*ano = '\0';//��������ַ����ı�־������'\0'
	return another;//�����ַ�����Ԫ��ָ��
}


int main() {
	char* str = "abcdefg";
	printf("%s", reverseLeftWords(str, 2));
	return 0;
}