/*
 * Libs/SFOLib/Source/fstream: 6 files, 003EB9D0-003EBEF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EB9D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cFSDataPtr_dtor)
static inline void merge_flush_func_003EB9D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EB9D0 */

/* merge_units: begin func_003EBA50 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Singleton {
    char b[0xC];
    int unkC;
    int unk10;
    unsigned char unk14;
} Singleton;

extern signed char D_0055A850;
extern int D_0055A858;
extern Singleton D_0055A870;
extern void std_list_deleter_voidPtr_ctor_void(Singleton*);
extern void cFileStreamMan_dtor(void);
extern void __register_global_object(void*, void*, void*);

/* Returns the lazily constructed singleton at D_0055A870. */
Singleton* GetFileStreamMan(void) {
    if (D_0055A850 == 0) {
        std_list_deleter_voidPtr_ctor_void(&D_0055A870);
        D_0055A870.unkC = 0;
        D_0055A870.unk10 = 0;
        D_0055A870.unk14 = 0;
        __register_global_object(&D_0055A870, cFileStreamMan_dtor, &D_0055A858);
        D_0055A850 = 1;
    }
    return &D_0055A870;
}
static inline void merge_flush_func_003EBA50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EBA50 */

/* merge_units: begin func_003EBAD0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma inline_depth(16)
#pragma cplusplus on

struct Sub_EBAD0 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
struct Req_EBAD0 {
    int frame;
    unsigned char state;
    char pad5[3];
    char* file;
    void (*cb)(Sub_EBAD0*, int, int);
    int user;
    unsigned char owned;
};

extern "C" {
extern char D_004BE010;
void cFileMan_dtor(char* f, int a);
}

static inline Sub_EBAD0* ReqSub_EBAD0(Req_EBAD0* r)
{
    return r->file ? (Sub_EBAD0*)(r->file + 0x88) : 0;
}

static inline int SubData_EBAD0(Sub_EBAD0* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int cFSData_FreeStream(Req_EBAD0* r, int release)
{
    Sub_EBAD0* s = ReqSub_EBAD0(r);
    if (release) {
        if (SubData_EBAD0(s)) {
            r->cb(s, r->user, 0);
            {
                int p = s->n0;
                if (p) {
                    { AllocGuard g; cMemMan_Deallocate(1, (void*)p, &D_004BE010, 0x56); }
                    s->n0 = 0;
                    s->n8 = 0;
                    s->n4 = 0;
                    s->bC = 0;
                }
            }
        }
    }
    if (r->owned) {
        char* f = r->file;
        AllocGuard g;
        cFileMan_dtor(f, -1);
        cMemMan_Deallocate(0, f, &D_004BE010, 0x134);
    }
    r->cb = 0;
    r->user = 0;
    r->frame = 0;
    r->file = 0;
    r->state = 6;
    r->owned = 0;
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EBAD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EBAD0 */

/* merge_units: begin func_003EBC90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Sub_EBDD0 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
extern "C" int cFSHandle_AllocateMem(Sub_EBDD0* s, int size); /* gsynth: defined below */
#pragma pop
#pragma inline_depth(16)
#pragma cplusplus on

struct Sub_EBC90 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
struct Req_EBC90 {
    int frame;
    unsigned char state;
    char pad5[3];
    char* file;
    void (*cb)(Sub_EBC90*, int, int);
    int user;
    unsigned char owned;
};

extern "C" {
void cFileMan_Open(char* f);
int cFileMan_GetSize(char* f);
#if 0 /* merge_units */
int cFSHandle_AllocateMem(Sub_EBC90* s, int size);
#endif /* merge_units */
#define cFSHandle_AllocateMem(a0, a1) ((int)cFSHandle_AllocateMem((Sub_EBDD0 *)(a0), (a1))) /* merge_units */


void cFileMan_Stream(char* f, int* data, int size);
}

static inline Sub_EBC90* ReqSub_EBC90(Req_EBC90* r)
{
    return r->file ? (Sub_EBC90*)(r->file + 0x88) : 0;
}

static inline int SubData_EBC90(Sub_EBC90* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int cFSData_StartStream(Req_EBC90* r)
{
    Sub_EBC90* s = ReqSub_EBC90(r);
    cFileMan_Open(r->file);
    int data = 0;
    int size = cFileMan_GetSize(r->file);
    if (!cFSHandle_AllocateMem(s, size))
        return 0;
    r->state = 1;
    if (!s->bC) {
        data = SubData_EBC90(s);
        cFileMan_Stream(r->file, &data, size);
    } else {
        if (r->state == 1 || r->state == 3) {
            Sub_EBC90* t = ReqSub_EBC90(r);
            if (SubData_EBC90(t)) {
                t->bC = 1;
                r->state = 3;
                r->cb(t, r->user, 1);
            }
        }
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EBC90(void) {}
#undef cFSHandle_AllocateMem /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EBC90 */

/* merge_units: begin func_003EBDD0 */
#pragma push /* merge_units */
#pragma inline_depth(16)
#pragma cplusplus on



extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
int Libgcc_Moddi3(unsigned long p, int align);
}

static inline void* Alloc_EBDD0(unsigned int n)
{
    AllocGuard g;
    return cMemMan_Allocate(1, n, &D_004BE010, 0x37);
}

extern "C" int cFSHandle_AllocateMem(Sub_EBDD0* s, int size)
{
    int n = size + 0x7F;
    if (s->n0) {
        s->bC = 1;
        return 1;
    }
    s->n0 = (int)Alloc_EBDD0(n);
    if (s->n0) {
        unsigned long u = (unsigned int)s->n0;
        if (Libgcc_Moddi3(u, 0x40))
            s->n8 = (int)((u + 0x7F) / 0x80 * 0x80);
        else
            s->n8 = 0;
        s->n4 = n;
        s->bC = 0;
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EBDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EBDD0 */

/* merge_units: begin func_003EBEF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

/* Initializes an empty vector header (also used as a member initializer by cFileMan_ctor_void). */
L4OwnedVec* cFSHandle_ctor(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.data = 0;
    self->vec.count = 0;
    self->owned = 0;
    return self;
}
static inline void merge_flush_func_003EBEF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EBEF0 */
