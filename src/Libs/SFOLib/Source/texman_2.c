/*
 * Libs/SFOLib/Source/texman: 2 files, 0037FE70-0037FEA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037FE70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_8(char* self) {
    return self + 4;
}

List* std_list_deleter_tDataDelRec_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_0037FE70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037FE70 */

/* merge_units: begin func_0037FEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

typedef struct Node_37FEA0 { struct Node_37FEA0* prev; struct Node_37FEA0* next; int value; } Node_37FEA0;
typedef struct { Node_37FEA0* p; } It_37FEA0;
typedef struct { int count; Node_37FEA0* prev; Node_37FEA0* next; } List_37FEA0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    int pad0C;
    int next;
    unsigned char pad14[0x428 - 0x14];
    List_37FEA0 freeB;
    List_37FEA0 freeA;
    unsigned char data[1];
} Obj_37FEA0;

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
extern char StreamedTextureCallback[];
int cFileMan_Open(int* f);
unsigned int cFileMan_GetSize(int* f);
int cFileMan_IsClientMemAllocated(int* f);
void* cTexMan_PatchupTDX_cFileManR_intR(Obj_37FEA0* o, int* f, int* flags);
void std_list_deleter_int_erase_listdeleter(It_37FEA0* result, void* list, It_37FEA0* pos);
int cTexture_GetRefCount(void* t);
void opDelete_cTextureP_int_bool_charP_etc(void* t, int a, int b, char* file, int line);
void cTexMan_EraseDeletedTID(Obj_37FEA0* o, int v);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void* cTexture_ctor(void* t);
int GetFileStreamMan(void);
void cFileStreamMan_StreamRequest(int q, int* f, void* cb, void* t, int a, int b, int c);
void cTexture_Init_charP_tTDXHeaderP_uint(void* t, int a, void* data, int flags);
}

static inline void Erase(It_37FEA0* out, List_37FEA0* l, It_37FEA0* b) { It_37FEA0 result; It_37FEA0 value; value = *b; std_list_deleter_int_erase_listdeleter(&result, l, &value); *out = result; }

extern "C" int cTexMan_AddTextureTDX(Obj_37FEA0* o, int* file, int arg2)
{
    int flags;
    void* data;
    int idx;
    void* t;
    if ((unsigned char)cFileMan_Open(file)) {
        return -1;
    }
    if (cFileMan_GetSize(file) > 0x100040) {
        return -1;
    }
    flags = 0;
    if (cFileMan_IsClientMemAllocated(file)) {
        flags |= 0x1000;
    }
    if (!(*file & 4)) {
        data = cTexMan_PatchupTDX_cFileManR_intR(o, file, &flags);
        if (!data) {
            return -1;
        }
    }
    if (o->freeA.count) {
        It_37FEA0 r;
        It_37FEA0 pos;
        Node_37FEA0* n = o->freeA.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeA, &pos);
    } else if (o->freeB.count) {
        It_37FEA0 r;
        It_37FEA0 pos;
        Node_37FEA0* n = o->freeB.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeB, &pos);
    } else {
        idx = o->next++;
    }
    if (o->tex[idx] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
        opDelete_cTextureP_int_bool_charP_etc(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        cTexMan_EraseDeletedTID(o, idx);
    }
    {
        AllocGuard guard;
        t = cMemMan_Allocate(0, 0x70, D_004BC2B8, 0x4D8);
    }
    if (t) {
        t = cTexture_ctor(t);
    }
    o->tex[idx] = t;
    if (*file & 4) {
        data = o->data;
        cFileStreamMan_StreamRequest(GetFileStreamMan(), file, StreamedTextureCallback, o->tex[idx], 0, 1, 1);
        flags |= 0x2000;
    }
    cTexture_Init_charP_tTDXHeaderP_uint(o->tex[idx], arg2, data, flags);
    return idx;
}
static inline void merge_flush_func_0037FEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037FEA0 */
