typedef struct { char pad[8]; int h; } Obj7488;
extern int func_0030EB60(int h);
extern int func_00307530(Obj7488 *o, void *a, void *b);
int func_00307488(Obj7488 *o, void *a, void *b)
{
    int r;
    if (o == 0) return 2;
    if (a == 0) return 1;
    if (b == 0) return 1;
    if (o->h != 0) {
        r = func_0030EB60(o->h);
        if (r == 0) return r;
        return func_00307530(o, a, b);
    }
    return func_00307530(o, a, b);
}
