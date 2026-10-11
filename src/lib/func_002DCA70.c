#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned char b0, b1, b2, b3; int f4; int f8; int fC; } M2DCA70;
extern int D_00598420;
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern unsigned char func_002E6090(unsigned int);
extern int func_002DCC08(int *);
extern void func_002DE880(int, unsigned int, int, int, int, M2DCA70 *);
void func_002DCA70(unsigned int slot, int who)
{
    M2DCA70 m;
    void *p = 0;
    void *q = 0;
    unsigned int id, i;
    if (slot >= 4) return;
    if (func_002E51B8(slot, &p) != 0) return;
    if (p == 0) return;
    id = F(p, unsigned int, 0x400);
    if (id >= 0x100) return;
    if (func_002E52D8(slot, id, &q) != 0) return;
    if (q == 0) return;
    m.b1 = func_002E6090(id);
    m.b0 = F(q, unsigned char, 0x14);
    m.b2 = F(q, unsigned char, 0x18);
    m.b3 = F(q, unsigned char, 0x1C);
    m.f8 = F(q, int, 0x24);
    m.fC = F(p, int, 0x448);
    if (func_002DCC08(&m.f4) != 0) return;
    if (who == -1) {
        for (i = 0; i < 0x100; i++) {
            if (func_002E52D8(slot, i, &q) != 0) return;
            if (q == 0) continue;
            if (F(q, unsigned char, 0x28) != 1) continue;
            if (i == id) continue;
            func_002DE880(0x50, slot, i, D_00598420, 0x10, &m);
        }
        return;
    }
    func_002DE880(0x50, slot, who, D_00598420, 0x10, &m);
}