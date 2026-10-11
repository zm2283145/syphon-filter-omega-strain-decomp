typedef struct { int f0; int f4; unsigned int f8; } ScfObj_038;
int func_00301038(ScfObj_038 *o, unsigned int v)
{
    int ret = 2;
    if (o == 0) return ret;
    if (v >= 12) return 0x17;
    o->f8 = v;
    return 0;
}