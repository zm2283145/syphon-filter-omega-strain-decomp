extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, void **);
int func_002DD280(void)
{
    void *p;
    unsigned int slot = D_0048C450;
    if (slot < 4) {
        p = 0;
        if (func_002E51B8(slot, &p) == 0 && p != 0) return *(int *)((char *)p + 0x43C);
    }
    return -1;
}
