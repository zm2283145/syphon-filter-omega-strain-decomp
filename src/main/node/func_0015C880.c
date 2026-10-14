#pragma cplusplus on
#include "types.h"
struct V_C88 { float x, y, z, w; } __attribute__((aligned(16)));
struct M_C88 {
    V_C88 r[4];
    M_C88() {}
    M_C88(const M_C88& o) { const M_C88* s = &o; M_C88* d = this; __int128 qa, qb; asm volatile { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
};
struct Rel_C88 { int a, b, c; unsigned char d; };
struct Node_C88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void SetMatrix(M_C88* m, int f);
    char pad4[0x29];
    unsigned char x2D;
    char pad2E[0x36];
    int x64;
    Rel_C88 x68;
    int x78;
    int x7C;
};
extern "C" {
extern void* const D_004D95B0[];
extern char D_004EA770[];
extern M_C88 D_0055C9F0;
void cGOBJ_ctor(Node_C88* self, int* id, int n, char* name);
void func_0015C860(Rel_C88* r);
Node_C88* cNode_ctor2(Node_C88* self, int a, int b, int c, float x, float y, float z);
}
typedef void (*SetM_C88)(Node_C88*, M_C88*, int);
Node_C88* cNode_ctor2(Node_C88* self, int a, int b, int c, float x, float y, float z)
{
    int id = -1;
    cGOBJ_ctor(self, &id, 10, D_004EA770);
    *(void**)self = (void*)D_004D95B0;
    { Rel_C88* r = &self->x68; func_0015C860(r); r->d = 1; }
    {
        M_C88 m = D_0055C9F0;
        self->x64 = a;
        m.r[3].x = x;
        m.r[3].y = y;
        m.r[3].z = z;
        m.r[3].w = 1.0f;
        self->SetMatrix(&m, 0);
    }
    self->x78 = c;
    self->x7C = b;
    self->x2D = 0;
    return self;
}


