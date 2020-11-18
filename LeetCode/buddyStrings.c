/*
给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
交换字母的定义是取两个下标 i 和 j （下标从 0 开始），只要 i != j 就交换 A[i] 和 A[j] 处的字符。例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。

示例 1：

输入： A = "ab", B = "ba"
输出： true
解释： 你可以交换 A[0] = 'a' 和 A[1] = 'b' 生成 "ba"，此时 A 和 B 相等。
示例 2：

输入： A = "ab", B = "ab"
输出： false
解释： 你只能交换 A[0] = 'a' 和 A[1] = 'b' 生成 "ba"，此时 A 和 B 不相等。
示例 3:

输入： A = "aa", B = "aa"
输出： true
解释： 你可以交换 A[0] = 'a' 和 A[1] = 'a' 生成 "aa"，此时 A 和 B 相等。
示例 4：

输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true
示例 5：

输入： A = "", B = "aa"
输出： false


提示：

0 <= A.length <= 20000
0 <= B.length <= 20000
A 和 B 仅由小写字母构成。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/buddy-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



#include"public.h"
typedef enum{false,true} bool;//C语言中一种定义布尔类型的方法之一



/**
* 功能：给定2个字符串，只要可以通过交换两个字符，使得2个字符串相等，就返回true
* 返回值：bool
* 参数：char*类型的两个字符串
*/
bool buddyStrings(char* A, char* B) {
	int lengthA = strlen(A);//A的长度
	int lengthB = strlen(B);//B的长度
	int differentCount = 0;//A和B中不同元素的个数
	char differentIndex[4] = { '\0' };//记录两个字符串不同的那两个位置的四个字符
	char* ptr = differentIndex;//定义一个指向上面的字符串的指针

	if (lengthA != lengthB || lengthA == lengthB && lengthA == 0) {//A和B长度不相等或者他们都是空串则返回false
		return false;
	}

	for (int i = 0; i < lengthA; i++) {//统计两个字符串中的不同的位置的个数
		if (A[i] != B[i]) {
			differentCount++;
		}
	}
	if (differentCount == 0) {//情况1：如果不同的位置等于0，则判断里面有没有两个字符相等，如果相等，则交换后，他们还是相等的，返回true，否则返回false
		for (int i = 0; i < lengthA; i++) {
			for (int j = i + 1; j < lengthA; j++) {
				if (A[i] == A[j]) {
					return true;
				}
			}
		}
		return false;
	}
	else if (differentCount == 2) {//情况2：如果不同的位置是2个，那么看把这两个位置的字符交换后，是否和字符串B相等，相等返回true，否则返回false
		for (int i = 0; i < lengthA; i++) {
			if (A[i] != B[i]) {
				*ptr = A[i];
				ptr++;
				*ptr = B[i];
				ptr++;
			}
		}
		if (differentIndex[0] == differentIndex[3] && differentIndex[1] == differentIndex[2]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {//情况3：如果不同位置的个数大于2，直接返回false（因为，交换1次以后两个字符串不可能相等）
		return false;
	}
}