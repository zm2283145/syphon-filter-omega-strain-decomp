extern int func_002FB2D8(int *, unsigned long);
extern int func_002FB580(int *, int, unsigned short);
int func_002FB418(int *o, unsigned int size, unsigned short align)
{
    int r;
    if (o == 0 || size == 0) return 1;
    o[0] = 0;
    o[1] = 0;
    if (align >= 2) {
        size += align - 1;
        size += align - size % align;
    }
    r = func_002FB2D8(o, size);
    if (r) return r;
    r = func_002FB580(o + 1, o[0], align);
    __asm__ __volatile__("");
    return r;
}
