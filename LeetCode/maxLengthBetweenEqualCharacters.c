/*
给你一个字符串s，请你返回两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回-1 。
子字符串 是字符串中的一个连续字符序列。

示例 1：

输入：s = "aa"
输出：0
解释：最优的子字符串是两个 'a' 之间的空子字符串。
示例 2：

输入：s = "abca"
输出：2
解释：最优的子字符串是 "bc" 。
示例 3：

输入：s = "cbzxy"
输出： - 1
解释：s 中不存在出现出现两次的字符，所以返回 - 1 。
示例 4：

输入：s = "cabbac"
输出：4
解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。

提示：

1 <= s.length <= 300
s 只含小写英文字母

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/largest-substring-between-two-equal-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include"public.h"


/**
* 功能：给定一个字符串s,返回两个相同字符之间的最长子字符串的长度 
* 返回值：int（最长子字符串）
* 参数：字符串指针
*/
int maxLengthBetweenEqualCharacters(char* s) {
	char arr[301];
	Strcpy(arr, s);
	char* left = arr;
	char* right = arr + strlen(s) - 1;
	int max = -1;
	int len;
	while (left < right) {
		while (left < right) {
			if (left < right && *left == *right) {
				left++;
				*right = '\0';
				if (*left == '\0') {
					len = 0;
				}
				else {
					len = strlen(left);
				}
				if (len > max) {
					max = len;
				}
				Strcpy(arr, s);
				left--;
				break;
			}
			else {
				right--;
			}
		}
		left++;
		right = arr + strlen(s) - 1;
	}
	
	return max;
}
/*
本体题的解题思路是，在函数内部，首先复制一份字符串，
使用这个字符串，然后定义2个指针，分别指向这个字符串的首尾
开始进入while循环，如果right指针遇到和左边一样的字符，那么
left指针++，然后*right='\0'，（方便计算长度），判断这个strlen（left）比max（当前最大的子字符串长度）大吗？
如果大，那么更新max。因为这里对left++了，那么，就需要最后left--，并且把复制字符串还原为源字符串,
如果没有遇到和*left一样的，right就--；
最后返回max（初始化为-1），如果从来都没有进入复制循环，那么max不会更新，就可以直接返回-1这个初始值。
*/