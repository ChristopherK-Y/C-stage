/*
给你一个字符串 s ，请你根据下面的算法重新构造字符串：

从s中选出最小的字符，将它接在结果字符串的后面。
从s剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它接在结果字符串后面。
重复步骤 2 ，直到你没法从 s 中选择字符。
从s中选出 最大 的字符，将它 接在结果字符串的后面。
从s剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它接在结果字符串后面。
重复步骤5,直到你没法从s中选择字符。
重复步骤1到6，直到s中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。

请你返回将s中字符重新排序后的结果字符串 。



示例 1：

输入：s = "aaaabbbbcccc"
输出："abccbaabccba"
解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
示例 2：

输入：s = "rat"
输出："art"
解释：单词 "rat" 在上述算法重排序以后变成 "art"
示例 3：

输入：s = "leetcode"
输出："cdelotee"
示例 4：

输入：s = "ggggggg"
输出："ggggggg"
示例 5：

输入：s = "spo"
输出："ops"


提示：

1 <= s.length <= 500
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/increasing-decreasing-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"


/**
* 功能：给你一个字符串s,请你根据下面的算法重新构造字符串
* 返回值：结果字符串指针
* 参数：char*源字符串指针
*/
char* sortString(char* s) {
	char count[26] = { 0 };
	char* ptr = s;
	int len = strlen(s);
	char result[500];
	char* tailPtr = result;
	int wordsCount;
	while (*ptr) {
		count[*ptr++ - 'a']++;
	}

	while (1) {
		for (int i = 0; i < 26; i++) {
			if (count[i]) {
				*tailPtr++ = i + 'a';
				count[i]--;
			}
		}
		for (int i = 25; i >= 0; i--) {
			if (count[i]) {
				*tailPtr++ = i + 'a';
				count[i]--;
			}
		}
		wordsCount = 0;
		for (int i = 0; i < 26; i++) {
			wordsCount += count[i];
		}
		if (wordsCount == 0) {
			*tailPtr = '\0';
			break;
		}
	}
	return result;
}

int main() {
	char sss[] = "aabbcc";
	char* ssss = sortString(sss);
	char* s = sss;
	int i = 0;
	printf("%c", ssss[1]);
	printf("%c", ssss[2]);
	while (ssss[i]) {
		
		printf("%c", ssss[i++]);
	}
	return 0;
}