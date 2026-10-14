/*
 * main/gameLight: range (3 files, 00179C20-00179D70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00179C20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E4Del { int pad; virtual ~E4Del(); };
struct E4Inner { int pad; E4Del d; };
typedef struct {
    void* vt;
    char pad[0x5C];
    E4Del* m60;
} E4Light;
extern char D_004DA1D0[];
extern "C" void cGOBJ_dtor(void* p, int flag);
extern "C" void operator_delete(void* p);
extern "C" E4Light* cGameLight_dtor(E4Light* p, short flag)
{
    if (p != 0) {
        p->vt = D_004DA1D0;
        if (p->m60) {
            delete p->m60;
            p->m60 = 0;
        }
        cGOBJ_dtor(p, 0);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179C20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179C20 */

/* merge_units: begin func_00179CC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Light_e1;
typedef void (*LightFn_e1)(Light_e1*);
class LightV_e1 { public: int pad; virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void Disable(); };
struct Light_e1 { int pad; LightFn_e1* vt; int id; };
extern LightFn_e1 D_004DA070[];
extern LightFn_e1 D_004D9240[];
extern LightFn_e1 D_004D9280[];
extern char D_00535D62;
extern char D_00535D20[];
extern "C" void LightMgr_RemoveFromTable(void*, Light_e1*);
extern "C" Light_e1* DirLight_Destruct(Light_e1* self, short reg)
{
    if (self != 0) {
        self->vt = D_004DA070;
        if (self != 0) {
            self->vt = D_004D9240;
            self->id = -1;
            ((LightV_e1*)self)->Disable();
            D_00535D62 = 1;
            if (self != 0) {
                self->vt = D_004D9280;
            }
        }
        if (reg > 0) {
            LightMgr_RemoveFromTable(D_00535D20, self);
        }
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179CC0 */

/* merge_units: begin func_00179D70 */
#pragma push /* merge_units */
#pragma cplusplus on

#if 0 /* merge_units */
extern "C" void cGOBJ_dtor(void* self, int flag);
#endif /* merge_units */
#define cGOBJ_dtor(a0, a1) (cGOBJ_dtor((a0), (a1))) /* merge_units */

class VDel { public: int a; virtual ~VDel(); };
extern "C" char D_004DA0B0[];
#if 0 /* merge_units */
extern "C" char D_004DA1D0[];
#endif /* merge_units */
#define D_004DA1D0 ((char*)&D_004DA1D0) /* merge_units */

typedef struct { void* vt; char pad[0x5C]; VDel* x60; } S_00179D70;
extern "C" S_00179D70* cGameDirectionalLight_dtor(S_00179D70* self, short flag)
{
    if (self) {
        self->vt = D_004DA0B0;
        if (self) {
            self->vt = D_004DA1D0;
            if (self->x60) {
                delete self->x60;
                self->x60 = 0;
            }
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#undef cGOBJ_dtor /* merge_units */
#undef D_004DA1D0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179D70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179D70 */
