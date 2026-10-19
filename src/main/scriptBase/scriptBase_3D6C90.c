/*
 * main/scriptBase: range (3 files, 003D6C90-003D6F40)
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
void *memcpy();
int strlen(const char *);

/* merge_units: begin func_003D6C90 */
#pragma push /* merge_units */
typedef struct { void* name; char pad0[0x3C]; int next; } PsNode;
extern int String_CompareNoCase(void* a, void* b);
extern PsNode* ScriptType_GetRecord(int idx);
int ScriptType_DerivesFromName(PsNode* n) { do { if (String_CompareNoCase(n->name, "AI") == 0) return 1; if (n->next <= -1) break; } while ((n = ScriptType_GetRecord(n->next)) != 0); return 0; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D6C90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D6C90 */

/* merge_units: begin func_003D6D00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_strength_reduction off
extern "C" {
extern char D_004BD3B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { char* name; int id; int val; } E6D00;
typedef struct { int pad0; int count; E6D00** data; } V6D00;
typedef struct { int pad0; V6D00 vec; char pad10[0x3C - 0x10]; unsigned char b3C; char pad3D[3]; int x40; unsigned char b44; char pad45[3]; int x48; } S6D00;
static inline void* SD_Alloc(int n, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, n, D_004BD3B0, line);
}
static inline char* Dup(char* s)
{
    char* p = 0;
    if (s) {
        int len = strlen(s) + 1;
        int n = (len + 31) / 32 * 32;
        p = (char*)SD_Alloc(n, 0x130);
        memcpy(p, s, n);
    }
    return p;
}
extern "C" void func_003D6D00(S6D00* self, int n, char** names, int* vals, int x40, int base)
{
    int i;
    int zero;
    self->x40 = x40;
    zero = 0;
    PtrVector_Resize(&self->vec, n, &zero);
    self->b44 = 1;
    self->b3C = 1;
    self->x48 = base + n;
    for (i = 0; i < n; i++) {
        E6D00** slot = &self->vec.data[i];
        E6D00* e = (E6D00*)SD_Alloc(0xC, 0x17F);
        if (e) {
            char* nm = *names;
            int v = *vals;
            char* d = Dup(nm);
            e->id = base + i;
            e->val = v;
            e->name = d;
        }
        *slot = e;
        vals++;
        names++;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D6D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D6D00 */

/* merge_units: begin func_003D6F40 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void operator_delete(void* p);
void* func_0013A040(void* self, short f);
void* func_003D7280(void* self, short f);
void* func_003D7190(void* self, short f);
}

struct Item { void* data; };
struct ItemVec { int a; int count; };
extern "C" Item** func_003D7370(ItemVec* v, int i);

struct Owner {
    void* data;
    ItemVec items;
    int pad[2];
    char m14[0x10];
    char m24[0x10];
};

/* Destructor: frees the owned buffer and every item (each under the allocator lock), then destroys members. */
extern "C" Owner* func_003D6F40(Owner* self, short flag)
{
    if (self) {
        void* d = self->data;
        if (g_ProfileLockEnabled)
            Alloc_Lock(9);
        g_ProfileLockDepth++;
        Mem_Free(0, d, D_004BD3B0, 0x170);
        if (g_ProfileLockEnabled)
            Alloc_Unlock(9);
        g_ProfileLockDepth--;
        for (int i = 0; i < self->items.count; i++) {
            Item* it = *func_003D7370(&self->items, i);
            AllocGuard g;
            if (it) {
                void* p = it->data;
                if (g_ProfileLockEnabled)
                    Alloc_Lock(9);
                g_ProfileLockDepth++;
                Mem_Free(0, p, D_004BD3B0, 0x15C);
                if (g_ProfileLockEnabled)
                    Alloc_Unlock(9);
                g_ProfileLockDepth--;
            }
            Mem_Free(0, it, D_004BD3B0, 0x173);
        }
        void* m;
        m = self->m24;
        if (m)
            func_0013A040(m, -1);
        m = self->m14;
        if (m)
            func_003D7280(m, -1);
        m = &self->items;
        if (m)
            func_003D7190(m, -1);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D6F40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D6F40 */
