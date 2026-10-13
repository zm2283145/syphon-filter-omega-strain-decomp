#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

struct Col { float r, g, b, a; Col() {} Col(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
struct Subs {
    char text[0x40];
    unsigned char mode;
    char pad41[3];
    int lang;
    char pad48[8];
    Col col;
    int f60, f64, f68;
    char pad6C[4];
};
struct VBig { char pad[0x8A74]; void* vtbl; char pad8A78[8]; };
struct IdList { char pad[0x16]; unsigned char f16; char pad17; unsigned int n; short ids[0x200]; };
struct Buf { char* buf; char* aligned; char* end; };
struct Slot { Col color; char padF0[0xF0 - 0x10]; int fF0; int fF4; float fF8; char padFC[0x104 - 0xFC]; char b104; char b105; char b106; char pad107[0x110 - 0x107]; };
struct Mtx { __int128 r[4]; };
struct Render { char pad0[0x1F0]; Slot slots[8]; char pad[0xA80 - 0x1F0 - 8 * 0x110]; Mtx mtx[0x14]; };
struct Self {
    Buf bufs[2];
    int f18, f1C, f20;
    int f24[4];
    unsigned char f34;
    char pad35[0xB];
    Col rect;
    Subs* p50;
    VBig* p54;
    char pad58[8];
    int f60[3];
    int f6C[3];
    char pad78[8];
    Col col80;
    int f90[3];
    float f9C;
    float fA0;
    int fA4;
    int fA8;
    unsigned char fAC;
    char padAD[3];
    unsigned char fB0;
    char padB1[3];
    int fB4;
};

extern "C" {
extern char D_004BEE90[];
extern char D_004BEEE8[];
extern void* D_004E08B8[];
extern int D_0055C5D0;
extern char D_005381F0[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern IdList* D_00539248;
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void FlushCache(int);
void func_0036AFC0(VBig*);
void func_0036AB80(VBig*, int*, const char*);
void func_00382910(IdList*);
void func_0037A9F0(void*);
void func_00410C20(Subs* self, void* file, int lang);
}
/* retail's hand-written memclear (addi + sq zero), inlined from a shared helper */
static inline void MemClear(void* dst, int n) {
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v0, n, 0xF
        or $a0, $a0, $v0
        nop
        bgtz $a0, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
static inline void* Alloc(unsigned int size, int line) { AllocGuard g; return Mem_Alloc(0, size, D_004BEE90, line); }

static inline Subs* NewSubs(void) {
    Subs* s = (Subs*)Alloc(sizeof(Subs), 0x74);
    if (s) {
        s->lang = 0;
        s->col.r = 1.0f; s->col.g = 1.0f; s->col.b = 1.0f; s->col.a = 0.5f;
        s->f60 = 0; s->f64 = 0; s->f68 = 0;
        MemClear(s, 0x40);
    }
    return s;
}

static inline VBig* NewVBig(void) {
    VBig* v = (VBig*)Alloc(sizeof(VBig), 0xB4);
    if (v) {
        func_0036AFC0(v);
        v->vtbl = D_004E08B8;
    }
    return v;
}

static inline void AddId(IdList* l, int id) {
    if (l->n < 0x200) {
        if (l->n == 0 || l->ids[l->n - 1] != id) {
            l->ids[l->n++] = id;
        }
    }
}

#define SlotAt(i) ((Slot*)(D_005381F0 + 0x1F0 + (i) * 0x110))
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void func_00412600(Self* self, void* file, int lang)
{
    int i;
    for (i = 0; i < 3; i++) {
        i[self->f60] = 0;
        i[self->f90] = 0;
        i[self->f6C] = 0;
    }
    self->col80 = Col(1.0f, 1.0f, 1.0f, 1.0f);
    self->f9C = 1.0e32f;
    self->fA0 = -1.0f;
    self->fA4 = 3;
    self->fA8 = 1;
    self->fAC = 0;
    { int i; for (i = 0; i < 2; i++) {
        Buf* b = &self->bufs[i];
        b->buf = (char*)Alloc(0x7280, 0x5E);
        b->aligned = (char*)(((int)b->buf + 0x7F) / 0x80 * 0x80);
        b->end = b->buf + 0x7280;
    } }
    FlushCache(0);
    { int i; for (i = 0; i < 4; i++) i[self->f24] = 0; }
    self->f18 = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f34 = 0;
    self->fB4 = 0;
    self->fB0 = 0;
    self->p50 = NewSubs();
    func_00410C20(self->p50, file, lang);
    {
        const char* name = self->p50->text;
        if (*name != 0) asm { .set reorder } /* empty scheduling barrier: keeps the retail b/nop branch shape */ else name = 0;
        if (self->p54 == 0) {
            if (name == 0) name = D_004BEEE8;
            self->p54 = NewVBig();
            func_0036AB80(self->p54, &D_0055C5D0, name);
            { IdList* l = D_00539248; l->n = 0; l->f16 = 0; }
            AddId(D_00539248, *(int*)self->p54);
            func_00382910(D_00539248);
            func_0037A9F0(&D_005381F0);
            func_0037A9F0(&D_005381F0);
        }
    }
    self->rect.r = 20.0f; self->rect.g = 20.0f; self->rect.b = 600.0f; self->rect.a = 440.0f;
    D_00538C60++;
    { Slot* s = SlotAt(D_00538C60); s->b106 = 1; }
    {
        Slot* s = SlotAt(D_00538C60);
        s->color.r = self->rect.r;
        s->color.g = self->rect.g;
        s->color.b = self->rect.b;
        s->color.a = self->rect.a;
        s->b105 = 1;
        s->b106 = 1;
    }
    {
        Slot* s = SlotAt(D_00538C60);
        s->fF0 = 0;
        s->fF8 = 1.0f;
        s->b106 = 1;
        s->b104 = 1;
    }
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
}


