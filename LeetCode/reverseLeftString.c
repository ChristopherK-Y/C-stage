//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺
//���� s1 = AABCD �� s2 = BCDAA������1
//���� s1 = abcd  �� s2 = ACBD�� ����0.

#include"public.h"

/**
* ���ܣ�����һ���ַ�������תn���ַ�
* ����ֵ���ַ�ָ��
* ������ԭ�ַ�ָ�룬Ҫ���Ƶĳ�������n
*/
char* reverseLeftString(char* src, int n) {
    char* copy = (char*)malloc(sizeof(char) * (strlen(src) + 1)); // ����һ���ԭ�ַ�����1Byte�Ŀռ�//��Ϊ���������ÿ�β����������ָ�붼����ƣ�Ϊ�˱���Խ����ʣ����Ƕ࿪��1��Byte�Ŀռ�
    char* first = src + n;//firstָ��ƫ��n����λ��ֱ��ָ��������ƺ��ַ�����ͷԪ��
    char* second = src;//ָ����Ҫ�����Ƶ��ַ�����ͷԪ�أ���Ϊ��һ��Ԫ�أ�
    char* ptr = copy;
    while (*first) {
        *ptr++ = *first++;//�ѵ�n+1��Ԫ�ؿ�ʼ����β��another��������д
    }
    while (n) {
        *ptr++ = *second++;//��ǰn���ַ���another�ַ�������д
        n--;
    }
    *ptr = '\0';//��������ַ����ı�־������'\0'
    return copy;//�����ַ�����Ԫ��ָ��
 }


/**
* ���ܣ��ж�һ���ַ�����������[0����������]����λ֮���Ƿ������һ���ַ������
* ����ֵ�����Σ�1��0��
* ������Ҫ�жϵ�2���ַ���ָ��
*/
int judge(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    for (int i = 0; i < strlen(str1); i++) {//��ת�ˣ�ֻ������[0,strlen(str1)]���£�ÿ�ζ��Ƿ���һ���ַ�ָ�룬���ı�ԭ�ַ������ַ���˳��
        if (strcmp(reverseLeftString(str1, i), str2) == 0) {//�����ת���ˣ�2���ַ�����ȣ���ôֱ��return 1��
            return 1;
        }
    }
    return 0;//��ת�����е������2���ַ���������ȣ���return 0;
}