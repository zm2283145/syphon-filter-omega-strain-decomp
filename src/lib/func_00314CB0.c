typedef struct { char pad[8]; unsigned char state; } Obj4CB0;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_002E6098(int id);
extern int func_00314F58(int id, Obj4CB0 **out);
int func_00314CB0(int id)
{
    Obj4CB0 *o;
    int ok, v;
    if (D_00491432 <= 0) return 0;
    ok = D_00491430;
    if (ok != 1) return 0;
    v = func_002E6098(id);
    if (v != ok) return 0;
    if (func_00314F58(id, &o) == 0 && o != 0) {
        if (o->state == v) return 1;
    }
    return 0;
}
