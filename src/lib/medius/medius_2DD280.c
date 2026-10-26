extern unsigned int D_0048C450;
extern int NetGetConnInfo(unsigned int, void **);
int NetGetMyWorldID(void)
{
    void *p;
    unsigned int slot = D_0048C450;
    if (slot < 4) {
        p = 0;
        if (NetGetConnInfo(slot, &p) == 0 && p != 0) return *(int *)((char *)p + 0x43C);
    }
    return -1;
}
