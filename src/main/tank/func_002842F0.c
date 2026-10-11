#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
extern char* D_005061D0;
extern char D_004A93D0[];
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
void func_00282160(void* out);
void* cTank_SetTurret(void* mem, void* a, void* b, void* c, int d, void* t);
void func_00284870(void* t);
}
typedef struct { char pad[0x144]; float f; } O_002842F0;
inline void* operator new(unsigned int, void* p) { return p; }
struct Seg_002842F0 { void* a; O_002842F0* b; char pad8[0x1C]; float f; unsigned char flag;
    Seg_002842F0(void* a_, O_002842F0* b_) { b = b_; a = a_; f = b->f; flag = 0; } };
typedef struct { char pad[0x64]; struct Seg_002842F0* s0; Seg_002842F0* s1; void* turret; unsigned char b70; } T_002842F0;
static inline void* RO_002842F0(void** x) { func_00282160(x); return *x; }
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