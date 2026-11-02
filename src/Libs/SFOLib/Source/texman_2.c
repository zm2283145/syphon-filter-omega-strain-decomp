/*
 * Libs/SFOLib/Source/texman: 17 files, 00380DB0-003814C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00380DB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

typedef struct Node_380DB0 { struct Node_380DB0* prev; struct Node_380DB0* next; int value; } Node_380DB0;
typedef struct { Node_380DB0* p; } It_380DB0;
typedef struct { int count; Node_380DB0* prev; Node_380DB0* next; } List_380DB0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    int pad0C;
    int next;
    unsigned char pad14[0x428 - 0x14];
    List_380DB0 freeB;
    List_380DB0 freeA;
} Obj_380DB0;

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
void std_list_deleter_int_erase_listdeleter(It_380DB0* result, void* list, It_380DB0* pos);
int cTexture_GetRefCount(void* t);
void opDelete_cTextureP_int_bool_charP_etc(void* t, int a, int b, char* file, int line);
#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_380DB0* o, int v);
#endif /* merge_units */
void cTexMan_EraseDeletedTID(void*, int); /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((void *)(a0), (a1))) /* merge_units */

void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void* cTexture_ctor(void* t);
void cTexture_Init_charP_int_int_int_etc(void* t, int a, int b, int c, int d, int e);
}

static inline void Erase(It_380DB0* out, List_380DB0* l, It_380DB0* b) { It_380DB0 result; It_380DB0 value; value = *b; std_list_deleter_int_erase_listdeleter(&result, l, &value); *out = result; }

extern "C" int cTexMan_AddTexture(Obj_380DB0* o, int a, int b, int c, int d)
{
    int idx;
    void* t;
    if (o->freeA.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeA.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeA, &pos);
    } else if (o->freeB.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeB.next;
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
        t = cMemMan_Allocate(0, 0x70, D_004BC2B8, 0x41B);
    }
    if (t) {
        t = cTexture_ctor(t);
    }
    o->tex[idx] = t;
    cTexture_Init_charP_int_int_int_etc(o->tex[idx], a, b, c, d, 0);
    return idx;
}
#undef cTexMan_EraseDeletedTID /* merge_units */
static inline void merge_flush_func_00380DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00380DB0 */

/* merge_units: begin func_00380FB0 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int refs; } RefObj;
typedef struct { char pad[8]; RefObj** items; char pad2[4]; int count; } RefTable;

/* Increments the reference count of item index; returns 1 if the item exists. */
unsigned char cTexMan_AddTextureReference(RefTable* self, int index)
{
    unsigned char ok = 0;
    RefObj* obj;
    if (index >= 0 && index < self->count && (obj = self->items[index]) != 0) {
        obj->refs++;
        ok = 1;
    }
    return ok;
}
static inline void merge_flush_func_00380FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00380FB0 */

/* merge_units: begin func_00381000 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0x10]; int count; } E2List;
extern void cFileMan_ctor_void(void*);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(void*, void*, int, int);
extern int cTexMan_AddTextureFromFile_cFileManR(E2List*, void*);
extern void cFileMan_dtor(void*, int);
int cTexMan_UseMrYuckTexture(E2List* s) {
    char buf[0xA0];
    int r;
    cFileMan_ctor_void(buf);
    cFileMan_EncodeFilename_charP_cFileIOP_bool(buf, "GAMEDATA\\COMMON\\ERROR.TDX", 0, 0);
    r = cTexMan_AddTextureFromFile_cFileManR(s, buf);
    if (r == -1) r = s->count - 1;
    cFileMan_dtor(buf, -1);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381000 */

