typedef struct { int a, b, c; } Str_328140;
typedef struct { Str_328140 name; int val; Str_328140 desc; unsigned char flag; char pad[0x2C - 0x1D]; } E_328140;
typedef struct { char p0[0xC]; char list[4]; int count; E_328140* data; char p18[8]; } G_328140;
typedef struct {
    char pad[0x4C];
    int count;
    G_328140* data;
} O_328140;
extern char D_004B8790[];
void func_00298690(void* s);
void String_CtorCStr_13B480(Str_328140* s, char* c);
void func_0013D680(Str_328140* d, Str_328140* s);
void func_00138B70(void* s, int f);
void func_003292C0(void* v, E_328140* pos, int n, E_328140* e);

static inline void CtorE_328140(E_328140* e)
{
    func_00298690(&e->name);
    func_00298690(&e->desc);
}
static inline void DtorS_328140(Str_328140* s)
{
    if (s) func_00138B70(s, 0);
}
static inline G_328140* At_328140(O_328140* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->data[i];
}

int func_00328140(O_328140* o, int idx, char* name, int val, char* desc)
{
    G_328140* g = At_328140(o, idx);
    if (g == 0) return -1;
    {
        E_328140 e;
        Str_328140 ta;
        Str_328140 tb;
        int r;
        CtorE_328140(&e);
        String_CtorCStr_13B480(&ta, name);
        func_0013D680(&e.name, &ta);
        func_00138B70(&ta, 0);
        e.val = val;
        { Str_328140* p = &tb; String_CtorCStr_13B480(p, desc ? desc : D_004B8790); }
        func_0013D680(&e.desc, &tb);
        func_00138B70(&tb, 0);
        e.flag = 0;
        func_003292C0(g->list, g->data + g->count, 1, &e);
        r = g->count - 1;
        DtorS_328140(&e.desc);
        func_00138B70(&e, 0);
        return r;
    }
}

