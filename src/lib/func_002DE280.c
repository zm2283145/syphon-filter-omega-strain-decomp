typedef struct { unsigned char d, e; char data[0x1FE]; } P2DE280;
extern P2DE280 D_0051F4D8;
extern int func_002E51B8(unsigned int, char **);
extern void *memcpy(void *, const void *, unsigned int);
extern int Net_SendConvertRecipient(signed char, unsigned int, int, int, P2DE280 *);
int Net_SendPrefixedB(signed char a, unsigned int idx, int c, unsigned int d, unsigned int e, int len, void *data)
{
    char *p = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (d >= 6) return 0x17;
    if (e >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    r = func_002E51B8(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    if (c == *(int *)(p + 0x400)) return r;
    D_0051F4D8.d = d;
    D_0051F4D8.e = e;
    memcpy(D_0051F4D8.data, data, len);
    return Net_SendConvertRecipient(a, idx, c, len + 2, &D_0051F4D8);
}
