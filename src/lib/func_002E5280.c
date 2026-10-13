extern int D_0051FED8[];
extern void func_002DD328(int *);

int func_002E5280(unsigned int i)
{
    int *p;

    if (i >= 4) {
        return 0x17;
    }
    p = &D_0051FED8[i];
    if (*p != 0) {
        func_002DD328(p);
    }
    *p = 0;
    return 0;
}
