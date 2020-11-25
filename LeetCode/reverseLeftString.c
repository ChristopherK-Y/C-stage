//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：
//给定 s1 = AABCD 和 s2 = BCDAA，返回1
//给定 s1 = abcd  和 s2 = ACBD， 返回0.

#include"public.h"

/**
* 功能：左旋一个字符串，旋转n个字符
* 返回值：字符指针
* 参数：原字符指针，要左移的长度整形n
*/
char* reverseLeftString(char* src, int n) {
    char* copy = (char*)malloc(sizeof(char) * (strlen(src) + 1)); // 开辟一块比原字符串大1Byte的空间//因为我们下面的每次操作无论如何指针都会后移，为了避免越界访问，我们多开辟1个Byte的空间
    char* first = src + n;//first指针偏移n个单位，直接指向完成左移后字符串的头元素
    char* second = src;//指向需要往后移的字符串的头元素（仅为第一个元素）
    char* ptr = copy;
    while (*first) {
        *ptr++ = *first++;//把第n+1个元素开始至结尾往another数组里面写
    }
    while (n) {
        *ptr++ = *second++;//把前n个字符往another字符数组内写
        n--;
    }
    *ptr = '\0';//最后填上字符串的标志结束符'\0'
    return copy;//返回字符串首元素指针
 }


/**
* 功能：判断一个字符串，在左移[0，它自身长度]个单位之后，是否和另外一个字符串相等
* 返回值：整形（1或0）
* 参数：要判断的2个字符串指针
*/
int judge(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    for (int i = 0; i < strlen(str1); i++) {//旋转了（只左旋）[0,strlen(str1)]个下，每次都是返回一个字符指针，不改变原字符串中字符的顺序。
        if (strcmp(reverseLeftString(str1, i), str2) == 0) {//如果旋转完了，2个字符串相等，那么直接return 1；
            return 1;
        }
    }
    return 0;//旋转了所有的情况，2个字符串都不相等，就return 0;
}