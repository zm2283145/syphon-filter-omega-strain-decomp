extern unsigned int D_0048C450;
extern int func_002E4190(int *, unsigned int);
extern int func_002DD9F8(unsigned int, char **);
extern int func_002E51B8(unsigned int, char **);
extern int func_002F5508(char *, void *, int);
extern int func_002F56F8(char *, int);
extern void *memcpy(void *, const void *, unsigned int);
int func_002E3718(unsigned int id, void *data, int len)
{
    char *p = 0;
    char *e = 0;
    int avail = 0;
    int r;
    if (id >= 0x800) return 0x17;
    if (data == 0) return 0x17;
    if (len <= 0) return 0x17;
    r = func_002E4190(&avail, id);
    if (r) return r;
    if (avail < len) return 0x1F;
    r = func_002DD9F8(id, &e);
    if (r) return r;
    if (e == 0) return r;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    if (*(int *)(p + 0x400) != *(int *)(e + 0xC)) return 9;
    if (func_002F5508(e + 0x2C, data, len)) return 0x1F;
    func_002F56F8(e + 0x2C, 1);
    memcpy(*(void **)(e + 0x10), *(void **)(e + 0x3C), *(int *)(e + 0x34));
    return 0;
}
