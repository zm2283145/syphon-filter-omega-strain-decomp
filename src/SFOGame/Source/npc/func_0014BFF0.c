/* 0014BFF0 cNPC::UpdateMovement() (npc.cc). Rebuilt from the prototype DWARF/.line data (lines 5611-5980); retail
 * rewrote the transport/terrain block near the start and added the weapon-type facing branch (taken from the retail asm).
 * Message temporaries/locals are C++ classes with weak inline destructors (.dtors_drop). VU0 operations, lq/sq quad
 * copies and abs.s/min.s are inline asm because MW has no C spelling for them. */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma enumsalwaysint off
#include "types.h"

struct cVector;
/* 128-bit copy: lq/sq have no C spelling in MW (a struct copy is split into words). */
static inline void CopyV(cVector* d, const cVector* s)
{
    cVector* dp = d; const cVector* sp = s;
    __int128 t;
    __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(sp));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(dp) : "memory");
}
/* VU0 vsub: no C equivalent */
static inline void SubC(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { CopyV(this, &o); }
    cVector& operator=(const cVector& o) { CopyV(this, &o); return *this; }
    cVector operator-(const cVector& b) const { cVector r; SubC(&r, this, &b); return r; }
    void Zero() { cVector* p = this; __asm__ volatile("sq $0, 0x0(%0)" : : "r"(p) : "memory"); }
    /* VU0 normalise (vrsqrt): no C equivalent */
    void Normalize() { NormP(this); }
    static void NormP(cVector* p0)
    {
        cVector* p = p0;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory");
    }
    /* VU0 length squared: no C equivalent */
    float LengthSq() { return LsqP(this); }
    static float LsqP(const cVector* p0)
    {
        float r = 0.0f;
        int t;
        const cVector* p = p0;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2 %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(p) : "memory");
        return r;
    }
    /* VU0 zero test (vaddx + clip flags): no C equivalent */
    unsigned char IsZero()
    {
        int k, fl;
        int r = 0;
        const cVector* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni fl, vi17
            bne k, fl, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
} __attribute__((aligned(16)));
extern "C" float Libc_Atan2f(float, float);
struct cNetHuman;
struct cMatrix { cVector r0, r1, r2, t; const cVector& T() const { return t; } float Z() const { return t.z; } const cVector& R1() const { return r1; } float HeadingZ() const { return Libc_Atan2f(-r1.x, r1.y); } void ToNet(cNetHuman& n) const; };
/* abs.s / min.s have no C spelling in MW */
static inline float Fabs(float x) { float r = 0.0f; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float MinF(float a, float b) { float r = 0.0f; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

enum eMoveMode { MM_0 = 0, MM_1 = 1, MM_MAX = 0x7F };
struct cObjectId { int mId; bool operator==(const cObjectId& o) const { return mId == o.mId; } };
struct cGOBJ;
struct cSafePtr {
    cGOBJ* ptr;
    cObjectId id;
    bool IsValid() const;
    cGOBJ* Get() const { return IsValid() ? ptr : 0; }
};
struct cNetHuman { char pad[0x3C]; float speed; float rotZ; float x, y, z; };
inline void cMatrix::ToNet(cNetHuman& n) const { n.x = t.x; n.y = t.y; n.z = t.z; }
struct tSecondaryState { char pad[0x4C]; unsigned char aims; char pad4D[0x50 - 0x4D]; };
struct cHumanIkRoutine { char pad[0x310]; unsigned char mode0; unsigned char mode1; };
struct cGOBJ {
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
    virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
    virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23();
    virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29(); virtual void g30(); virtual void g31();
    virtual void g32(); virtual void g33(); virtual void g34(); virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43(); virtual void g44(); virtual void g45();
    virtual cVector GetBonePos(int bone);          /* 0xC0 */
    virtual void g47(); virtual void g48(); virtual void g49(); virtual void g50(); virtual void g51(); virtual void g52(); virtual void g53(); virtual void g54(); virtual void g55();
    virtual cMatrix GetNetMatrix();                /* 0xE8 */
    virtual void g57(); virtual void g58();
    virtual cMatrix GetMatrix();                   /* 0xF4 */
    virtual unsigned char IsInActiveSector(const void* plane); /* 0xF8 */
    virtual void g61(); virtual void g62(); virtual void g63();
    virtual unsigned char GetState();              /* 0x108 */
    char pad04[0xC - 4];
    cObjectId mObjectId;
    char pad10[0x14 - 0x10];
    unsigned char mbIsLocal;
    char pad15[0x2C - 0x15];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    cObjectId* ObjId() { return &mObjectId; }
    bool IsActiveAndNotStreaming() { return mActiveFlag && mEnabled && !mStreamingFlag; }
};
inline bool cSafePtr::IsValid() const { return !ptr || ptr->mObjectId == id; }
static inline bool IsTerrainActive(cGOBJ* g) { return g && g->IsActiveAndNotStreaming(); }
struct cHuman : cGOBJ {
    char pad30[0x30AC - 0x30];
    unsigned char destReached;      /* 0x30AC */
    unsigned char destReachedValue; /* 0x30AD */
    char pad30AE[0x3204 - 0x30AE];
    int flags3204;                  /* 0x3204 */
    char pad3208[0x3210 - 0x3208];
    int flags3210;                  /* 0x3210 */
    char pad3214[0x3260 - 0x3214];
    unsigned char sex;              /* 0x3260 */
    char pad3261[0x3310 - 0x3261];
    struct Carry { char pad[0xDC]; unsigned char active; }* carry; /* 0x3310 */
    cHumanIkRoutine* ikRoutine;     /* 0x3314 */
    char pad3318[0x3478 - 0x3318];
    cSafePtr transport;             /* 0x3478 */
    char pad3480[0x3524 - 0x3480];
    void* mWeapon;                  /* 0x3524 */
    char pad3528[0x3584 - 0x3528];
    cNetHuman* m_NetHuman;          /* 0x3584 */
    bool Rolling() { return ((flags3204 >> 5) & 1) != 0; }
    bool Bit7() { return ((flags3204 >> 7) & 1) != 0; }
    unsigned char IsLocal() { return mbIsLocal; }
    bool IsCarrying() { return carry && carry->active; }
};
struct cNode { char pad[0x60]; cGOBJ* terrainGobj; char pad64[0x7C - 0x64]; int groupIndex; bool InGroup(int g) { return groupIndex == g; } };
struct cPathNavigator {
    cVector nextDestination;
    cVector pathDelta;
    char pad20[0x50 - 0x20];
    int nextNodeIndex;
    char pad54[0x5C - 0x54];
    int nodeGroupIndex;
    int NextNode() { return nextNodeIndex; }
    float PathHeading() { return Libc_Atan2f(-pathDelta.x, pathDelta.y); }
    unsigned char onPatrolPath : 1;
    unsigned char onPath : 1;
    unsigned char forceOnNodes : 1;
    unsigned char destinationReachedFlag : 1;
    unsigned char IsDestinationReached() { return destinationReachedFlag; }
};
struct cCurrentLookAt { cSafePtr gobj; float duration; int priority; unsigned char use; char pad[3]; };
struct cNPCInfoObject { char pad[4]; };

struct cNPC;
extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_NpcRegionTable[];
extern int D_005721A8;
extern int D_00494178;
extern tSecondaryState SecondaryStateTable[];
extern char D_004EA3C0[], D_004EA3B0[];
extern signed char D_004EA3A8;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0100[], D_004DAE30[], D_004F1610[], g_Game[];
cNode* cAIPathData_GetNode(int);
cNode* cPathNavigator_GetLastNodeReached(cPathNavigator*);
float cPathNavigator_PathFloorZ(cPathNavigator*, unsigned char, unsigned char);
cHuman* cNetObj_GetPlayer(int);
void cPathNavigator_UpdateGobjBeingTransported(cPathNavigator*, int);
void* func_0014D460(void*);
void* func_0014D450(void*);
cGOBJ* func_0014D410(void*);
void cPlane_dtor(void*, int);
void __register_global_object(void*, void*, void*);
void NpcAi_GroundActor(cGOBJ*, unsigned char, int, float);
void NpcPath_SetHeight(cPathNavigator*, float);
void cNPCInfoObject_ctor(cNPCInfoObject*);
void cNPCInfoObject_dtor(cNPCInfoObject*, int);
void NetGetMyClientIndex(int*, int);
unsigned char cNPCInfoObject_IsInActiveTerrain(cNPCInfoObject*, cObjectId*, int);
void func_00433F20(cNPCInfoObject*, cObjectId*, unsigned char);
void cPathNavigator_SetDestinationReached(cPathNavigator*, unsigned char);
void cPathNavigator_Update(cPathNavigator*);
cGOBJ* cSafePtr_cGOBJ_GetPtr_void(cSafePtr*);
cVector cNode_GetLoc(cNode*);
unsigned char cWeapon_GetEquipmentType(void*);
float Libc_Atan2f(float, float);
void cNPC_DoAction(cNPC*, int, int, float);
void cNPC_SetMoveMode(cNPC*, int, int);
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
void QueueMessage_cMessageR_cSystemP_int(const void*, void*, int);
void cPlaySoundMsg_ctor_cSndFxR(void*, void*, cGOBJ*);
void cFileMan_dtor(void*, int);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct cMessage {
    void* vt;
    char pad04[0x20 - 4];
    unsigned char mDestinationType;
    cMessage() {}
    cMessage(void* n) { cMessage_ctor_cMessageNameR(this, n); }
    __declspec(weak) __declspec(MSG_DTOR) ~cMessage() { cMessage_dtor(this, 0); }
};
struct cCharActionMsg : cMessage {
    int mAction; unsigned char mParamType;
    cCharActionMsg(int a, unsigned char t) : cMessage(g_ActorActionMsgClass) { vt = D_004E0840; mAction = a; mParamType = t; }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg() { vt = D_004E0840; }
};
struct tDestParams {
    cVector dest;
    float o0, o1, o2, o3;
    float rotZ;
    float speed;
    int flags;
    tDestParams(const cVector& d, float rz, float sp)
    {
        tDestParams* p = this;
        p->dest = d;
        p->o0 = 0.0f; p->o1 = 0.0f; p->o2 = 0.0f; p->o3 = 0.0f;
        p->rotZ = rz;
        p->speed = MinF(1.0f, sp);
        p->flags = 0;
    }
};
struct cCharActionMsg_DestinationParams : cCharActionMsg {
    char pad2C[4];
    tDestParams params;
    cCharActionMsg_DestinationParams(const cVector& d, float rz, float sp) : cCharActionMsg(0, 13), params(d, rz, sp)
    {
        vt = D_004E0100;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg_DestinationParams() { vt = D_004E0840; }
};
struct cSndMember { char pad[0x9C]; __declspec(weak) __declspec(MSG_DTOR) ~cSndMember() { cFileMan_dtor(this, -1); } };
struct cPlaySoundMsg : cMessage {
    char pad24[0x78 - 0x24];
    cSndMember s0;
    cSndMember s1;
    char pad1B0[0x10];
    cPlaySoundMsg() {}
    __declspec(weak) __declspec(MSG_DTOR) ~cPlaySoundMsg() { vt = D_004DAE30; }
};
static inline void SendAction(const cCharActionMsg& m, cGOBJ* g) /* mDestinationType = 1 at the call site */
{
    ((cCharActionMsg&)m).mDestinationType = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g, 1);
}

static inline bool NotB(unsigned char b) { return !b; }
static inline int GetMyIndex(int conn)
{
    if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, conn);
    return D_00494178;
}
static inline int GetClientIndex(int conn)
{
    int idx = 0;
    if (g_IsMultiplayer) idx = GetMyIndex(conn);
    else idx = 0;
    return idx;
}
static inline float WrapAngle(float a)
{
    if (a > 3.1415927f) a -= 6.2831855f;
    else if (a < -3.1415927f) a += 6.2831855f;
    return a;
}

struct cNPC {
    virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4(); virtual void n5(); virtual void n6(); virtual void n7();
    virtual void n8(); virtual void n9(); virtual void n10(); virtual void n11(); virtual void n12(); virtual void n13(); virtual void n14(); virtual void n15();
    virtual void n16(); virtual void n17(); virtual void n18(); virtual void n19(); virtual void n20(); virtual void n21(); virtual void n22(); virtual void n23();
    virtual void n24(); virtual void n25(); virtual void n26(); virtual void n27(); virtual void n28(); virtual void n29(); virtual void n30(); virtual void n31();
    virtual void n32(); virtual void n33(); virtual void n34(); virtual void n35(); virtual void n36(); virtual void n37(); virtual void n38();
    virtual eMoveMode GetMoveMode();                /* 0xA4 */
    virtual unsigned char UseCurrentLookAt(int w);  /* 0xA8 */
    virtual unsigned char TargetPositionValid();    /* 0xAC */
    virtual const cVector* GetTargetPos();          /* 0xB0 */
    virtual unsigned char IsTargetVisible();        /* 0xB4 */
    virtual void n44(); virtual void n45(); virtual void n46(); virtual void n47(); virtual void n48(); virtual void n49(); virtual void n50(); virtual void n51();
    virtual float GetRawTravelSpeed();              /* 0xD8 */
    char pad04[0x30 - 4];
    cHuman* mGobj;
    char pad34[0x114 - 0x34];
    int pathLinkType;               /* 0x114 */
    char pad118[0x124 - 0x118];
    int actionFlags;                /* 0x124 */
    char pad128[0x13C - 0x128];
    unsigned char m13C;             /* 0x13C */
    char pad13D[0x158 - 0x13D];
    unsigned char inActiveSector;   /* 0x158 */
    char pad159[0x16C - 0x159];
    cCurrentLookAt currentLookAt[3];/* 0x16C */
    char pad1A8[0x1B0 - 0x1A8];
    cPathNavigator* pathNavigator;  /* 0x1B0 */
    char pad1B4[0x1D0 - 0x1B4];
    cNode* searchLookNode;          /* 0x1D0 */
    char pad1D4[0x1D6 - 0x1D4];
    unsigned char deathFallScreamWhenFalling; /* 0x1D6 */
    cHuman* GetGobj() { return mGobj; }
    bool IsDying() { return IsDS(mGobj->GetState()); }
    static bool IsDS(unsigned short st) { return st == 3 || st == 2; }
    void NotifyTerrain(int forced, float z)
    {
        unsigned char f = forced;
        if (f ? (mGobj->IsCarrying() || !inActiveSector) : !inActiveSector)
            NpcAi_GroundActor(mGobj, f, 1, z);
    }
    cCurrentLookAt* GetLookAt(int w) { cCurrentLookAt* r = 0; if (currentLookAt[w].use) r = &currentLookAt[w]; return r; }
    bool IsAiming()
    {
        return mGobj->ikRoutine ? IsAimingMode(mGobj->ikRoutine) : false;
    }
    static bool IsAimingMode(cHumanIkRoutine* ik)
    {
        return SS(ik->mode0).aims && SS(ik->mode1).aims;
    }
    static const tSecondaryState& SS(int m) { return SecondaryStateTable[m]; }
};

extern "C" void cNPC_UpdateMovement(cNPC* self)
{
    cVector pos = self->GetGobj()->GetMatrix().T();
    unsigned char prevInActiveSector;
    float floorZ;
    prevInActiveSector = self->inActiveSector;
    self->inActiveSector = 1;
    {
        unsigned char resetZ = 1;
        if (self->pathLinkType != 7) {
            resetZ = ((self->mGobj->flags3204 >> 7) & 1) != 0;
            if (self->pathNavigator->NextNode() >= 0) {
                if (!IsTerrainActive(cAIPathData_GetNode(self->pathNavigator->NextNode())->terrainGobj))
                    resetZ = 0;
            }
            {
                cNode* n = cPathNavigator_GetLastNodeReached(self->pathNavigator);
                if (n) {
                    if (!IsTerrainActive(n->terrainGobj))
                        resetZ = 0;
                }
            }
        }
        floorZ = cPathNavigator_PathFloorZ(self->pathNavigator, prevInActiveSector, resetZ);
    }
    if ((self->mGobj->flags3210 >> 22) & 1) {
        int groupIndex = -1;
        if (g_IsMultiplayer) {
            int i;
            for (i = 0; i != 4; i++) {
                cHuman* gobj = cNetObj_GetPlayer(i);
                if (gobj) {
                    if (gobj->transport.Get() == self->mGobj) {
                        groupIndex = g_NpcRegionTable[i];
                        break;
                    }
                }
            }
        }
        cPathNavigator_UpdateGobjBeingTransported(self->pathNavigator, groupIndex);
        {
            cGOBJ* t = func_0014D410(func_0014D450(func_0014D460(self->mGobj)));
            if (!t || !t->IsActiveAndNotStreaming())
                self->inActiveSector = 0;
        }
    } else if (!prevInActiveSector || self->mGobj->GetMatrix().Z() <= floorZ) {
        bool s3;
        if (D_004EA3A8 == 0) {
            __register_global_object(D_004EA3C0, (void*)cPlane_dtor, D_004EA3B0);
            D_004EA3A8 = 1;
        }
        self->inActiveSector = self->mGobj->IsInActiveSector(D_004EA3C0);
        s3 = 0;
        if (self->m13C == 1) {
            unsigned char s2 = 0;
            if (NotB(self->pathNavigator->IsDestinationReached()) && NotB(self->IsDying()))
                s2 = 1;
            if (s2) s3 = 1;
        }
        self->NotifyTerrain(s3, floorZ);
    } else if (self->mGobj->GetState() == 3) {
        NpcPath_SetHeight(self->pathNavigator, 3.0f + self->mGobj->GetMatrix().Z());
    }
    if (prevInActiveSector != self->inActiveSector)
        self->pathNavigator->forceOnNodes = !self->inActiveSector;
    if (g_IsMultiplayer) {
        cNPCInfoObject npcInfo;
        cNPCInfoObject_ctor(&npcInfo);
        if (self->inActiveSector != cNPCInfoObject_IsInActiveTerrain(&npcInfo, self->mGobj->ObjId(), GetClientIndex(D_005721A8)))
            func_00433F20(&npcInfo, &self->mGobj->mObjectId, self->inActiveSector);
        if (self->mGobj->mbIsLocal) {
            cNetHuman* netHuman = self->mGobj->m_NetHuman;
            if (netHuman) {
                self->mGobj->GetNetMatrix().ToNet(*netHuman);
            }
        }
        cNPCInfoObject_dtor(&npcInfo, -1);
    }
    if (!self->IsDying() || self->pathLinkType == 7) {
        float speed;
        eMoveMode moveMode;
        unsigned char rolling;
        cVector faceDelta;
        if (self->mGobj->destReached)
            cPathNavigator_SetDestinationReached(self->pathNavigator, self->mGobj->destReachedValue);
        cPathNavigator_Update(self->pathNavigator);
        speed = self->GetRawTravelSpeed();
        moveMode = self->GetMoveMode();
        rolling = self->mGobj->Rolling();
        if (0.0f == speed)
            moveMode = MM_0;
        if (moveMode != 1)
            speed = 0.0f;
        if (g_IsMultiplayer) {
            if (self->mGobj->mbIsLocal) {
                cNetHuman* netHuman = self->mGobj->m_NetHuman;
                if (netHuman) netHuman->speed = speed;
            }
        }
        if (self->UseCurrentLookAt(2)) {
            cCurrentLookAt* lookAt = self->GetLookAt(2);
            if (lookAt->gobj.Get())
                faceDelta = cSafePtr_cGOBJ_GetPtr_void(&lookAt->gobj)->GetBonePos(-1) - pos;
        } else if (rolling || self->pathLinkType == 7) {
            faceDelta = self->pathNavigator->pathDelta;
        } else if ((self->IsAiming() && self->IsTargetVisible()) || (cWeapon_GetEquipmentType(self->mGobj->mWeapon) == 1 && self->TargetPositionValid())) {
            faceDelta = *self->GetTargetPos() - pos;
            if (faceDelta.LengthSq() < 16.0f)
                faceDelta.Zero();
        } else {
            faceDelta.Zero();
        }
        if (moveMode == 1) {
            float rotZ;
            if (faceDelta.IsZero())
                faceDelta = self->pathNavigator->pathDelta;
            else
                faceDelta.Normalize();
            if (self->pathLinkType == 9 && !(self->actionFlags & 2) && !rolling) {
                float pathDeltaZ = self->pathNavigator->PathHeading();
                float deltaAngle = WrapAngle(pathDeltaZ - self->mGobj->GetMatrix().HeadingZ());
                if (Fabs(deltaAngle) <= 0.43633232f) {
                    cNPC_DoAction(self, 2, 0, 0.0f);
                    self->actionFlags &= ~2;
                    self->pathLinkType = 0;
                }
            }
            rotZ = Libc_Atan2f(-faceDelta.x, faceDelta.y);
            { cCharActionMsg_DestinationParams msg(self->pathNavigator->nextDestination, rotZ, speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        } else if (moveMode == 0) {
            float rotZ;
            if (!g_IsMultiplayer || self->mGobj->IsLocal()) {
                if (faceDelta.IsZero()) {
                    faceDelta = self->mGobj->GetMatrix().R1();
                    if (self->searchLookNode && self->searchLookNode->InGroup(self->pathNavigator->nodeGroupIndex)) {
                        faceDelta = cNode_GetLoc(self->searchLookNode) - pos;
                        faceDelta.Normalize();
                    }
                } else {
                    faceDelta.Normalize();
                }
                rotZ = Libc_Atan2f(-faceDelta.x, faceDelta.y);
            } else if (g_IsMultiplayer) {
                rotZ = self->mGobj->m_NetHuman ? self->mGobj->m_NetHuman->rotZ : 0.0f;
            }
            { cCharActionMsg_DestinationParams msg(faceDelta, rotZ, speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        } else {
            float angleTarget;
            float pathDeltaZ = self->pathNavigator->PathHeading();
            float deltaAngle = WrapAngle(pathDeltaZ - self->mGobj->GetMatrix().HeadingZ());
            if (self->pathLinkType == 4 || self->pathLinkType == 11 || self->pathLinkType == 3 || self->pathLinkType == 9)
                angleTarget = 25.0f;
            else
                angleTarget = 360.0f;
            if (Fabs(deltaAngle) <= 0.017453292f * angleTarget) {
                cNPC_SetMoveMode(self, 1, 20);
                if (self->pathLinkType == 4) {
                    SendAction(cCharActionMsg(15, 0), self->mGobj);
                } else if (self->pathLinkType == 11) {
                    SendAction(cCharActionMsg(16, 0), self->mGobj);
                } else if (self->pathLinkType == 3) {
                    QueueMessage_cMessageR_cSystemP_int(&cCharActionMsg(26, 0), self->mGobj, 0);
                }
            }
            { cCharActionMsg_DestinationParams msg(self->pathNavigator->nextDestination, self->pathNavigator->PathHeading(), speed); msg.mDestinationType = 1; QueueMessage_cMessageR_cSystemP_int(&msg, self->mGobj, 1); }
        }
    }
    if (self->deathFallScreamWhenFalling && ((self->mGobj->flags3204 >> 7) & 1)) {
        self->deathFallScreamWhenFalling = 0;
        cPlaySoundMsg msg;
        cPlaySoundMsg_ctor_cSndFxR(&msg, self->mGobj->sex == 1 ? D_004F1610 : D_004F1610, self->mGobj);
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    }
}
