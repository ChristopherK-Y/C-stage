/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：

输入 : s = "abcdefg", k = 2
输出 : "cdefgab"
示例 2：

输入 : s = "lrloseumgh", k = 6
输出 : "umghlrlose"

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include"public.h"
/**
* 功能：把字符串前面的若干个字符转移到字符串的尾部
* 返回值：字符指针char*
* 参数：字符指针char*，需要左旋的字符个数
*/
char* reverseLeftWords(char* s, int n) {
	char* another = (char*)malloc(sizeof(char) * (strlen(s)));//开辟一块比原字符串大1Byte的空间//因为我们下面的每次操作无论如何指针都会后移，为了避免越界访问，我们多开辟1个Byte的空间
	char* first = s + n;//first指针偏移n个单位，直接指向完成左移后字符串的头元素
	char* second = s;//指向需要往后移的字符串的头元素（仅为第一个元素）
	char* ano = another;
	while (*first) {
		*ano++ = *first++;//把第n+1个元素开始至结尾往another数组里面写
	}
	for (int i = 0; i < n; i++) {
		*ano++ = *second++;//把前n个字符往another字符数组内写
	}
	*ano = '\0';//最后填上字符串的标志结束符'\0'
	return another;//返回字符串首元素指针
}


int main() {
	char* str = "abcdefg";
	printf("%s", reverseLeftWords(str, 2));
	return 0;
}