/*
 * main/texman: range (7 files, 003814D0-00382060)
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
int strlen(const char *);

/* merge_units: begin func_003814D0 */
#pragma push /* merge_units */
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
extern "C" void Tdx_Clone(Obj_381870* o, int* file, int idx); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0x148]; struct { int pad0; int count; }* list; } F3814D0;
typedef struct { char pad[0x98]; F3814D0* f; } A3814D0;
typedef struct { char pad[8]; char** names; int pad0C; int count; } S3814D0;
typedef struct { int pad0; char path[0x9C]; } B3814D0;
extern void Resource_Construct(void*);
extern void FileMan_Release(void*, int);
extern int Archive_GetMemberName(void*, int);
extern void cFileMan_EncodeFilename_charP_cFileManR(void*, int, void*);
extern void FileMan_FindMember(void*);
extern int String_CompareNoCase(char*, char*);
#if 0 /* merge_units */
extern void Tdx_Clone(void*, void*, int);
#endif /* merge_units */
#define Tdx_Clone(a0, a1, a2) (Tdx_Clone((void *)(a0), (void *)(a1), (a2))) /* merge_units */

extern char D_004BC2C8[];

void cTexMan_RemoveTextureHOG(S3814D0* self, A3814D0* arg1)
{
    B3814D0 buf;
    char name[0x50];
    F3814D0* f = arg1->f;
    int n;
    int i;
    Resource_Construct(&buf);
    n = f->list->count;
    for (i = 0; i < n; i++) {
        char* path = buf.path;
        cFileMan_EncodeFilename_charP_cFileManR(&buf, Archive_GetMemberName(f, i), arg1);
        FileMan_FindMember(&buf);
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
                Tdx_Clone(self, &buf, idx);
        }
    }
    FileMan_Release(&buf, -1);
}
#undef Tdx_Clone /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003814D0(void) {}
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
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
#if 0 /* merge_units */
extern int String_CompareNoCase(const char* a, const char* b);
#endif /* merge_units */
#define String_CompareNoCase(a0, a1) (String_CompareNoCase((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void Tdx_Clone(TdxMgr* m, TdxEnt* e, int idx);
#endif /* merge_units */
#define Tdx_Clone(a0, a1, a2) (Tdx_Clone((void *)(a0), (void *)(a1), (a2))) /* merge_units */


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
        if (idx != -1) Tdx_Clone(m, e, idx);
    }
}
#undef strlen /* merge_units */
#undef String_CompareNoCase /* merge_units */
#undef Tdx_Clone /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003816F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003816F0 */

/* merge_units: begin func_00381870 */
#pragma push /* merge_units */
typedef struct { char pad[0x54]; int v; } F_00381B90;
typedef struct { F_00381B90* a[5]; F_00381B90* b[1]; int o0; int o1; } T_00381B90;
void Tdx_Unrelocate(T_00381B90* t, int base, int n1, int n2, int x, int y); /* gsynth: defined below */
#pragma cplusplus on
#pragma opt_rotateloops off
#pragma opt_propagation off







extern "C" {
extern char D_004BC2B8[], D_004BC300[];
void* FileMan_ReadData(int* f);
int FileMan_GetSize(int* f);
void* Mem_Alloc(int pool, int size, char* file, int line);
int TexHeader_PixelOffset(TdxHdr_381870* t);
int TexHeader_PaletteOffset(TdxHdr_381870* t);
void* Tdx_GetFrame(TdxHdr_381870* t, int n);
#if 0 /* merge_units */
void Tdx_Unrelocate(void* fr, char* base, int n1, int n2, int x, int y);
#endif /* merge_units */
#define Tdx_Unrelocate(a0, a1, a2, a3, a4, a5) (Tdx_Unrelocate((T_00381B90 *)(a0), (int)(a1), (a2), (a3), (a4), (a5))) /* merge_units */

void Tdx_RelocateFrames(void* fr, char* base, int n1, int n2, int x, int y);
int cTexture_GetRefCount(void* t);
void Tex_DestroyRecord(void* t, int a, int b, char* file, int line);
void cTexMan_EraseDeletedTID(Obj_381870* o, int v);
void cLList_int_PushBackActual(void* list, int* value);
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
        Tex_DestroyRecord(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        cTexMan_EraseDeletedTID(o, idx);
        cLList_int_PushBackActual(o->freeA, &idx);
    }
}

extern "C" void Tdx_Clone(Obj_381870* o, int* file, int idx)
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
        if (FileMan_ReadData(file) != h0) {
            return;
        }
        h = t->hdr;
        if (h->relocated) {
            char* p = h->data;
            int px = TexHeader_PixelOffset(h);
            int pl = TexHeader_PaletteOffset(h);
            int i;
            for (i = 0; i < h->nframes; i++) {
                Tdx_Unrelocate(Tdx_GetFrame(h, i), p, h->n1, h->n2, px, pl);
                p += h->stride;
            }
            h->relocated = 0;
        }
        size = FileMan_GetSize(file);
        {
            AllocGuard guard;
            n = (TdxHdr_381870*)Mem_Alloc(0, size, D_004BC2B8, 0x349);
        }
        Copy_381870(n, h, FileMan_GetSize(file));
        if (!n->relocated) {
            char* p = n->data;
            int px = TexHeader_PixelOffset(n);
            int pl = TexHeader_PaletteOffset(n);
            int i;
            for (i = 0; i < n->nframes; i++) {
                Tdx_RelocateFrames(Tdx_GetFrame(n, i), p, n->n1, n->n2, px, pl);
                p += n->stride;
            }
            n->relocated = 1;
        }
        cTexture_SetReallocData(t, n);
    } else {
        Release_381870(o, idx);
    }
}
#undef Tdx_Unrelocate /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381870 */

/* merge_units: begin func_00381B90 */
#pragma push /* merge_units */
void Tdx_Unrelocate(T_00381B90* t, int base, int n1, int n2, int x, int y) {
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

int Tex_FindInList(TdxMgr_00381F30* m, __int128 key)
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
#undef D_00539328 /* merge_units */
#undef D_00539330 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382060 */