/* merge_units: begin func_00381080 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct ListNode_381080 ListNode_381080;
typedef struct { int size; ListNode_381080* sentinelPrev; ListNode_381080* first; } List_381080;
typedef struct { char pad[0x10]; unsigned short h10; } S44_381080;
typedef struct { char pad[0x44]; S44_381080* p44; char pad2[0x60 - 0x48]; char b60; char b61; } Obj_381080;
typedef struct {
    char pad[8]; Obj_381080** arr; int total; int count;
    char pad14[0x41C - 0x14]; List_381080 l41C; List_381080 l428; List_381080 l434;
} Mgr_381080;
extern "C" {
extern char D_004BC2B8[];
void cTexture_dtor(Obj_381080* o, int flags);
void std_list_deleter_int_erase_listdeleter_listdeleter(ListNode_381080** result, List_381080* list, ListNode_381080** first, ListNode_381080** last);
}
static inline void Free_381080(Obj_381080* o)
{
    AllocGuard g;
    cTexture_dtor(o, -1);
    cMemMan_Deallocate(0, o, D_004BC2B8, 0x3D1);
}
static inline void ListClear_381080(List_381080* self)
{
    ListNode_381080* result;
    ListNode_381080* first;
    ListNode_381080* last;
    last = (ListNode_381080*)&self->sentinelPrev;
    first = self->first;
    std_list_deleter_int_erase_listdeleter_listdeleter(&result, self, &first, &last);
}
static inline void Reset_381080(Mgr_381080* m)
{
    int i;
    for (i = 0; i < m->count; i++) {
        if (m->arr[i]) {
            m->arr[i]->b60 = 0;
            if (m->arr[i]->p44->h10 > 0)
                m->arr[i]->b61 = 0;
        }
    }
}
extern "C" void cTexMan_FlushTextures(Mgr_381080* m)
{
    int i;
    Reset_381080(m);
    for (i = 0; i < m->total; i++) {
        if (m->arr[i]) {
            Free_381080(m->arr[i]);
            m->arr[i] = 0;
        }
    }
    ListClear_381080(&m->l428);
    ListClear_381080(&m->l434);
    ListClear_381080(&m->l41C);
    m->count = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381080 */

/* merge_units: begin func_00381260 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct Node_3812D0 {
    int pad0;
    int pad4;
    int value;
} Node_3812D0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int count;
    int pad42C;
    Node_3812D0* head;
    int freeA[3];
} Obj_3812D0;
extern "C" void cTexMan_FlushDeletedTextures(Obj_3812D0* o); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0x10]; unsigned short h10; } G7S44;
typedef struct { char pad[0x44]; G7S44* p44; char pad2[0x60 - 0x48]; char b60; char b61; } G7Obj;
typedef struct { char pad[8]; G7Obj** arr; int pad2; int count; } G7Mgr;
#if 0 /* merge_units */
extern void cTexMan_FlushDeletedTextures(G7Mgr* m);
#endif /* merge_units */
#define cTexMan_FlushDeletedTextures(a0) (cTexMan_FlushDeletedTextures((Obj_3812D0 *)(a0))) /* merge_units */



