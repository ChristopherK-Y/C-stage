/*
给定一个矩阵 A， 返回 A 的转置矩阵。
矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

示例 1：

输入： [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
输出： [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
示例 2：

输入： [[1, 2, 3], [4, 5, 6]]
输出： [[1, 4], [2, 5], [3, 6]]

提示：
1 <= A.length  <= 1000
1 <= A[0].length  <= 1000

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/transpose-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"//头文件

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 翻译：
 * 返回大小为*returnSize的数组。
 * 数组的大小以*returnColumnSizes数组的形式返回。
 * 注意：返回的数组和*columnSizes数组都必须是malloced，假设调用方调用free（）
 * 
 * 功能：给定一个矩阵 A,返回A的转置矩阵
 * 返回值：一个二级指针
 * 参数：传入的二级指针A，传入的二维数组的行数ASize，传入的二维数组的列数*AcolSize，返回的二维数组的行数returnSize，
 * 返回的二维数组的每列的元素个数所以还是一个二维数组returnColumnSizes
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * *AColSize);//定义一个int型的二级指针用于指向一个数组的首地址（数组内的每一个元素为一个int*类型的指针）（开辟的空间为原数组的列数）
    for (int i = 0; i < *AColSize; i++) {
        ret[i] = (int*)malloc(sizeof(int) * ASize);//给刚刚定义的每一个int*类型的指针给予指向的空间（也就是为新二维数组的列开辟空间，大小为原数组的行数）
    }
    
    for (int i = 0; i < *AColSize; i++) {//逆置块（较简单）
        for (int j = 0; j < ASize; j++) {
            ret[i][j] = A[j][i];
        }
    }

    *returnSize = *AColSize;//现在的行数等于之前的列数
    *returnColumnSizes = (int*)malloc(sizeof(int) * *AColSize);//每列的元素个数（是个数组），先开辟一块每个元素都是int型的数组空间，元素个数为现在的行数（原数组的列数）
    for (int i = 0; i < *AColSize; i++) {
        (*returnColumnSizes)[i] = ASize;//每一列的元素个数都是之前的行数（ASize）
    }
    return ret;//最后返回这个新开辟且已经重新赋值的二维数组
}
