typedef struct { unsigned char ok; int f4; int f8; int sema; } ScfSem_578;
extern int func_0010D1B0(int s);
int func_00302578(ScfSem_578 *o, unsigned char *out)
{
    unsigned char ok;
    int ret = 2;
    if (o == 0) return ret;
    ok = o->ok;
    if (ok != 1) return ret;
    if (out == 0) return ret;
    *out = 0;
    if (func_0010D1B0(o->sema) != -1) *out = ok;
    return 0;
}