/* 00162080 cPathRequest::Update() (path.cc), rebuilt from the prototype DWARF/.line data.
 * Statics: D_004EA798 cellPoolIndex, D_004EA7B0 cellPool, D_004ED9F0 nodeRequest, D_004EE010 destinationNodeList,
 * D_004ED9D0 losRequestMode. Message temporaries are C++ classes with weak inline destructors (.dtors_drop). */
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
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { CopyV(this, &o); }
    cVector& operator=(const cVector& o) { CopyV(this, &o); return *this; }
    cVector& operator-=(const cVector& b) { SubB(this, this, &b); return *this; }
    /* VU0 vsub: no C equivalent */
    static inline void SubB(cVector* d0, const cVector* a0, const cVector* b0)
    {
        cVector* d = d0; const cVector* a = a0; const cVector* bp = b0;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(bp) : "memory");
    }
} __attribute__((aligned(16)));

/* VU0 vsub: no C equivalent */
static inline void SubC(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline cVector operator-(const cVector& a, const cVector& b)
{
    cVector r;
    SubC(&r, &a, &b);
    return r;
}
/* abs.s has no C spelling in MW */
static inline float Fabs(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
/* VU0 length (vsqrt/vwaitq/qmfc2): no C equivalent */
static inline float Len1(const cVector* p0)
{
    float ret = 0.0f;
    int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2 %1, $vf4; mtc1 %1, %0" : "+f"(ret), "=&r"(t) : "r"(p0) : "memory");
    return ret;
}
static inline float Length(cVector v) { return Len1(&v); }

enum eRequestPriority { PRIORITY_IMMEDIATE = 0, PRIORITY_NEXTFRAME = 1, PRIORITY_QUEUEUP = 2 };
struct cObjectId { int mId; cObjectId() { mId = -1; } bool operator==(const cObjectId& o) const { return mId == o.mId; } };
struct cSystem;
struct cMessageName;
struct cMessage;
struct cGobjController {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual unsigned char GetControllerType();
};
struct cGOBJ {
    void* vt;
    char pad04[0xC - 4];
    cObjectId mObjectId;
    char pad10[0x58 - 0x10];
    cGobjController* mController;
};
struct cSafePtr {
    cGOBJ* ptr;
    cObjectId id;
    bool IsValid() const { return !ptr || ptr->mObjectId == id; }
    cGOBJ* Get() const { return IsValid() ? ptr : 0; }
    void operator=(cGOBJ* g) { ptr = g; id = g ? g->mObjectId : cObjectId(); }
};
struct cLosSystem {
    virtual void d0();
    virtual void HandleMessage(const cMessage& m);
};
struct tNodeLink { int index; int type; };
struct __wrap_iterator { tNodeLink* it_; };
struct cDestList;
struct cNodeRequest;
struct cPathCell;
struct cPriorityQueue;
struct cNode;
extern "C" {
extern int D_004EA798;
extern cPathCell D_004EA7B0[];
extern cNodeRequest D_004ED9F0;
extern cDestList D_004EE010;
extern unsigned char D_004ED9D0;
extern char g_Game[], g_LosCheckService[], g_NpcRouteMgr[];
extern char g_LosRequestMsgClass[], D_004D9180[], D_004ED9B8[], D_004D9760[];
extern const int D_00489FF8;
extern float g_LevelFarDistance;
void cArray_FixedCapacity_int_64_ResizeActual(cDestList*, unsigned int, const int*);
void cPathRequest_AddStartNodeToList(struct cPathRequest*, int);
void* cSystemContainer_GetSystem(void*, void*);
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
void QueueMessage_cMessageR_cSystemP_int(const void*, void*, int);
cNode* cAIPathData_GetNode(int);
unsigned char cNodeRequest_Update(cNodeRequest*);
cPathCell* cPriorityQueue_cPathCell_Pop(cPriorityQueue*);
void cPriorityQueue_cPathCell_Push(cPriorityQueue*, cPathCell*);
tNodeLink* std_vector_imp_tNodeLink_begin_void_2(void*);
tNodeLink* std_vector_imp_tNodeLink_end_void_2(void*);
__wrap_iterator std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(void*, tNodeLink* const&);
cVector cNode_GetLoc(cNode*);
}
struct Iterator {
    __wrap_iterator mIterator;
    Iterator() {}
    Iterator(const __wrap_iterator& i) { mIterator.it_ = i.it_; }
    bool operator==(const Iterator& o) const { return mIterator.it_ == o.mIterator.it_; }
    bool operator!=(const Iterator& o) const { return !(*this == o); }
    tNodeLink* operator->() { return mIterator.it_; }
    void operator++() { mIterator.it_++; }
};
struct cVectorL {
    int imp[3];
    __wrap_iterator begin() { return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(this, std_vector_imp_tNodeLink_begin_void_2(this)); }
    __wrap_iterator end() { return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(this, std_vector_imp_tNodeLink_end_void_2(this)); }
};
struct cArrayL {
    cVectorL mArray;
    unsigned char mCanExpand;
    Iterator begin() { return Iterator(mArray.begin()); }
    Iterator end() { return Iterator(mArray.end()); }
};
struct cNode {
    char pad[0x64];
    int type;
    cArrayL links;
    int nodeListIndex;
    int groupIndex;
};
struct cPathNavigator { char pad[0x50]; int nextNodeIndex; int previousNodeIndex; };
struct cNPC { char pad[0x1B0]; cPathNavigator* pathNavigator; };
struct cPathCell {
    int pad0;
    cPathCell* next;
    cPathCell* prev;
    float priority;
    cPathCell* parent;
    int nodeIndex;
    float costFromStart;
    unsigned char listMembership;
    float Cost() { return costFromStart; }
    int Cost2() { return nodeIndex; }
};
struct cStartNode { int pad0; cPathCell* next; cPathCell* prev; };
struct cPriorityQueue {
    int pad0;
    cStartNode startNode;
    cStartNode endNode;
    int size;
    void Clear()
    {
        startNode.next = (cPathCell*)&endNode;
        startNode.prev = (cPathCell*)&startNode;
        endNode.next = (cPathCell*)&endNode;
        endNode.prev = (cPathCell*)&startNode;
        size = 0;
    }
    cPathCell* Find(int nodeIndex)
    {
        cPathCell* found = 0;
        for (cPathCell* c = startNode.next; c != (cPathCell*)&endNode; c = c->next) {
            if (nodeIndex == c->nodeIndex) {
                found = c;
                break;
            }
        }
        return found;
    }
    void Remove(cPathCell* c)
    {
        cPathCell* next = c->next;
        cPathCell* prev = c->prev;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};
struct cPath {
    cVector destination;
    int destinationNodeIndex;
    char pad14[0x20 - 0x14];
    int* nodes;
    int capacity;
    int size;
    void SetDNI(int n) { destinationNodeIndex = n; }
    void Add(int n) { nodes[size] = n; size++; }
};
struct cNodePickerParameters {
    float minimumDistanceFromTarget;
    float maximumDistanceFromTarget;
    unsigned char lookForCompanionNode;
    cNodePickerParameters() { minimumDistanceFromTarget = 0.0f; maximumDistanceFromTarget = 0.0f; lookForCompanionNode = 0; }
};
struct cPathSystemRequest {
    cSafePtr gobj;
    int losHandle;
    unsigned char type;
    unsigned char newRequestFlag;
    unsigned char requestDone;
    void SetId2(cGOBJ* g) { gobj.id = g ? g->mObjectId : cObjectId(); }
    void SetId1(cGOBJ* g) { SetId2(g); }
    void Reset(cGOBJ* g, unsigned char t) { requestDone = 0; gobj.ptr = g; newRequestFlag = 1; type = t; SetId1(g); if (g) losHandle = g->mObjectId.mId; }
};
struct cNodeRequest : cPathSystemRequest {
    char pad10[0x430 - 0x10];
    cNodePickerParameters evaluation;
    cVector position;
    cVector targetPosition;
    float distanceToTargetLimit;
    int groupIndex;
    int typeMask;
    unsigned char losCheck;
    int nodeIndexToExclude;
    unsigned char nodeMode;
    int result;
    int companionResult;
    unsigned char checkingCompanionLOS;
    unsigned char checkAllNodes;
    unsigned char pathNodeRequest;
    void SetDist(float d) { distanceToTargetLimit = d; }
};
struct cDestList {
    unsigned int size;
    int array[64];
    int* begin() { return array; }
    int* end() { return &array[size]; }
};


#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct cMessage {
    void* vt;
    char pad04[0x20 - 4];
    unsigned char mDestinationType;
    cMessage(void* n) { cMessage_ctor_cMessageNameR(this, n); }
    __declspec(weak) __declspec(MSG_DTOR) ~cMessage() { cMessage_dtor(this, 0); }
};
struct cLosRequestMessage : cMessage {
    void* mRequester;
    int* mReturnHandle;
    void* mResult;
    cVector mLosStartPoint;
    cVector mLosVector;
    cGOBJ* mExcludedGobj0;
    cGOBJ* mExcludedGobj1;
    int mIgnoreFlags;
    eRequestPriority mPriority;
    cLosRequestMessage(void* req, int* handle, void* result, const cVector& start, const cVector& vec, cGOBJ* e0, cGOBJ* e1, int flags, eRequestPriority prio)
        : cMessage(g_LosRequestMsgClass)
    {
        vt = D_004D9180;
        mRequester = req;
        mReturnHandle = handle;
        mResult = result;
        mLosStartPoint = start;
        mLosVector = vec;
        mExcludedGobj0 = e0;
        mExcludedGobj1 = e1;
        mIgnoreFlags = flags;
        mPriority = prio;
        mLosStartPoint.w = 1.0f;
        mLosVector.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~cLosRequestMessage() { vt = D_004D9180; }
};
struct cPathMessage : cMessage {
    signed char id;
    int data;
    int companionData;
    cPathMessage(signed char i, int d) : cMessage(D_004ED9B8) { vt = D_004D9760; id = i; data = d; }
    __declspec(weak) __declspec(MSG_DTOR) ~cPathMessage() { vt = D_004D9760; }
};


struct cPathRequest : cPathSystemRequest {
    unsigned char pathMode;
    unsigned char pathFound;
    unsigned char destinationOnNode;
    cPath* path;
    char pad18[8];
    cVector destinationPosition;
    cVector startPosition;
    int startNodeIndex;
    int startNodeIndex2;
    int startGroupIndex;
    int destinationNodeIndex;
    int destinationGroupIndex;
    int cellPoolIndexRestore;
    cPriorityQueue openList;
    cPriorityQueue closedList;

    bool IsDestGroup(int g) { return destinationGroupIndex == g; }
    bool IsDestNode(int n) { return destinationNodeIndex == n; }
    bool IsStartNode(int n) { return startNodeIndex == n; }
    cSystem* Target()
    {
        cGOBJ* g = gobj.Get();
        return g->mController == 0 ? (cSystem*)g : (cSystem*)g->mController;
    }
};

#define FAIL() do { D_004ED9F0.requestDone = 1; QueueMessage_cMessageR_cSystemP_int(&cPathMessage(3, -1), self->Target(), 1); } while (0)
static inline cPathCell* AllocCell()
{
    cPathCell* c = 0;
    if (D_004EA798 < 400) c = &D_004EA7B0[D_004EA798++];
    return c;
}

extern "C" unsigned char cPathRequest_Update(cPathRequest* self)
{
    unsigned char doneFlag = 0;
    if (self->newRequestFlag) {
        self->newRequestFlag = 0;
        self->pathFound = 0;
        if (self->cellPoolIndexRestore == 0)
            self->cellPoolIndexRestore = D_004EA798;
        self->openList.Clear();
        self->closedList.Clear();
        cArray_FixedCapacity_int_64_ResizeActual(&D_004EE010, 0, &D_00489FF8);
        if (self->startNodeIndex >= 0) {
            cPathRequest_AddStartNodeToList(self, self->startNodeIndex);
            if (self->startNodeIndex2 >= 0) {
                cPathRequest_AddStartNodeToList(self, self->startNodeIndex2);
                self->startNodeIndex = -1;
            }
            if (self->destinationNodeIndex >= 0) {
                self->pathMode = 3;
            } else {
                self->pathMode = 1;
            }
        } else {
            if (self->startGroupIndex == self->destinationGroupIndex && Fabs(self->startPosition.z - self->destinationPosition.z) < 2.6f) {
                self->pathMode = 2;
                cVector targetBonePosition = self->destinationPosition;
                targetBonePosition.z += 2.6f;
                cLosSystem& losManager = *(cLosSystem*)cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                cVector delta = self->startPosition;
                eRequestPriority priority = PRIORITY_QUEUEUP;
                delta -= self->destinationPosition;
                losManager.HandleMessage(cLosRequestMessage(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), &self->losHandle, 0, targetBonePosition, delta, 0, 0, 4, priority));
                D_004ED9D0 = 1;
            } else {
                self->pathMode = 0;
                if (self->gobj.Get()->mController && (self->gobj.Get()->mController->GetControllerType() == 1 || self->gobj.Get()->mController->GetControllerType() == 2)) {
                    cNPC* npc = (cNPC*)self->gobj.Get()->mController;
                    if (npc->pathNavigator->nextNodeIndex >= 0) {
                        cNode& node = *cAIPathData_GetNode(npc->pathNavigator->nextNodeIndex);
                        if (node.type & 0x80)
                            cPathRequest_AddStartNodeToList(self, npc->pathNavigator->nextNodeIndex);
                    }
                    if (npc->pathNavigator->previousNodeIndex >= 0) {
                        cNode& node = *cAIPathData_GetNode(npc->pathNavigator->previousNodeIndex);
                        if (node.type & 0x80)
                            cPathRequest_AddStartNodeToList(self, npc->pathNavigator->previousNodeIndex);
                    }
                }
            }
            D_004ED9F0.position = self->startPosition;
            D_004ED9F0.targetPosition = self->startPosition;
            D_004ED9F0.groupIndex = self->startGroupIndex;
        }
        if (self->pathMode != 3) {
            D_004ED9F0.Reset(self->gobj.Get(), 2);
            D_004ED9F0.evaluation = cNodePickerParameters();
            D_004ED9F0.typeMask = 128;
            D_004ED9F0.losCheck = 1;
            D_004ED9F0.SetDist(g_LevelFarDistance);
            D_004ED9F0.nodeIndexToExclude = -1;
            D_004ED9F0.checkingCompanionLOS = 0;
            D_004ED9F0.checkAllNodes = 1;
            D_004ED9F0.pathNodeRequest = 1;
        }
    }
    if (self->pathMode == 0) {
        if (cNodeRequest_Update(&D_004ED9F0) != 0) {
            if (self->openList.size == 0) {
                FAIL();
                doneFlag = 1;
            } else if (self->destinationNodeIndex >= 0) {
                self->pathMode = 3;
            } else {
                self->pathMode = 1;
            }
            D_004ED9F0.newRequestFlag = 1;
        }
    } else if (self->pathMode == 1) {
        if (D_004ED9F0.newRequestFlag) {
            D_004ED9F0.position = self->destinationPosition;
            D_004ED9F0.targetPosition = self->destinationPosition;
            D_004ED9F0.groupIndex = self->destinationGroupIndex;
            if (self->startNodeIndex2 >= 0)
                D_004ED9F0.typeMask |= 8;
        }
        if (cNodeRequest_Update(&D_004ED9F0) != 0) {
            if (D_004EE010.size == 0) {
                FAIL();
                doneFlag = 1;
            } else {
                self->pathMode = 3;
            }
            D_004ED9F0.newRequestFlag = 1;
        }
    } else if (self->pathMode == 2) {
        if (!D_004ED9F0.newRequestFlag) {
            if (D_004ED9F0.result) {
                self->path->size = 0;
                if (self->destinationNodeIndex >= 0)
                    self->path->Add(self->destinationNodeIndex);
                self->path->destination = self->destinationPosition;
                self->path->SetDNI(self->destinationNodeIndex);
                D_004ED9F0.requestDone = 1;
                QueueMessage_cMessageR_cSystemP_int(&cPathMessage(2, -1), self->Target(), 1);
                doneFlag = 1;
            } else {
                self->pathMode = 0;
                D_004ED9F0.newRequestFlag = 1;
            }
        }
    } else {
        while (self->openList.size != 0) {
            cPathCell* cell = cPriorityQueue_cPathCell_Pop(&self->openList);
            cNode* node = cAIPathData_GetNode(cell->nodeIndex);
            if (self->IsDestGroup(node->groupIndex)) {
                if (self->IsDestNode(cell->nodeIndex)) {
                    doneFlag = 1;
                } else {
                    int* iterator;
                    for (iterator = D_004EE010.begin(); iterator != D_004EE010.end(); iterator++) {
                        if (cell->Cost2() == *iterator) {
                            doneFlag = 1;
                            break;
                        }
                    }
                }
                if (doneFlag) {
                    self->path->size = 0;
                    while (cell) {
                        self->path->Add(cell->nodeIndex);
                        cell = cell->parent;
                    }
                    self->path->destination = self->destinationPosition;
                    self->path->SetDNI(self->destinationOnNode ? self->destinationNodeIndex : -1);
                    D_004ED9F0.requestDone = 1;
                    if (self->gobj.Get())
                        QueueMessage_cMessageR_cSystemP_int(&cPathMessage(2, -1), self->Target(), 1);
                    self->pathFound = 1;
                    break;
                }
            }
            if (self->IsStartNode(cell->nodeIndex) || (node->type & 0x88)) {
                cArrayL* linkList = &node->links;
                Iterator linkIterator;
                for (linkIterator = linkList->begin(); linkIterator != linkList->end(); ++linkIterator) {
                    if (linkIterator->type != 7) {
                        int childNodeIndex = linkIterator->index;
                        if (childNodeIndex >= 0) {
                            cVector childNodePosition = cNode_GetLoc(cAIPathData_GetNode(childNodeIndex));
                            float newCost = cell->Cost() + Length(childNodePosition - cNode_GetLoc(node));
                            cPathCell* childCell = self->openList.Find(childNodeIndex);
                            if (!childCell)
                                childCell = self->closedList.Find(childNodeIndex);
                            if (!childCell || newCost < childCell->costFromStart) {
                                if (!childCell) {
                                    childCell = AllocCell();
                                    if (!childCell) {
                                        FAIL();
                                        doneFlag = 1;
                                        break;
                                    }
                                } else if (childCell->listMembership == 1) {
                                    self->openList.Remove(childCell);
                                } else if (childCell->listMembership == 2) {
                                    self->closedList.Remove(childCell);
                                }
                                childCell->nodeIndex = childNodeIndex;
                                childCell->costFromStart = newCost;
                                childCell->priority = newCost + Length(self->destinationPosition - childNodePosition);
                                childCell->parent = cell;
                                childCell->listMembership = 1;
                                cPriorityQueue_cPathCell_Push(&self->openList, childCell);
                            }
                        }
                    }
                }
            }
            cell->listMembership = 2;
            cPriorityQueue_cPathCell_Push(&self->closedList, cell);
            if (D_004EA798 >= 400) {
                FAIL();
                doneFlag = 1;
                break;
            }
        }
        if (!doneFlag)
            FAIL();
        doneFlag = 1;
    }
    if (doneFlag)
        D_004EA798 = self->cellPoolIndexRestore;
    return doneFlag;
}
