/*
 * SFOGame/Source/path: 2 files, 0015F3D0-0015F510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015F3D0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0015F3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015F3D0 */

/* merge_units: begin func_0015F510 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma inline_depth(8)
struct CxFrV4 {
    float x,y,z,w;
    CxFrV4(){}
    CxFrV4(const CxFrV4& o){ CxFrV4* d = this; const CxFrV4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    CxFrV4& operator=(const CxFrV4& o){ CxFrV4* d = this; const CxFrV4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct CxFrReq {void* actor;int serial;char pad8[4];unsigned char type,dirty,reported;char padF[0x11];CxFrV4 to;CxFrV4 from;int a;char pad44[4];int b;int c;int d;};
struct CxFrLink {CxFrLink*next;CxFrLink*prev;CxFrReq*req;};
struct CxFrList {int count;void*unused;CxFrLink*head;};
struct CxFrManager {char pad[0x2C];CxFrList cache;};
struct CxFrIt {CxFrLink*link;bool operator!=(const CxFrIt&o)const{return link!=o.link;}CxFrReq*Req(){return link->req;}};
extern "C" {
CxFrIt std_list_cPathSystemRequestPtr_begin_void(CxFrList*);
CxFrIt cLListIterator_cPathSystemRequestPtr_ctor(const CxFrIt&);
CxFrIt std_list_cPathSystemRequestPtr_end_void(CxFrList*);
}
static inline CxFrIt CxFr_Begin(CxFrList*l){return cLListIterator_cPathSystemRequestPtr_ctor(std_list_cPathSystemRequestPtr_begin_void(l));}
static inline CxFrIt CxFr_End(CxFrList*l){return cLListIterator_cPathSystemRequestPtr_ctor(std_list_cPathSystemRequestPtr_end_void(l));}
static inline CxFrV4 CxFr_Sub(CxFrV4*a,CxFrV4*b){
    CxFrV4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline float CxFr_LenSq(CxFrV4 v){
    CxFrV4 tv=v;
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&tv) : "memory");
    return r;
}
extern "C" CxFrReq*cPathSystem_FindSimilarPastRequest_int_int_int_int_etc(CxFrManager*self,int a,int b,int c,int d,CxFrV4*from,CxFrV4*to){
    CxFrIt cur=CxFr_Begin(&self->cache);
    for(;cur!=CxFr_End(&self->cache);cur.link=cur.link->prev){
        CxFrReq* req=cur.Req();
        if(req->type!=1)continue;
        if(!req->reported)continue;
        if(a!=req->a)continue;
        if(c!=req->c)continue;
        if(b!=req->b)continue;
        if(d!=req->d)continue;
        bool ok=true;
        if(a<0){
            CxFrV4 d; d=CxFr_Sub(from,&req->from); if(!(d.LenSq()<=16.0f))ok=false;
        }
        if(ok&&c<0){
            CxFrV4 d; d=CxFr_Sub(to,&req->to); if(!(d.LenSq()<=16.0f))ok=false;
        }
        if(!ok)continue;
        return req;
    }
    return 0;
}
static inline void merge_flush_func_0015F510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015F510 */
