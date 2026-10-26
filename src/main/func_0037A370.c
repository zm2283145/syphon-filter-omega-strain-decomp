#pragma opt_propagation off
#pragma cplusplus on
/* Renderer_ClearRect: queues a GS packet that clears a w x h rectangle of the
 * renderer's frame/z buffers with the given RGBA colour (z test off when
 * flag is set). Same packet builder shape as XLib_ClearZBuffer/Video_BuildFrameClearPacket. */
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x90];
    u64_t frame;
    char pad98[0xA0 - 0x98];
    u64_t zbuf;
    u64_t test;
    char padB0[0xD0 - 0xB0];
    unsigned char ready;
} R370;
extern "C" {
extern char D_00537F80[];
extern u64_t D_004BC1B0[];
extern u64_t* DmaPacket_Reserve(void* q, int a, int b, int c, int d, int e);
}

extern "C" void Renderer_ClearRect(R370* o, int w, int h, int* rgba, int flag, int idx)
{
    GsQ* q = (GsQ*)DmaPacket_Reserve(D_00537F80, 1, 1, 12, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x5000000C << 32);
    q->hi = 0x800BULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = o->frame; q++; q->lo = 0x4C;
    q->hi = o->zbuf; q++; q->lo = 0x4E;
    q->hi = o->test; q++; q->lo = 0x18;
    q->hi = ((u64_t)(unsigned int)(w - 1) << 16) | ((u64_t)(unsigned int)(h - 1) << 48); q++; q->lo = 0x40;
    q->hi = (u64_t)!(bool)flag | 0x31000; q++; q->lo = 0x47;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = 0x4E; q++; q->lo = 0;
    q->hi = (u64_t)rgba[0] | ((u64_t)rgba[1] << 8) | ((u64_t)rgba[2] << 16) | ((u64_t)rgba[3] << 24) | ((u64_t)0x3F800000 << 32); q++; q->lo = 1;
    q->hi = D_004BC1B0[idx]; q++; q->lo = 0x42;
    q->hi = (u64_t)((0x800 - ((unsigned int)w >> 1)) << 4) | ((u64_t)((0x800 - ((unsigned int)h >> 1)) << 4) << 16); q++; q->lo = 5;
    q->hi = (u64_t)((((unsigned int)w >> 1) + 0x800) << 4) | ((u64_t)((((unsigned int)h >> 1) + 0x800) << 4) << 16); q++; q->lo = 5;
    o->ready = 1;
}
