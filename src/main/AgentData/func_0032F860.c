#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_propagation off
union ScriptArg { int i; float f; void* p; };
struct Tab2F860 { int a; int count; int c; int d; };
struct Ent2F860 { unsigned char flag; char pad[19]; };
struct List2F860 { Ent2F860* p; int x; int y; int z; };
struct Agent2F860 { char pad[0xAB0]; List2F860 lists[4]; };
extern "C" {
extern Tab2F860 D_00532A70[];
}

static inline unsigned char All2F860(Agent2F860* a, unsigned char kind)
{
    int i = 0;
    Tab2F860* t = &D_00532A70[kind];
    int n = t->count;
    if (0 < n) {
        List2F860* l = &a->lists[kind];
        Ent2F860* p = l->p;
        do {
            if (!p[i].flag) return 0;
            i++;
        } while (i < n);
    }
    return 1;
}

extern "C" int Script_cAgentData_HasAllSpecialRatings(ScriptArg* args)
{
    Agent2F860* a = (Agent2F860*)args[0].p;
    int t = 0;
    return All2F860(a, t);
}
