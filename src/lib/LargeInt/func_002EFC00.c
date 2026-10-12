typedef struct { int first; char rest[124]; } BlkFC00;
static BlkFC00 D_0048C6B8 = { 0 };
void func_002EFC00(BlkFC00 *p, int v)
{
    *p = D_0048C6B8;
    p->first = v;
}
