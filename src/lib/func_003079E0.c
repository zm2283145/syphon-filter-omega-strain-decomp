typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
int func_003079E0(ScfTbl *t, unsigned int idx, int val)
{
    int ret = 2;
    if (t == 0) return ret;
    if (idx >= t->count) return 3;
    t->ent[idx].f8C = val;
    return 0;
}