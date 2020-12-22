char* myStrncpy(char* Dst, const char* Src, size_t Size) {
    assert(Dst);
    assert(Src);
    size_t count = 1;
    char* head = Dst;
    while ((*head = *Src) && (count < Size)) {
        head++, Src++, count++;
    }
    return Dst;
}