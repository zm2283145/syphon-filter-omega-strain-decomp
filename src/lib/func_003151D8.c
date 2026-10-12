typedef struct { int a; int b; } Ent51D8;
typedef struct { char pad[4]; int count; char pad2[0x204 - 8]; Ent51D8 *tbl; } Obj51D8;
extern int func_00314FE0(Obj51D8 *o);
int func_003151D8(Obj51D8 *o, int i, Ent51D8 **out)
{
    if (out == 0) return 0x17;
    if (func_00314FE0(o) != 1) return 0x17;
    if (o->tbl == 0) return 0x17;
    if (i >= o->count) return 0x17;
    *out = &o->tbl[i];
    return *out ? 0 : 0x29;
}
