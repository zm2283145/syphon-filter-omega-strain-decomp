#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
#include "vc_copy.h"
#include "q4r.h"
typedef unsigned __int128 u_long128;
struct cVector { float x, y, z, w; cVector& operator=(const cVector& source) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0(%1)" : "=r"(reg) : "r"(&source)); __asm__ volatile("sq %1, 0(%0)" : : "r"(&refThis), "r"(reg)); return refThis; } };
struct cMatrix { float m[4][4]; cMatrix& operator=(const cMatrix& source) { cMatrix& refThis = *this; const cMatrix* s = &source; cMatrix* d = &refThis; u_long128 reg0, reg1; __asm__ volatile("lq %0, 0(%1)" : "=r"(reg0) : "r"(s)); __asm__ volatile("lq %0, 16(%1)" : "=r"(reg1) : "r"(s)); __asm__ volatile("sq %0, 0(%1)" : : "r"(reg0), "r"(d)); __asm__ volatile("lq %0, 32(%1)" : "=r"(reg0) : "r"(s)); __asm__ volatile("sq %0, 16(%1)" : : "r"(reg1), "r"(d)); __asm__ volatile("lq %0, 48(%1)" : "=r"(reg1) : "r"(s)); __asm__ volatile("sq %0, 32(%1)" : : "r"(reg0), "r"(d)); __asm__ volatile("sq %0, 48(%1)" : : "r"(reg1), "r"(d)); return *this; } };
struct cMessageName { int id; bool operator==(const cMessageName& o) const { return id == o.id; } };
struct cArray { int cap; int n; void* data; int pad; void* At() { void** p = &data; return *p; } void* Get() { return data; } };
struct PosKey_E890 { float t; char pad4[0xC]; cVector pos; };
struct VisKey_E890 { float t; unsigned char vis; };
struct cMessage;
struct cNIShuttle { void* vtable; char pad4[0x20]; int mAction; };
class cNIEventBase {
public:
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual void UpdateAll(float t);
    char pad4[0x60 - 0x4];
    int mType; char mParentName[48]; cNIEventBase* mParent; int mChildCount;
    cArray mChildren; cArray mPosKeys; int mPosORT; float mPosTime;
    cArray mVisKeys; int mVisORT; float mVisTime; unsigned char mVisible;
    cVector mPos; cMatrix mLocalXform; unsigned char mPlaying; float mSpeedMult;
};
extern "C" {
extern cMessageName D_004F7C28;
cMessageName* cMessage_Name(const cMessage* m);
unsigned char cGOBJ_HandleMessage(cNIEventBase* self, const cMessage* m);
unsigned char cNIEventBase_HandleMessage(cNIEventBase* self, const cMessage* m);
}

extern "C" unsigned char cNIEventBase_HandleMessage(cNIEventBase* self, const cMessage* m)
{
    if (*cMessage_Name(m) == D_004F7C28) {
        cNIShuttle* msg = (cNIShuttle*)m;
        int action = msg->mAction;
        switch (action) {
        case 0: self->mPlaying = 1; break;
        case 1: self->mPlaying = 0; break;
        case 2: {
            cMatrix mat;
            self->mPosTime = 0.0f;
            self->mVisTime = 0.0f;
            self->mPos = ((PosKey_E890*)self->mPosKeys.data)[0].pos;
            *(cVector*)mat.m[3] = self->mPos;
            self->mLocalXform = mat;
            self->mVisible = ((VisKey_E890*)self->mVisKeys.At())[0].vis;
            self->UpdateAll(0.0f);
            self->mPlaying = 0;
            break;
        }
        }
        return 1;
    }
    return cGOBJ_HandleMessage(self, m);
}

