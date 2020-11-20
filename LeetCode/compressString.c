/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1 :

输入："aabcccccaaa"
输出："a2b1c5a3"
示例2 :

输入："abbccd"
输出："abbccd"
解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"

//############################################################     方法1：暴力求解     #######################################################################################


/**
* 功能：计算一个传入数字的位数
* 返回值：int
* 参数：int
*/
int nums(int count) {
	int result = 0;
	while (count) {
		count /= 10;
		result++;
	}
	return result;
}

/**
* 功能：利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能
* 返回值：字符串指针
* 参数：字符串指针
*/
char* compressString_mine(char* S) {
	char* ptr = S;
	char* target = (char*)malloc(sizeof(char)*100000);
	memset(target, '\0', 100000);
	char* tail = target;
	int count = 1;
	int number = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == S[i + 1]) {
			count++;
		}
		else {
			if (count < 10) {
				*tail++ = S[i];
				*tail++ = count + '0';
				count = 1;
			}
			else {
				*tail++ = S[i];
				number = nums(count);
				tail = tail + number - 1;
				while(count){
					*tail-- = (count % 10) + '0';
					count /= 10;
				}
				tail += number + 1;
				count = 1;
			}
		}
	}

	if (strlen(target) < strlen(S)) {
		return target;
	}
	return S;
}

//############################################################     方法2：进阶方法     #######################################################################################
char* compressString_others(char* S) {
	int size = strlen(S);
	if (size <= 2) return S;
	char* str = (char*)malloc(sizeof(char) * (2 * size));
	str[0] = S[0];
	int count = 1, index = 1;
	for (int i = 1; i < size + 1; i++) {
		if (S[i] == S[i - 1]) {
			count++;
		}
		else {
			int num = (int)log10(count) + index;
			index = num;
			while (count) {
				str[num--] = count % 10 + '0';
				count /= 10;
			}
			str[++index] = S[i];
			count = 1;
			++index;
		}
	}
	if (index >= size + 1) return S;
	return str;
}
/*
作者：PonderYao
链接：https ://leetcode-cn.com/problems/compress-string-lcci/solution/cyu-yan-yi-dong-jie-fa-4msde-9211yu-61mde-100-by-b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/