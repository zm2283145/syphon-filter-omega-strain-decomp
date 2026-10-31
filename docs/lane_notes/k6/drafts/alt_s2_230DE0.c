#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

static inline void ScaleV(void* rp, const void* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    static void VU0Neg(V& o, const V& i) { __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&o), "r"(&i) : "memory"); }
    V operator-() const { V t; VU0Neg(t, *this); return t; }
    float Length() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    float LengthSquared() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    V& Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); return *this; }
    V GetNormalized() const { V r = *this; V* p = &r; p->Normalize(); return *p; }
    V operator*(float k) const { V r; V* p = &r; ScaleV(p, this, k); return r; }
    V operator/(float scale) const { V r; ScaleV(&r, this, 1.0f / scale); return r; }
    float operator*(const V& o) const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&o) : "memory"); return r; }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    friend V operator-(const V& a, const V& b) { V result; VU0Subtract(result, a, b); return result; }
    static void VU0Add(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator+(const V& vector) const { V result; VU0Add(result, *this, vector); return result; }
    V& operator+=(const V& vector) { VU0Add(*this, *this, vector); return *this; }
    static void VU0Cross(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vopmula.xyz $ACC, $vf1, $vf2; vopmsub.xyz $vf3, $vf2, $vf1; vsubw.w $vf3, $vf0, $vf0w; sqc2 $vf3, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    static V Cross(const V& a, const V& b) { V result; VU0Cross(result, a, b); return result; }
    friend V operator^(const V& a, const V& b) { return Cross(a, b); }
} __attribute__((aligned(16)));

struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Q4 { __int128 a, b, c, d; };
struct M { VP m[4]; const V& Row(int i) const { return *(const V*)&m[i]; } M() {} M(const M& o) { M* d = this; __int128 a; __int128 b; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); } };
static inline void Apply(V* o, const M* m, const V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void ApplySelf(V* v, const M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline V operator*(const M& m, const V& v) { V r = v; V* p = &r; ApplySelf(p, &m); return *p; }
static inline void operator*=(V& v, const M& m) { Apply(&v, &m, &v); }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Min(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void SetUnit(M* m) { __int128 t; __asm__ volatile("sqc2 $vf0, 0x30(%0); qmfc2.ni %1, $vf0; pcpyud %1, %1, $0; sq %1, 0x10(%0); pexcw %1, %1; sq %1, 0x20(%0); pcpyud %1, %1, $0; sq %1, 0x0(%0)" : "+r"(m), "=&r"(t) : : "memory"); }

struct tPARInit {
    V pos;
    M mat;
    tPARInit(V p, M m) : pos(p), mat(m) {}
};

struct cObjectId { int id; cObjectId() { id = -1; } cObjectId(const cObjectId& o) { id = o.id; } cObjectId& operator=(const cObjectId& o) { id = o.id; return *this; } };

struct cXform {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    M localToWorldMatrix;
    unsigned char needsUpdate;
    M& GetMatrix() { if (needsUpdate) Update(); return localToWorldMatrix; }
};
struct cCollisionModelAddress { int off; cCollisionModelAddress(const cCollisionModelAddress& o) { off = o.off; } };
struct cCollisionModel_Data;
struct BBox { V min; V max; };
struct cGOBJ {
    VPAD32(a)
    virtual const BBox* GetBBox() const;
    VPAD8(b) VPAD2(c) VPAD1(d)
    virtual struct cCollisionModel* GetCollisionModel() const;
    VPAD8(e) VPAD2(f)
    virtual V GetPos() const;
    virtual M GetMtx() const;
    char pad4[8];
    cObjectId mObjectId;
    const cObjectId& GetId() const { return mObjectId; }
    char pad10[0x39];
    unsigned char mClassID;
    char pad4A[6];
    cXform* mXform;
    char pad54[0x10];
    struct cVUM_GOBJ* x64;
};
struct cVUM_GOBJ { char pad[0x68]; int* x68; bool HasModel() const { return *x68 ? 1 : 0; } };

extern "C" {
extern char D_004A6E38[], D_004A6E50[];
extern char g_Game[], g_LosCheckService[], g_LosRequestMsgClass[], D_004D9180[], D_004DAE30[], D_0052ACC0[], D_004DE5F0[];
extern unsigned char g_IsMultiplayer;
void* cMemMan_Allocate(int pool, int size, char* file, int line);
cCollisionModel_Data* cCollisionModelMaster_GetData(void* master);
V* cCollisionModel_Data_GetVertex(cCollisionModel_Data* d, int i);
V* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(cCollisionModel_Data* m, cCollisionModelAddress it);
cObjectId nGobjManager_GetNextId(int type);
void nGobjManager_AddGOBJ(void* g);
void* cGameParticle_ctor_cObjectIdR_int(void* p, const cObjectId& id, int def);
void cParticle_SetShatterData(void* p, cGOBJ* o, cVUM_GOBJ* v, const cGOBJ* d, const V* pt, const V* n, float floorZ);
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
void cFileMan_dtor(void*, int);
void cSndFx_ctor_int_charP_cGOBJP_int(void* s, int a, char* name, void* g, int b);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(void* m, void* s, void* pos);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* sys, int x);
int cNetShatterMsg_Pack(void* m, int a, unsigned int* id, int b, int c, int size, unsigned char* buf);
void cNetObj_SendMessage_int_int_ucharP_int_etc(unsigned int id, int size, unsigned char* buf, int a, int b);
}

struct cCollisionModel_Data { char pad[0x1C]; int type; cCollisionModelAddress mVertices;
    V& GetVertex(int index) { return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(this, mVertices)[index]; }
};
struct cCollisionModelMaster { cCollisionModel_Data* mData; };
struct cCollisionModel {
    cGOBJ* parentGobj;
    cCollisionModelMaster* mMaster;
    int GetType() const { return mMaster->mData->type; }
    V GetVertex(int index) const { return mMaster->mData->GetVertex(index); }
    V GetVertex2(int index) const { return *cCollisionModel_Data_GetVertex(cCollisionModelMaster_GetData(mMaster), index); }
};

struct cGameParticle { VPAD8(a) VPAD4(b) VPAD2(c) virtual void Init(tPARInit* i); VPAD4(d) VPAD2(e) virtual void Activate(int on); char pad[0x60]; void* particle; };

typedef struct { int a; int b; } FxDef;
typedef struct { unsigned char flag; char pad[7]; } FxFlag;
extern "C" { extern FxFlag D_004F7A54[]; extern FxDef SpecFxTable[]; }
static inline FxDef* GetDef_(int id) { if ((unsigned int)id < 41) return &SpecFxTable[id]; return 0; }
static inline FxDef* GetDef(int id) { if (!D_004F7A54[id].flag) return 0; return GetDef_(id); }
static inline void* GAlloc(int sz, int line) { AllocGuard g; return cMemMan_Allocate(0, sz, D_004A6E38, line); }


struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
    V GetNormal() const { return h.normal; }
};
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {} MsgB(void* name) { cMessage_ctor_cMessageNameR(this, name); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct LosMsg : MsgB {
    int x24;
    int x28;
    LosRes* res;
    V from;
    V dir;
    void* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V& f, V d, void* o, int mask)
    {
        LosMsg* m = this;
        cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = mask;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};
struct cSystem { VPAD1(a) virtual void Post(const LosMsg& m); };
extern "C" cSystem* cSystemContainer_GetSystem(void*, void*);

struct cSndFx {
    char pad[0x190];
    cSndFx(int a, char* name, void* g, int b) { cSndFx_ctor_int_charP_cGOBJP_int(this, a, name, g, b); }
    __declspec(weak) __declspec(MSG_DTOR) ~cSndFx() { cFileMan_dtor(pad + 0xE4, -1); cFileMan_dtor(pad + 0x48, -1); }
};
struct cPlaySoundMsg : MsgB {
    char pad24[0x19C];
    cPlaySoundMsg(cSndFx& s, V* pos) { cPlaySoundMsg_ctor_cSndFxR_cGOBJP(this, &s, pos); }
    __declspec(weak) __declspec(MSG_DTOR) ~cPlaySoundMsg() { vtable = D_004DAE30; cFileMan_dtor(pad24 + 0xF0, -1); cFileMan_dtor(pad24 + 0x54, -1); }
};
struct cNetShatterMsg : MsgB {
    int mObject;
    int mDestroyer;
    cNetShatterMsg(const cObjectId& o, const cObjectId& d) : MsgB(D_0052ACC0) { vtable = D_004DE5F0; mObject = -1; mDestroyer = -1; mObject = o.id; mDestroyer = d.id; }
    __declspec(weak) __declspec(MSG_DTOR) ~cNetShatterMsg() { vtable = D_004DE5F0; }
};

extern "C" void Global_Shatter(cGOBJ* object, const cGOBJ* destroyer, bool bNet)
{
    cVUM_GOBJ* vumGobj = 0;
    if (object->mClassID == 15) vumGobj = object->x64;
    if (vumGobj && vumGobj->HasModel()) {
        M mat;
        SetUnit(&mat);
        tPARInit init(object->GetPos(), mat);
        cGameParticle* particleGobj = (cGameParticle*)GAlloc(0x74, 0x5F9);
        if (particleGobj) { int fx = 9; particleGobj = (cGameParticle*)cGameParticle_ctor_cObjectIdR_int(particleGobj, nGobjManager_GetNextId(0xE7), GetDef(fx)->a); }
        if (particleGobj) {
            particleGobj->Init(&init);
            nGobjManager_AddGOBJ(particleGobj);
            particleGobj->Activate(1);
            void* particle = particleGobj->particle;
            if (particle) {
                V bulletVector = (object->GetPos() - destroyer->GetPos()).GetNormalized();
                V losPos;
                V losDir;
                V vertex0;
                V oppositeVertex;
                V shatterCollisionPoint;
                cCollisionModel* collisionModel = object->GetCollisionModel();
                cXform* xform;
                if (collisionModel && (xform = collisionModel->parentGobj->mXform) && collisionModel->GetType() == 4) {
                    V center = (collisionModel->GetVertex(0) + collisionModel->GetVertex(1) + collisionModel->GetVertex(2) + collisionModel->GetVertex(3)) * 0.25f;
                    int vertex0Index = 0;
                    int i;
                    for (i = 1; i < 4; i++) {
                        if (collisionModel->GetVertex(i).z < center.z && collisionModel->GetVertex(i).x + collisionModel->GetVertex(i).y < center.x + center.y) {
                            vertex0Index = i;
                        }
                    }
                    vertex0 = collisionModel->GetVertex2(vertex0Index);
                    float maxDistanceSquared = 0.0f;
                    int oppositeVertexIndex = 3 - vertex0Index;
                    int otherVertexIndex;
                    for (i = 0; i < 4; i++) {
                        float distance = (vertex0 - collisionModel->GetVertex(i)).LengthSquared();
                        if (distance > maxDistanceSquared) {
                            otherVertexIndex = oppositeVertexIndex;
                            maxDistanceSquared = distance;
                            oppositeVertexIndex = i;
                        }
                    }
                    V otherVertex = collisionModel->GetVertex(otherVertexIndex);
                    oppositeVertex = collisionModel->GetVertex2(oppositeVertexIndex);
                    vertex0 *= xform->GetMatrix();
                    oppositeVertex *= xform->GetMatrix();
                    otherVertex *= xform->GetMatrix();
                    losPos = (vertex0 + oppositeVertex) / 2.0f;
                    losDir = (vertex0 - otherVertex) ^ (oppositeVertex - otherVertex);
                    losDir.Normalize();
                    shatterCollisionPoint = xform->GetMatrix() * center;
                } else {
                    losPos = object->GetPos();
                    losDir = object->GetMtx().Row(1);
                    oppositeVertex = object->GetBBox()->max;
                    vertex0 = object->GetBBox()->min;
                    shatterCollisionPoint = object->GetBBox()->min;
                }
                if (losDir * bulletVector < 0.0f) {
                    losDir = -losDir;
                }
                cSystem* losManager = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                LosRes result;
                losManager->Post(LosMsg(&result, losPos, losDir * 40.0f, object, 4));
                V shatterCollisionNormal;
                float floorZ = object->GetBBox()->min.z;
                float length = 3.0f;
                if (result.hit) {
                    shatterCollisionPoint = result.pt;
                    shatterCollisionNormal = result.GetNormal();
                    length = Min(length, 0.5f * (shatterCollisionPoint - losPos).Length());
                } else {
                    shatterCollisionPoint = losPos + losDir * 40.0f;
                    shatterCollisionNormal = -losDir;
                }
                if (!result.hit || Abs(shatterCollisionNormal.z) < 0.9f) {
                    losPos += losDir * length;
                    losManager->Post(LosMsg(&result, losPos, V(0.0f, 0.0f, -200.0f, 0.0f), object, 4));
                    if (result.hit) {
                        floorZ = result.pt.z;
                    } else {
                        shatterCollisionPoint = losPos;
                        shatterCollisionNormal = -losDir;
                    }
                }
                cParticle_SetShatterData(particle, object, vumGobj, destroyer, &shatterCollisionPoint, &shatterCollisionNormal, floorZ);
                V pos = object->GetPos();
                cSndFx sound(0, D_004A6E50, 0, 0);
                cPlaySoundMsg msg(sound, &pos);
                msg.kind = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
            }
        }
    }
    if (g_IsMultiplayer && !bNet) {
        cNetShatterMsg msg(object->GetId(), destroyer->GetId());
        unsigned int msgID;
        unsigned char buf[128];
        int nSize = cNetShatterMsg_Pack(&msg, 0, &msgID, 0, 0, 0x80, buf);
        cNetObj_SendMessage_int_int_ucharP_int_etc(msgID, nSize, buf, -1, 0);
    }
}
