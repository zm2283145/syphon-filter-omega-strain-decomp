/* cGameCamera deleting destructor, written as plain C with explicit vtable stores:
 * each inline member dtor stores the derived then base vtable, guarded by its address. */
#include "types.h"
typedef struct { void* vt; } VO;
extern char D_004DA580[], D_004DA2F0[], D_004DA3E0[], D_004DA380[], D_004DA410[], D_004DA3B0[];
extern char D_004DA440[], D_004DA350[], D_004DAD70[], D_004DA330[], D_004DAD90[], D_004DA470[];
void func_00136300(void*, int);
void func_00136350(void*, int);
void func_0017ED20(void*, int);
void func_0017EC00(void*, int);
void func_0017EC70(void*, int);
void func_001810D0(void*, int);
void cGOBJ_dtor(void*, int);
void operator_delete(void*);

static inline void BaseD(VO* o, void* vt) { if (o) o->vt = vt; }
static inline void CrvD(VO* o, void* vt, void* bvt) { if (o) { o->vt = vt; BaseD(o, bvt); } }
static inline void S1D(void* o) { if (o) func_001810D0(o, 0); }
static inline void S2D(void* o) { if (o) S1D(o); }
static inline void S3D(void* o) { if (o) S2D(o); }

void* cGameCamera_dtor(char* self, short flag)
{
    if (self) {
        ((VO*)self)->vt = D_004DA580;
        if ((VO*)(self + 0xC70)) {
            ((VO*)(self + 0xC70))->vt = D_004DA2F0;
            func_00136300(self + 0xCB0, -1);
            func_00136350(self + 0xC70, 0);
        }
        if ((VO*)(self + 0xB20)) {
            func_0017ED20(self + 0xBA0, -1);
            func_0017EC00(self + 0xB58, -1);
            func_0017EC70(self + 0xB20, -1);
        }
        CrvD((VO*)(self + 0xA90), D_004DA3E0, D_004DA380);
        CrvD((VO*)(self + 0x9D0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x910), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x850), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x780), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x6C0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x600), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x530), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x460), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x3A0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x2E0), D_004DA410, D_004DA3B0);
        CrvD((VO*)(self + 0x210), D_004DA440, D_004DA350);
        CrvD((VO*)(self + 0x170), D_004DAD70, D_004DA330);
        if ((VO*)(self + 0x70)) {
            ((VO*)(self + 0x70))->vt = D_004DAD90;
            S3D(self + 0xA0);
            BaseD((VO*)(self + 0x70), D_004DA330);
        }
        if (self) {
            ((VO*)self)->vt = D_004DA470;
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0) operator_delete(self);
    }
    return self;
}
