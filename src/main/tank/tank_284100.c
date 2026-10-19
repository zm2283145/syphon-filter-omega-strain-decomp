/*
 * main/tank: range (2 files, 00284100-002842F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "net_local_id.h"
#pragma push
#pragma cplusplus on
#include "tank_obj_init.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00284100 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}typedef struct { int a; } Id_4100;
extern "C" {
extern char D_004A93D0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void IdMgr_Allocate(Id_4100* out, int kind);
void cGOBJ_ctor(void* p, Id_4100* id, int a, int* b);
}
extern "C" TankObj* Global_CreateTank(int arg)
{
    TankObj* p;
{ AllocGuard g; p = (TankObj*)Mem_Alloc(0, 0x78, D_004A93D0, 0x2F2); }
    if (p) {
Id_4100 id; int z[1];
        z[0] = 0;
        IdMgr_Allocate(&id, 0xF9);
        cGOBJ_ctor(p, &id, 0, z);
        TankObj_Init(p, arg);
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00284100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00284100 */

/* merge_units: begin func_002842F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {
extern char* D_005061D0;
#if 0 /* merge_units */
void* Mem_Alloc(int heap, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

void NetStream_ReadObject(void* out);
void* cTank_SetTurret(void* mem, void* a, void* b, void* c, int d, void* t);
void func_00284870(void* t);
}
typedef struct { char pad[0x144]; float f; } O_002842F0;
inline void* operator new(unsigned int, void* p) { return p; }
struct Seg_002842F0 { void* a; O_002842F0* b; char pad8[0x1C]; float f; unsigned char flag;
    Seg_002842F0(void* a_, O_002842F0* b_) { b = b_; a = a_; f = b->f; flag = 0; } };
typedef struct { char pad[0x64]; struct Seg_002842F0* s0; Seg_002842F0* s1; void* turret; unsigned char b70; } T_002842F0;
static inline void* RO_002842F0(void** x) { NetStream_ReadObject(x); return *x; }
static inline char R8_002842F0(void) { return *D_005061D0++; }
static inline void* New_002842F0(int size, int line) { AllocGuard g; return Mem_Alloc(0, size, D_004A93D0, line); }
static inline void Del_002842F0(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A93D0, line); }
#pragma opt_propagation off
extern "C" void func_002842F0(T_002842F0* t) {
    void* x0; void* x1; void* x2; void* x3; void* x4; void* x5; void* x6;
    char n = R8_002842F0();
    unsigned char hasTurret = R8_002842F0() != 0;
    t->b70 = R8_002842F0() != 0;
    if (n) {
        void* a = RO_002842F0(&x0);
        O_002842F0* b = (O_002842F0*)RO_002842F0(&x1);
        void* c = RO_002842F0(&x2);
        O_002842F0* d = (O_002842F0*)RO_002842F0(&x3);
        if (t->s0) Del_002842F0(t->s0, 0x1F1);
        t->s0 = new (New_002842F0(0x2C, 0x1F3)) Seg_002842F0(a, b);
        if (t->s1) Del_002842F0(t->s1, 0x1F9);
        t->s1 = new (New_002842F0(0x2C, 0x1FB)) Seg_002842F0(c, d);
    }
    if (hasTurret) {
        void* a = RO_002842F0(&x4);
        void* b = RO_002842F0(&x5);
        void* c = RO_002842F0(&x6);
        void* m;
        if (t->turret) Del_002842F0(t->turret, 0x1E8);
        m = New_002842F0(0x70, 0x1EA);
        if (m) m = cTank_SetTurret(m, a, b, c, 0, t);
        t->turret = m;
        func_00284870(t->turret);
    }
}
#undef Mem_Alloc /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002842F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002842F0 */
