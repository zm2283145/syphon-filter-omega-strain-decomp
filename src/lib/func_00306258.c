typedef struct { int sec; int usec; } ScfTime;
extern unsigned char D_00491300;
extern ScfTime D_00529828;
extern int func_003060D8(ScfTime *tv);
int func_00306258(void)
{
    unsigned char *flag = &D_00491300;
    int ret = 1;
    if (*flag == 1) return ret;
    ret = func_003060D8(&D_00529828);
    if (ret == 0) *flag = 1;
    return ret;
}