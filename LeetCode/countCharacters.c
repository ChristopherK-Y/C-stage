/*给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。
假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。
返回词汇表 words 中你掌握的所有单词的 长度之和。

示例 1：

输入：words = ["cat", "bt", "hat", "tree"], chars = "atach"
输出：6
解释：
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello", "world", "leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。


提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length  <= 100
所有字符串中都仅包含小写英文字母

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include"public.h"

/**
* 功能：返回词汇表words中你掌握的所有单词的长度之和
* 返回值：int 长度之和
* 参数：二级指针，原字符串数组的指针，字符串的个数，字母表字符串的指针
* 
* 思路：
* 围绕hash表的理念来解，将chars生成一个hash表，一共26个int空间对应26个字母，不出现的为0，出现的为1，重复则++
* 重点：hash表要保留着让所有word都能用来查找，因此创建一个同等大小的count计数数组
* 遍历单个word过程中，长度超过chars长度的直接跳过；
* 判断字符在hash表中是否出现（hash值不为0），如果出现重复，判断count值是否超过hash，超过说明该字母在chars中的重复个数不足
* 如果判断没问题，count值+1；如果循环中无break，max加上该word的长度
* 一轮word遍历后，下一轮word遍历前，count必须置零！
*/
int countCharacters(char** words, int wordsSize, char* chars) {
	int len = strlen(chars);
	if (len == 0 || wordsSize == 0) {//任何一方为0就是0
		return 0;
	}
	int map[26], count[26];
	memset(map, 0, sizeof(int) * 26);
	for (int i = 0; i < len; i++) {//统计字母表中每个字母的频率
		map[chars[i] - 'a']++;
	}
	int j = 0;
	int max = 0;
	for (int i = 0; i < wordsSize; i++) {
		int wordLen = strlen(words[i]);
		if (wordLen > len) {
			continue;
		}
		memset(count, 0, sizeof(int) * 26);
		for (j = 0; j < wordLen; j++) {
			count[words[i][j] - 'a']++;
			if (map[words[i][j] - 'a'] < count[words[i][j] - 'a']) {
				break;
			}
		}
		if (j == wordLen) {
			max += wordLen;
		}
	}
	return max;
}