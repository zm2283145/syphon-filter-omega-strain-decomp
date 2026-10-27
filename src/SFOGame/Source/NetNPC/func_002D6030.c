#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Path2D6030 { char pad[0x4C]; volatile int f4C; int f50; int f54; };
struct Bits141 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 1; unsigned char b6 : 1; unsigned char b7 : 1; };
struct Npc2D6030 {
    VPAD32(a) virtual unsigned char IsActive(); VPAD32(b) VPAD16(c) VPAD4(d) VPAD2(e) virtual int Slot87();
    char p4[0x10]; unsigned char f14; char p15[0x43]; Npc2D6030* f58; char p5C[0x3C]; float f98;
    char p9C[0xA5]; Bits141 f141; char p142[0xE]; int f150; char p154[0x5C]; Path2D6030* f1B0;
};
struct Owner2D6030 { char p0[0x14]; unsigned char f14; char p15[0x43]; Npc2D6030* f58; char p5C[0x34EC]; int f3548; char p354C[0x38]; char* f3584; };
struct Self2D6030 {
    void* vt; char p4[0x10]; unsigned char f14; char p15[0x83]; float f98; char p9C[0xA5]; Bits141 f141; char p142[0xE]; int f150;
    char p154[0x8C]; int f1E0; char* f1E4; int f1E8; short f1EC; char p1EE[0x12]; int f200; char p204[4]; int f208; char p20C[4]; int f210; Bits141 f214;
};
extern "C" {
extern char D_004DE2A0[];
void cNPC_ctor_cGOBJP(Self2D6030* self, Owner2D6030* owner);
int cAIPathData_GetNode(int n);
}
static inline int PathNode(Path2D6030* p) { int n = p->f4C; return n >= 0 ? n : p->f54; }
static inline void ResetFlags(Self2D6030* self, bool v) {
    self->f14 = 0;
    self->f214.b0 = v;
    self->f200 = 0;
    self->f214.b1 = v;
    self->f214.b2 = v;
}
extern "C" Self2D6030* cNetNPC_ctor(Self2D6030* self, int id, Owner2D6030* owner)
{
    cNPC_ctor_cGOBJP(self, owner);
    self->vt = D_004DE2A0;
    self->f1E0 = id;
    self->f1E4 = 0;
    self->f1E8 = 0;
    self->f1EC = 0;
    if (owner) {
        if (owner->f3584) {
            if (!self->f1E0) self->f1E0 = (int)owner->f3584;
            char* q = owner->f3584; if (q) q += 0x1C; self->f1E4 = q;
        }
        owner->f14 = 0;
        int node = owner->f3548;
        if (owner->f58 && owner->f58->IsActive() == 1) {
            Npc2D6030* o = owner->f58;
            float f = o->f98; self->f141.b7 = o->f141.b7;
            self->f98 = f;
            self->f210 = 0;
            Path2D6030* p = o->f1B0;
            if (PathNode(p) >= 0) {
                node = PathNode(p);
            } else if (p->f50 >= 0) {
                node = p->f50;
                self->f210 = cAIPathData_GetNode(node);
            }
            self->f150 = o->f150;
            self->f141.b2 = o->Slot87();
        }
        if (node >= 0) self->f1E8 = cAIPathData_GetNode(node);
        self->f208 = node;
    } else {
        self->f208 = -1;
    }
    ResetFlags(self, false);
    return self;
}




