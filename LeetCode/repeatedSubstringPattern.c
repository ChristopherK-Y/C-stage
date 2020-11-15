/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出 : True

解释 : 可由子字符串 "ab" 重复两次构成。
示例 2 :

输入 : "aba"

输出 : False
示例 3 :

输入 : "abcabcabcabc"

输出 : True

解释 : 可由子字符串 "abc" 重复四次构成。(或者子字符串 "abcabc" 重复两次构成。)

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/repeated-substring-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include"public.h"
typedef enum {false,true} bool;


/**
* 功能：判断一个字符串是否可以由它的一个子串重复多次构成
* 返回值：bool
* 参数：char*字符串首地址
* 
* 思路与算法
* 如果一个长度为 n 的字符串 s 可以由它的一个长度为n′的子串s′重复多次构成，那么:
* n一定是n′的倍数;
* s′一定是s的前缀;
* 对于任意的i∈[n′,n)，有s[i]=s[i−n′]。
* 也就是说，ss 中长度为n′的前缀就是s′,并且在这之后的每一个位置上的字符s[i]，都需要与它之前的第n′个字符s[i−n′]相同。
* 因此，我们可以从小到大枚举n′，并对字符串s进行遍历，进行上述的判断。注意到一个小优化是，因为子串至少需要重复一次，所以n′不会大于n的一半，我们只需要在 [1,n/2]的范围内枚举n′即可。
*/
bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);
	for (int i = 1; i <= len / 2; i++) {
		if (len % i == 0) {
			bool result = true;
			for (int j = i; j < len; j++) {
				if (s[j] != s[j - i]) {
					result = false;
					break;
				}
			}
			if (result) {
				return true;
			}
		}	
	}
	return false;
}