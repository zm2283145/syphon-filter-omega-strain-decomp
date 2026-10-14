/*
 * main/fstream: range (3 files, 003EBAD0-003EBDD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_003EBAD0 */
#pragma push /* merge_units */
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
void func_0036E220(char* f, int a);
}

static inline Sub_EBAD0* ReqSub_EBAD0(Req_EBAD0* r)
{
    return r->file ? (Sub_EBAD0*)(r->file + 0x88) : 0;
}

static inline int SubData_EBAD0(Sub_EBAD0* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int func_003EBAD0(Req_EBAD0* r, int release)
{
    Sub_EBAD0* s = ReqSub_EBAD0(r);
    if (release) {
        if (SubData_EBAD0(s)) {
            r->cb(s, r->user, 0);
            {
                int p = s->n0;
                if (p) {
                    { AllocGuard g; Mem_Free(1, (void*)p, &D_004BE010, 0x56); }
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
        func_0036E220(f, -1);
        Mem_Free(0, f, &D_004BE010, 0x134);
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
extern "C" int func_003EBDD0(Sub_EBDD0* s, int size); /* gsynth: defined below */
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
void func_0036DEF0(char* f);
int FileMan_GetSize(char* f);
#if 0 /* merge_units */
int func_003EBDD0(Sub_EBC90* s, int size);
#endif /* merge_units */
#define func_003EBDD0(a0, a1) (func_003EBDD0((Sub_EBDD0 *)(a0), (a1))) /* merge_units */

void func_0036D950(char* f, int* data, int size);
}

static inline Sub_EBC90* ReqSub_EBC90(Req_EBC90* r)
{
    return r->file ? (Sub_EBC90*)(r->file + 0x88) : 0;
}

static inline int SubData_EBC90(Sub_EBC90* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int func_003EBC90(Req_EBC90* r)
{
    Sub_EBC90* s = ReqSub_EBC90(r);
    func_0036DEF0(r->file);
    int data = 0;
    int size = FileMan_GetSize(r->file);
    if (!func_003EBDD0(s, size))
        return 0;
    r->state = 1;
    if (!s->bC) {
        data = SubData_EBC90(s);
        func_0036D950(r->file, &data, size);
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
#undef func_003EBDD0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EBC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EBC90 */

/* merge_units: begin func_003EBDD0 */
#pragma push /* merge_units */
#pragma inline_depth(16)
#pragma cplusplus on



extern "C" {
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
int func_0011A668(unsigned long p, int align);
}

static inline void* Alloc_EBDD0(unsigned int n)
{
    AllocGuard g;
    return Mem_Alloc(1, n, &D_004BE010, 0x37);
}

extern "C" int func_003EBDD0(Sub_EBDD0* s, int size)
{
    int n = size + 0x7F;
    if (s->n0) {
        s->bC = 1;
        return 1;
    }
    s->n0 = (int)Alloc_EBDD0(n);
    if (s->n0) {
        unsigned long u = (unsigned int)s->n0;
        if (func_0011A668(u, 0x40))
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
