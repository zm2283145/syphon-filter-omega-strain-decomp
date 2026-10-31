typedef struct { unsigned int base; unsigned int size; unsigned int cur; unsigned int cur2; } Arena;
typedef struct { char pad[0x68]; } MpegImg;

typedef struct {
    char pad0[0x114];
    unsigned int x114;
    unsigned int x118;
    unsigned int x11C;
    Arena arena;
    char pad1[0x13C - 0x130];
    int x13C;
    int x140;
    int x144;
    int x148;
    char pad2[0x154 - 0x14C];
    int x154;
    int x158;
    int x15C;
    char pad3[0x18C - 0x160];
    int x18C;
    int x190;
    int x194;
    char pad4[0x1A0 - 0x198];
    int x1A0;
    char pad5[0x200 - 0x1A4];
    MpegImg img[9];
    char pad6[0x860 - 0x5A8];
    int x860;
} MpegC030;

typedef struct {
    int w;
    int h;
    char pad[0x38];
    MpegC030 *m;
} MpegDecC030;

extern void _alalcFree(Arena *a);
extern unsigned int _alalcAlloc(void *ctx, Arena *a, unsigned int size, unsigned int align);
extern int _RefImageInit(MpegImg *p, int x, int y);
extern void _initRefImages(MpegImg *, MpegImg *, MpegImg *, MpegImg *, MpegImg *, MpegImg *,
                          MpegImg *, MpegImg *, MpegImg *, unsigned int, unsigned int, unsigned int,
                          int, int);


void _initSeq(MpegDecC030 *d)
{
    MpegC030 *m = d->m;
    int w, h, mbh;
    unsigned int size;
    MpegImg *p3, *p4, *p5, *p6, *p7, *p8;
    MpegImg *t;
    int q;

    if (!m->x860) {
        m->x18C = 3;
        m->x154 = 1;
        m->x158 = 1;
        m->x1A0 = 1;
        m->x194 = 1;
        m->x15C = 5;
    }
    m->x144 = (m->x13C + 15) >> 4;
    if (m->x860 && !m->x154)
        mbh = ((m->x140 + 31) >> 5) * 2;
    else
        mbh = (m->x140 + 15) >> 4;
    m->x148 = mbh;
    h = mbh * 16;
    w = m->x144 * 16;
    if (w != d->w || h != d->h) {
    /* uninitialized q: combine leaves a (use q) at this label; q is spilled, so it reads a stack slot and orders sched2 */
    h = (h + q) - q;
    t = &m->img[8];
    d->w = w;
    d->h = h;
    size = (unsigned int)((w * 0x180) * h) >> 8;
    p8 = t;
    p3 = &m->img[3]; p4 = &m->img[4]; p5 = &m->img[5]; p6 = &m->img[6]; p7 = &m->img[7];
    _alalcFree(&m->arena);
    m->x114 = _alalcAlloc(m, &m->arena, size, 64);
    m->x118 = _alalcAlloc(m, &m->arena, size, 64);
    m->x11C = _alalcAlloc(m, &m->arena, size, 64);
    _initRefImages(&m->img[0], &m->img[1], &m->img[2], p3, p4, p5,
                  p6, p7, p8, m->x114, m->x118, m->x11C, w, h);
    _RefImageInit(&m->img[0], w, h);
    _RefImageInit(&m->img[1], w, h);
    _RefImageInit(&m->img[2], w, h);
    _RefImageInit(p3, w, h >> 1);
    _RefImageInit(p4, w, h >> 1);
    _RefImageInit(p5, w, h >> 1);
    _RefImageInit(p6, w, h >> 1);
    _RefImageInit(p7, w, h >> 1);
    _RefImageInit(p8, w, h >> 1);
    }
}
