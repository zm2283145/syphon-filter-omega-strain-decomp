extern unsigned int D_0048C450;
extern int NetGetConnInfo(unsigned int, char **);
extern int NetIGetObject(char **, unsigned int);
int NetISetFieldChanged(unsigned int id, int bit)
{
    char *e = 0;
    char *p = 0;
    int *w;
    int r;
    if (id >= 0x1000) return 0x17;
    if ((unsigned int)bit >= 0x40) return 0x17;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    r = NetIGetObject(&e, id);
    if (r) return r;
    if (e == 0) return 0xA;
    if (*(int *)(e + 4) != -1 && *(int *)(e + 4) != *(int *)(p + 0x400)) return 8;
    w = (int *)(e + 0x28);
    if (bit >= 0x20) {
        w = (int *)(e + 0x24);
        bit = bit / 2;
    }
    *w |= 1 << bit;
    return 0;
}
