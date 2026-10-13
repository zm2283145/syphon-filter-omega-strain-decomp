typedef struct TexE {
    char pad0[0x58];
    unsigned long x58;
} TexE;
typedef struct TdxMgr {
    char pad0[8];
    TexE** ents;
} TdxMgr;
extern int D_005392D0;
extern int D_00539250;

void func_003820E0(TdxMgr* m, int idx)
{
    TexE* e = m->ents[idx];
    if (D_005392D0 & 4) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x120;
    } else if (D_005392D0 & 8) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x160;
    } else {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x80;
    }
    D_00539250 = idx;
}
