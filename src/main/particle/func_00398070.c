#pragma cplusplus on
#pragma opt_strength_reduction off
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004BC5D0[];
extern char D_004BC640[];
extern char D_004BC650[];
void String_Copy(char* d, const char* s);
int func_00129C80(char* s, char* t);
void func_00128F58(char* s, char* t);
int strcmp(const char*, const char*);
int strlen(const char*);
void* func_00398320(unsigned int size, int pool, char* file, int line);
Rel* func_00398450(Rel* r);
void* func_003983E0(void* self);
int func_00398430(PtrVec* v, int* value);
int func_00398300(PtrVec* v, int* value);
int** func_00171EC0(void* v);
}

struct Tbl {
    PtrVec v;
    unsigned char flag;
};
struct Ent {
    char* name;
    PtrVec v;
    unsigned char flag;
};
extern "C" Tbl* volatile D_0053BB58;
extern "C" int func_003982E0(Tbl* v, Ent* const& value);

static inline void* New398(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

static inline void EntInit(Ent* e, char* name, int value)
{
    func_003983E0(&e->v);
    e->name = (char*)func_00398320(strlen(name) + 1, 0, D_004BC650, 0x119C);
    String_Copy(e->name, name);
    func_00398300(&e->v, &value);
}

extern "C" void func_00398070(void* self, const char* name, int value)
{
    char buf[0x80];
    Ent* t;
    Ent* e;
    int i;
    String_Copy(buf, name);
    if (!func_00129C80(buf, D_004BC640))
        func_00128F58(buf, D_004BC640);
    if (!D_0053BB58) {
        Tbl* t = (Tbl*)New398(0x10, 0x11AE);
        if (t) {
            func_00398450((Rel*)&t->v);
            t->flag = 1;
        }
        D_0053BB58 = t;
    }
    for (i = 0; i < D_0053BB58->v.count; i++) {
        if (!strcmp(((Ent*)D_0053BB58->v.data[i])->name, buf)) {
            func_00398430(&((Ent*)(*func_00171EC0(D_0053BB58))[i])->v, &value);
            return;
        }
    }
    e = (Ent*)New398(0x14, 0x11B7);
    if (e)
        EntInit(e, buf, value);
    t = e; func_003982E0(D_0053BB58, t);
}




