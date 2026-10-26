#pragma opt_propagation off
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0x2C - 0x24];
    int psm;
    char pad30[0xD0 - 0x30];
    unsigned char ready;
    char padD1[0x12C - 0xD1];
    unsigned int tbp[5];
    int cur;
} R1E0;
extern char D_00537F80[];
extern u64_t* DmaPacket_Reserve(void* q, int a, int b, int c, int d, int e);

void XLib_ClearZBuffer(R1E0* o)
{
    unsigned int tbp = o->tbp[o->cur];
    GsQ* q = (GsQ*)DmaPacket_Reserve(D_00537F80, 1, 1, 8, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x50000008 << 32);
    q->hi = 0x8007ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = (u64_t)tbp | ((u64_t)(o->w >> 6) << 16) | ((u64_t)o->psm << 24); q++; q->lo = 0x4C;
    q->hi = 0x32001; q++; q->lo = 0x47;
    q->hi = 6; q++; q->lo = 0;
    q->hi = 0; q++; q->lo = 1;
    q->hi = ((0x800 - (o->w >> 1)) << 4) | ((u64_t)((0x800 - (o->h >> 1)) << 4) << 16); q++; q->lo = 5;
    q->hi = (((o->w >> 1) + 0x800) << 4) | ((u64_t)(((o->h >> 1) + 0x800) << 4) << 16); q++; q->lo = 5;
    o->ready = 1;
}
