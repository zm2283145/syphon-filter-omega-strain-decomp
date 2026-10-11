typedef struct { unsigned char ok; int f4; int f8; } ScfSem_1D0;
extern int func_003024C0(ScfSem_1D0 *o);
int func_003021D0(ScfSem_1D0 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    o->ok = 0;
    o->f4 = 0;
    o->f8 = 0;
    ret = func_003024C0(o);
    if (ret != 0) return ret;
    o->ok = 1;
    return ret;
}