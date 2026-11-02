#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)
struct M;
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    V& operator*=(const M& m);
    bool operator!=(const V& o) const { return x != o.x || y != o.y || z != o.z; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M* p);
} __attribute__((aligned(16)));
inline V& V::operator*=(const M& m) {
    V* p = this;
    const M* q = &m;
    __asm__ volatile("lqc2 vf8, 0x0(%1); lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf7, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(p), "r"(this), "r"(q) : "memory");
    return *p;
}
struct GObj {                       /* object whose transform the destination is relative to */
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void UpdateTransform();  /* vtable +0x58 */
    char pad4[0xC];
    M mTransform;                   /* 0x10 */
    unsigned char mTransformDirty;  /* 0x50 */
};
struct ObjRef { char pad0[0xC]; unsigned int mId; char pad10[0x40]; GObj* mObj; int mValid; };
struct Dest {                       /* cDestinationParams */
    V mDestinationPos;              /* 0x00 */
    V mPlane;                       /* 0x10 */
    float mDestinationRotZ;         /* 0x20 */
    float mSpeedOfMotion;           /* 0x24 */
    ObjRef* mObjRef;                /* 0x28 */
    Dest(const V& pos);
};
struct CharMsg {                    /* cCharActionMsg */
    char** vt;
    char pad4[0x20];
    int f24;
    unsigned char f28;
    char pad29[7];
    CharMsg();
    void Destroy(int flags) { ((void (*)(CharMsg*, int))vt[2])(this, flags); }
    CharMsg* Clone() { return ((CharMsg* (*)(CharMsg*))vt[3])(this); }
};
struct Msg : CharMsg {              /* cCharActionMsg_DestinationParams, 0x60 */
    Dest d;                         /* 0x30 */
    Msg(const V& pos);
    const V& Pos() const { const V* p = &d.mDestinationPos; return *p; }
    const V& Plane() const { const V* p = &d.mPlane; return *p; }
};
struct Out {                        /* _netcharactionreq_destinationparams */
    unsigned int nSendTime, nNetObjectID;
    float x, y, z;                  /* 0x08 */
    float px, py, pz, pw;           /* 0x14 */
    short DestinationRotZ;          /* 0x24 */
    unsigned short SpeedOfMotion;   /* 0x26 */
};
union FI { unsigned int i; float f; };
extern "C" {
extern Msg* D_0055A228;             /* prevDestMsg */
extern unsigned int D_0055A210;     /* m_uiMsgID */
extern char g_ActorActionMsgClass[];
extern char D_004E0840[], D_004E0100[];
void* cMemMan_Allocate(int pool, int size, const char* file, int line);
void cMemMan_Deallocate(int pool, void* p, const char* file, int line);
void cMessage_ctor_cMessageNameR(void* m, void* name);
int cCharActionMsg_Pack(Msg* m, int id, unsigned int* outId, int sendTime, int useTime, int size, unsigned char* buf);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_InvertRotTrans(M* m);
V func_003E5EF0(const V* plane);
float func_003E5EE0(const V* plane);
void func_003E5E80(V* plane, const V* point, const V* normal);
V* func_00133EC0(M* m);
V opMul(float f, const V* v);
V* cVector_Translate(V* a, const V* b);
V* cVector_Rotate_cMatrixR(V* v, const M* m);
int func_003E57B0(Msg* self, int InObjID, unsigned int* nOutMsgID, int nSendTime, int nUseTime, int nSizeOfBuffer, unsigned char* ucOutStream);
}
inline M::M(const M* p) { cMatrix_ctor_cMatrixR(this, p); void* xx = this; }
static inline M Inverse(const M& m) { M t; return M(cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, &m))); }
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
inline Dest::Dest(const V& pos) {
    Dest* p = this;
    { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(p), "r"(&pos) : "memory"); }
    p->mPlane.x = 0.0f; p->mPlane.y = 0.0f; p->mPlane.z = 0.0f; p->mPlane.w = 0.0f;
    p->mDestinationRotZ = 0.0f;
    p->mSpeedOfMotion = Min(1.0f, 0.0f);
    p->mObjRef = 0;
}
inline CharMsg::CharMsg() { cMessage_ctor_cMessageNameR(this, g_ActorActionMsgClass); vt = (char**)D_004E0840; f24 = 0; f28 = 13; }
inline Msg::Msg(const V& pos) : d(pos) { vt = (char**)D_004E0100; }
static inline void* operator new(unsigned int size, const char* file, int line) {
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, size, file, line);
    }
    return p;
}
/* cPlane::Transform */
static inline void TransformPlane(V& plane, M& m) {
    V n = func_003E5EF0(&plane);
    cVector_Rotate_cMatrixR(&n, &m);
    V pt = opMul(-func_003E5EE0(&plane), &n);
    cVector_Translate(&pt, func_00133EC0(&m));
    func_003E5E80(&plane, &pt, &n);
}
static inline short ToShort(float f) { return (short)(f * 16384.0f); }

