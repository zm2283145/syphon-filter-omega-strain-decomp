#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct V4_13A { float x, y, z, w; };
struct Hit_13A { char b[0x70]; };
struct Ev_13A { char b[0xD0]; };
struct Rec_13A;
struct It_13A { Rec_13A* p; };
struct Req_13A {
    char pad0[0x24];
    int id;
    int* outIdx;
    void* buf;
    V4_13A from;
    V4_13A to;
    int x50;
    int x54;
    int x58;
    unsigned char mode;
};
struct Self_13A {
    char pad0[0x20];
    char recs[0x10];
    char list30[0xC];
    char list3C[0xC];
};
class Provider_13A {
public:
    virtual void v0();
    virtual void v1();
    virtual void SetQuery(void* q);
};

extern "C" {
void cVector_ctor_cVectorR(V4_13A* d, const V4_13A* s);
void cLosResult_ctor_void(void* buf);
Provider_13A* cLosRequest_cCollisionModelList_Game_GetCollisionModelList(void);
void cCollisionModelList_Resize_ExclusionList(Provider_13A* p, int v);
void cCollisionModelList_PushBack_ExclusionList(Provider_13A* p, int v);
void cVector_ctor_void(V4_13A* p);
void cCollisionFace_ctor_void(Hit_13A* h);
int nCollision_DetectForIntersectionBetweenRayAndFaces(V4_13A* pt, Hit_13A* hit, V4_13A* from, V4_13A* to, Provider_13A* p, int a, unsigned char b, int c, long d, long e);
void cLosResult_SetLosBlocked(void* r, unsigned char s);
void cLosResult_SetIntersectionPoint(void* r, V4_13A* pt);
void cLosResult_SetBlockingFace(void* r, Hit_13A* h);
void cCollisionFace_dtor(Hit_13A* h, int f);
void cLosResult_SetHandle(void* r, int v);
void cLosResultReadyMessage_ctor(Ev_13A* e, void* r);
void QueueMessage_cMessageR_cSystemP_int(Ev_13A* e, int target, int f);
void cLosResultReadyMessage_dtor(Ev_13A* e, int f);
void cArray_cLosRequest_cCollisionModelList_Game_Begin(It_13A* out, void* v);
void cArray_cLosRequest_cCollisionModelList_Game_End(It_13A* out, void* v);
int cArray_cLosRequest_cCollisionModelList_Game_Iterator_opNe(It_13A* a, It_13A* b);
Rec_13A* cArray_cLosRequest_cCollisionModelList_Game_Iterator_opArrow(It_13A* it);
unsigned char cLosRequest_cCollisionModelList_Game_IsInUse(Rec_13A* r);
int cLosManager_cCollisionModelList_Game_GetNewHandle(Self_13A* s);
void cLosRequest_cCollisionModelList_Game_Reset(Rec_13A* r, V4_13A* a, V4_13A* b, int id, void* buf, int d0, int d4, int d8, int dc);
Rec_13A* cArray_cLosRequest_cCollisionModelList_Game_Iterator_opMul(It_13A* it);
void cArray_cLosRequest_cCollisionModelList_Game_Iterator_opInc(It_13A* it);
void std_list_cLosRequest_cCollisionModelList_GamePtr_push_back(void* list, Rec_13A** v);
}

/* inline LosResult storage; its (inlined, otherwise empty) dtor leaves only the this-null check */
struct Inl_13A { char b[0xA0]; __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Inl_13A() { if (this) { b[0] = b[0]; } } };
struct Query_13A {
    V4_13A from;
    V4_13A to;
    unsigned char active;
    int id;
    void* buf;
    int pad2C;
    Inl_13A inl;
    int d0;
    int d4;
    int d8;
    int dc;
    Query_13A(const V4_13A* f, const V4_13A* t, int i, void* b, int a4, int a8, int ac)
    {
        Query_13A* self = this;
        cVector_ctor_cVectorR(&self->from, f);
        cVector_ctor_cVectorR(&self->to, t);
        self->active = 1;
        self->id = i;
        self->buf = b ? b : &self->inl;
        cLosResult_ctor_void(&self->inl);
        self->d0 = 0;
        self->d4 = a4;
        self->d8 = a8;
        self->dc = ac;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Query_13A() { active = 0; }
};
static inline Rec_13A* FindFree(Self_13A* self, Req_13A* req)
{
    It_13A it;
    It_13A end;
    cArray_cLosRequest_cCollisionModelList_Game_Begin(&it, self->recs);
    cArray_cLosRequest_cCollisionModelList_Game_End(&end, self->recs);
    for (; cArray_cLosRequest_cCollisionModelList_Game_Iterator_opNe(&it, &end); cArray_cLosRequest_cCollisionModelList_Game_Iterator_opInc(&it)) {
        if (!cLosRequest_cCollisionModelList_Game_IsInUse(cArray_cLosRequest_cCollisionModelList_Game_Iterator_opArrow(&it))) {
            int idx;
            if (req->outIdx) *req->outIdx = cLosManager_cCollisionModelList_Game_GetNewHandle(self);
            idx = req->outIdx ? *req->outIdx : 0;
            cLosRequest_cCollisionModelList_Game_Reset(cArray_cLosRequest_cCollisionModelList_Game_Iterator_opArrow(&it), &req->from, &req->to, req->id, req->buf, idx, req->x50, req->x54, req->x58);
            return cArray_cLosRequest_cCollisionModelList_Game_Iterator_opMul(&it);
        }
    }
    return 0;
}

extern "C" int cLosManager_cCollisionModelList_Game_HandleRequest(Self_13A* self, Req_13A* req)
{
    if (req->mode == 0) {
        Query_13A q(&req->from, &req->to, req->id, req->buf, req->x50, req->x54, req->x58);
        Provider_13A* p = cLosRequest_cCollisionModelList_Game_GetCollisionModelList();
        p->SetQuery(&q);
        cCollisionModelList_Resize_ExclusionList(p, 0);
        if (q.d4) cCollisionModelList_PushBack_ExclusionList(p, q.d4);
        if (q.d8) cCollisionModelList_PushBack_ExclusionList(p, q.d8);
        {
            V4_13A pt;
            Hit_13A hit;
            cVector_ctor_void(&pt);
            cCollisionFace_ctor_void(&hit);
            int st = nCollision_DetectForIntersectionBetweenRayAndFaces(&pt, &hit, &q.from, &q.to, p, 0, *(unsigned char*)&q.dc, 0, 0, 1);
            cLosResult_SetLosBlocked(q.buf, st);

            cLosResult_SetIntersectionPoint(q.buf, &pt);
            cLosResult_SetBlockingFace(q.buf, &hit);
            cCollisionFace_dtor(&hit, -1);
        }
        cLosResult_SetHandle(q.buf, q.d0);
        if (q.id) {
            Ev_13A ev;
            cLosResultReadyMessage_ctor(&ev, q.buf);
            QueueMessage_cMessageR_cSystemP_int(&ev, q.id, 1);
            cLosResultReadyMessage_dtor(&ev, -1);
        }
    } else {
        Rec_13A* rec = FindFree(self, req);
        if (!rec) return 0;
        switch (req->mode) {
        case 1:
            std_list_cLosRequest_cCollisionModelList_GamePtr_push_back(self->list30, &rec);
            break;
        case 2:
            std_list_cLosRequest_cCollisionModelList_GamePtr_push_back(self->list3C, &rec);
            break;
        default:
            if (rec) ((unsigned char*)rec)[0x20] = 0;
            return 0;
        }
    }
    return 1;
}
