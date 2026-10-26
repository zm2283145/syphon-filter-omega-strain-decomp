int InitCodec(char *o)
{
    void (*cb)(int);
    int h;
    if (o == 0 || (h = *(int *)(o + 0x3C)) == 0) return -1;
    cb = *(void (**)(int))(o + 0x20);
    if (cb) cb(h);
    *(int *)(o + 0x30) = 0;
    *(int *)(o + 0x34) = 0;
    return 0;
}