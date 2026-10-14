/*
 * lib/medius: 2 files, 002E1A20-002E1BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E1A20 */
typedef struct { char pad[0x400]; int self; } S;
typedef struct { char pad[0x14]; int f14; int f18; int f1C; } P;
extern unsigned int D_00598418;
extern int D_0048C450;
extern char D_0048C454;
extern char D_0048C440;
extern int D_0058DF88;
extern int D_0048C478;
extern int D_0058DF8C;
extern int D_0048C47C;
extern int D_0048C488;
extern int D_0048C48C;
extern int D_0048C464;
extern int func_002E51B8(unsigned int, S **);
extern int func_002E1470(unsigned int, int);
extern unsigned char func_002E6090(unsigned int);
extern int Net_SendTyped(char, int, int, unsigned int, unsigned int, int, void *);
extern int func_002E5F68(void);
extern int func_002DF8E8(void);
extern void func_002DB388(unsigned int);
extern int func_002E52D8(unsigned int, unsigned int, P **);
extern void func_002DCA70(unsigned int, int);
extern int func_002E5550(unsigned int, int);

int func_002E1A20(unsigned int id)
{
    S *s;
    unsigned char b[1];
    P *p;
    int ret;
    int i;

    s = 0;
    p = 0;
    if (id >= 4) return 0x17;
    ret = func_002E51B8(id, &s);
    if (ret != 0) return ret;
    if (s == 0) return ret;
    func_002E1470(id, 0);
    b[0] = func_002E6090(s->self);
    Net_SendTyped(0x50, id, -1, 0, D_00598418, 1, b);
    func_002E5F68();
    func_002DF8E8();
    func_002DB388(id);
    D_0048C450 = 4;
    D_0048C454 = 0;
    D_0048C440 = 0;
    ret = func_002E52D8(id, s->self, &p);
    if (ret != 0) return ret;
    if (p == 0) return ret;
    p->f14 = 2;
    p->f18 = 0;
    p->f1C = 0;
    func_002DCA70(id, -1);
    for (i = 0; i < 4; i++) {
        if (func_002E51B8(i, &s) == 0 && s != 0) func_002E5550(i, 0x100);
    }
    D_0048C464 = 0;
    D_0058DF88 = 0;
    D_0048C478 = 0;
    D_0058DF8C = 0;
    D_0048C47C = 0;
    D_0048C488 = 0;
    D_0048C48C = 0;
    return 0;
}
/* merge_units: end func_002E1A20 */

/* merge_units: begin func_002E1BA0 */
typedef struct { int a, b, c; int used; char pad[0xC]; } SE1BA0;
extern SE1BA0 D_0058D188[];
int func_002E1BA0(void)
{
    int i;
    for (i = 0; i < 0x7F; i++)
        if (D_0058D188[i].used == 0) return i;
    return 0x7F;
}
/* merge_units: end func_002E1BA0 */
