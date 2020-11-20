/*
给你一个整数 n，请你返回一个含 n 个字符的字符串，其中每种字符在该字符串中都恰好出现奇数次。
返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。

示例 1：

输入：n = 4
输出："pppz"
解释："pppz" 是一个满足题目要求的字符串，因为 'p' 出现 3 次，且 'z' 出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ohhh" 和 "love"。
示例 2：

输入：n = 2
输出："xy"
解释："xy" 是一个满足题目要求的字符串，因为 'x' 和 'y' 各出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ag" 和 "ur"。
示例 3：

输入：n = 7
输出："holasss"


提示：
1 <= n <= 500

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include"public.h"


/**
* 功能：给你一个整数n,请你返回一个含n个字符的字符串,其中每种字符在该字符串中都恰好出现奇数次。
* 返回值：char 型数组指针
* 参数：整形n
*/
char* generateTheString_mine(int n) {
	char* result = (char*)malloc(sizeof(char) * (n + 1));
	result[n] = '\0';
	if (n & 1) {
		memset(result, 'a', n);
	}
	else {
		memset(result, 'a', n - 1);
		result[n - 1] = 'b';
	}
	return result;
}

/**
* 其他人写的代码，较为简洁
*/
char* generateTheString_others(int n)
{
	char* ret;
	ret = (char*)malloc(sizeof(char) * (n + 1));
	ret[n] = '\0';
	memset(ret, 'b', n);
	ret[n - 1] = 'b' + (n % 2 == 0);
	return ret;
}
/*
作者：yxyy3604
链接：https ://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/solution/1374-sheng-cheng-mei-chong-zi-fu-du-shi-qi-shu-ge-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/