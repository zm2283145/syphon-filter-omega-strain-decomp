typedef struct { int x; int y; char pad[0x1F8]; } G4Ent;
typedef struct { int a, b, c; G4Ent e[64]; } G4Tbl;
extern void Net_AllocZeroed(void* out, int size);
G4Tbl* func_00315E38(void)
{
    G4Tbl* p = 0;
    unsigned int i;
    Net_AllocZeroed(&p, 0x800C);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        for (i = 0; i < 64; i++) {
            p->e[i].x = 0;
            p->e[i].y = 0;
        }
    }
    return p;
}