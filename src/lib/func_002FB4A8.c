extern int func_002FB418(void **, int, unsigned short);
extern void *memset(void *, int, unsigned int);
int func_002FB4A8(void **b, int sz, unsigned short al)
{
    int r;
    if (b != 0) {
        if (sz == 0) return 1;
        b[0] = 0;
        b[1] = 0;
        r = func_002FB418(b, sz, al);
        if (r) return r;
        if (b[1] != 0) { memset(b[1], 0, sz); return 0; }
    }
    return 1;
}
