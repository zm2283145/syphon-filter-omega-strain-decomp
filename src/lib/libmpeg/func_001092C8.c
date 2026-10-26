typedef struct { char pad[0x10]; int x10; int x14; long x18; long x20; } Ctx92C8;
typedef struct { char pad[0x98]; int x98; int x9C; unsigned long xA0; char p1[0x20]; int xC8; int xCC; int xD0; int xD4; int xD8; int xDC; int xE0; int xE4; int xE8; char p2[0x784]; Ctx92C8 *x870; } Mpeg92C8;
typedef struct { char pad[0x28]; int x28; char p1[0x18]; int x44; int x48; int x4C; int x50; int x54; int x58; int x5C; int x60; } Pic92C8;
static const unsigned int dat_00485F70[16] = { 0x2, 0x0, 0x2, 0x0, 0x2, 0x3, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0, 0x2, 0x4, 0x0, 0x6 };
extern void _getPtsDtsFlags(Mpeg92C8 *, Pic92C8 *, void *, void *, void *);
extern int _isOutSizeOK(Mpeg92C8 *, Pic92C8 *);
extern void _csc_storeRefImage(Mpeg92C8 *, Pic92C8 *);
extern void _cpr8(Mpeg92C8 *);
extern void _markOutput(Mpeg92C8 *);

void _dispRefImage(Mpeg92C8 *m, Pic92C8 *p)
{
    Ctx92C8 *c = m->x870;
    _getPtsDtsFlags(m, p, &c->x10, &c->x18, &c->x20);
    c = m->x870;
    m->x98 = c->x10;
    m->xA0 = ((unsigned int*)dat_00485F70)[(int)(c->x20 >> 5) & 0xF];
    m->xE4 = p->x5C;
    m->xE8 = p->x60;
    m->xCC = p->x44;
    m->xD0 = p->x48;
    m->xD4 = p->x4C;
    m->xD8 = p->x50;
    m->xDC = p->x54;
    m->xE0 = p->x58;
    if (!_isOutSizeOK(m, p)) return;
    if (p->x28 != 1) return;
    if (m->xC8) _csc_storeRefImage(m, p);
    else _cpr8(m);
    _markOutput(m);
}