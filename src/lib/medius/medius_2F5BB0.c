volatile int D_0049089C = 0;
extern int func_002F7B48(void);
extern int func_002F67F0(void);
int func_002F5BB0(void)
{
    volatile int *p = &D_0049089C;
    int r;
    if (*p == 0) {
        r = func_002F7B48();
        if (r) return r;
        r = func_002F67F0();
        if (r) return r;
    }
    (*p)++;
    return 0;
}

