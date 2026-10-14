extern unsigned int D_0048C450;
extern int func_002E51B8(unsigned int, char **);
extern int func_002DD968(char **, unsigned int);
int func_002E6708(unsigned int id, int bit)
{
    char *e = 0;
    char *p = 0;
    int *w;
    int r;
    if (id >= 0x1000) return 0x17;
    if ((unsigned int)bit >= 0x40) return 0x17;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    r = func_002DD968(&e, id);
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
