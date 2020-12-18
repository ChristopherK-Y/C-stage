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
* 见注释^-^
*/
int countCharacters(char** words, int wordsSize, char* chars) {
	int	charsLen = strlen(chars);
	if (charsLen == 0 || wordsSize == 0) {//如果单词表或者字母表任意一个为0，那么就直接返回0
		return 0;
	}
	int map[26], count[26];//定义2个数组，用于统计字母表和每个单词的字母频率
	memset(map, 0, sizeof(int) * 26);//首先对字母表统计数组清零
	for (int i = 0; i < charsLen; i++) {
		map[chars[i] - 'a']++;//统计字母表中每种字母的频率
	}
	
	int j = 0, max = 0;//j为单词的长度循环遍历，见58行，max为被拼写的单词的总长度
	for (int i = 0; i < wordsSize; i++) {
		int len = strlen(words[i]);
		if (len > charsLen) {//如果单词的长度比字母表的长度还长，说明这个单词一定无法拼写
			continue;//直接跳过该单词
		}
		memset(count, 0, sizeof(int) * 26);//对单词频率计数数组清零
		for (j = 0; j < len; j++) {
			count[words[i][j] - 'a']++;//统计该单词每个字母的频率
			if (map[words[i][j]-'a'] < count[words[i][j] - 'a']) {
				break;//如果出现任何一个单词的频率比字母表中的频率还高，说明一定无法拼写
			}
		}
		if (len == j) {
			max += len;//如果未执行break，说明该单词可以被拼写，就把该单词的长度加到max中
		}
	}
	return max;//返回max，被拼写的单词的总长度
}


