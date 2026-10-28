/*
 * SFOGame/Source/human: 7 files, 0018A0B0-0018A420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0018A0B0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

typedef struct { int top; int cur[2]; int dirty[2]; } Bits_18A0B0;
static inline unsigned char Get_18A0B0(int* a, int bit) { return ((a[bit/32] >> (bit&31)) & 1) != 0; }
static inline void Set_18A0B0(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
void ActionPriority_Reset(Bits_18A0B0* b, int bit)
{
    int old[2];
    int i;
    unsigned int j;
    old[0] = b->cur[0];
    old[1] = b->cur[1];
    b->cur[0] = 0;
    b->cur[1] = 0;
    Set_18A0B0(b->cur, bit);
    for (i = 31; i >= 0 && !Get_18A0B0(b->cur, i); i--) {
    }
    if (!Get_18A0B0(b->cur, i)) b->top = -1; else b->top = i;
    for (j = 0; j < 32; j++) {
        if (Get_18A0B0(b->cur, j) != Get_18A0B0(old, j)) Set_18A0B0(b->dirty, j);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A0B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A0B0 */

/* merge_units: begin func_0018A210 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_0018A210)
static inline void merge_flush_func_0018A210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A210 */

/* merge_units: begin func_0018A260 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cSkaAnimEndedMessage_Clone();
extern void * const D_004DA930[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cSkaAnimEndedMessage_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA930);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA930[8] = { (void*)0x0, (void*)0x0, (void*)cSkaAnimEndedMessage_dtor, (void*)cSkaAnimEndedMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A260 */

/* merge_units: begin func_0018A2C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

#if 0 /* merge_units */
extern char D_004DA930[];   /* AnimEvent vtable */
#endif /* merge_units */
#define D_004DA930 ((char*)&D_004DA930) /* merge_units */


extern char D_00542B60[];   /* AnimEvent message type */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

float func_0018A2C0(char* self) {
    return *(float*)(self + 156);
}

float cSkaRequestStream_AnimationPacket_GetDuration(char* self) {
    return *(float*)(self + 152);
}

void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(char* self) {
    return self + 76;
}

signed char cSkaRequestStream_AnimationPacket_GetInstruction(signed char* self) {
    return self[72];
}

AnimEvent* cSkaAnimEndedMessage_ctor_void(AnimEvent* self) {
    cMessage_ctor_cMessageNameR(&self->base, D_00542B60);
    self->base.vtable = D_004DA930;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0.0f;
    return self;
}

Vec4* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
#undef D_004DA930 /* merge_units */
static inline void merge_flush_func_0018A2C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A2C0 */

/* merge_units: begin func_0018A380 */
#pragma push /* merge_units */
typedef struct { float a, b, c, d; } AnimRate;
static inline float b4inv(float r) { return (r != 0.0f) ? 1.0f / r : 3.4028235e38f; }
AnimRate* cSkaCrossFadeDuration_ctor_float(AnimRate* p, float r) {
    p->a = r;
    p->b = r;
    p->c = b4inv(r);
    p->d = b4inv(r);
    return p;
}
static inline void merge_flush_func_0018A380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A380 */

/* merge_units: begin func_0018A410 */
#pragma push /* merge_units */
float cSkaAnimationSet_DefaultCrossFadeDuration(char* self) {
    return *(float*)(self + 0);
}
static inline void merge_flush_func_0018A410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A410 */

/* merge_units: begin func_0018A420 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

class cSkaAnim;
class cSkaNode;

class cSkaPlaybackGroupId {
public:
    cSkaAnim* animId;
    int syncGroupId;
    cSkaPlaybackGroupId() : animId(0), syncGroupId(-1) {}
    cSkaPlaybackGroupId(const cSkaNode* anim);
    cSkaPlaybackGroupId(const cSkaPlaybackGroupId& o) : animId(o.animId), syncGroupId(o.syncGroupId) {}

};

class cSkaNode {
public:
    int pad00;
    unsigned char type;
    char pad05[0x40 - 0x05];
    int mSyncGroupId;
    const int& GetSyncGroupId() const { return mSyncGroupId; }
    bool IsAnim() const { bool r = true; if (type != 0 && type != 1) r = false; return r; }
    cSkaPlaybackGroupId GetPlaybackGroupId() const {
        return IsAnim() ? cSkaPlaybackGroupId(this) : cSkaPlaybackGroupId();
    }
};

/* cSkaAnimationBlend: +0 animation node, +4 playback group id */
struct cSkaAnimationBlend {
    cSkaNode* node;
    cSkaPlaybackGroupId id;
};

class cArray_cSkaNodePtr {
public:
    char pad[0x10];
};

class cSkaAnimationSet {
public:
    char pad00[0x34];
    cArray_cSkaNodePtr nodeLookupTable_ByIndex;
};

class cSkaRequestStream_AnimationPacket {
public:
    unsigned char mAnimSpecifier;
    char pad01[0x0F];
    char mName[0x30];
    int mId;
    cSkaAnimationBlend* mAnimationBlend;
};

extern "C" {
int cSkaAnimationSet_GetNodeId(const cSkaAnimationSet* set, const char* name);
cSkaNode* const* cArray_cSkaNodePtr_opIndex(const cArray_cSkaNodePtr* a, int i);
}

inline cSkaPlaybackGroupId::cSkaPlaybackGroupId(const cSkaNode* anim)
{
    const int& s = anim->GetSyncGroupId();
    animId = s == -1 ? (cSkaAnim*)anim : 0;
    syncGroupId = s;
}


extern "C" void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(const cSkaRequestStream_AnimationPacket* self, const cSkaNode*& animation, cSkaPlaybackGroupId& playbackGroupId, const cSkaAnimationSet& animationSet)
{
    switch (self->mAnimSpecifier) {
    case 0:
        animation = *cArray_cSkaNodePtr_opIndex(&animationSet.nodeLookupTable_ByIndex, cSkaAnimationSet_GetNodeId(&animationSet, self->mName));
        {
            const cSkaNode* n = animation;
            playbackGroupId = n ? n->GetPlaybackGroupId() : cSkaPlaybackGroupId();
        }
        break;
    case 1:
        animation = *cArray_cSkaNodePtr_opIndex(&animationSet.nodeLookupTable_ByIndex, self->mId);
        {
            const cSkaNode* n = animation;
            playbackGroupId = n ? n->GetPlaybackGroupId() : cSkaPlaybackGroupId();
        }
        break;
    case 2:
        animation = self->mAnimationBlend->node;
        playbackGroupId = self->mAnimationBlend->id;
        break;
    default:
        animation = 0;
        playbackGroupId = cSkaPlaybackGroupId();
        break;
    }
}
static inline void merge_flush_func_0018A420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A420 */
