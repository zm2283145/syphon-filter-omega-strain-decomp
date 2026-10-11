typedef struct { char p[0xC]; short _flags; char q[0x4A]; } F00124BC0;
typedef struct G00124BC0 { struct G00124BC0 *_next; int _niobs; F00124BC0 *_iobs; } G00124BC0;
int func_00124BC0(char *ptr, int (*function)(F00124BC0 *))
{
    F00124BC0 *fp;
    int n, ret = 0;
    G00124BC0 *g;
    for (g = (G00124BC0 *)(ptr + 0x1D8); g != 0; g = g->_next)
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
            if (fp->_flags != 0) ret |= (*function)(fp);
    return ret;
}
