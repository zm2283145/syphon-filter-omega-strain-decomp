/*
 * SFOGame/Source/npc: 6 files, 00151D30-00152B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00151D30 */
#pragma push /* merge_units */
/* 00151D30 cNPC::HandleMessage(const cMessage&) (npc.cc), rebuilt from the prototype DWARF/.line data.
 * Message temporaries are C++ classes with weak inline destructors (kept in .dtors_drop). */
#pragma cplusplus on
#pragma enumsalwaysint off
#include "types.h"

enum eMode { MODE_PATROL = 0, MODE_TAKECOVER = 2, MODE_LOSCHECK = 10, MODE_MAX = 0x7F };
enum ePathID { PID_NEG = -1, PID_0 = 0, PID_MAX = 0x7F };
enum eAIID { AID_NEG = -1, AID_0 = 0, AID_MAX = 0x7F };
enum eMoveMode { MM_0 = 0, MM_MAX = 0x7F };
enum eCause { CAUSE_0 = 0, CAUSE_MAX = 0x7F };

struct cMessageName { int id; bool operator==(const cMessageName& o) const { return id == o.id; } };
struct cVector { float x, y, z, w; } __attribute__((aligned(16)));
struct cSystem;
struct cGOBJ {
    virtual void gv0();
    virtual void gv1();
    virtual void gv2();
    virtual void gv3();
    virtual void gv4();
    virtual void gv5();
    virtual void gv6();
    virtual void gv7();
    virtual void gv8();
    virtual void gv9();
    virtual void gv10();
    virtual void gv11();
    virtual void gv12();
    virtual void gv13();
    virtual void gv14();
    virtual void gv15();
    virtual void gv16();
    virtual void gv17();
    virtual void gv18();
    virtual void gv19();
    virtual void gv20();
    virtual void gv21();
    virtual void gv22();
    virtual void gv23();
    virtual void gv24();
    virtual void gv25();
    virtual void gv26();
    virtual void gv27();
    virtual void gv28();
    virtual void gv29();
    virtual void gv30();
    virtual void gv31();
    virtual void gv32();
    virtual void gv33();
    virtual void gv34();
    virtual void gv35();
    virtual void gv36();
    virtual void gv37();
    virtual void gv38();
    virtual void gv39();
    virtual void gv40();
    virtual void gv41();
    virtual void gv42();
    virtual void gv43();
    virtual void gv44();
    virtual void gv45();
    virtual void gv46();
    virtual void gv47();
    virtual void gv48();
    virtual void gv49();
    virtual void gv50();
    virtual void gv51();
    virtual void gv52();
    virtual void gv53();
    virtual void gv54();
    virtual void gv55();
    virtual void gv56();
    virtual void gv57();
    virtual void gv58();
    virtual void gv59();
    virtual void gv60();
    virtual void gv61();
    virtual void gv62();
    virtual void gv63();
    virtual unsigned char State();
    char pad04[0x2C - 4];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    bool IsActiveAndNotStreaming() { return mActiveFlag && mEnabled && !mStreamingFlag; }
};
struct cNode { char pad[0x78]; int nodeListIndex; int groupIndex; };
struct cPathNavigator {
    cVector nextDestination;
    cVector pathDelta;
    char pad20[0x4C - 0x20];
    int nodeIndex;
    int nextNodeIndex;
    char pad54[0x60 - 0x54];
    unsigned char onPatrolPath : 1;
    unsigned char onPath : 1;
};
struct cMessage {
    void* vt;
    char pad04[0x20 - 4];
    unsigned char mDestinationType;
};
struct cAIMessage : cMessage { eAIID id; int data; int data2; };
struct cPathMessage : cMessage { ePathID id; int data; int companionData; };
struct cLosResultReadyMessage : cMessage { char pad24[0x30 - 0x24]; unsigned char mIsLosBlocked; };

