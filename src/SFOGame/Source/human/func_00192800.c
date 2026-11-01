/* 00192800 cHuman::HandleRunningJumpOffLedge(const nMSGLIB::cCharActionMsg&) (human.cc), rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma enumsalwaysint off
#pragma inline_depth(8)
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V& ZeroZ() { z = 0.0f; return *this; }
    V& Normalize();
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void SubM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void MulT(V* d, const V* p, float s) { __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
static inline void NegM(V* d, const V* p) { asm volatile { lqc2 vf1, 0x0(p); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(d) } }
static inline void NormM(V* v) { asm volatile { lqc2 vf1, 0x0(v); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(v) } }
static inline void XformM(V* d, const V* s, const M* m) { asm volatile { lqc2 vf8, 0x0(s); lqc2 vf4, 0x0(m); lqc2 vf5, 0x10(m); lqc2 vf6, 0x20(m); lqc2 vf7, 0x30(m); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(d) } }
static inline void QRotM(V* v, const V* q) {
    asm volatile {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline float DotM(const V* a, const V* b)
{
    int rv0;
    float ret = 0.0f;
    asm volatile {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
/* max.s (EE FPU min/max), not expressible in C */
static inline float Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float MaxElement(const V& v) { float x = v.x; float y = v.y; float z = v.z; return Max(x, Max(y, z)); }

inline V& V::Normalize() { const void* xx = this; V* t = this; NormM(t); return *this; }
static inline V Rotate(const V* q, const V& v) { V r = v; V* p = &r; QRotM(p, q); return *p; }
static inline V Normalized(V v) { return v.Normalize(); }
static inline V XY(const V& v) { V r = v; V* p = &r; p->z = 0.0f; return *p; }
static inline V operator+(const V& a, const V& b) { V r; V* pd = &r; AddM(pd, &a, &b); return r; }
static inline V operator-(const V& a, const V& b) { V r; V* pd = &r; const V* pa = &a; const V* pb = &b; SubM(pd, pa, pb); return r; }
static inline V operator*(const V& v, float s) { V r; const V* pv = &v; V* pd = &r; MulT(pd, pv, s); return r; }

extern "C" {
V cVector_opSub(const V* a, const V* b);
V cVector_opMul(const V* a, float s);
V cVector_opAdd(const V* a, const V* b);
V* cVector_opAssign(V* d, const V* s);
float cVector_Dot(const V* a, const V* b);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
V* cQuatVec_Rotation(void*);
V* cQuatVec_Translation(void*);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(void*);
void cSkaAnimAnchor_TreeNode_UpdateTransform(void*);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(void*);
void* nGobjManager_LookupGOBJ_cObjectIdR(const int*);
float Libc_Atan2f(float, float);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(const void*, void*, int);
void cMessage_dtor(void*, int);
extern int D_004EE6B8;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[], D_004E0140[];
}

struct cBox {
    V min, max;
    unsigned char IsEmpty() const { return min.x > max.x; }
    V Center() const { V r = (min + max) * 0.5f; return r; }
    V Dimensions() const { return IsEmpty() ? V(0.0f, 0.0f, 0.0f, 0.0f) : max - min; }
};
struct cLineSegment {
    V endPoints[2];
    /* the body sits three inline levels below the call: puts d/e and the operator temps in retail's deepest stack slots */
    unsigned char I3(const V& p, const V& n, V& out) const
    {
        V d = cVector_opSub(&endPoints[1], &endPoints[0]);
        V e = cVector_opSub(&p, &endPoints[0]);
        float den = cVector_Dot(&d, &n);
        float num = cVector_Dot(&e, &n);
        if (den < 0.0f) { den = -den; num = -num; }
        if (num >= 0.0f && num <= den && den != 0.0f) {
            cVector_opAssign(&out, &cVector_opAdd(&endPoints[0], &cVector_opMul(&d, num / den)));
            return 1;
        }
        return 0;
    }
    unsigned char I25(const V& p, const V& n, V& out) const { return I3(p, n, out); }
    unsigned char I2(const V& p, const V& n, V& out) const { return I25(p, n, out); }
    unsigned char IntersectPlane(const V& n, const V& p, V& out) const { return I2(p, n, out); }
};

struct cXform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0x10 - 4];
    M localToWorldMatrix;
    unsigned char needsUpdate;
    const M& Matrix() { if (needsUpdate) Update(); return localToWorldMatrix; }
};
struct cGOBJ {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual cBox* GetBBox() const;
    char pad4[0x4C - 4];
    int mSubclassId;
    cXform* mXform;
};
struct cGobjController {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual unsigned char IsLocal();
};
struct cSkaAnimAnchor_TreeNode {
    const V& Translation_WorldSpace()
    {
        char* d;
        if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(this)) {
            cSkaAnimAnchor_TreeNode_UpdateTransform(this);
            d = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(this);
        } else {
            d = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(this) + 80;
        }
        return *(V*)(d + 16);
    }
};

