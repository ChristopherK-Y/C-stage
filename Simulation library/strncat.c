char* myStrncat(char* Dst, const char* Src, size_t Size) {
    assert(Dst);
    assert(Src);
    size_t count = 1;
    char* tail = Dst + strlen(Dst);
    while ((*tail = *Src) && (count < Size)) {
        tail++, Src++, count++;
    }
    if (count == Size - 1) {
        *tail = '\0';
    }
    return Dst;
}