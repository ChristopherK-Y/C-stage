int my_atoi(const char* str) {
    long result = 0;//结果，使用long类型防止越界
    int sign = 1;//符号位，默认正数
    const char* ptr = str;

    while (*ptr == ' ') {//跳过空格
        ptr++;
    }

    if (*ptr == '-') {//对负数的符号位修改
        sign = -1;
        ptr++;
    }

    while (('0' <= *ptr) && (*ptr <= '9')) {//相加
        result = result * 10 + (*ptr - '0');
        ptr++;
    }
    
    result *= sign;
    return result;

}