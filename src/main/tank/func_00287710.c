#pragma cplusplus on
#include "vslot_pad.h"

struct V4 { union { __int128 q; struct { float x, y, z, w; } f; }; V4() {} };
typedef union { __int128 q; struct { float x, y, z, w; } f; } GV4;
struct Mtx { GV4 r[3]; GV4 t; };
struct Node { VPAD16(a) VPAD4(b) virtual void Refresh(); int pad4[3]; Mtx m; unsigned char dirty; };
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int Active(); };
struct Tgt {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual V4 GetPos(int a); /* 0xC0 */
    char p4[0x2C - 4];
    bool x2C; bool x2D; bool x2E; char p2F;
    char p30[0x58 - 0x30];
    Ctl* x58;
    bool Alive() { bool r = 0; if (x2D && x2C) r = 1; return r; }
    bool Live() { return !x2E; }
    bool Targetable() { bool r = 0; if (Alive() && Live()) r = 1; return r; }
};
struct Owner { char p[0x50]; Node* node; };
struct Self { Owner* owner; char p4[0x18 - 4]; float lo; float hi; };
struct It {
    Tgt** p;
    bool operator==(const It& o) const { Tgt** b = o.p; return p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
};

extern "C" {
extern char* g_ActorList;
void* cObjList_cHumanPtr_GetList(char* self);
void cArray_cHumanPtr_Begin(It* out, void* v);
void cArray_cHumanPtr_End(It* out, void* v);
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx* m, V4* v, V4* out);
}

static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(qa), "=&r"(qb) : "r"(s), "r"(d) : "memory"); }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

extern "C" Tgt* cTurret_GetClosestEnemy(Self* self) {
    It it;
    It end;
    Mtx m;
    V4 hd;
    Node* n = self->owner->node;
    if (n->dirty) n->Refresh();
    { Mtx* src = &n->m; Mtx* dst = &m; Q4(dst, src); }
    char* reg = g_ActorList;
    cArray_cHumanPtr_Begin(&it, cObjList_cHumanPtr_GetList(reg));
    cArray_cHumanPtr_End(&end, cObjList_cHumanPtr_GetList(reg));
    float best = 1000.0f;
    Tgt* found = 0;
    for (; it != end; it.p++) {
        Tgt* t = *it.p;
        if (t->Targetable()) {
            bool ok = 0;
            if (t->x58 && t->x58->Active()) ok = 1;
            if (ok) {
                V4 pos = t->GetPos(-1);
                GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(&m, &pos, &hd);
                
                if (0.3f + hd.f.x > self->lo && hd.f.x - 0.3f < self->hi) {
                    float d = Abs(hd.f.z);
                    if (d < best) {
                        best = d;
                        found = t;
                    }
                }
            }
        }
    }
    return found;
}






