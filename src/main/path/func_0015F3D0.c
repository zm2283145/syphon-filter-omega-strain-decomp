#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef union { __int128 q; struct { float x, y, z, w; } f; } RbV4;
typedef struct RbActor { char pad0[0xC]; int serial; } RbActor;
typedef struct RbNode { char pad0[0x7C]; int x7C; } RbNode;
typedef struct RbObj { RbV4 pos; int x10; } RbObj;
typedef struct RbReq {
    RbActor* actor;
    int serial;
    int serial2;
    unsigned char state;
    unsigned char dirty;
    unsigned char reported;
    char padF[3];
    unsigned char x12;
    char pad13;
    RbObj* x14;
    char pad18[8];
    RbV4 x20;
    RbV4 x30;
    int x40;
    int x44;
    int x48;
    int x4C;
    int x50;
    int x54;
} RbReq;
typedef struct RbRouter { char pad0[0x20]; } RbRouter;
extern "C" {
RbReq* cPathSystem_GetRequest(RbRouter* r);
void cPathSystem_FreeRequest(RbRouter* r, RbReq* req);
RbNode* cAIPathData_GetNode(int i);
void cNode_GetLoc(RbV4* out, RbNode* n);
unsigned char cPathRequest_Update(RbReq* req);
unsigned char cPathSystem_RestorePath(RbRouter* r, int to, int from, RbObj* obj);
}
#pragma push
#pragma opt_propagation on
extern "C" unsigned char cPathSystem_RestorePath(RbRouter* r, int to, int from, RbObj* obj)
{
    int none;
    int saved = obj->x10;
    RbReq* req = cPathSystem_GetRequest(r);
    unsigned char res;
    RbNode* n;
    RbV4 t;
    req->dirty = 1;
    req->reported = 0;
    req->state = 1;
    /* retail folds the null actor into $zero but keeps the dead blocks (b over them): conditions that are assignment expressions are not folded by the IR propagation */
    { RbActor* actor = 0; req->serial = *((req->actor = actor) ? &actor->serial : (none = -1, &none)); RbActor* a; if ((a = actor)) req->serial2 = a->serial; }
    req->x14 = obj;
    req->x40 = to;
    req->x44 = -1;
    req->x4C = from;
    req->x12 = 1;
    VCopyF(&req->x20, &obj->pos);
    req->x50 = cAIPathData_GetNode(from)->x7C;
    n = cAIPathData_GetNode(to);
    req->x48 = n->x7C;
    cNode_GetLoc(&t, n);
    VCopyF(&req->x30, &t);
    req->x54 = 0;
    res = cPathRequest_Update(req);
    cPathSystem_FreeRequest(r, req);
    obj->x10 = saved;
    return res;
}
#pragma pop

