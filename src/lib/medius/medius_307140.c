typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
int rt_udp_get_buffer_size(ScfTbl *t, unsigned int idx, int which, int *out)
{
    ScfEnt *e;
    int v;
    int ret = 1;
    if (out == 0) return ret;
    *out = 0;
    ret = 2;
    if (t == 0) return ret;
    ret = 3;
    if (idx >= t->count) return ret;
    if (t->ent == 0) return ret;
    e = &t->ent[idx];
    if (e->type != 12) return ret;
    if (which == 0) { *out = e->f24; return 0; }
    if (which == 1) { *out = e->f3C; return 0; }
    return 1;
}