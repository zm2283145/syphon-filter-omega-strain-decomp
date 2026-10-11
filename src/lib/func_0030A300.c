typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;

extern void func_002FA5B0(int *p);
int func_0030A300(ScfTbl *t, int unused, int idx)
{
    ScfEnt *e;
    int ret = 7;
    if (idx == -1) return ret;
    e = &t->ent[idx];
    if (e->type != 4) {
        e->type = 1;
        func_002FA5B0(&e->f1C);
        func_002FA5B0(&e->f34);
    }
    return 0;
}