int func_003E57B0(Msg* self, int InObjID, unsigned int* nOutMsgID, int nSendTime, int nUseTime, int nSizeOfBuffer, unsigned char* ucOutStream)
{
    int nSizeOfData = -1;
    if (!D_0055A228) {
        V tmpVector(0.0f, 0.0f, 0.0f, 0.0f);
        D_0055A228 = new ("character.cc", 0x2C5) Msg(tmpVector);
    }
    const V& b = self->d.mDestinationPos;
    const V& a = D_0055A228->d.mDestinationPos;
    if (a.x != b.x || a.y != b.y || a.z != b.z) {
        if ((unsigned int)nSizeOfBuffer >= 40 && ucOutStream) {
            Out* msg;
            cCharActionMsg_Pack(self, InObjID, 0, nSendTime, nUseTime, nSizeOfBuffer, ucOutStream);
            msg = (Out*)ucOutStream;
            if (!self->d.mObjRef || !self->d.mObjRef->mObj || !self->d.mObjRef->mValid) {
                msg->x = self->Pos().x;
                msg->y = self->Pos().y;
                msg->z = self->Pos().z;
                msg->px = self->Plane().x;
                msg->py = self->Plane().y;
                msg->pz = self->Plane().z;
                msg->pw = self->Plane().w;
                msg->SpeedOfMotion = (unsigned short)(int)(32768.0f * self->d.mSpeedOfMotion);
            } else {
                V pos(self->d.mDestinationPos);
                V plane(self->d.mPlane);
                GObj* obj;
                pos.w = 1.0f;
                obj = self->d.mObjRef->mObj;
                if (obj->mTransformDirty) obj->UpdateTransform();
                {
                    M inv = Inverse(obj->mTransform);
                    pos *= inv;
                    TransformPlane(plane, inv);
                }
                msg->x = pos.x;
                msg->y = pos.y;
                msg->z = pos.z;
                {
                    FI u;
                    u.i = self->d.mObjRef->mId;
                    msg->px = u.f;
                }
                {
                    FI u;
                    u.i = (unsigned short)(short)ToShort(plane.x) | (((short)ToShort(plane.y) << 16) & 0xFFFF0000);
                    msg->py = u.f;
                }
                msg->pz = plane.z;
                msg->pw = plane.w;
                msg->SpeedOfMotion = 0xFFFF;
            }
            msg->DestinationRotZ = (short)(8192.0f * self->d.mDestinationRotZ);
            if (nOutMsgID) {
                nSizeOfData = 40;
                *nOutMsgID = D_0055A210;
            }
            {
                Msg* prev = D_0055A228;
                {
                    AllocGuard g;
                    prev->Destroy(-1);
                    cMemMan_Deallocate(0, prev, "character.cc", 0x363);
                }
            }
            D_0055A228 = (Msg*)self->Clone();
        }
    }
    return nSizeOfData;
}
