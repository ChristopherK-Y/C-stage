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


/**
* 功能：利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能
* 返回值：字符串指针
* 参数：字符串指针
*/

int nums(int count) {
	int result = 0;
	while (count) {
		count /= 10;
		result++;
	}
	return result;
}

char* compressString(char* S) {
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
				while(count){
					*(tail + number - 1) = (count % 10) + '0';
					count /= 10;
					tail--;
				}
				tail += number;
				count = 1;
			}
		}
	}

	if (strlen(target) < strlen(S)) {
		return target;
	}
	return S;
}

int main() {
	char a[] = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
	printf("%s", compressString(a));
	return 0;
}