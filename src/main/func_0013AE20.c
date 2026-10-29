#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"

#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX

struct cGOBJ;
struct cSystem;

struct cVector {
    float x, y, z, w;
    cVector() {}
} __attribute__((aligned(16)));

static inline void QCopy(cVector* pd, const cVector* ps)
{
    __int128 t;
    asm { .set reorder; lq t, 0(ps) }
    asm { sq t, 0(pd) }
}

struct cCollisionModel_FaceProperties {
    unsigned char b0, b1, b2;
    char pad[13];
};

struct cCollisionModel_FaceLocator {
    int a, b;
    char pad[8];
};

struct cCollisionFace {
    cVector vertices[3];
    cVector unitNormal;
    cCollisionModel_FaceProperties faceProperties;
    unsigned char isCamPassThru;
    unsigned char isReceiveShadow;
    unsigned char isReceiveReflection;
    char pad53[13];
    cCollisionModel_FaceLocator faceLocator;
};

static inline void FaceCtor(cCollisionFace* f)
{
    char* b = (char*)f;
    cVector* p = (cVector*)b;
    cVector* e = (cVector*)(b + 0x30);
    do { p++; } while (p != e);
    f->faceProperties.b0 = 0;
    f->faceProperties.b2 = 0;
    f->faceLocator.a = 0;
    f->faceLocator.b = 0;
}

/* Vestigial inline face dtor: the empty asm is a scheduling barrier that keeps the
   null-check (and its dead address) alive until late branch removal, as in retail. */
static inline void FaceBar(cCollisionFace* f) { if (f != 0) __asm__ volatile(".set reorder"); }
struct cLosResult {
    unsigned char mIsLosBlocked;
    cVector mIntersectionPoint;
    cCollisionFace mBlockingFace;
    int mHandle;
    void SetIsLosBlocked(unsigned char b) { mIsLosBlocked = b; }
    void SetIntersectionPoint(const cVector& p) { QCopy(&mIntersectionPoint, &p); }
    void SetBlockingFace(const cCollisionFace& f);
    void SetHandle(int h) { mHandle = h; }
};

struct cArray_FixedCapacity_GOBJ2 {
    unsigned int count;
    cGOBJ* data[2];
};

extern "C" void cArray_FixedCapacity_cGOBJPtr_2_ResizeActual(cArray_FixedCapacity_GOBJ2* a, unsigned int n, cGOBJ* const* v);

class cCollisionModelList_Game {
public:
    virtual void v0();
    virtual void v1();
    virtual void SetCenterOfActivation(void* req);
    char pad4[0x10];
    cArray_FixedCapacity_GOBJ2 mExclusionList;

    void PushBack_ExclusionList(cGOBJ* g)
    {
        if (g) {
            if (mExclusionList.count < 2) {
                mExclusionList.data[mExclusionList.count] = g;
                mExclusionList.count++;
            }
        }
    }
};

extern cCollisionModelList_Game* D_004EA0B8;
extern char g_LosResultMsgClass[];
extern char D_004D91C0[];

extern "C" {
unsigned char nCollision_DetectForIntersectionBetweenRayAndFaces(cVector* pt, cCollisionFace* face, cVector* from, cVector* dir,
    cCollisionModelList_Game* list, int a, unsigned char flags, int c, long d, long e);
void cCollisionFace_opAssign(cCollisionFace* d, const cCollisionFace* s);
void cMessage_ctor_cMessageNameR(void* m, void* name);
void cLosResult_ctor_cLosResultR(cLosResult* d, cLosResult* s);
void QueueMessage_cMessageR_cSystemP_int(void* m, cSystem* to, int f);
void cMessage_dtor(void* m, int f);
}

struct cMessage {
    void* vtable;
    char pad[0x2C];
    __declspec(weak) __declspec(DROPDTOR) ~cMessage() { cMessage_dtor(this, 0); }
};

inline void cLosResult::SetBlockingFace(const cCollisionFace& f) { cCollisionFace_opAssign(&mBlockingFace, &f); }

struct cLosResultReadyMessage : cMessage {
    cLosResult mResult;
    cLosResultReadyMessage(cLosResult* r)
    {
        cMessage_ctor_cMessageNameR(this, g_LosResultMsgClass);
        vtable = D_004D91C0;
        cLosResult_ctor_cLosResultR(&mResult, r);
    }
    __declspec(weak) __declspec(DROPDTOR) ~cLosResultReadyMessage()
    {
        vtable = D_004D91C0;
        FaceBar(&mResult.mBlockingFace);
    }
};
struct cLosRequest {
    cVector losStartPoint;
    cVector losVector;
    unsigned char isInUse;
    cSystem* requester;
    cLosResult* result;
    cLosResult resultMemory;
    int handle;
    cGOBJ* excludedGobj0;
    cGOBJ* excludedGobj1;
    int mIgnoreFlags;
};

extern "C" void cLosRequest_cCollisionModelList_Game_Process(cLosRequest* self)
{
    cCollisionModelList_Game& collisionModelList = *D_004EA0B8;
    collisionModelList.SetCenterOfActivation(self);
    {
        cGOBJ* z = 0;
        cGOBJ** pz = &z;
        cArray_FixedCapacity_cGOBJPtr_2_ResizeActual(&collisionModelList.mExclusionList, 0, pz);
    }
    if (self->excludedGobj0) collisionModelList.PushBack_ExclusionList(self->excludedGobj0);
    if (self->excludedGobj1) collisionModelList.PushBack_ExclusionList(self->excludedGobj1);
    cVector intersectionPoint;
    cCollisionFace intersectingFace;
    cCollisionFace* pf = &intersectingFace;
    FaceCtor(pf);
    unsigned char intersectionDetected = nCollision_DetectForIntersectionBetweenRayAndFaces(&intersectionPoint, &intersectingFace,
        &self->losStartPoint, &self->losVector, &collisionModelList, 0, *(unsigned char*)&self->mIgnoreFlags, 0, 0, 1);
    self->result->SetIsLosBlocked(intersectionDetected);
    self->result->SetIntersectionPoint(intersectionPoint);
    self->result->SetBlockingFace(intersectingFace);
    self->result->SetHandle(self->handle);
    if (self->requester) {
        cLosResultReadyMessage msg(self->result);
        QueueMessage_cMessageR_cSystemP_int(&msg, self->requester, 1);
    }
}

