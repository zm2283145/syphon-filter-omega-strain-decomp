/*
 * main/particle: range (2 files, 00397F80-00398070)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);
int strlen(const char *);

/* merge_units: begin func_00397F80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_intPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00397F80 */

/* merge_units: begin func_00398070 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004BC5D0[];
extern char D_004BC640[];
extern char D_004BC650[];
int strstr(char* s, char* t);
void Libc_Strcat(char* s, char* t);
void* opNewArray(unsigned int size, int pool, char* file, int line);
Rel* std_vector_cEffectRequestPtr_ctor(Rel* r);
void* cArray_intPtr_ctor(void* self);
int std_vector_intPtr_push_back(PtrVec* v, int* value);
int cArray_intPtr_PushBackActual(PtrVec* v, int* value);
int** std_vector_pod_int_data(void* v);
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
extern "C" int std_vector_cEffectRequestPtr_push_back(Tbl* v, Ent* const& value);

static inline void* New398(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004BC5D0, line);
}

static inline void EntInit(Ent* e, char* name, int value)
{
    cArray_intPtr_ctor(&e->v);
    e->name = (char*)opNewArray(strlen(name) + 1, 0, D_004BC650, 0x119C);
    Libc_Strcpy(e->name, name);
    cArray_intPtr_PushBackActual(&e->v, &value);
}

extern "C" void cParticleSystem_RequestEffectLoad(void* self, const char* name, int value)
{
    char buf[0x80];
    Ent* t;
    Ent* e;
    int i;
    Libc_Strcpy(buf, name);
    if (!strstr(buf, D_004BC640))
        Libc_Strcat(buf, D_004BC640);
    if (!D_0053BB58) {
        Tbl* t = (Tbl*)New398(0x10, 0x11AE);
        if (t) {
            std_vector_cEffectRequestPtr_ctor((Rel*)&t->v);
            t->flag = 1;
        }
        D_0053BB58 = t;
    }
    for (i = 0; i < D_0053BB58->v.count; i++) {
        if (!strcmp(((Ent*)D_0053BB58->v.data[i])->name, buf)) {
            std_vector_intPtr_push_back(&((Ent*)(*std_vector_pod_int_data(D_0053BB58))[i])->v, &value);
            return;
        }
    }
    e = (Ent*)New398(0x14, 0x11B7);
    if (e)
        EntInit(e, buf, value);
    t = e; std_vector_cEffectRequestPtr_push_back(D_0053BB58, t);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00398070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00398070 */
