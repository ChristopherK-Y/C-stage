char* myStrstr(const char* source, const char* target) {
    const char* src = source;//指向source字符串
    const char* tar = target;//指向目标字串
    const char* temp = src;//保存当前的src指针的位置
    while (*src && *tar) {
        temp = src;
        while (*tar && *src) {
            if (*src == *tar) {//如果相等，两个指针同时后移，然后再进行比较
                src++;
                tar++;
            }
            else {//如果不相等，src指针后移，tar指针归零，退出比较循环
                src = temp + 1;
                tar = target;
                break;
            }
            if (*tar == '\0') {//如果tar++后遇到'\0'就说明匹配成功，返回之前保存的src指针，也就是temp指针
                return temp;
            }
        }
    }
    return NULL;//最后都没有返回指针的话，说明没有这个字串，所以返回NULL指针
}