void cTexMan_Flush(G7Mgr* m)
{
    int i;
    for (i = 0; i < m->count; i++) {
        if (m->arr[i]) {
            m->arr[i]->b60 = 0;
            if (m->arr[i]->p44->h10 > 0) {
                m->arr[i]->b61 = 0;
            }
        }
    }
    cTexMan_FlushDeletedTextures(m);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381260(void) {}
#undef cTexMan_FlushDeletedTextures /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00381260 */

/* merge_units: begin func_003812D0 */
#pragma push /* merge_units */
#pragma cplusplus on





extern "C" {
extern char D_004BC300[];
#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_3812D0* o, int v);
#endif /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((void *)(a0), (a1))) /* merge_units */


void cLList_int_PushBackActual(void* list, int* value);
}

extern "C" void cTexMan_FlushDeletedTextures(Obj_3812D0* o)
{
    while (o->count) {
        int v = o->head->value;
        int idx = v;
        if (o->tex[v] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
            opDelete_cTextureP_int_bool_charP_etc(o->tex[idx], 0, 1, D_004BC300, 0x39E);
            o->tex[idx] = 0;
            cTexMan_EraseDeletedTID(o, idx);
            cLList_int_PushBackActual(o->freeA, &idx);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003812D0(void) {}
#undef cTexMan_EraseDeletedTID /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003812D0 */

/* merge_units: begin func_003813A0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int list428[3];
    int freeA[3];
} Obj_3813A0;

extern "C" {
#if 0 /* merge_units */
void cTexture_DecRefCount(void* t);
#endif /* merge_units */
struct TexEntry; /* merge_units */
void cTexture_DecRefCount(TexEntry* e); /* merge_units */
#define cTexture_DecRefCount(a0) (cTexture_DecRefCount((TexEntry *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_3813A0* o, int v);
#endif /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((void *)(a0), (a1))) /* merge_units */



}

extern "C" void cTexMan_RemoveTexture(Obj_3813A0* o, int idx, int keep)
{
    int i = idx;
    if (o->tex[idx]) {
        cTexture_DecRefCount(o->tex[idx]);
        if (cTexture_GetRefCount(o->tex[i]) == 0) {
            cLList_int_PushBackActual(o->list428, &i);
        }
    }
    if (keep == 0) {
        int j = idx;
        if (o->tex[idx] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
            opDelete_cTextureP_int_bool_charP_etc(o->tex[j], 0, 1, D_004BC300, 0x39E);
            o->tex[j] = 0;
            cTexMan_EraseDeletedTID(o, j);
            cLList_int_PushBackActual(o->freeA, &j);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003813A0(void) {}
#undef cTexture_DecRefCount /* merge_units */
#undef cTexMan_EraseDeletedTID /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003813A0 */

/* merge_units: begin func_003814C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture entry release.
 */

#include "texman_types.h"

void cTexture_DecRefCount(TexEntry* e) {
    e->refCount = e->refCount + -1;
}
static inline void merge_flush_func_003814C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003814C0 */

/* merge_units: begin func_003814D0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

#pragma push
#pragma cplusplus on
typedef struct {
    char pad0[0x22];
    unsigned short nframes;
    unsigned short n1;
    unsigned short n2;
    char pad28[0x38 - 0x28];
    int stride;
    int relocated;
    char data[1];
} TdxHdr_381870;
typedef struct {
    char pad0[0x44];
    TdxHdr_381870* hdr;
    int flags;
    char pad4C[0x64 - 0x4C];
    int loaded;
} Tex_381870;
typedef struct {
    unsigned char pad0[0x8];
    Tex_381870** tex;
    unsigned char pad0C[0x434 - 0xC];
    int freeA[3];
} Obj_381870;
extern "C" void cTexMan_RemoveTextureTDX(Obj_381870* o, int* file, int idx); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0x148]; struct { int pad0; int count; }* list; } F3814D0;
typedef struct { char pad[0x98]; F3814D0* f; } A3814D0;
typedef struct { char pad[8]; char** names; int pad0C; int count; } S3814D0;
typedef struct { int pad0; char path[0x9C]; } B3814D0;
extern int cHogFile_GetBlockName(void*, int);
extern void cFileMan_EncodeFilename_charP_cFileManR(void*, int, void*);
extern void cFileMan_Open(void*);
extern int String_CompareNoCase(char*, char*);
#if 0 /* merge_units */
extern void cTexMan_RemoveTextureTDX(void*, void*, int);
#endif /* merge_units */
#define cTexMan_RemoveTextureTDX(a0, a1, a2) (cTexMan_RemoveTextureTDX((Obj_381870 *)(a0), (int *)(a1), (a2))) /* merge_units */



extern char D_004BC2C8[];

void cTexMan_RemoveTextureHOG(S3814D0* self, A3814D0* arg1)
{
    B3814D0 buf;
    char name[0x50];
    F3814D0* f = arg1->f;
    int n;
    int i;
    cFileMan_ctor_void(&buf);
    n = f->list->count;
    for (i = 0; i < n; i++) {
        char* path = buf.path;
        cFileMan_EncodeFilename_charP_cFileManR(&buf, cHogFile_GetBlockName(f, i), arg1);
        cFileMan_Open(&buf);
        if (String_CompareNoCase(path + strlen(path) - 3, D_004BC2C8) == 0) {
            char* s = path;
            char* end = s + strlen(s);
            char* q = end;
            char* d;
            int idx;
            int j;
            while (*q != '\\' && q != s)
                q--;
            if (*q == '\\')
                s = q + 1;
            d = name;
            while (s != end && *s != '.')
                *d++ = *s++;
            *d = 0;
            idx = -1;
            for (j = 0; j < self->count; j++) {
                if (self->names[j] && String_CompareNoCase(name, self->names[j]) == 0)
                    break;
            }
            if (j < self->count)
                idx = j;
            if (idx != -1)
                cTexMan_RemoveTextureTDX(self, &buf, idx);
        }
    }
    cFileMan_dtor(&buf, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003814D0(void) {}
#undef cTexMan_RemoveTextureTDX /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003814D0 */

/* merge_units: begin func_003816F0 */
#pragma push /* merge_units */
typedef struct TdxMgr {
    char pad0[8];
    char** names;
    char pad0c[4];
    int count;
} TdxMgr;
typedef struct TdxEnt {
    int id;
    char name[1];
} TdxEnt;
#if 0 /* merge_units */
extern int String_CompareNoCase(const char* a, const char* b);
#endif /* merge_units */
#define String_CompareNoCase(a0, a1) (String_CompareNoCase((char *)(a0), (char *)(a1))) /* merge_units */



#if 0 /* merge_units */
extern void cTexMan_RemoveTextureTDX(TdxMgr* m, TdxEnt* e, int idx);
#endif /* merge_units */
void cTexMan_RemoveTextureTDX(Obj_381870* o, int* file, int idx); /* merge_units */
#define cTexMan_RemoveTextureTDX(a0, a1, a2) (cTexMan_RemoveTextureTDX((Obj_381870 *)(a0), (int *)(a1), (a2))) /* merge_units */




void cTexMan_RemoveTextureFromFile(TdxMgr* m, TdxEnt* e)
{
    char* s = e->name;
    char buf[80];
    char* end;
    char* p;
    char* d;
    int idx;
    if (String_CompareNoCase(s + strlen(s) - 3, D_004BC2C8) == 0) {
        end = s + strlen(s);
        p = end;
        while (*p != '\\' && p != s) p--;
        if (*p == '\\') s = p + 1;
        d = buf;
        while (s != end && *s != '.') *d++ = *s++;
        *d = 0;
        {
        int i;
        idx = -1;
        for (i = 0; i < m->count; i++) {
            if (m->names[i] && String_CompareNoCase(buf, m->names[i]) == 0) break;
        }
        if (i < m->count) idx = i;
        }
        if (idx != -1) cTexMan_RemoveTextureTDX(m, e, idx);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003816F0(void) {}
#undef String_CompareNoCase /* merge_units */
#undef cTexMan_RemoveTextureTDX /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003816F0 */

/* merge_units: begin func_00381870 */
#pragma push /* merge_units */
typedef struct { char pad[0x54]; int v; } F_00381B90;
typedef struct { F_00381B90* a[5]; F_00381B90* b[1]; int o0; int o1; } T_00381B90;
void tTDXImageFrame_UnPatchup(T_00381B90* t, int base, int n1, int n2, int x, int y); /* gsynth: defined below */
#pragma cplusplus on
#pragma opt_rotateloops off
#pragma opt_propagation off







extern "C" {
void* cFileMan_Read_void(int* f);
int cFileMan_GetSize(int* f);
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (unsigned int)(a1), (a2), (a3))) /* merge_units */

int tTDXHeader_OffToImageData(TdxHdr_381870* t);
int tTDXHeader_OffToMapData(TdxHdr_381870* t);
void* tTDXHeader_GetFrameData(TdxHdr_381870* t, int n);
#if 0 /* merge_units */
void tTDXImageFrame_UnPatchup(void* fr, char* base, int n1, int n2, int x, int y);
#endif /* merge_units */
void tTDXImageFrame_UnPatchup(T_00381B90* t, int base, int n1, int n2, int x, int y); /* merge_units */
#define tTDXImageFrame_UnPatchup(a0, a1, a2, a3, a4, a5) (tTDXImageFrame_UnPatchup((T_00381B90 *)(a0), (int)(a1), (a2), (a3), (a4), (a5))) /* merge_units */



void tTDXImageFrame_Patchup(void* fr, char* base, int n1, int n2, int x, int y);
#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_381870* o, int v);
#endif /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((void *)(a0), (a1))) /* merge_units */

void cTexture_SetReallocData(Tex_381870* t, TdxHdr_381870* h);
}

static inline void Copy_381870(void* d0, void* s0, int n0)
{
    int n = n0;
    __int128 u;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 0xF
        or t, t, u
        nop
        bgtz t, bytes
    quads:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq u, -0x10(d)
        b done
        nop
    bytes:
        lb u, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb u, -1(d)
        .set reorder
    done:
    }
}

static inline void Release_381870(Obj_381870* o, int idx)
{
    if (o->tex[idx] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
        opDelete_cTextureP_int_bool_charP_etc(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        cTexMan_EraseDeletedTID(o, idx);
        cLList_int_PushBackActual(o->freeA, &idx);
    }
}

extern "C" void cTexMan_RemoveTextureTDX(Obj_381870* o, int* file, int idx)
{
    Tex_381870* t = o->tex[idx];
    if (t->flags & 0x1000) {
        return;
    }
    if (t->loaded) {
        TdxHdr_381870* h;
        TdxHdr_381870* n;
        int size;
        TdxHdr_381870* h0 = t->hdr;
        if (cFileMan_Read_void(file) != h0) {
            return;
        }
        h = t->hdr;
        if (h->relocated) {
            char* p = h->data;
            int px = tTDXHeader_OffToImageData(h);
            int pl = tTDXHeader_OffToMapData(h);
            int i;
            for (i = 0; i < h->nframes; i++) {
                tTDXImageFrame_UnPatchup(tTDXHeader_GetFrameData(h, i), p, h->n1, h->n2, px, pl);
                p += h->stride;
            }
            h->relocated = 0;
        }
        size = cFileMan_GetSize(file);
        {
            AllocGuard guard;
            n = (TdxHdr_381870*)cMemMan_Allocate(0, size, D_004BC2B8, 0x349);
        }
        Copy_381870(n, h, cFileMan_GetSize(file));
        if (!n->relocated) {
            char* p = n->data;
            int px = tTDXHeader_OffToImageData(n);
            int pl = tTDXHeader_OffToMapData(n);
            int i;
            for (i = 0; i < n->nframes; i++) {
                tTDXImageFrame_Patchup(tTDXHeader_GetFrameData(n, i), p, n->n1, n->n2, px, pl);
                p += n->stride;
            }
            n->relocated = 1;
        }
        cTexture_SetReallocData(t, n);
    } else {
        Release_381870(o, idx);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381870(void) {}
#undef cMemMan_Allocate /* merge_units */
#undef tTDXImageFrame_UnPatchup /* merge_units */
#undef cTexMan_EraseDeletedTID /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00381870 */

/* merge_units: begin func_00381B90 */
#pragma push /* merge_units */
void tTDXImageFrame_UnPatchup(T_00381B90* t, int base, int n1, int n2, int x, int y) {
    int i, j;
    for (i = 0; i < n1; i++) {
        t->a[i]->v -= t->o0 + x;
        t->a[i] = (F_00381B90*)((char*)t->a[i] - t->o0);
    }
    t->o0 -= base;
    if (n2) {
        for (j = 0; j < n2; j++) {
            t->b[j]->v -= t->o1 + y;
            t->b[j] = (F_00381B90*)((char*)t->b[j] - t->o1);
        }
        t->o1 -= base;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381B90 */

/* merge_units: begin func_00381F30 */
#pragma push /* merge_units */
typedef struct TdxMgr_00381F30 {
    char pad0[8];
    __int128** names;
    char pad0c[4];
    int count;
} TdxMgr_00381F30;

static inline int qeq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

int FindTexture__7cTexManCF1(TdxMgr_00381F30* m, __int128 key)
{
    int i;
    int idx = -1;
    i = 0;
    if (i < m->count) do {
        if (m->names[i] && qeq(key, *m->names[i])) break;
        i++;
    } while (i < *(volatile int*)&m->count);
    if (i < m->count) idx = i;
    return idx;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381F30 */

/* merge_units: begin func_00381FB0 */
#pragma push /* merge_units */
#define R(a) (*(volatile unsigned int*)(a))
extern int D_00539328;
extern int D_00539330;
extern unsigned int D_00539340[][1024];

int cTexMan_VIF1InterruptCB(void)
{
    R(0x1000E010) = 2;
    while (R(0x1000A000) & 0x100) {
    }
    R(0x1000A020) = 0;
    R(0x1000A030) = D_00539340[D_00539330][D_00539328] & 0x0FFFFFFF;
    R(0x1000A000) = 0x105;
    asm volatile ("sync");
    D_00539328++;
    R(0x10003C10) = 8;
    asm volatile ("sync");
    asm volatile ("ei");
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381FB0 */

/* merge_units: begin func_00382060 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_00539328[];
#endif /* merge_units */
#define D_00539328 ((char*)&D_00539328) /* merge_units */



#if 0 /* merge_units */
extern char D_00539330[];
#endif /* merge_units */
#define D_00539330 ((char*)&D_00539330) /* merge_units */




void cTexMan_TermTextureStream(int a0) {
    int a1, v1;
    int cond;

    a1 = *(int*)((char*)a0 + 1156);
    cond = a1 == 0;
    if (cond) goto L003820A0;
    v1 = *(unsigned char*)((char*)a0 + 1161);
    cond = v1 != 0;
    if (cond) goto L00382088;
    a0 = *(int*)((char*)a0 + 1152);
    v1 = 0 + 1;
    cond = a0 != v1;
    if (cond) goto L00382098;
L00382088:;
    v1 = 0x13000000;
    *(int*)((char*)a1 + 8) = v1;
    goto L003820A0;
L00382098:;
    v1 = 0x13000000;
    *(int*)(char*)a1 = v1;
L003820A0:;
    *(int*)(char*)D_00539328 = 0;
    v1 = *(int*)(char*)D_00539330;
    v1 = v1 ^ 1;
    *(int*)(char*)D_00539330 = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382060(void) {}
#undef D_00539328 /* merge_units */
#undef D_00539330 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00382060 */

/* merge_units: begin func_003820C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Texture manager state reset.
 */


void cTexMan_StartFrame(TexManager* m) {
    m->unk480 = 0;
    m->unk484 = 0;
    m->unk488 = 0;
    m->unk489 = 0;
}
static inline void merge_flush_func_003820C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003820C0 */

/* merge_units: begin func_003820E0 */
#pragma push /* merge_units */
typedef struct TexE {
    char pad0[0x58];
    unsigned long x58;
} TexE;
typedef struct TdxMgr_003820E0 {
    char pad0[8];
    TexE** ents;
} TdxMgr_003820E0;
extern int g_DrawMode;
extern int D_00539250;

void cTexMan_SetActive(TdxMgr_003820E0* m, int idx)
{
    TexE* e = m->ents[idx];
    if (g_DrawMode & 4) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x120;
    } else if (g_DrawMode & 8) {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x160;
    } else {
        e->x58 &= ~0x1E0;
        e->x58 |= 0x80;
    }
    D_00539250 = idx;
}
static inline void merge_flush_func_003820E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003820E0 */
