
typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    char name[16];
    int f20;
    char f24;
} In_46E0F0;
typedef struct {
    char data[0x1D0];
    int f0;
    int len;
    int f8;
    int fC;
    int f10;
    char name[16];
    int f24;
    char f28;
} Pkt_46E0F0;
typedef void (*Cb_46E0F0)(int, int, int, Pkt_46E0F0*);
extern int D_00497CC0;
extern int D_00497CC4;
extern int D_005984AC;
extern char* D_005984A8;
extern Cb_46E0F0 D_005984A4;
extern int D_005984DC;
extern void* memcpy(void*, const void*, unsigned int);
extern int Net_SendLocked(int, int, int, int, int, int, void*);
int MediusUniqueCallbackFileUploadResponseHandler(int a, int b, int c, In_46E0F0* in)
{
    Pkt_46E0F0 pkt;
    int n;
    pkt.len = 0;
    pkt.f0 = in->f0;
    pkt.f8 = in->f4;
    pkt.fC = in->f8;
    pkt.f10 = in->fC;
    memcpy(pkt.name, in->name, 0x15);
    if (pkt.fC) {
        n = D_005984AC - pkt.f0;
        if (n > 0x1D0) n = 0x1D0;
        pkt.len = n;
        memcpy(pkt.data, D_005984A8 + pkt.f0, n);
    }
    if (D_00497CC0 != 1) pkt.f10 = -0x3C6;
    if (D_00497CC4 < 0) pkt.f10 = -0x3C6;
    if (D_005984A4) D_005984A4(a, b, c, &pkt);
    Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005984DC, 0x1FC, &pkt);
    return 0x28;
}



