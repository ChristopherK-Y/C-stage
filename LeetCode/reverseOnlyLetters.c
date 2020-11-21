/*
给定一个字符串 S，返回"反转后的"字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"


提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S 中不包含 \ or "

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"//头文件
/*解题思路：
定义两个指针，分别指向字符串的头和尾
然后开始判断，2个while循环，当他们分别都指向字母的时候
交换他们的位置，直到left指针大于等于right指针的时候
退出循环，return 结果字符串
*/
char* Strcpy(char* dst, char* src) {//strcpy函数
	char* ptr = src;
	while (*dst++ = *ptr++) {

	}
	return dst;
}



/**
* 功能：给定一个字符串S,返回"反转后的"字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
* 返回值：char*数组
* 参数：char*
*/
char* reverseOnlyLetters(char* S) {
	char* result = (char*)malloc(sizeof(char)*(strlen(S)+1));
	Strcpy(result, S);
	char* left = result;
	char* right = result + strlen(result) - 1;
	while (left < right) {
		while (left < right && (!(*left >= 'a' && *left <= 'z') && !(*left >= 'A' && *left <= 'Z'))) {
			left++;
		}
		while (left < right && (!(*right >= 'a' && *right <= 'z') && !(*right >= 'A' && *right <= 'Z'))) {
			right--;
		}
		if (left < right) {
			*left ^= *right;
			*right ^= *left;
			*left ^= *right;
			left++;
			right--;
		}
	}
	return result;
}


/*int main() {
	char* example = "Test1ng-Leet=code-Q!";
	printf("%s", reverseOnlyLetters(example));
	return 0;
}*///测试代码