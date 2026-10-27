/*
 * Libs/SFOLib/Source/fstream: 4 files, 003EA8E0-003EAA40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EA8E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc: copy helpers and tree end() iterator.
 */

#include "types.h"

Word* cLListIterator_cFSDataPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cFSDataPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cFSDataPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003EA8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA8E0 */

/* merge_units: begin func_003EA910 */
#pragma push /* merge_units */
typedef struct { int m0; char name[0x94]; int m98; } YA910;
typedef struct { int m0; unsigned char type; char pad[3]; YA910* y; } XA910;
typedef struct NA910 { int m0; struct NA910* next; XA910* data; } NA910;
extern void std_list_deleter_voidPtr_begin_void(int* out, void* list);
#if 0 /* merge_units */
extern void std_list_cFSDataPtr_generic_iterator_ctor(NA910** out, int* in);
#endif /* merge_units */
#define std_list_cFSDataPtr_generic_iterator_ctor(a0, a1) ((void)std_list_cFSDataPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_list_cFSDataPtr_end(int* out, void* list);
#endif /* merge_units */
#define std_list_cFSDataPtr_end(a0, a1) (std_list_cFSDataPtr_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLListIterator_cFSDataPtr_ctor(NA910** out, int* in);
#endif /* merge_units */
#define cLListIterator_cFSDataPtr_ctor(a0, a1) ((void)cLListIterator_cFSDataPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

extern int String_CompareNoCase(const char* a, const char* b);
XA910* cFileStreamMan_FindStreamData(void* self, YA910* key, int type)
{
    XA910* found = 0;
    NA910* e;
    NA910* it;
    int t1;
    int t2;
    XA910* x;
    int b;
    int a;
    NA910* n;
    std_list_deleter_voidPtr_begin_void(&t1, self);
    std_list_cFSDataPtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_cFSDataPtr_end(&t2, self), cLListIterator_cFSDataPtr_ctor(&e, &t2), n != e; n = n->next) {
        YA910* y;
        x = n->data;
        y = x->y;
        a = y->m98;
        b = key->m98;
        if ((unsigned char)type == x->type
            && !String_CompareNoCase(key->name, y ? y->name : 0)
            && (!b || !a || b == a)) {
            found = x;
            break;
        }
    }
    return found;
}
#undef std_list_cFSDataPtr_generic_iterator_ctor /* merge_units */
#undef std_list_cFSDataPtr_end /* merge_units */
#undef cLListIterator_cFSDataPtr_ctor /* merge_units */
static inline void merge_flush_func_003EA910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA910 */

/* merge_units: begin func_003EAA40 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; unsigned char flag; } Obj94;

/* Returns 1 if the byte flag at +0x94 of the second argument is set. */
unsigned char cFileStreamMan_IsStreamRequestDone(void* self, Obj94* obj)
{
    unsigned char result = 0;
    if (obj->flag)
        result = 1;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EAA40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EAA40 */

/* merge_units: begin func_003EAA60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc
 */


extern int cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(int a0, int a1, int a2, int a3, int a4);

/* Forward to cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode with the two middle arguments zero. */
int cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(int a0, int a1, int a4) {
    return cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(a0, a1, 0, 0, a4);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003EAA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003EAA60 */
