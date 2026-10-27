typedef struct {
    unsigned char f00, f01; char p02[2];
    int f04;
    int f08;
    signed char f0C; char p0D[3];
    int f10, f14, f18;
    short f1C; char p1E[2];
    unsigned char f20, f21; short f22;
    char p24[4];
    unsigned char f28, f29; char p2A[2];
    int f2C;
    short f30; unsigned char f32, f33;
    char p34[4];
    float f38;
    int f3C, f40;
    char p44[0xC];
    unsigned char f50; char p51[0xB];
} NetHuman1FF0;
extern unsigned char D_005721D0;
extern unsigned char D_0051F080;
extern int D_0051F088;
extern int D_0051F078;
extern int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, NetHuman1FF0* g, char* h, int i);
extern void NetRequestObjectPrivateOwnership(int);
extern void cTargetInfo_Init(NetHuman1FF0*);
extern void cTargetInfo_dtor(NetHuman1FF0*, int);
void cNetHuman_CreateNetHuman(void* recv, int id)
{
    if (D_005721D0) {
        NetHuman1FF0 o;
        int h;
        o.f00 = 0;
        o.f01 = 0;
        o.f04 = -1;
        o.f08 = -1;
        o.f0C = -1;
        o.f10 = 0;
        o.f14 = 0;
        o.f18 = 0;
        o.f28 = 0;
        o.f30 = 4;
        o.f32 = 0;
        o.f33 = 0;
        o.f38 = 1000.0f;
        o.f3C = 0;
        o.f40 = 0;
        o.f50 = 0;
        o.f22 = 0;
        o.f21 = 0;
        o.f1C = 0;
        o.f20 = 0;
        cTargetInfo_Init(&o);
        o.f2C = id;
        o.f29 = 1;
        if (NetCreateObject(&h, 2, 4, 0, 0, 0, 0, &o, "cNetHuman", D_0051F078) == 0) {
            D_0051F080 = 1;
            NetRequestObjectPrivateOwnership(h);
            D_0051F088++;
        }
        cTargetInfo_dtor(&o, 0);
    }
}