struct cMessage {
    void* vt;
    char pad04[0x20 - 4];
    unsigned char mDestinationType;
};
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB : cMessage {
    MsgB(void* n) { cMessage_ctor_cMessageNameR(this, n); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct cCharActionMsg : MsgB {
    int mAction; unsigned char mParamType;
    cCharActionMsg(int a, unsigned char t) : MsgB(g_ActorActionMsgClass) { vt = D_004E0840; mAction = a; mParamType = t; }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg() { vt = D_004E0840; }
};
struct cCharActionMsg_ObjectId_Int : cCharActionMsg { int mObjectId; int mInt; };
struct cCharActionMsg_Vector : cCharActionMsg {
    char pad2C[4];
    V mVector;
    cCharActionMsg_Vector(int a, const V& v) : cCharActionMsg(a, 4) { vt = D_004E0140; mVector = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~cCharActionMsg_Vector() { vt = D_004E0140; }
};
static inline void QueueAction(const cCharActionMsg& m, void* g)
{
    ((cCharActionMsg&)m).mDestinationType = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g, 1);
}

enum eAction { ACTION_NEG = -1, ACTION_0 = 0, ACTION_MAX = 0x7F };
enum eJumpDestinationType { JDT_NONE = 0, JDT_FLOOR = 1, JDT_LEDGE = 2, JDT_MAX = 0x7F };

struct cHuman {
    char pad0[0x14];
    unsigned char mActiveFlag;
    char pad15[0x58 - 0x15];
    cGobjController* mController;
    char pad5C[0x31C0 - 0x5C];
    V vec31C0;
    char pad31D0[0x3204 - 0x31D0];
    int flags3204;
    char pad3208[4];
    int state320C;
    char pad3210[0x3290 - 0x3210];
    cSkaAnimAnchor_TreeNode* anchor;
    unsigned char IsLocal() { unsigned char r = 0; if (mController && mController->IsLocal()) r = 1; return r; }
};

extern "C" void cHuman_HandleRunningJumpOffLedge(cHuman* self, const cCharActionMsg& msg)
{
    if (!self->mActiveFlag && self->IsLocal()) return;
    if (!((self->flags3204 >> 1) & 1)) return;
    {
        int s = self->state320C;
        if (s == 2) return;
        if (s == 4) return;
        if (s == 5) return;
    }
    if (msg.mParamType != 6) return;
    {
        const cCharActionMsg_ObjectId_Int& msg_ObjId_Int = (const cCharActionMsg_ObjectId_Int&)msg;
        cGOBJ* gobj = (cGOBJ*)nGobjManager_LookupGOBJ_cObjectIdR(&msg_ObjId_Int.mObjectId);
        if (!gobj) return;
        { int id = D_004EE6B8; if (gobj->mSubclassId != id) return; }
        cBox* box = gobj->GetBBox();
        if (!box) return;
        cLineSegment lineSegment;
        cXform* xform = gobj->mXform;
        V center = box->Center();
        V dimensions = box->Dimensions();
        float maxDimension = MaxElement(dimensions);
        lineSegment.endPoints[0] = center;
        lineSegment.endPoints[1] = center;
        if (maxDimension == dimensions.x) {
            lineSegment.endPoints[0].x = box->min.x;
            lineSegment.endPoints[1].x = box->max.x;
        } else if (maxDimension == dimensions.y) {
            lineSegment.endPoints[0].y = box->min.y;
            lineSegment.endPoints[1].y = box->max.y;
        } else if (maxDimension == dimensions.z) {
            lineSegment.endPoints[0].z = box->min.z;
            lineSegment.endPoints[1].z = box->max.z;
        }
        if (xform) {
            const M& m = xform->Matrix();
            XformM(&lineSegment.endPoints[0], &lineSegment.endPoints[0], &m);
            XformM(&lineSegment.endPoints[1], &lineSegment.endPoints[1], &m);
        }
        V moveVec_WorldSpace = Rotate(cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self->anchor)), self->vec31C0);
        V xyMoveDir_WorldSpace = Normalized(XY(moveVec_WorldSpace));
        V intersectionPoint;
        unsigned char destinationFound = lineSegment.IntersectPlane(V(-xyMoveDir_WorldSpace.y, xyMoveDir_WorldSpace.x, 0.0f, 0.0f), self->anchor->Translation_WorldSpace(), intersectionPoint);
        if (!destinationFound) return;
        V deltaToDestination = intersectionPoint - *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self->anchor));
        { const V* pa = &deltaToDestination; if (DotM(pa, &xyMoveDir_WorldSpace) <= 0.0f) return; }
        V destinationPoint = intersectionPoint;
        float destinationZRotation;
        if (msg_ObjId_Int.mInt == 2) {
            V lineSegmentDelta = lineSegment.endPoints[1] - lineSegment.endPoints[0];
            V destinationYAxis;
            destinationYAxis.z = 0.0f;
            destinationYAxis.w = 0.0f;
            destinationYAxis.y = lineSegmentDelta.x;
            destinationYAxis.x = -lineSegmentDelta.y;
            if (DotM(&destinationYAxis, &xyMoveDir_WorldSpace) < 0.0f) NegM(&destinationYAxis, &destinationYAxis);
            destinationZRotation = Libc_Atan2f(-destinationYAxis.x, destinationYAxis.y);
        } else if (msg_ObjId_Int.mInt == 1) {
            destinationZRotation = 0.0f;
        }
        eJumpDestinationType destinationType = (eJumpDestinationType)msg_ObjId_Int.mInt;
        eAction actionId;
        V destinationTransform = destinationPoint;
        if (destinationType == JDT_FLOOR) {
            actionId = (eAction)21;
            destinationTransform.w = 1.0f;
        } else if (destinationType == JDT_LEDGE) {
            actionId = (eAction)22;
            destinationTransform.w = destinationZRotation;
        }
        QueueAction(cCharActionMsg_Vector(actionId, destinationTransform), self);
    }
}
