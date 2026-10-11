typedef struct { int sec; int usec; } ScfTime;
extern int func_003060C0(ScfTime *tv);
extern int func_003060F0(ScfTime *tv, unsigned int *elapsed);
int func_003061F8(unsigned int ms)
{
    ScfTime tv;
    unsigned int el = 0;
    int r;
    r = func_003060C0(&tv);
    if (r != 0) return r;
    while (el < ms) {
        r = func_003060F0(&tv, &el);
        if (r != 0) return r;
    }
    return 0;
}