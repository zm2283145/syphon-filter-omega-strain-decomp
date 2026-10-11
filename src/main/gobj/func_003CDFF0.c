#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef struct { __int128 r[4]; } Mat_3CDFF0;
class Xf_3CDFF0 {
public:
    virtual void dtor(int f);
    virtual void set(Mat_3CDFF0* m);
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual int busy();
};
struct Obj_3CDFF0;
class ObjV_3CDFF0 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
    virtual void attach(Mat_3CDFF0* m, int flag);
    char pad4[0x48 - 4]; unsigned char owns; char pad49[7]; Xf_3CDFF0* xf;
};
typedef struct { void* vt; char pad4[0xC]; Mat_3CDFF0 m; unsigned char f50; } Xf2_3CDFF0;
extern "C" {
extern char D_004BD228[];
extern char D_004DF6A0[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
Xf_3CDFF0* func_0036FCF0(void* p, Mat_3CDFF0* m);
}
static inline void* Alloc_3CDFF0(unsigned int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004BD228, line); }

#pragma push
extern "C" void Object_AttachTransform(ObjV_3CDFF0* self, Mat_3CDFF0* m, int flag)
{
    if (!self->xf) {
        if (flag) {
            Xf_3CDFF0* x = (Xf_3CDFF0*)Alloc_3CDFF0(0xC0, 0x151);
            if (x) x = func_0036FCF0(x, m);
            self->xf = x;
        } else {
            Xf2_3CDFF0* y = (Xf2_3CDFF0*)Alloc_3CDFF0(0x60, 0x153);
            if (y) {
                Mat_3CDFF0* d; __int128 qa; __int128 qb; char one;
                y->vt = D_004DF6A0;
                d = &y->m;
                asm { .set reorder; lq qa, 0x0(m) }
                one = 1;
                asm { .set reorder; lq qb, 0x10(m) }
                asm { .set reorder; sq qa, 0x0(d) }
                asm { .set reorder; lq qa, 0x20(m) }
                asm { .set reorder; sq qb, 0x10(d) }
                asm { .set reorder; lq qb, 0x30(m) }
                asm { .set reorder; sq qa, 0x20(d) }
                asm { .set reorder; sq qb, 0x30(d) }
                y->f50 = one;
            }
            self->xf = (Xf_3CDFF0*)y;
        }
        self->owns = 1;
        return;
    }
    if (flag && !self->xf->busy()) {
        Xf_3CDFF0* p = self->xf;
        if (p) {
            if (self->owns) {
                { AllocGuard g; p->dtor(-1); Mem_Free(0, p, D_004BD228, 0x174); }
                self->owns = 0;
            }
            self->xf = 0;
        }
        self->attach(m, flag);
        return;
    }
    self->xf->set(m);
}
#pragma pop