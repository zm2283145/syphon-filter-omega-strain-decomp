/*
 * main/scriptBase: range (4 files, 003D6580-003D68B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
int strlen(const char *);

/* merge_units: begin func_003D6580 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Vec3D6580 {
    int* data;
    int* end;
    int pad;
    int count;
    int cap;
};

struct Obj3D6580 {
    char pad[0xA4];
    Vec3D6580 v;
};

extern "C" {
extern char D_004BD428[];
extern char D_004BD418[];
void* func_00398320(unsigned int size, int pool, char* file, int line);
void func_003D6680(void* allocation, int pool, int flags, char* file, int line);
}

extern "C" void func_003D6580(Obj3D6580* o, int x)
{
    if (o->v.count + 1 > o->v.cap) {
        int* p;
        o->v.cap += 500;
        p = (int*)func_00398320(o->v.cap * 4, 0, D_004BD428, 0xCE);
        if (o->v.data) {
            memcpy(p, o->v.data, o->v.count * 4);
        }
        o->v.end = p + (o->v.end - o->v.data);
        if (o->v.data) {
            func_003D6680(o->v.data, 0, 1, D_004BD418, 0xD3);
        }
        o->v.data = p;
    }
    o->v.count++;
    *o->v.end++ = x;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D6580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D6580 */

/* merge_units: begin func_003D6680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(func_003D6680)
#pragma pop /* merge_units */
/* merge_units: end func_003D6680 */

/* merge_units: begin func_003D6730 */
#pragma push /* merge_units */
typedef struct { int val; char* name; int pad; } E6730;
typedef struct { char* name; int pad; int count; E6730* ents; } S6730;
typedef struct { char pad[0xA8]; int* cur; } W6730;
#if 0 /* merge_units */
extern void func_003D6580(W6730* w, int n);
#endif /* merge_units */
#define func_003D6580(a0, a1) (func_003D6580((void *)(a0), (a1))) /* merge_units */

extern int func_003D6570(W6730* w, int n);
extern void func_003D63C0(W6730* w, int n);
static inline void WStr6730(W6730* w, const char* s)
{
    int n = strlen(s) + 1;
    func_003D6580(w, n);
    n = func_003D6570(w, n);
    func_003D63C0(w, n);
    String_Copy(w->cur, s);
    w->cur += n;
}
static inline void WInt6730(W6730* w, int v)
{
    func_003D63C0(w, 1);
    *w->cur++ = v;
}
#pragma opt_strength_reduction off
void func_003D6730(S6730* s, W6730* w)
{
    int n;
    int i;
    WStr6730(w, s->name);
    n = s->count;
    WInt6730(w, n);
    for (i = 0; i < n; i++) {
        WStr6730(w, s->ents[i].name);
        WInt6730(w, s->ents[i].val);
    }
}
#undef func_003D6580 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D6730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D6730 */

/* merge_units: begin func_003D68B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { char* name; int pad4; int key; } Item;
typedef struct {
    char pad0[8]; int nItems; Item** items; char pad10[0x18];
    int nKeys; int* keys; char pad30[0x10]; int key40;
} Obj;
#if 0 /* merge_units */
extern void func_003D6580(Writer* w, int size);
#endif /* merge_units */
#define func_003D6580(a0, a1) (func_003D6580((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_003D6570(Writer* w, int size);
#endif /* merge_units */
#define func_003D6570(a0, a1) (func_003D6570((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003D63C0(Writer* w, int words);
#endif /* merge_units */
#define func_003D63C0(a0, a1) (func_003D63C0((void *)(a0), (a1))) /* merge_units */

extern char* func_003D7510(int key);
static inline void Writer_PutString(Writer* w, char* s)
{
    int size = strlen(s) + 1;
    int words;
    func_003D6580(w, size);
    words = func_003D6570(w, size);
    func_003D63C0(w, words);
    String_Copy((char*)w->cursor, s);
    w->cursor += words;
}
static inline void Writer_PutInt(Writer* w, int v)
{
    func_003D63C0(w, 1);
    *w->cursor++ = v;
}
#pragma opt_strength_reduction off
/* Serialises the name key, the item name/key pairs and the key list. */
void func_003D68B0(Obj* o, Writer* w)
{
    int n;
    int i;
    if (o->key40 >= 0)
        Writer_PutString(w, func_003D7510(o->key40));
    else
        Writer_PutInt(w, 0);
    n = o->nItems;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++) {
        Writer_PutString(w, o->items[i]->name);
        Writer_PutString(w, func_003D7510(o->items[i]->key));
    }
    n = o->nKeys;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        Writer_PutString(w, func_003D7510(o->keys[i]));
}
#undef func_003D6580 /* merge_units */
#undef func_003D6570 /* merge_units */
#undef func_003D63C0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003D68B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003D68B0 */
