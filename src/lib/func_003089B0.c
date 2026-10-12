typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
extern void *memset(void *d, int c, unsigned int n);
int func_003089B0(ScfTbl *t, int *out)
{
    unsigned int i = 0;
    if (out == 0) return 1;
    *out = -1;
    for (; i < t->count; i++) {
        if (t->ent[i].type == 0) {
            memset(&t->ent[i], 0, 0x90);
            *out = i;
            return 0;
        }
    }
    return 8;
}
