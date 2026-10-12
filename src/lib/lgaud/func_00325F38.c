extern int D_0049147C;
extern char D_0052AD00[];
extern int D_0052AEB8;
extern int func_00110720(void *cd);int func_00325F38(int poll, int *result)
{
    int r;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (poll == 0) {
        while (func_00110720(D_0052AD00))
            ;
        if (result)
            *result = D_0052AEB8;
        return 0;
    }
    r = func_00110720(D_0052AD00);
    if (r == 0 && result)
        *result = D_0052AEB8;
    return r;
}