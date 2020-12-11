//模拟实现memmove

#include"usual.h"
/**
* 功能：实现memmove
* 返回值：void*
* 参数：void*的目的基地址，const void*源基地址，需要复制的字节数（unsigned int）
* 
* 思路：
* ①两个内存空间没有任何一字节是重叠的，实现就是按memcpy
* ②两个内存空间有重叠
*   ①目的地址 < 源地址：复制不受影响
*   ②目的地址在源地址后方至少Size个字节处，即：Dst-Size >= Src：复制不受影响
*   ③源地址后方Size个字节中存在目的地址：复制受限
* 
*   如果复制不受限：从前往后/从后往前
*   如果复制受限：只能从后往前
*/
void* myMemmove(void* Dst, const void* Src, size_t Size) {
    void* ret = Dst;
    if (Dst <= Src || ((char*)Dst - Size) >= (char*)Src) {
        while (Size) {
            *(char*)Dst = *(char*)Src;
            ((char*)Dst)++;
            ((char*)Src)++;
            Size--;
        }
        return ret;
    }
    else {
        (char*)Dst = (char*)Dst + Size - 1;
        (char*)Src = (char*)Src + Size - 1;
        while (Size) {
            *(char*)Dst = *(char*)Src;
            ((char*)Dst)--;
            ((char*)Src)--;
            Size--;
        }
    }
    return ret;
}

int main() {
    int src[10] = { 1,2,3,4,5,6,7 };
    int dst[15] = { 0 };
    myMemmove(dst, src, sizeof(int) * 8);

    myMemmove(src + 2, src, sizeof(int) * 5);

    //myMemmove(src + 5, src, sizeof(int) * 5);

    return 0;
}