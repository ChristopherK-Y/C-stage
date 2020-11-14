/*
����һ���������� arr�������ж��������Ƿ������������Ԫ�ض��������������������ڣ��뷵�� true �����򣬷��� false ��

ʾ�� 1��

���룺arr = [2, 6, 4, 1]
�����false
���ͣ���������������Ԫ�ض��������������
ʾ�� 2��

���룺arr = [1, 2, 34, 3, 4, 5, 7, 23, 12]
�����true
���ͣ�������������Ԫ�ض����������������[5, 7, 23] ��


��ʾ��

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/three-consecutive-odds
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

typedef enum { false, true } bool;//����һ����C�����ж��岼�����͵ķ���

/**
* ���ܣ���һ���������Ƿ��������Ԫ�ض������������
* ����ֵ��bool(���ߵĴ������Ѿ����壬����ʹ�ü���)
* ������һ����������,����Ĵ�С
*///����1
bool threeConsecutiveOdds(int* arr, int arrSize) {
	int count = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0 ) {//������һ������2ȡ�࣬�����1�������������������ż��
			count = 0;
			continue;
		}
		if (arr[i] % 2 == 1) {
			count++;
		}
		if (count > 2) {
			return true;
		}
	}
	return false;
}

//����2�����ַ�����˼·ֻ��һ�������ʱ�临�ӶȺͿռ临�Ӷ��ϻ���һ�£�
bool threeConsecutiveOdds(int* arr, int arrSize) {
	int count = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] & 1) {//����һ������1��λ��Ľ�����ǽ������һλ����λȡ��
			count++;
		}
		else {//���ȡ������1��ô�����������������ż��
			count = 0;
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}