struct cNPC;
extern "C" {
extern char D_004EE550[], D_004ED9B8[], D_004EA3E8[];
extern char g_ScriptAIWaypointReachedMsgKey[], g_ScriptAIDestinationReachedMsgKey[];
extern char g_ActorActionMsgClass[], g_LosResultMsgClass[], g_CasEventMsgClass[];
extern char D_004D92E0[], D_004DCD50[], D_004DCCD0[], D_004DCCB0[], D_004E0840[], D_004E0140[], D_004D9340[];
extern char g_Game[], g_NpcRouteMgr[];
extern unsigned char g_IsMultiplayer;
unsigned char cNPC_Update(cNPC*, const cMessage&);
cMessageName& cMessage_Name(const cMessage*);
cGOBJ* nGobjManager_LookupGOBJ_cObjectIdR(int*);
#if 0 /* merge_units */
void cNPC_SoundHeard(cNPC*, eCause, cGOBJ*);
#endif /* merge_units */
struct Pt1HrNpc; /* merge_units */
struct Pt1HrActor; /* merge_units */
void cNPC_SoundHeard(Pt1HrNpc* self, unsigned char kind, Pt1HrActor* src); /* merge_units */
#define cNPC_SoundHeard(a0, a1, a2) (cNPC_SoundHeard((Pt1HrNpc *)(a0), (unsigned char)(a1), (Pt1HrActor *)(a2))) /* merge_units */

void cStateMachine_ExitStateMessageReceived(void*);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(const void*, void*, int);
#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

cNode* cAIPathData_GetNode(int);
void cNetNPCMsgs_SendMessage(cGOBJ*, int, int, unsigned int, unsigned int, unsigned int, int);
int cPathNavigator_NewPath(cPathNavigator*);
void cNPC_SetMoveMode(cNPC*, int, int);
#if 0 /* merge_units */
void cNPC_DoAction(cNPC*, int, int, float);
#endif /* merge_units */
void cNPC_DoAction(void*, int, int, float); /* merge_units */
#define cNPC_DoAction(a0, a1, a2, a3) (cNPC_DoAction((void *)(a0), (a1), (a2), (a3))) /* merge_units */

float Libc_Atan2f(float, float);
void* cSystemContainer_GetSystem(void*, void*);
int cPathSystem_IsRequestBeingProcessed(void*, cGOBJ*);
void cPathNavigator_Request_int(cPathNavigator*, int);
void cNPC_MoveToCoverNode(cNPC*);
unsigned char cNPC_HandleCASEvent(cNPC*, const cMessage&);
unsigned char cSystem_HandleMessage(cNPC*, const cMessage&);
}

