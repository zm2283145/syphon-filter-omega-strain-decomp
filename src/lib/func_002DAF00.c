typedef enum { TyEnum_0 } TyEnum;
typedef struct { char p[0x20]; int x20; int x24; int x28; } C2DAF00;
typedef struct { char p0[0x68]; C2DAF00 *x68; char p1[0x84 - 0x6C]; int x84; int x88; int x8C; char p2[0xBC - 0x90]; TyEnum xBC; char p3[0xD4 - 0xC0]; void (*xD4)(void *, int, int); } S2DAF00;
extern void func_00307488(int, char *, int *);
extern int func_002F4DA8(char *);
void func_002DAF00(S2DAF00 *s, int flag)
{
    char buf[16];
    int v;
    if (flag == 0) {
        func_00307488(s->x8C, buf, &s->x88);
        v = func_002F4DA8(buf);
        s->x84 = v;
        s->x68->x20 = v;
        s->xBC = 2;
        s->x68->x28 = s->x88;
        if (s->xD4) s->xD4(s, s->x84, s->x88);
    } else {
        s->x88 = 0;
        s->x84 = 0;
        s->x68->x20 = 0;
        s->xBC = 2;
        s->x68->x28 = s->x88;
        if (s->xD4) s->xD4(s, s->x84, s->x88);
    }
}
