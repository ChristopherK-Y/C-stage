/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。

示例 :

输入: "Hello, my name is John"
输出 : 5
解释 : 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/number-of-segments-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处
*/

#include"public.h"//头文件

/**
* 功能：统计字符串中的单词个数
* 返回值：一个整形的数（单词的个数）
* 参数：字符串指针
*/
int countSegments(char* s) {
	int count = 0;//定义一个计数器，初始化为0
	char* ptr = s;//定义一个指针指向这个字符指针
	while (*ptr) {
		if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0')) {//直接反向思维,如果写 == '' && != && != 有太多的考虑因素(可以体会)
			count++;//走到一个单词的最后一个字母了，count++
		}
		ptr++;//判断一次结束，指针后移
	}
	return count;//返回count的值
}
/*//测试块
int main() {
	const char* str = "";
	printf("%d", countSegments(str));
	return 0;
}
*/