/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"

/**
* 功能：给一个字符串,反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
* 返回值：一个指向字符串的指针
* 参数：原字符串指针
* 
* 思路：
* ①定义三个指针，第一个从左往右指向每一个元素，第二个指针指向第一个元素的下一个元素，第三个从左往右指向新开辟的数组的每一个元素
* ②给定两个while循环，第一个循环是一个死循环（其中有退出的条件），其中有两个分支，如果second指针指向的元素为' '或者'\0'那么，
* 就开始赋值（第二个循环）否则，就说明并不是符合条件的，说明一个单词还没有走完，first指针后移，second指针更新。
* 如果进入了第二个循环，复制阶段的判定条件为，first指针大于等于原字符串的头指针，且first指针不是' '
* 然后将second指向的东西赋给新字符串：赋空格或者赋'\0'
* ③判断现在second现在指向的内容是'\0'吗？如果是，直接返回新字符串的头指针就ok，如果不是，准备指向第二个单词（详情见下：：52—52行）
*/
char* reverseWords(char* s) {
	if (strlen(s) == 0) {//如果这个字符串为空，就直接返回这个这个空串
		return s;
	}
	char* first = s;//定义一个指针first指向第一个元素
	char* second = first + 1;//定义一个指针second指向first的下一个元素
	char* ret = (char*)malloc(sizeof(char)*(strlen(s) + 1));//动态开辟和原字符串一样大小的空间
	char* retP = ret;//定义一个retP指向刚刚开辟的新字符串首地址

	while (1) {
		if (*second == ' ' || *second == '\0') {//如果当前指针的下一个元素为空格或者是字符串结尾，那么就开始复制字符串（反向）
			while (first >= s && *first != ' ') {//反向复制的时候，循环条件为first指针要大于等于原字符串的头指针地址，且，它的当前指向不能是' ',
				*retP++ = *first--;//复制语句
			}
			*retP++ = *second;//这一步是给新字符串赋空格的或者是赋字符串末尾的
			if (*second == '\0') {//如果second指向字符串末尾了，那么直接返回ret指针
				return ret;
			}
			second += 1;//如果并不是'\0'，second指针后移，first指针复位
			first = second - 1;
		}
		else {//如果并不是符合条件的，说明一个单词还没有走完
			first++;//first指针后移
			second = first + 1;//second指针更新
		}
	}
}

/*//测试代码块
int main() {
	const char* test = "s'teL ekat edoCteeL tsetnoc";
	char* ret = reverseWords(test);
	printf("%s", ret);
	return 0;
}
*/