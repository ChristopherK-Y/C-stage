//模拟实现memcpy

#include"usual.h"

void* mymemcpy(void* dst, const char* src, size_t size) {
    assert(dst);
    assert(src);
    
    void* ret = dst;
    size_t count = size;
    while (count) {
        *(char*)dst = *(char*)src;
        ((char*)dst)++;
        ((char*)src)++;
        count--;
    }
    return ret;
}

int main() {
    char src[] = "12345678910";
    char dst[20] = { 0 };
    size_t size = sizeof(src) / sizeof(src[0]);
    printf(mymemcpy(dst, src, 5));
    return 0;
}