/* 128-bit cVector copy: lq/sq have no C equivalent in MW (a struct copy is split into words). */
static inline void CopyV(cVector* d, const cVector* s)
{
    cVector* dp = d; const cVector* sp = s;
    __int128 t;
    __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(sp));
    __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(dp) : "memory");
}
struct cCharActionMsg;
static inline void QueueAction(const cCharActionMsg& m, cGOBJ* g);
static inline float Heading(const cVector& d) { return Libc_Atan2f(-d.x, d.y); }
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB : cMessage {
    MsgB(void* n) { cMessage_ctor_cMessageNameR(this, n); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct cAIModeChangeMsg : MsgB {
    eMode aiMode;
    cAIModeChangeMsg(eMode m) : MsgB(D_004EA3E8) { vt = D_004D92E0; aiMode = m; }
    __declspec(weak) __declspec(MSG_DTOR) ~cAIModeChangeMsg() { vt = D_004D92E0; }
};
struct cAINodeMsg : MsgB {
    cNode* node; cNode* nextNode;
    cAINodeMsg(void* n, cNode* a, cNode* b) : MsgB(n) { vt = D_004DCD50; node = a; nextNode = b; mDestinationType = 2; }
    __declspec(weak) __declspec(MSG_DTOR) ~cAINodeMsg() { vt = D_004DCD50; }
};
struct cAIWaypointReachedMsg : cAINodeMsg {
    cAIWaypointReachedMsg(cNode* a, cNode* b) : cAINodeMsg(g_ScriptAIWaypointReachedMsgKey, a, b) { vt = D_004DCCD0; }
    __declspec(weak) __declspec(MSG_DTOR) ~cAIWaypointReachedMsg() { vt = D_004DCCD0; }
};
struct cAIDestinationReachedMsg : cAINodeMsg {
    cAIDestinationReachedMsg(cNode* a, cNode* b) : cAINodeMsg(g_ScriptAIDestinationReachedMsgKey, a, b) { vt = D_004DCCB0; }
    __declspec(weak) __declspec(MSG_DTOR) ~cAIDestinationReachedMsg() { vt = D_004DCCB0; }
};
struct cCharActionMsg : MsgB {
    int mAction; unsigned char mParamType;
    cCharActionMsg(int a, unsigned char t) : MsgB(g_ActorActionMsgClass) { vt = D_004E0840; mAction = a; mParamType = t; }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg() { vt = D_004E0840; }
};
struct cCharActionMsg_Vector : cCharActionMsg {
    char pad2C[4];
    cVector mVector;
    cCharActionMsg_Vector(int a, const cVector& v) : cCharActionMsg(a, 4) { vt = D_004E0140; CopyV(&mVector, &v); }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg_Vector() { vt = D_004E0140; }
};
struct cAIMsg : MsgB {
    eAIID id; int data;
    cAIMsg(eAIID i, int d) : MsgB(D_004EE550) { vt = D_004D9340; id = i; data = d; }
    __declspec(weak) __declspec(MSG_DTOR) ~cAIMsg() { vt = D_004D9340; }
};

static inline void QueueAction(const cCharActionMsg& m, cGOBJ* g)
{
    ((cCharActionMsg&)m).mDestinationType = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
}
struct cCurrentLookAt { char pad[0xC]; int priority; unsigned char use; char pad11[3]; };

struct cNPC {
    virtual void nv0();
    virtual void nv1();
    virtual void nv2();
    virtual void nv3();
    virtual void nv4();
    virtual void nv5();
    virtual void nv6();
    virtual void nv7();
    virtual void nv8();
    virtual void nv9();
    virtual void nv10();
    virtual void nv11();
    virtual void nv12();
    virtual void nv13();
    virtual void nv14();
    virtual void nv15();
    virtual void nv16();
    virtual void nv17();
    virtual void nv18();
    virtual void nv19();
    virtual void nv20();
    virtual void nv21();
    virtual void nv22();
    virtual void nv23();
    virtual void nv24();
    virtual void nv25();
    virtual void nv26();
    virtual void nv27();
    virtual void nv28();
    virtual void nv29();
    virtual void nv30();
    virtual void nv31();
    virtual unsigned char IsLocalControlled();
    virtual void nv33();
    virtual void nv34();
    virtual void nv35();
    virtual void nv36();
    virtual void nv37();
    virtual void nv38();
    virtual eMoveMode GetMoveMode();
    virtual void nv40();
    virtual void nv41();
    virtual void nv42();
    virtual void nv43();
    virtual void nv44();
    virtual void nv45();
    virtual void nv46();
    virtual void nv47();
    virtual void nv48();
    virtual void nv49();
    virtual void nv50();
    virtual void SelectTravelMode(int m, int p);
    virtual void nv52();
    virtual void nv53();
    virtual void nv54();
    virtual void nv55();
    virtual void nv56();
    virtual void nv57();
    virtual void nv58();
    virtual void nv59();
    virtual void nv60();
    virtual void nv61();
    virtual void nv62();
    virtual void nv63();
    virtual void nv64();
    virtual void nv65();
    virtual void nv66();
    virtual void nv67();
    virtual void nv68();
    virtual void nv69();
    virtual void nv70();
    virtual void nv71();
    virtual void nv72();
    virtual void nv73();
    virtual void nv74();
    virtual void nv75();
    virtual void nv76();
    virtual void nv77();
    virtual void nv78();
    virtual void nv79();
    virtual float GetTravelSpeed(int s);
    virtual void nv81();
    virtual void nv82();
    virtual void nv83();
    virtual void ResumeMovement();
    char pad04[0x30 - 4];
    cGOBJ* mGobj;
    char pad34[0x44 - 0x34];
    int currentState;               /* 0x44 stateMachine */
    char pad48[0x60 - 0x48];
    float travelSpeed;              /* 0x60 */
    int travelSpeedPriority;        /* 0x64 */
    int losCheckFlag;               /* 0x68 */
    char pad6C[0x9C - 0x6C];
    int crouchPriority;             /* 0x9C */
    char padA0[0xBC - 0xA0];
    int chunks[1];                  /* 0xBC pathRegionGroupList */
    char padC0[0xE0 - 0xC0];
    int attackFromCoverNodeIndex;   /* 0xE0 */
    int coverNodeIndex;             /* 0xE4 */
    char padE8[0x114 - 0xE8];
    int pathLinkType;               /* 0x114 */
    char pad118[0x124 - 0x118];
    int actionFlags;                /* 0x124 */
    char pad128[0x13F - 0x128];
    eMode nodeRequestMode;          /* 0x13F */
    eMode nodeMode;                 /* 0x140 */
    unsigned char targetLOSToDestinationNode : 1;
    unsigned char lookAroundFlag : 1;
    unsigned char deactivateDead : 1;
    unsigned char inHotbox : 1;
    unsigned char grenadeStopOnTarget : 1;
    unsigned char firstActivation : 1;
    unsigned char usingPathTravelSpeed : 1;
    unsigned char useActivationRadius : 1;
    char pad142[0x160 - 0x142];
    int lookAtPriority;             /* 0x160 */
    unsigned char lookWith;         /* 0x164 */
    unsigned char sortLookAtList;
    unsigned char newLookAtListData;
    unsigned char newLookAtAvailable;
    unsigned char stopForLookAt;    /* 0x168 */
    char pad169[3];
    cCurrentLookAt currentLookAt[3];/* 0x16C */
    char pad1A8[0x1B0 - 0x1A8];
    cPathNavigator* pathNavigator;  /* 0x1B0 */
    char pad1B4[0x1C0 - 0x1B4];
    float closestDistanceReachedToPathNode;     /* 0x1C0 */
    float closestDistanceReachedToPathNodeTime; /* 0x1C4 */

    void SetTravelSpeed(float speed, int priority)
    {
        if (travelSpeedPriority <= priority) {
            travelSpeed = speed;
            travelSpeedPriority = priority;
            usingPathTravelSpeed = 1;
        }
    }
    bool IsLink(int t) { return pathLinkType == t; }
    void StopLookAt(int priority)
    {
        int i = lookWith;
        if (currentLookAt[i].priority <= priority) {
            if (currentLookAt[i].priority <= priority) {
                currentLookAt[i].use = 0;
                currentLookAt[i].priority = 0;
            }
            newLookAtListData = 0;
            lookAtPriority = 0;
            if (stopForLookAt) ResumeMovement();
        }
    }
    bool InPathRegion(int nodeIndex)
    {
        bool r = true;
        if (nodeIndex >= 0) {
            int g = cAIPathData_GetNode(nodeIndex)->groupIndex;
            r = ((chunks[g / 32] >> (g & 31)) & 1) != 0;
        }
        return r;
    }
    void RequestPath(int nodeIndex)
    {
        if (!cPathSystem_IsRequestBeingProcessed(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), mGobj) && InPathRegion(nodeIndex))
            cPathNavigator_Request_int(pathNavigator, nodeIndex);
    }
};

extern "C" unsigned char cNPC_HandleMessage(cNPC* self, const cMessage& message)
{
    unsigned char res;
    cGOBJ& human = *self->mGobj;
    if (human.IsActiveAndNotStreaming()) {
        unsigned char messageHandledByAIState = cNPC_Update(self, message);
        if (self->mGobj->State() != 3 && cMessage_Name(&message) == *(cMessageName*)D_004EE550) {
            const cAIMessage& msg = (const cAIMessage&)message;
            if ((unsigned char)msg.id == 7) {
                int objectID = msg.data;
                cGOBJ* gobj = nGobjManager_LookupGOBJ_cObjectIdR(&objectID);
                if (gobj) {
                    eCause type = (eCause)msg.data2;
                    if (type == 2 || type == 3 || type == 4 || type == 7)
                        cNPC_SoundHeard(self, type, gobj);
                }
            } else if ((unsigned char)msg.id == 4) {
                self->StopLookAt(50);
            } else if ((unsigned char)msg.id == 1) {
                cStateMachine_ExitStateMessageReceived(&self->currentState);
                QueueMessage_cMessageR_cSystemP_int(&cAIModeChangeMsg((eMode)self->currentState), self, 0);
            }
        } else if (cMessage_Name(&message) == *(cMessageName*)D_004ED9B8) {
            const cPathMessage& msg = (const cPathMessage&)message;
            if ((unsigned char)msg.id == 5) {
                cNode* node = cAIPathData_GetNode(msg.data);
                cNode* nextNode = 0;
                if (self->pathNavigator->nextNodeIndex >= 0)
                    nextNode = cAIPathData_GetNode(self->pathNavigator->nextNodeIndex);
                if (self->GetMoveMode() == 0) {
                    cPathNavigator* pn = self->pathNavigator;
                    pn->nodeIndex = msg.data;
                }
                if (g_IsMultiplayer) {
                    if (self->IsLocalControlled() == 1) {
                        QueueMessage_cMessageR_cSystemP_int(&cAIWaypointReachedMsg(node, nextNode), self->mGobj, 0);
                        cNetNPCMsgs_SendMessage(self->mGobj, 45, 4, node->nodeListIndex, 0, 0, 0);
                        self->closestDistanceReachedToPathNode = 999999.0f;
                        self->closestDistanceReachedToPathNodeTime = 0.0f;
                    }
                } else {
                    QueueMessage_cMessageR_cSystemP_int(&cAIWaypointReachedMsg(node, nextNode), self->mGobj, 0);
                    self->closestDistanceReachedToPathNode = 999999.0f;
                    self->closestDistanceReachedToPathNodeTime = 0.0f;
                }
            } else if ((unsigned char)msg.id == 2) {
                if (!messageHandledByAIState) {
                    self->nodeMode = self->nodeRequestMode;
                    self->nodeRequestMode = MODE_PATROL;
                    if (cPathNavigator_NewPath(self->pathNavigator)) {
                        cNPC_SetMoveMode(self, 1, 20);
                        self->SelectTravelMode(self->nodeMode, 10);
                    }
                }
            } else if ((unsigned char)msg.id == 7) {
                if (!messageHandledByAIState) {
                    if (self->travelSpeedPriority == 20)
                        self->travelSpeedPriority = 0;
                    self->actionFlags &= ~2;
                    if (!self->IsLink(msg.data)) {
                        if (self->pathLinkType == 6) {
                            cNPC_DoAction(self, 9, 10, 0.0f);
                            if (self->crouchPriority <= 10)
                                self->crouchPriority = 0;
                        } else if (self->pathLinkType == 8) {
                            cNPC_DoAction(self, 10, 0, 0.0f);
                        } else if (self->pathLinkType == 3) {
                            QueueAction(cCharActionMsg(30, 0), self->mGobj);
                        }
                        self->pathLinkType = msg.data;
                    }
                    if (self->pathLinkType == 6) {
                        cNPC_DoAction(self, 1, 10, 0.0f);
                    } else if (self->pathLinkType == 8) {
                        cNPC_DoAction(self, 4, 0, 0.0f);
                        self->SetTravelSpeed(self->GetTravelSpeed(3), 20);
                    } else if (self->pathLinkType == 5) {
                        QueueAction(cCharActionMsg_Vector(21, self->pathNavigator->nextDestination), self->mGobj);
                    } else if (self->pathLinkType == 12) {
                        cVector destination;
                        CopyV(&destination, &self->pathNavigator->nextDestination);
                        destination.w = Heading(self->pathNavigator->pathDelta);
                        QueueAction(cCharActionMsg_Vector(22, destination), self->mGobj);
                    } else if (self->pathLinkType == 13) {
                        QueueAction(cCharActionMsg_Vector(21, self->pathNavigator->nextDestination), self->mGobj);
                    } else if (self->pathLinkType == 4 || self->pathLinkType == 11 || self->pathLinkType == 3) {
                        cNPC_SetMoveMode(self, 2, 20);
                    } else if (self->pathNavigator->onPatrolPath) {
                        if (self->pathLinkType == 2) {
                            self->SetTravelSpeed(self->GetTravelSpeed(3), 20);
                        } else if (self->pathLinkType == 1) {
                            self->SetTravelSpeed(self->GetTravelSpeed(1), 20);
                        }
                    }
                }
            } else if ((unsigned char)msg.id == 6) {
                cNode* node = 0;
                int nodeIndex = msg.data;
                cNPC_SetMoveMode(self, 0, 20);
                self->pathLinkType = 0;
                if (self->travelSpeedPriority <= 50)
                    self->travelSpeedPriority = 0;
                if (nodeIndex >= 0) {
                    self->pathNavigator->nodeIndex = nodeIndex;
                    node = cAIPathData_GetNode(msg.data);
                }
                if (g_IsMultiplayer) {
                    if (self->IsLocalControlled() == 1) {
                        QueueMessage_cMessageR_cSystemP_int(&cAIDestinationReachedMsg(node, 0), self->mGobj, 0);
                        if (nodeIndex >= 0)
                            cNetNPCMsgs_SendMessage(self->mGobj, 45, 4, nodeIndex, 0, 0, 0);
                    }
                } else {
                    QueueMessage_cMessageR_cSystemP_int(&cAIDestinationReachedMsg(node, 0), self->mGobj, 0);
                }
            } else if ((unsigned char)msg.id == 0) {
                if (!messageHandledByAIState) {
                    if (msg.data >= 0) {
                        if (self->nodeRequestMode == MODE_TAKECOVER) {
                            self->coverNodeIndex = msg.data;
                            self->attackFromCoverNodeIndex = msg.companionData;
                        } else {
                            self->attackFromCoverNodeIndex = msg.data;
                            self->coverNodeIndex = msg.companionData;
                        }
                        self->RequestPath(msg.data);
                        self->targetLOSToDestinationNode = 0;
                    }
                }
            } else if ((unsigned char)msg.id == 4) {
                if (!messageHandledByAIState)
                    cNPC_SetMoveMode(self, 2, 20);
            }
        } else if (self->mGobj->State() != 3 && cMessage_Name(&message) == *(cMessageName*)g_LosResultMsgClass) {
            const cLosResultReadyMessage& msg = (const cLosResultReadyMessage&)message;
            if (self->nodeRequestMode == MODE_LOSCHECK) {
                if (msg.mIsLosBlocked && self->coverNodeIndex >= 0) {
                    self->RequestPath(self->coverNodeIndex);
                    self->targetLOSToDestinationNode = 0;
                    self->nodeRequestMode = MODE_TAKECOVER;
                } else {
                    self->coverNodeIndex = -1;
                    cNPC_MoveToCoverNode(self);
                }
            } else if (self->targetLOSToDestinationNode != (unsigned char)!msg.mIsLosBlocked) {
                self->targetLOSToDestinationNode = !msg.mIsLosBlocked;
                QueueMessage_cMessageR_cSystemP_int(&cAIMsg((eAIID)6, (unsigned char)!msg.mIsLosBlocked), self, 0);
            }
            self->losCheckFlag &= ~1;
        } else if (self->mGobj->State() != 3 && cMessage_Name(&message) == *(cMessageName*)g_CasEventMsgClass) {
            return cNPC_HandleCASEvent(self, message);
        } else {
            res = cSystem_HandleMessage(self, message);
        }
    }
    return res;
}
#undef cNPC_SoundHeard /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNPC_DoAction /* merge_units */
static inline void merge_flush_func_00151D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00151D30 */

/* merge_units: begin func_00152B10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIDestinationReachedMsg_dtor, D_004DCCB0, D_004DCD50, cMessage_dtor)
static inline void merge_flush_func_00152B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00152B10 */

/* merge_units: begin func_00152B80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIWaypointReachedMsg_dtor, D_004DCCD0, D_004DCD50, cMessage_dtor)
static inline void merge_flush_func_00152B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00152B80 */

/* merge_units: begin func_00152BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAINodeMsg_dtor, D_004DCD50, cMessage_dtor)
static inline void merge_flush_func_00152BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00152BF0 */

/* merge_units: begin func_00152C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cNPC_SoundHeard: react to a heard event (raise awareness of the source, start an investigate slot) */
struct Pt1HrActor;
struct Pt1HrPerc;
struct Pt1HrCtrl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsPlayerControlled();
    virtual int IsAiControlled();
};
struct Pt1HrHandle { Pt1HrActor* target; int serial; };
struct Pt1HrPerc {
    char pad0[0x1C];
    int alertLevel;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    char pad21[0x40 - 0x21];
    Pt1HrHandle focus;
};
struct Pt1HrActor {
    char pad0[0xC];
    int serial;
    char pad10[0x58 - 0x10];
    Pt1HrCtrl* ctrl;
};
struct Pt1HrCtrlData { char pad0[0x1AC]; Pt1HrPerc* perc; };
struct Pt1HrSlot {
    Pt1HrActor* target;
    int serial;
    float weight;
    int prio;
    unsigned char active;
    unsigned char fresh;
    char pad12[2];
};
struct Pt1HrReaction { char pad0[0x39]; unsigned char investigate; };
struct Pt1HrNpc {
    VPAD16(a) VPAD8(b) VPAD2(c)
    virtual int CanSee(Pt1HrActor* a);
    VPAD8(d) VPAD4(e) VPAD1(f)
    virtual int ReleaseSlot(int slot);
    VPAD16(g) VPAD8(h) VPAD4(k) VPAD2(i) VPAD1(j)
    virtual void Investigate(Pt1HrActor* a, int prio, float weight);
    char pad4[0x30 - 4];
    Pt1HrActor* actor;
    char pad34[0x80 - 0x34];
    float hearing;
    char pad84[0x164 - 0x84];
    unsigned char curSlot;
    char pad165[0x16C - 0x165];
    Pt1HrSlot slots[2];
    char pad194[0x1AC - 0x194];
    Pt1HrPerc* perc;
};
extern "C" {
extern void* g_LocalPlayer;
Pt1HrActor* cGobjController_GetTarget(void* players);
#if 0 /* merge_units */
void cAITarget_AddAwareness(Pt1HrPerc* p, Pt1HrActor* a, int kind, float amount);
#endif /* merge_units */
void cAITarget_AddAwareness(void* p, void* src, int kind, float amt); /* merge_units */
#define cAITarget_AddAwareness(a0, a1, a2, a3) (cAITarget_AddAwareness((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

float cAITarget_GetAwarenessThreat(Pt1HrPerc* p, Pt1HrActor* a);
Pt1HrReaction* cAITarget_GetAwareness(Pt1HrPerc* p, Pt1HrActor* a);
}
static inline Pt1HrActor* Pt1Hr_GetB(Pt1HrPerc* p)
{
    Pt1HrActor* t = p->focus.target;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != p->focus.serial)
            ok = false;
    return ok ? t : 0;
}

