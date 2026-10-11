extern void func_00102EB8(void *);
extern int func_00103330(void *);
int func_001036B0(char *db, int field)
{
    int odd = field & 1;
    int r;
    func_00102EB8(db + odd * 0x28);
    if (odd) r = func_00103330(db + 0x140);
    else r = func_00103330(db + 0x50);
    return r;
}
