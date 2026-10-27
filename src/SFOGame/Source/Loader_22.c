/*
 * SFOGame/Source/Loader: 4 files, 001C3C30-001C3E90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C3C30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* v.back(): address of the last element. */
int* std_vector_charPtr_back(PtrVec* v) {
    return v->data + v->count - 1;
}
static inline void merge_flush_func_001C3C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3C30 */

/* merge_units: begin func_001C3C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* load a file member into a fresh buffer and hand it to the owner's buffer list (creating the list on first use) */
struct Buf_3C50 { char* p; };
typedef struct { int a; char name[1]; } File_3C50;
struct List_3C50 { char pad[0xC]; unsigned char owned; };
typedef struct { char pad[0x10]; List_3C50* list; } Self_3C50;
extern "C" {
int cFileMan_Open(File_3C50* f);
int cFileMan_GetSize(File_3C50* f);
int cFileMan_Read_charPP_int(File_3C50* f, char** buf, int size);
void cFileMan_Close(File_3C50* f);
void* cMemMan_Allocate(int a, int size, char* file, int line);
void std_vector_charPtr_ctor_void(List_3C50* l);
void std_vector_charPtr_push_back_charPR(List_3C50* list, Buf_3C50* buf);
extern char D_0049EE88;
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f);
}
static inline void MemCopy_3C50(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f)
{
    Buf_3C50 buf;
    Buf_3C50 tmp;
    int size;
    int r;
    r = cFileMan_Open(f);
    if (!(r & 0xFF)) {
        size = cFileMan_GetSize(f);
        { char* p; { AllocGuard g; p = (char*)cMemMan_Allocate(0, size, &D_0049EE88, 0xDB); } buf.p = p; }
        if (buf.p) {
            tmp = buf;
            r = cFileMan_Read_charPP_int(f, &tmp.p, size);
            cFileMan_Close(f);
            if (!(r & 0xFF)) {
                { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_3C50(dst, src, size); }
                if (!self->list) {
                    List_3C50* l;
                    { AllocGuard g; l = (List_3C50*)cMemMan_Allocate(0, 0x10, &D_0049EE88, 0xF1); }
                    if (l) { std_vector_charPtr_ctor_void(l); l->owned = 1; }
                    self->list = l;
                }
                std_vector_charPtr_push_back_charPR(self->list, &buf);
            }
        }
    }
    if (r & 0xFF) buf.p = 0;
    return buf.p;
}
static inline void merge_flush_func_001C3C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3C50 */

/* merge_units: begin func_001C3E90 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_1C3E90;
typedef struct { char pad[0x24]; int tree; } Map_1C3E90;
typedef struct { char pad[0xC]; Map_1C3E90* second; } Val_1C3E90;
typedef struct { char pad[0xC]; Val_1C3E90 v; } Node_1C3E90;
typedef struct { Node_1C3E90* n; } It_1C3E90;
extern char D_004FFBC0[];
extern void std_tree_pair_cString_value_compare_begin(It_1C3E90* out, void* tree);
extern void std_tree_pair_cString_value_compare_end(It_1C3E90* out, int tree);
extern void std_red_black_tree_1_increment(It_1C3E90* it);
extern void cAssocArray_cString16N_3_int_Find(It_1C3E90* out, int* tree, Key_1C3E90* key);
extern void cAssocArray_cString16N_3_int_End(It_1C3E90* out, int* tree);
extern int cAssocArray_cString16N_3_int_ConstIterator_opNe(It_1C3E90* a, It_1C3E90* b);
static inline unsigned char EqB_1C3E90(void* a, void* b) { return a == b; }
static inline int Eq_1C3E90(void* a, void* b) { return a == b; }
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
unsigned char SkaRegistry_AllModelsHaveKey(void* mgr, char* name)
{
    It_1C3E90 it;
    It_1C3E90 end;
    It_1C3E90 b;
    It_1C3E90 e;
    It_1C3E90 f;
    It_1C3E90 g;
    Key_1C3E90 key;
    unsigned char ok = 1;
    std_tree_pair_cString_value_compare_begin(&b, D_004FFBC0);
    it.n = b.n;
    std_tree_pair_cString_value_compare_end(&e, (int)D_004FFBC0);
    end.n = e.n;
    while ((Eq_1C3E90(it.n, end.n) != 0) ^ 1) {
        Val_1C3E90* v = &it.n->v;
        Map_1C3E90** pm = &v->second;
        Map_1C3E90* m;
        CANONICAL_KEY_INIT_IX(key.c, name)
        m = *pm;
        cAssocArray_cString16N_3_int_Find(&f, &m->tree, &key);
        cAssocArray_cString16N_3_int_End(&g, &m->tree);
        if (!cAssocArray_cString16N_3_int_ConstIterator_opNe(&f, &g)) { ok = 0; break; }
        std_red_black_tree_1_increment(&it);
    }
    return ok;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C3E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C3E90 */

/* merge_units: begin func_001C4000 */
#pragma push /* merge_units */
typedef struct { int* p; } It_1C4000;
typedef struct { int cap; int count; int* data; } Vec_1C4000;
typedef struct { char pad[0xC]; Vec_1C4000* vec; } Obj_1C4000;
#if 0 /* merge_units */
extern char D_0049EE88[];
#endif /* merge_units */
#define D_0049EE88 ((char*)&D_0049EE88) /* merge_units */

extern int* std_vector_imp_cTerrainPtr_1_begin(Vec_1C4000* v);
extern int* std_vector_imp_cTerrainPtr_1_end(Vec_1C4000* v);
extern void std_vector_cTerrainPtr_pointer2iterator(It_1C4000* out, Vec_1C4000* v, int** src);
extern void cTerrain_FinalizeActivation(int id);
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int f);
extern void cArray_cTerrainPtr_dtor(Vec_1C4000* v, int f);
void cLoader_FinalizeActivation(Obj_1C4000* o)
{
    It_1C4000 it;
    It_1C4000 end;
    int* tb;
    int* te;
    int g[1];
    Vec_1C4000* v;
    int* p;
    int* e;
    v = o->vec;
    tb = std_vector_imp_cTerrainPtr_1_begin(v);
    std_vector_cTerrainPtr_pointer2iterator(&it, v, &tb);
    v = o->vec;
    p = it.p;
    te = std_vector_imp_cTerrainPtr_1_end(v);
    std_vector_cTerrainPtr_pointer2iterator(&end, v, &te);
    e = end.p;
    if ((p == *(int* volatile*)&end.p) ^ 1) {
        do {
            cTerrain_FinalizeActivation(*p++);
        } while ((p == e) ^ 1);
    }
    v = o->vec;
    cTimerDisable_ctor(g);
    cArray_cTerrainPtr_dtor(v, -1);
    cMemMan_Deallocate(0, v, D_0049EE88, 0xAC);
    cTimerDisable_dtor(g, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4000(void) {}
#undef D_0049EE88 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4000 */
