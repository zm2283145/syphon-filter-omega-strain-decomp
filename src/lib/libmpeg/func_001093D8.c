typedef struct { char pad[0x10]; volatile int x10; int x14; long x18; long x20; volatile int x28; int x2C; long x30; long x38; } Ctx93D8;
typedef struct { char pad[0x98]; int x98; int x9C; volatile unsigned long xA0; char p1[0x20]; int xC8; int xCC; int xD0; int xD4; int xD8; int xDC; int xE0; int xE4; int xE8; char p2[0xA0]; int x18C; char p3[0x6E0]; Ctx93D8 *x870; } Mpeg93D8;
typedef struct { char pad[0x10]; int x10; char p0[0x14]; int x28; char p1[0x18]; int x44; int x48; int x4C; int x50; int x54; int x58; int x5C; int x60; } Pic93D8;
extern void _getPtsDtsFlags(Mpeg93D8 *, Pic93D8 *, void *, void *, void *);
extern int _isOutSizeOK(Mpeg93D8 *, Pic93D8 *);
extern void _csc_storeRefImage(Mpeg93D8 *, Pic93D8 *);
extern void _cpr8(Mpeg93D8 *, Pic93D8 *);
extern void _markOutput(Mpeg93D8 *);

void _dispRefImageField(Mpeg93D8 *m, Pic93D8 *top, Pic93D8 *bot)
{
    Pic93D8 *first, *second;
    Ctx93D8 *c,*c2,*c3;
    int flag = 0; int val,v3,v4;
    if (m->x18C == 2) {
        first = top;
        second = bot;
        flag = 0x40;
    } else {
        first = bot;
        second = top;
    }
    c = m->x870;
    _getPtsDtsFlags(m, first, &c->x10, &c->x18, &c->x20);
    c2 = m->x870;
    val=c2->x10;
    m->xA0 = 1;
    m->x98 = val;
    _getPtsDtsFlags(m, second, &c2->x28, &c2->x30, &c2->x38);
    c3 = m->x870;
    v3=c3->x28;
    m->xA0 = 1;
    m->x98 = v3;
    m->xE4 = first->x5C;
    c3->x20 |= flag;
    v4=first->x60;
    c3->x38 |= flag;
    m->xE8 = v4;
    m->xCC = first->x44;
    m->xD0 = second->x48;
    m->xD8 = first->x50;
    m->xDC = second->x54;
    if (!_isOutSizeOK(m, top)) return;
    if (top->x28 != 1) return;
    if (bot->x28 != 1) return;
    top->x10 <<= 1;
    if (m->xC8) _csc_storeRefImage(m, top);
    else _cpr8(m, top);
    top->x10 >>= 1;
    _markOutput(m);
}



