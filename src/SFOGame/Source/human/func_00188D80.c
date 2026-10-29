#pragma cplusplus on
#include "types.h"

typedef __int128 Q128;

class cXform {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad04[0x40 - 0x04];
    Q128 translation;
    unsigned char needsUpdate;
    const Q128& GetTranslation() { if (needsUpdate) Update(); return translation; }
};

typedef signed char eBone;

class cHuman {
public:
    char pad00[0x2C];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    unsigned char mIsRenderable;
    char pad30[0x50 - 0x30];
    cXform* mXform;
    bool IsActive() const { return mActiveFlag && mEnabled; }
    bool IsStreaming() const { return mStreamingFlag; }
    bool NotStreaming() const { return !mStreamingFlag; } bool IsTargetable() const { bool r = false; if (IsActive() && NotStreaming()) r = true; return r; }
};

extern "C" {
extern eBone D_0048A2A0[4];
extern signed char ActorNodeCodeTable[];
void* cSKM_GOBJ_GetSkeleton_void(const cHuman* h);
void cSkeleton_GetBoneToWorldTranslation(Q128* out, void* skel, int node);
}

/* 16-byte qword copy (lq/sq) */
static inline void V4Copy(void* d, const void* s) { __int128 t; asm { .set noreorder
 lq t, 0(s)
 .set reorder
 sq t, 0(d) } }
#pragma opt_propagation off
#pragma opt_rebuildlogicals off
/* cVector returned by value; the work happens in an inlined constructor so the hidden
   return pointer is `this` (kept in a volatile stack slot, re-read at each use). */
struct RV { float x, y, z, w; RV() {} inline RV(const cHuman* self, int subTarget); } __attribute__((aligned(16)));
inline RV::RV(const cHuman* self, int subTarget)
{
    Q128* volatile out = (Q128*)this;
    if (self->IsTargetable()) {
        eBone targetBone = D_0048A2A0[subTarget & 3];
        void* skel = cSKM_GOBJ_GetSkeleton_void(self); int node = ActorNodeCodeTable[(unsigned char)targetBone]; cSkeleton_GetBoneToWorldTranslation(out, skel, node);
        return;
    }
    { const Q128* s = &self->mXform->GetTranslation(); V4Copy(out, s); (void)out; }
}
extern "C" RV cHuman_GetTargetPosition(const cHuman* self, int subTarget)
{
    return RV(self, subTarget);
}
