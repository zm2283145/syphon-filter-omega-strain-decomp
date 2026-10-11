int func_002FB580(unsigned int *out, unsigned int v, unsigned short align)
{
    if (out == 0 || v == 0) return 1;
    *out = v;
    if (align >= 2) {
        unsigned int r = v % align;
        if (r) *out = v + (align - r);
    }
    return 0;
}