//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);



/*//方法1，有太暴力，效率不够高
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

//方法2：如下
#include"public.h"

#define ROW 3
#define COL 8

/**
* 功能：在杨氏矩阵里面查找一个数
* 返回值：int（可以做bool）typedef enum{false,ture}bool;
* 参数：二维数组，目标数字，行数，列数
* 思路：首先我们先从，第一行的最后一个元素开始找，那么就会有以下3种情况：
* ①这个数和目标数字相等，直接返回1就好
* ②这个数小于目标数字，由于杨氏矩阵的递增特性，就说明这个数前面的数字都比目标数字要小，所以我们让行数加+1
* ③这个数大于目标数字，由于杨氏矩阵的递增特性，就说明这个数字的前面可能有和目标数字想等的数字，所以我们列数-1
* 然后：
* 我们不断的循环这个过程，就可以确定最后有没有目标数字。
*/
int youngTableau(int matrix[][COL], int target, int row, int col) {
    int i = 0;
    int j = col - 1;
    if (target<matrix[0][0] || target>matrix[row - 1][col - 1]) {//如果目标数字比矩阵里面最小的元素都小或者比最大的元素还大，那么它一定不在里面直接返回0就好
        return 0;
    }
    if (row > 0 && col > 0) {
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {//这个数和目标数字相等，直接返回1就好
                return 1;
            }
            else if (matrix[i][j] < target) {//这个数小于目标数字，由于杨氏矩阵的递增特性，就说明这个数前面的数字都比目标数字要小，所以我们让行数加+1
                i++;
            }
            else {//这个数大于目标数字，由于杨氏矩阵的递增特性，就说明这个数字的前面可能有和目标数字想等的数字，所以我们列数-1
                j--;
            }
        }
    }
    return 0;
}


/*测试代码块
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
