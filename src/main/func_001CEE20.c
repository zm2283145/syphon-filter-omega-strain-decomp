#include "types.h"
typedef struct { int* p; } F8It_1CE;
typedef struct { float m[4][4]; } F8Mtx_1CE;
typedef struct { char pad0[0x50]; unsigned char dirty; char pad51[0xF]; F8Mtx_1CE basis; char padA0[0x4]; char kids[4]; } F8Bone_1CE;
extern void func_001CF100(F8It_1CE* out, void* v);
extern void func_001CF0E0(F8It_1CE* out, void* v);
extern int func_001CEF10(F8It_1CE* a, F8It_1CE* b);
extern int* func_001CF0D0(F8It_1CE* it);
extern void func_001CEF50(int child);
extern F8It_1CE* func_001CEF30(F8It_1CE* it);
void Bone_SetLocalBasis(F8Bone_1CE* b, F8Mtx_1CE* m)
{
    b->basis.m[0][0] = m->m[0][0];
    b->basis.m[0][1] = m->m[0][1];
    b->basis.m[0][2] = m->m[0][2];
    b->basis.m[1][0] = m->m[1][0];
    b->basis.m[1][1] = m->m[1][1];
    b->basis.m[1][2] = m->m[1][2];
    b->basis.m[2][0] = m->m[2][0];
    b->basis.m[2][1] = m->m[2][1];
    b->basis.m[2][2] = m->m[2][2];
    b->basis.m[0][3] = m->m[0][3];
    b->basis.m[1][3] = m->m[1][3];
    b->basis.m[2][3] = m->m[2][3];
    if (!b->dirty) {
        F8It_1CE it;
        F8It_1CE end;
        F8It_1CE* pe;
        b->dirty = 1;
        func_001CF100(&it, b->kids);
        func_001CF0E0(&end, b->kids);
        pe = &end;
        while (func_001CEF10(&it, pe)) {
            func_001CEF50(*func_001CF0D0(&it));
            func_001CEF30(&it);
        }
    }
}
