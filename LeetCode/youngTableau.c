//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);



/*//����1����̫������Ч�ʲ�����
int youngTableau(int matrix[][COL], int target, int row, int col) {
    int i = 0;
    int j = col - 1;
    if (target<matrix[0][0] || target>matrix[row - 1][col - 1]) {
        return 0;
    }
    for (int k = col - 1; k > 0; k--) {
        if (matrix[0][k] > target) {
            j = k - 1;
        }
    }
    for (int k = 0; k < row - 1; k++) {
        if (matrix[k][j] < target) {
            i = k + 1;
        }
    }
    for (int a = i; a >= 0; a--) {
        for (int b = j; b >= 0; b--) {
            if (matrix[a][b] == target) {
                return 1;
            }
        }
    }
    return 0;
}
*/

//����2������
#include"public.h"

#define ROW 3
#define COL 8

/**
* ���ܣ������Ͼ����������һ����
* ����ֵ��int��������bool��typedef enum{false,ture}bool;
* ��������ά���飬Ŀ�����֣�����������
* ˼·�����������ȴӣ���һ�е����һ��Ԫ�ؿ�ʼ�ң���ô�ͻ�������3�������
* ���������Ŀ��������ȣ�ֱ�ӷ���1�ͺ�
* �������С��Ŀ�����֣��������Ͼ���ĵ������ԣ���˵�������ǰ������ֶ���Ŀ������ҪС������������������+1
* �����������Ŀ�����֣��������Ͼ���ĵ������ԣ���˵��������ֵ�ǰ������к�Ŀ��������ȵ����֣�������������-1
* Ȼ��
* ���ǲ��ϵ�ѭ��������̣��Ϳ���ȷ�������û��Ŀ�����֡�
*/
int youngTableau(int matrix[][COL], int target, int row, int col) {
    int i = 0;
    int j = col - 1;
    if (target<matrix[0][0] || target>matrix[row - 1][col - 1]) {//���Ŀ�����ֱȾ���������С��Ԫ�ض�С���߱�����Ԫ�ػ�����ô��һ����������ֱ�ӷ���0�ͺ�
        return 0;
    }
    if (row > 0 && col > 0) {
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {//�������Ŀ��������ȣ�ֱ�ӷ���1�ͺ�
                return 1;
            }
            else if (matrix[i][j] < target) {//�����С��Ŀ�����֣��������Ͼ���ĵ������ԣ���˵�������ǰ������ֶ���Ŀ������ҪС������������������+1
                i++;
            }
            else {//���������Ŀ�����֣��������Ͼ���ĵ������ԣ���˵��������ֵ�ǰ������к�Ŀ��������ȵ����֣�������������-1
                j--;
            }
        }
    }
    return 0;
}


/*���Դ����
int main() {
    int matrix[ROW][COL]={ {1,2,3,4,5,6,7,8},
                           {9,10,11,12,13,14,15,16},
                           {17,18,19,21,22,23,24,26}
    };
    int x = 10;
    if (youngTableau(matrix,x,ROW,COL)) {
        printf("In!\n");
    }
    else {
        printf("Not in!\n");
    }
    return 0;
}
*/
