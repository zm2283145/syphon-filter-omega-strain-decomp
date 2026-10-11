typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
extern void func_0030AB20(ScfTbl *t, ScfEnt *e);
int func_00308380(ScfTbl *t, unsigned int idx)
{
    ScfEnt *e;
    int ret = 1;
    if (t == 0) return ret;
    if (idx >= t->count) return ret;
    e = &t->ent[idx];
    if (e->type != 7) return 4;
    e->type = 4;
    func_0030AB20(t, e);
    return 0;
}