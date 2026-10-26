#pragma cplusplus on
#include "types.h"
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
extern "C" CxFrReq*NpcRoute_FindCachedRequest(CxFrManager*self,int a,int b,int c,int d,CxFrV4*from,CxFrV4*to){
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