static inline Pt1HrActor* Pt1Hr_GetC(Pt1HrPerc* p)
{
    Pt1HrActor* t = p->focus.target;
    if (t && t->serial != p->focus.serial)
        t = 0;
    return t;
}
extern "C" void cNPC_SoundHeard(Pt1HrNpc* self, unsigned char kind, Pt1HrActor* src)
{
    Pt1HrActor* who;
    Pt1HrActor* tgt;
    Pt1HrPerc* p;
    int none;
    if (!src)
        return;
    who = 0;
    if (kind == 4 && src->ctrl) {
        if (src->ctrl->IsPlayerControlled()) {
            who = cGobjController_GetTarget(g_LocalPlayer);
            if (who && who != self->actor)
                cAITarget_AddAwareness(self->perc, who, 2, 0.0f);
        } else if (src->ctrl->IsAiControlled()) {
            who = Pt1Hr_GetB(((Pt1HrCtrlData*)src->ctrl)->perc);
            if (who && who != self->actor)
                cAITarget_AddAwareness(self->perc, who, 2, 0.0f);
        }
    }
    p = self->perc;
    if (!(p->alertLevel < 0x32 && (!Pt1Hr_GetB(p) || cAITarget_GetAwarenessThreat(p, Pt1Hr_GetC(p)) <= 0.1f)) && kind != 7)
        return;
    tgt = 0;
    if (self->CanSee(src))
        tgt = src;
    else if (who && self->CanSee(who))
        tgt = who;
    if (!tgt)
        return;
    p = self->perc;
    {
        bool busy = p->bit0 && p->bit2;
        if (busy)
            return;
    }
    if (!(self->hearing > 5.0f))
        return;
    {
        Pt1HrReaction* r = cAITarget_GetAwareness(p, tgt);
        if (r && r->investigate) {
            if (self->slots[self->curSlot].prio < 0x15) {
                if (self->ReleaseSlot(*(signed char*)&self->curSlot)) {
                    int* pp;
                    int off = self->curSlot * (int)sizeof(Pt1HrSlot);
                    char* b = (char*)(off + (int)self);
                    pp = (int*)(b + 0x178);
                    if (*pp < 0x15) {
                        b[0x17C] = 0;
                        *pp = 0;
                    }
                }
                self->curSlot = 1;
                self->slots[1].target = tgt;
                self->slots[1].serial = *(tgt ? &tgt->serial : (none = -1, &none));
                self->slots[1].active = 1;
                self->slots[1].fresh = 1;
                self->slots[1].weight = 1.0f;
                self->slots[1].prio = 0x14;
            }
        } else {
            self->Investigate(tgt, 0x14, 1.0f);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00152C50(void) {}
#undef cAITarget_AddAwareness /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00152C50 */

/* merge_units: begin func_00152FD0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; char pad10[0x1C]; unsigned char f2C; unsigned char f2D; unsigned char f2E; } Tgt_52FD0;
typedef struct { char pad[0xC]; int id; char pad10[0x114]; Tgt_52FD0* target; int serial; } Src_52FD0;
typedef struct { char pad[0x30]; Tgt_52FD0* f30; char pad34[0x10]; int mode; char pad48[0xAC]; int fF4; char padF8[0xB4]; void* perc; } Npc_52FD0;
extern void cAITarget_AddAwareness(void* p, void* src, int kind, float amt);

extern unsigned char cGrenade_GetDamageType(Src_52FD0* s);
#if 0 /* merge_units */
extern void cNPC_DoAction(Npc_52FD0* n, int a, int b, float t);
#endif /* merge_units */
#define cNPC_DoAction(a0, a1, a2, a3) (cNPC_DoAction((void *)(a0), (a1), (a2), (a3))) /* merge_units */

extern unsigned char cStateMachine_ChangeState(int* p, int v, int pri);
static inline void Notice_52FD0(Npc_52FD0* self, Src_52FD0* src)
{
    Tgt_52FD0* t;
    unsigned char ok;
    unsigned char isNull;
    Tgt_52FD0* p;
    t = src->target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != src->serial)
            ok = 0;
    p = ok ? t : 0;
    if (p) {
        int v = p->f2D && p->f2C && !p->f2E;
        if (v) {
            if ((isNull || t->serial == src->serial ? t : 0) != self->f30)
                cAITarget_AddAwareness(self->perc, p, 2, 0.0f);
        }
    }
}
void cNPC_Sound(Npc_52FD0* self, int kind, Src_52FD0* src, float amt)
{
    if (!src)
        return;
    if ((unsigned char)kind == 5) {
        if (self->mode != 10) {
            Notice_52FD0(self, src);
            if (cGrenade_GetDamageType(src) == 3) {
                cNPC_DoAction(self, 8, 0, 5.0f);
                return;
            }
            if (cStateMachine_ChangeState(&self->mode, 10, 50))
                self->fF4 = src->id;
        }
    } else {
        cAITarget_AddAwareness(self->perc, src, kind, amt);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00152FD0(void) {}
#undef cNPC_DoAction /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00152FD0 */
