#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void CopyV(V* d, const V* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *(__int128*)d = t; }
struct V {    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }

    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V operator-(const V& b) const { V c; SubV(&c, this, &b); return c; }
} __attribute__((aligned(16)));
struct M { V r[4]; M() {} V& Pos() { return r[3]; } };
class Actor {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual M GetMatrix();
};
struct cPath {
    V destination;
    int destinationNodeIndex;
    int restoreFirstNode;
    int restoreLastNode;
    int pad1C;
    int* nodes;
    int capacity;
    int size;
};
struct cPathNavigator {
    V nextDestination;
    V pathDelta;
    V pathStart;
    V pathSaveDestination;
    float distanceToNextPoint;
    float pathSegmentLength;
    int pathIndex;
    int nodeIndex;
    int nextNodeIndex;
    int previousNodeIndex;
    int destinationNodeIndex;
    int nodeGroupIndex;
    unsigned char onPatrolPath : 1;
    unsigned char onPath : 1;
    unsigned char forceOnNodes : 1;
    unsigned char destinationReachedFlag : 1;
    unsigned char humanDestinationReached : 1;
    unsigned char humanDestinationReachedPrevious : 1;
    unsigned char firstActivation : 1;
    char pad61[0xF];
    Actor* gobj;
    cPath* path;
    int maxPathNodeCount;
};
extern "C" {
int cPathNavigator_NextPathSegment(cPathNavigator* self);
void cPathNavigator_ForceDestination(cPathNavigator* self, const V& destinationPosition, int);
}
static inline V GetPosition(Actor* a) { M m = a->GetMatrix(); M* pm = &m; return pm->r[3]; }
void cPathNavigator_ForceDestination(cPathNavigator* self, const V& destinationPosition, int)
{
    if (self->path) {
        if (self->path->size > 0) self->path->size = 0;
        self->path->destination = destinationPosition;
        {
            cPath* p = self->path;
            p->destinationNodeIndex = -1;
        }
        self->nextNodeIndex = -1;
        self->pathIndex = self->path->size;
        self->destinationNodeIndex = self->path->destinationNodeIndex;
        self->destinationReachedFlag = !cPathNavigator_NextPathSegment(self);
        self->pathStart = destinationPosition;
        self->nextDestination = destinationPosition;
        self->pathDelta = self->nextDestination - self->gobj->GetMatrix().Pos();
    }
}
