typedef struct { char p0[0x3C]; int x3C; int p40; int x44; char p48[0xC]; int (*x54)(void *, int, void *); char p58[0x44]; int x9C, xA0; char pA4[0xC]; int xB0, xB4, xB8; } S2D87B8;
typedef struct { char p0[0x34]; int x34; char p38[0x840 - 0x38]; void * x840; int x844; char p848[0x10]; int x858; char *x85C; } T2D87B8;
extern int GetCurrentTimeMs(void);
extern int D_0048C438;
/* same-unit callee bodies (weak, discarded at link; the real ones are in src/lib): restore retail scheduling */
void __attribute__((weak, section(".dtors_drop"))) StartTime(void) { D_0048C438 = GetCurrentTimeMs(); }
int __attribute__((weak, section(".dtors_drop"))) MeasureTime(void) { return GetCurrentTimeMs() - D_0048C438; }
extern int GetVSequenceData(int, char *, int);
extern void * CreateRGBArray(int, int);
extern int jpeg_decode(int, int, int, int, int, char *);
extern int YUV2RGB(int, int, int, void *);
int gVideoOut(S2D87B8 *s, T2D87B8 *t)
{
    char buf[0x7E00];
    char *data;
    register int n asm("$3");
    int h;
    n = t->x858;
    data = t->x85C;
    if (n) {
        t->x858 = 0;
    } else if ((h = t->x844) != 0) {
        data = buf;
        n = GetVSequenceData(h, buf, 0x7E00);
    }
    if (n == 0) return 0;
    if (s->x54) {
        if (t->x840 == 0) t->x840 = CreateRGBArray(s->x9C, s->xA0);
        StartTime();
        jpeg_decode(s->x9C, s->xA0, s->xB0, s->xB4, s->xB8, data);
        s->x44 += MeasureTime();
        s->x3C++;
        YUV2RGB(s->xB0, s->xB4, s->xB8, t->x840);
        s->x54(s, t->x34, t->x840);
    }
    return 0;
}