typedef struct { char p0[0x14]; int x14; char p1[4]; int x1C; unsigned int x20; int x24; int x28; } R0288;
typedef struct { int x0; int x4; int x8; } S0288;
extern R0288 *func_0010FE50(int);
extern S0288 *func_001101F8(unsigned int, int);
extern int func_0010F988(unsigned int, void *, int, int, int, int);
extern void func_00117F48(int, void *, void *);
extern void func_00110248(void);
void func_00110288(R0288 *p, int b)
{
    R0288 *r = func_0010FE50(b);
    S0288 *s;
    { int t14 = p->x14; int t1C = p->x1C; r->x1C = t1C; r->x14 = t14; }
    r->x20 = 0x80000009;
    s = func_001101F8(p->x20, b);
    if (s == 0) {
        r->x24 = 0;
        r->x28 = 0;
    } else {
        r->x24 = (int)s;
        r->x28 = s->x8;
    }
    if (func_0010F988(0x80000008, r, 0x40, 0, 0, 0) == 0) func_00117F48(0x800, func_00110248, r);
}