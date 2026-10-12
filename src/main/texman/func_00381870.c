#pragma cplusplus on
#pragma opt_rotateloops off
#pragma opt_propagation off
#include "types.h"
#include "alloc_guard.h"

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

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
void* FileMan_ReadData(int* f);
int FileMan_GetSize(int* f);
void* Mem_Alloc(int pool, int size, char* file, int line);
int TexHeader_PixelOffset(TdxHdr_381870* t);
int TexHeader_PaletteOffset(TdxHdr_381870* t);
void* Tdx_GetFrame(TdxHdr_381870* t, int n);
void Tdx_Unrelocate(void* fr, char* base, int n1, int n2, int x, int y);
void Tdx_RelocateFrames(void* fr, char* base, int n1, int n2, int x, int y);
int func_00380360(void* t);
void func_00380280(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_381870* o, int v);
void func_00380170(void* list, int* value);
void func_003BB6B0(Tex_381870* t, TdxHdr_381870* h);
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
    if (o->tex[idx] && func_00380360(o->tex[idx]) <= 0) {
        func_00380280(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        func_003801A0(o, idx);
        func_00380170(o->freeA, &idx);
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
        func_003BB6B0(t, n);
    } else {
        Release_381870(o, idx);
    }
}