typedef struct { unsigned char c, d; char data[0x1FE]; } P2DE100;
extern int D_0048C4B0;
extern unsigned short D_0058C0B0;
extern P2DE100 D_0051F2D8;
extern int Net_TranslateSendFlags(signed char, unsigned char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002E51B8(unsigned int, char **);
extern int func_002E54A0(unsigned int);
extern int func_00303930(int, int, unsigned short, P2DE100 *, unsigned short);
extern int RtUdp_SendToPeers(int, int, unsigned char, P2DE100 *, unsigned short);

int Net_SendPrefixedA(signed char type, unsigned int idx, int port, unsigned int c, unsigned int d, int len, void *data)
{
    char *p = 0;
    unsigned char flags = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    r = Net_TranslateSendFlags(type, &flags);
    if (r) return r;
    D_0051F2D8.c = c;
    D_0051F2D8.d = d;
    memcpy(D_0051F2D8.data, data, len);
    if (port == 0xFFFF) {
        if (func_00303930(D_0048C4B0, func_002E54A0(idx), D_0058C0B0, &D_0051F2D8, len + 2)) return 0x25;
    } else {
        r = func_002E51B8(idx, &p);
        if (r) return r;
        if (p == 0) return r;
        if (port != *(int *)(p + 0x400)) {
            if (RtUdp_SendToPeers(D_0048C4B0, port, flags, &D_0051F2D8, len + 2)) return 0x25;
        }
    }
    return r;
}


