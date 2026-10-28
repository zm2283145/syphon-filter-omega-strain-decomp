#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"

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
