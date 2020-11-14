/*
给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。

示例 1：

输入：arr = [2, 6, 4, 1]
输出：false
解释：不存在连续三个元素都是奇数的情况。
示例 2：

输入：arr = [1, 2, 34, 3, 4, 5, 7, 23, 12]
输出：true
解释：存在连续三个元素都是奇数的情况，即[5, 7, 23] 。


提示：

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/three-consecutive-odds
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef enum { false, true } bool;//给出一种在C语言中定义布尔类型的方法

/**
* 功能：求一个数组中是否存在三个元素都是奇数的情况
* 返回值：bool(作者的代码中已经定义，仅需使用即可)
* 参数：一个整形数组,数组的大小
*///方法1
bool threeConsecutiveOdds(int* arr, int arrSize) {
	int count = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0 ) {//对任意一个数对2取余，如果是1，就是奇数，否则就是偶数
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

//方法2（两种方法的思路只有一点点差别，在时间复杂度和空间复杂度上基本一致）
bool threeConsecutiveOdds(int* arr, int arrSize) {
	int count = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] & 1) {//任意一个数和1按位与的结果就是将其最后一位比特位取出
			count++;
		}
		else {//如果取出的是1那么就是奇数，否则就是偶数
			count = 0;
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}
