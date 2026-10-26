typedef struct { char p0[4]; int x4; int x8; char p1[0xC4 - 0xC]; int xC4; char p2[0x130 - 0xC8]; int x130; } SBB28;
typedef struct { char p0[8]; int x8; char p1[0x40 - 0xC]; SBB28 *x40; } ABB28;
extern void _lastFrame(SBB28 *);
int _sceMpegFlush(ABB28 *a)
{
    SBB28 *s = a->x40;
    int r = 0;
    if (s->x4 != 0 && s->x8 != 0) {
        _lastFrame(s);
        r = 1;
        a->x8 = s->x130 - s->xC4;
        s->x4 = 0;
    }
    return r;
}