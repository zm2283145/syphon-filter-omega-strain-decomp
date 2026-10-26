typedef struct { char p0[0x38]; int x38; int p3c; int x40; char p44[0xC]; int (*x50)(void *, int, int, int); char p54[0x44]; int x98, x9C, xA0, xA4, xA8, xAC; } S2D8708;
extern int GetCurrentTimeMs(void);
extern int D_0048C438;
/* same-unit callee body (weak, discarded at link; the real one is src/lib/StartTime.c): restores retail delay-slot choice */
void __attribute__((weak, section(".dtors_drop"))) StartTime(void) { D_0048C438 = GetCurrentTimeMs(); }
extern int jpeg_encode(int, int, int, int, int, int);
extern int MeasureTime(void);
int gVideoIn(S2D8708 *s, int b)
{
    int r = 0;
    if (s->x50) {
        if (s->x50(s, s->xA4, s->xA8, s->xAC) > 0) {
            if (s->x98 > 0) {
            StartTime();
            r = jpeg_encode(s->x9C, s->xA0, s->xA4, s->xA8, s->xAC, b);
            s->x40 += MeasureTime();
            s->x38++;
            }
        }
    }
    return r;
}
