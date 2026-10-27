/*
 * main/texman: 3 files, 003809B0-003809E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003809B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture header data offset helpers.
 */

#include "types.h"

int tTDXHeader_OffToMapData(TexHdr* t) {
    return t->h36 + t->h34;
}

int tTDXHeader_OffToImageData(TexHdr* t) {
    return t->h34 + (t->pal ? 0x400 : 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003809B0 */

/* merge_units: begin func_003809E0 */
#pragma push /* merge_units */
/* Relocate the texture's image data and build its GS registers. */
typedef struct { int data; int pad; int altData; } Tex_3809E0;
extern void* g_TextureMgr;
extern int cTexMan_PatchupTDX_charP_intR(void* tdx, int data, int* extra);
extern void cTexture_Init_charP_tTDXHeaderP_uint(void* out, void* out2, int data, int extra);

void StreamedTextureCallback(Tex_3809E0* t, void* out)
{
    int extra = 0;
    int d = t->altData ? t->altData : t->data;
    {
        int r = cTexMan_PatchupTDX_charP_intR(g_TextureMgr, d, &extra);
        cTexture_Init_charP_tTDXHeaderP_uint(out, out, r, extra);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003809E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003809E0 */

/* merge_units: begin func_00380A40 */
#pragma push /* merge_units */
typedef struct A40Node {
    struct A40Node* prev;
    struct A40Node* next;
    int value;
} A40Node;

typedef struct A40It {
    A40Node* node;
} A40It;

typedef struct A40Tex {
    char pad00[0x64];
    int refCount;
} A40Tex;

typedef struct A40Mgr {
    char pad00[0x8];
    A40Tex** tex;
    int pad0C;
    int count;
    char pad14[0x428 - 0x14];
    char list[0xC];
} A40Mgr;

typedef struct A40File {
    int flags;
    char name[1];
} A40File;

extern char D_004BC2C8[];
extern int String_CompareNoCase(const char*, const char*);
extern int cTexMan_AddTextureTDX(A40Mgr* o, A40File* f, char* name);
extern int opNe_cLListIteratorR_cLListIteratorR_7(A40It* a, A40It* b);
extern void cLList_int_End(A40It* out, void* list);
extern void cLListIterator_int_opInc(A40It* out, A40It* it, int n);
extern void cLList_int_Erase(A40It* out, void* list, A40It* it);
extern int* func_00380D20(A40It* it);
extern void func_00380D30(A40It* out, void* list);

int cTexMan_AddTextureFromFile_cFileManR(A40Mgr* o, A40File* f) {
    char* s;
    char* end;
    char* p;
    char* q;
    int idx;
    int i;
    char buf[0x50];
    A40It it;
    A40It r;
    A40It t;
    A40It e;

    s = f->name;
    if (String_CompareNoCase(s + strlen(s) - 3, D_004BC2C8) == 0) {
    end = s + strlen(s);
    for (p = end; *p != '\\' && p != s; p--) {
    }
    if (*p == '\\')
        s = p + 1;
    q = buf;
    while (s != end && *s != '.') {
        *q++ = *s++;
    }
    *q = 0;
    idx = -1;
    for (i = 0; i < o->count; i++) {
        if (o->tex[i] && String_CompareNoCase(buf, (char*)o->tex[i]) == 0)
            break;
    }
    if (i < o->count)
        idx = i;
    if (idx >= 0) {
        if (o->tex[idx]->refCount == 0) {
            func_00380D30(&it, o->list);
            for (cLList_int_End(&e, o->list); opNe_cLListIteratorR_cLListIteratorR_7(&it, &e); cLList_int_End(&e, o->list)) {
                if (idx == *func_00380D20(&it)) {
                    cLList_int_Erase(&r, o->list, &it);
                    break;
                }
                cLListIterator_int_opInc(&t, &it, 0);
            }
        }
        o->tex[idx]->refCount++;
        return idx;
    }
    return cTexMan_AddTextureTDX(o, f, buf);
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00380A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00380A40 */
