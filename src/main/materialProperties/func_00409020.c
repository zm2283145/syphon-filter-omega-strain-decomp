#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* MaterialProps_Init: build the material table once (a vector of materials and a name -> index
 * map) and register the default material. */

struct MVec { int a; int b; int c; unsigned char owned; };
struct MProps { void* map; MVec* vec; unsigned char inited; };
struct Material { char name[0xC]; char props[5][0x38]; };
struct It { int p; };

extern "C" {
extern char D_004BEB80[];
extern char D_004BEB98[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_00409510(MVec* v, int n);
void func_0040A9A0(void* m, void* cmp, void* alloc);
void func_0020A070(Material* m);
int* func_00209F60(Material* m);
void MaterialProp_SetDefaults(void);
void func_00267740(void);
void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
void __destroy_array(void* arr, void* dtor, int size, int count);
void String_CtorCStr_13B480(char* s, char* c);
void String_AssignString(void* d, char* s);
void String_Dtor(void* s, int flag);
void func_004094E0(It* out, void* map, Material* key);
void func_004094D0(It* out, void* map);
int func_004094B0(It* a, It* b);
unsigned char* func_004094A0(It* it);
Material* func_00409480(MVec* v, int i);
void func_004093E0(Material* d, Material* s);
int func_004093D0(MVec* v);
void MaterialVec_PushBack(MVec* v, Material* m);
Material* MaterialVec_Back(MVec* v);
void func_004092D0(void* map, Material* m, signed char* idx);
void MaterialProps_Init(MProps* s);
}

static inline void Add(MProps* s, Material* m)
{
    It it;
    It end;
    signed char idx;
    if (!s->inited) MaterialProps_Init(s);
    func_004094E0(&it, s->map, m);
    func_004094D0(&end, s->map);
    if (func_004094B0(&it, &end)) {
        func_004093E0(func_00409480(s->vec, *func_004094A0(&it)), m);
    } else if (func_004093D0(s->vec) < 0x80) {
        MaterialVec_PushBack(s->vec, m);
        idx = func_004093D0(s->vec) - 1;
        func_004092D0(s->map, MaterialVec_Back(s->vec), &idx);
    }
}

void MaterialProps_Init(MProps* s)
{
    if (s->inited) return;
    s->inited = 1;
    {
        MVec* v;
        {
            AllocGuard g;
            v = (MVec*)Mem_Alloc(0, 0x10, D_004BEB80, 0x64);
        }
        if (v) {
            func_00409510(v, 0);
            v->b = 0;
            v->c = 0;
            v->owned = 1;
        }
        s->vec = v;
    }
    {
        void* m;
        {
            AllocGuard g;
            m = Mem_Alloc(0, 0x10, D_004BEB80, 0x65);
        }
        if (m) {
            char cmp[4];   /* empty comparator / allocator temporaries */
            char alloc[4];
            func_0040A9A0(m, cmp, alloc);
        }
        s->map = m;
    }
    {
        Material mat;
        int* z;
        /* the constructor's this pointer stays in s1 (the int round trip stops MW folding it) */
        Material* pm = (Material*)(int)&mat;
        func_0020A070(pm);
        z = func_00209F60(pm);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        __construct_array(pm->props, MaterialProp_SetDefaults, func_00267740, 0x38, 5);
        {
            char t[0xC];
            String_CtorCStr_13B480(t, D_004BEB98);
            String_AssignString(pm, t);
            String_Dtor(t, 0);
        }
        Add(s, &mat);
        __destroy_array(mat.props, func_00267740, 0x38, 5);
        String_Dtor(&mat, 0);
    }
}
