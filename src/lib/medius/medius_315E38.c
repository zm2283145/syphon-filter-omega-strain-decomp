typedef struct { int x; int y; char pad[0x1F8]; } G4Ent;
typedef struct { int a, b, c; G4Ent e[64]; } G4Tbl;
extern void rt_memory_allocate_init_zero(void* out, int size);
G4Tbl* CreateVSequence(void)
{
    G4Tbl* p = 0;
    unsigned int i;
    rt_memory_allocate_init_zero(&p, 0x800C);
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