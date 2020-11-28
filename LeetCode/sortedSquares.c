/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：

输入：[-4, -1, 0, 3, 10]
输出：[0, 1, 9, 16, 100]
示例 2：

输入：[-7, -3, 2, 3, 11]
输出：[4, 9, 9, 49, 121]


提示：

1 <= A.length <= 10000
- 10000 <= A[i] <= 10000
A 已按非递减顺序排序。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/squares-of-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"

//以下为方法1：方法很简单（不做解释）
//————————————————————————————————————————————————————————————————————————
/**
* qsort函数的比较部分，不做过多的解释
*/
int compare(const void* xp, const void* yp) {
	int x = *(int*)xp;
	int y = *(int*)yp;

	if (x > y) {
		return 1;
	}
	else if (x < y) {
		return -1;
	}
	else {
		return 0;
	}

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 注意:返回的数组必须被分配，假设调用者调用free()。
 */
int* sortedSquares_1(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;
	int* ret = (int*)malloc(sizeof(int) * ASize);
	for (int i = 0; i < ASize; i++) {
		ret[i] = A[i]*A[i];
	}
	qsort(ret, ASize, sizeof(int), compare);//qsort C语言内置的无类型快速排序
	return ret;
}
//————————————————————————————————————————————————————————————————————————
//以为方法2

/**
* 功能：给一个按非递减顺序排序的整数数组A，返回每个数字的平方组成的新数组，也按非递减顺序排序。
* 返回值：整数数组的首地址
* 参数：原数组的首地址A，数组的元素个数ASize，返回的数组的元素个数returnSize
* 
* 思路：
* ①我们首先动态开辟一个和原数组一样大小的数组(ret)
* ②定义三个int型变量：i初始化为指向第一个元素，j初始为指向最后一个元素，pos指向最后一个元素
* ③进入for循环：
* ——————————————————————————————————————————————
* 核心思路：（我们需要意识到下面几点）
* ①如果数组的元素全部都是非负数，那么平方之后的顺序不变
* ②如果数组的元素全部都是负数，那么平方之后的顺序恰好相反
* ③如果数组的元素既有负数也有正数，那么看似是无序的，实际上，我们的最大值不是开头就是结尾来的
* ——————————————————————————————————————————————
* 接着上面的③进入for循环：
* 我们首先比较开头(i)的平方和末尾(j)的平方的大小
* 1）如果开头的大，那么就在新数组的pos位置赋值i平方。i指针后移(i++)，pos指针前移(pos--)
* 2）否则，就在新数组的pos位置赋值j平方。j指针前移(j--)，pos指针前移(pos--)
* 循环条件为i <= j，(因为，如果写成i<j,且i的平方一直小于j的平方，那么，i的平方就永远不可能被赋值)
* ④返回ret指针
*/
int* sortedSquares(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;//返回数组的元素个数一定和原数组的元素个数相等
	int* ret = (int*)malloc(sizeof(int) * ASize);//动态开辟一个和原数组一样大小的数组(ret)
	for (int i = 0, j = ASize - 1, pos = ASize - 1; i <= j;) {//定义三个int型变量：i初始化为指向第一个元素，j初始为指向最后一个元素，pos指向最后一个元素
		if (A[i] * A[i] > A[j] * A[j]) {//如果开头的大，那么就在新数组的pos位置赋值i平方。i指针后移(i++)，pos指针前移(pos--)
			ret[pos] = A[i] * A[i];
			i++;
			pos--;
		}
		else{//否则，就在新数组的pos位置赋值j平方。j指针前移(j--)，pos指针前移(pos--)
			ret[pos] = A[j] * A[j];
			j--;
			pos--;
		}
	}
	return ret;//返回ret指针
}