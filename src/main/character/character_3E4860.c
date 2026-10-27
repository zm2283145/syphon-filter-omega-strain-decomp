/*
 * main/character: 14 files, 003E4860-003E5120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E4860 */
#pragma push /* merge_units */
#include "types.h"
/* Convert a 2.14 fixed-point integer to float. */
float Fixed14ToFloat(int value)
{
    return (1.0f / 16384.0f) * (float)value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4860 */

/* merge_units: begin func_003E4880 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline float fmin_(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; /* dead on purpose: retail keeps this addiu */ return *this; } } __attribute__((aligned(16)));
struct T80 { V a; V b; float c; float d; int e; };
extern "C" T80* cDestinationParams_ctor_cVectorR_cPlaneR_float_float(T80* t, const V* a, const V* b, float c, float d, int e);
T80* cDestinationParams_ctor_cVectorR_cPlaneR_float_float(T80* t, const V* a, const V* b, float c, float d, int e) {
    t->a = *a;
    t->b = *b;
    t->c = c;
    t->d = fmin_(1.0f, d);
    t->e = e;
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4880 */

/* merge_units: begin func_003E48C0 */
#pragma push /* merge_units */
/* Converts an unsigned fixed-point value with 15 fractional bits to float. */
float cCharActionMsg_DestinationParams_UnpackSpeedOfMotion(unsigned int value) {
    return (1.0f / 32768.0f) * (float)value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E48C0 */

/* merge_units: begin func_003E4900 */
#pragma push /* merge_units */
/* Converts a fixed-point value with 13 fractional bits to float. */
float cCharActionMsg_DestinationParams_UnpackDestinationRotZ(int value) {
    return (1.0f / 8192.0f) * (float)value;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4900 */

/* merge_units: begin func_003E4920 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern char D_004E0840[];         /* Msg3E43D0 vtable */
extern char g_ActorActionMsgClass[];         /* Msg3E43D0 type descriptor */
extern void* cMessage_ctor_cMessageNameR_messagebaseR(void* self, void* type, void* arg);

Vec4* cPlane_ctor_float_float_float_float(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Builds the message from explicit values. */
Msg3E43D0* cCharActionMsg_ctor_messagebaseR_int_eParamType(Msg3E43D0* self, void* arg, int a, int b) {
    cMessage_ctor_cMessageNameR_messagebaseR(self, g_ActorActionMsgClass, arg);
    self->vtable = D_004E0840;
    self->unk24 = a;
    self->unk28 = b;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4920 */

/* merge_units: begin func_003E49B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Sub { V4 v; float f40, f44; unsigned char b48; char p49[7]; } Sub;
typedef struct Packet { int kind, id; unsigned char a8, a9; char pad[2]; float x, y, z, w; float f1C, f20; unsigned char b24; } Packet;
typedef struct Msg { void* vt; char p4[0x20]; int a24; unsigned char a28; char p29[7]; Sub sub; char p50[0x10]; } Msg;
extern unsigned char D_005723C8, D_005721D0; extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0120[];
extern "C" {
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg*, void*, Packet*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
void** cNetObj_GetNetSystem(int); void QueueMessage_cMessageR_cSystemP_int_int(Msg*, void*, int, int); void cMessage_dtor(Msg*, int); }
static inline V4* V4_Set(V4* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; return v; }
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded address registers */
static inline void V4_Copy(V4* d, V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Sub_Set(Sub* s, V4* v, float a, float b, bool f, V4* d) { V4_Copy(d, v); s->f40 = a; s->f44 = b; s->b48 = f ? 1 : 0; }
extern "C" int cCharActionMsg_MotionParams_NetCharActionMotionParamsReq(int a, int b, int c, Packet* p0) {
    Msg msg; V4 v;
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Packet* p = p0;
        void** obj;
        Msg* m = &msg;
        cMessage_ctor_cMessageNameR_messagebaseR(m, g_ActorActionMsgClass, p);
        m->vt = D_004E0840;
        m->a24 = p->a8;
        m->a28 = p->a9;
        { bool fl = p->b24 != 0; Sub* ps = &m->sub; Sub_Set(&m->sub, V4_Set(&v, p->x, p->y, p->z, p->w), p->f1C, p->f20, fl, &ps->v); }
        m->vt = D_004E0120;
        obj = cNetObj_GetNetSystem(p->id);
        if (obj) QueueMessage_cMessageR_cSystemP_int_int(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x28;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E49B0 */

/* merge_units: begin func_003E4AF0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet_003E4AF0{int kind,id;unsigned char action,on;char pad[2];int a,b;float time;unsigned char enabled;}Packet_003E4AF0;
typedef struct Msg_003E4AF0{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];int a,b;float time;unsigned char enabled;char p39[3];}Msg_003E4AF0;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E0160[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4AF0*,void*,Packet_003E4AF0*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4AF0*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4AF0*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

int cCharActionMsg_ObjectId_Int_Scalar_Bool_NetCharActionNetObjectIdIntScalarBoolReq(int a,int b,int c,Packet_003E4AF0*p0){
 Msg_003E4AF0 msg;Packet_003E4AF0*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E0160;msg.a=p->a;msg.b=p->b;msg.time=p->time;msg.enabled=p->enabled;
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x1C;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4AF0 */

/* merge_units: begin func_003E4BE0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet_003E4BE0{int kind,id;unsigned char action,on;char pad[2];int a,b;}Packet_003E4BE0;
typedef struct Msg_003E4BE0{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];int a,b;char p34[4];}Msg_003E4BE0;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E0180[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4BE0*,void*,Packet_003E4BE0*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4BE0*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4BE0*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

int cCharActionMsg_ObjectId_Int_NetCharActionNetObjectIdIntReq(int a,int b,int c,Packet_003E4BE0*p0){
 Msg_003E4BE0 msg;Packet_003E4BE0*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E0180;msg.a=p->a;msg.b=p->b;
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x14;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4BE0 */

/* merge_units: begin func_003E4CC0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet_003E4CC0{int kind,id;unsigned char action,on;char pad[2];int a,b;}Packet_003E4CC0;
typedef struct Msg_003E4CC0{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];int a,b;char p34[4];}Msg_003E4CC0;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E01A0[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4CC0*,void*,Packet_003E4CC0*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4CC0*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4CC0*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

int cCharActionMsg_ObjectId_NetCharActionNetObjectIDReq(int a,int b,int c,Packet_003E4CC0*p0){
 Msg_003E4CC0 msg;Packet_003E4CC0*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E01A0;msg.a=p->a;
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x10;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4CC0 */

/* merge_units: begin func_003E4DA0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct V4Local{float x,y,z,w;}V4Local;
typedef struct Packet_003E4DA0{int kind,id;unsigned char action,on;char pad[2];V4Local vec;}Packet_003E4DA0;
typedef struct Msg_003E4DA0{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];char p2c[4];V4Local vec;char p40[8];}Msg_003E4DA0;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E0140[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4DA0*,void*,Packet_003E4DA0*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4DA0*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4DA0*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

static inline float GetX(Packet_003E4DA0*p){return p->vec.x;}
static inline void CopyV(V4Local*d,V4Local*s){float y;float z;float w;float x;w=s->w;z=s->z;y=s->y;x=s->x;d->x=x;d->y=y;d->z=z;d->w=w;}
int cCharActionMsg_Vector_NetCharActionVectorReq(int a,int b,int c,Packet_003E4DA0*p0){
 Msg_003E4DA0 msg;Packet_003E4DA0*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E0140;CopyV(&msg.vec,&p->vec);
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x1C;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4DA0 */

/* merge_units: begin func_003E4E90 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet_003E4E90{int kind,id;unsigned char action,on;char pad[2];float a;int b;}Packet_003E4E90;
typedef struct Msg_003E4E90{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];float a;int b;char p34[4];}Msg_003E4E90;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E01C0[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4E90*,void*,Packet_003E4E90*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4E90*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4E90*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

int cCharActionMsg_Scalar_NetCharActionScalarReq(int a,int b,int c,Packet_003E4E90*p0){
 Msg_003E4E90 msg;Packet_003E4E90*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E01C0;msg.a=p->a;
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x10;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4E90 */

/* merge_units: begin func_003E4F70 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct Packet_003E4F70{int kind,id;unsigned char action,on;char pad[2];float a;int b;}Packet_003E4F70;
typedef struct Msg_003E4F70{void*vt;char p4[0x20];int action;unsigned char on;char p29[3];int a,b;char p34[4];}Msg_003E4F70;extern char g_ActorActionMsgClass[],D_004E0840[],D_004E01E0[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR_messagebaseR(Msg_003E4F70*,void*,Packet_003E4F70*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR_messagebaseR(a0, a1, a2) ((void)cMessage_ctor_cMessageNameR_messagebaseR((void *)(a0), (a1), (void *)(a2))) /* merge_units */
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int_int(Msg_003E4F70*,void*,int,int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int_int(a0, a1, a2, a3) (QueueMessage_cMessageR_cSystemP_int_int((Msg *)(a0), (a1), (a2), (a3))) /* merge_units */
#if 0 /* merge_units */
void cMessage_dtor(Msg_003E4F70*,int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

int cCharActionMsg_Int_NetCharActionIntReq(int a,int b,int c,Packet_003E4F70*p0){
 Msg_003E4F70 msg;Packet_003E4F70*p;
 if(!D_005723C8)D_005723C8=1;
 p=p0;if(D_005721D0){void**obj;cMessage_ctor_cMessageNameR_messagebaseR(&msg,g_ActorActionMsgClass,p);msg.vt=D_004E0840;msg.action=p->action;msg.on=p->on;msg.vt=D_004E01E0;msg.a=(int)p->a;
 obj=cNetObj_GetNetSystem(p->id);if(obj)QueueMessage_cMessageR_cSystemP_int_int(&msg,*obj,0,0);
 msg.vt=D_004E0840;cMessage_dtor(&msg,0);}
 D_005723C8=0;return 0x10;
}
#undef cMessage_ctor_cMessageNameR_messagebaseR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E4F70 */

/* merge_units: begin func_003E5060 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void* reg);
extern int cMessage_RegisterFields(void* desc);
extern int cCharActionMsg_RegisterFields(void);
extern int NetMessageField(void* desc, void* field, int size, int count);
extern int NetRegisterApplicationMessage(void* t, void* fn);
extern int D_0055A218;
extern void cCharActionMsg_InteractParams_NetCharActionInteractParamsReq(void);
unsigned char cCharActionMsg_InteractParams_InitNet(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; char f14[16]; char f24[12]; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cCharActionMsg_RegisterFields() != 0
        && NetMessageField(&L.file, &L.fC, 4, 1) == 0
        && NetMessageField(&L.file, &L.f10, 4, 1) == 0
        && NetMessageField(&L.file, L.f14, 16, 1) == 0
        && NetMessageField(&L.file, L.f24, 12, 1) == 0
        && NetRegisterApplicationMessage(&D_0055A218, cCharActionMsg_InteractParams_NetCharActionInteractParamsReq) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E5060 */

/* merge_units: begin func_003E5120 */
#pragma push /* merge_units */
extern int D_0055A210;
extern void func_003E4430(void);
unsigned char cCharActionMsg_DestinationParams_InitNet(void* reg)
{
    struct { long long file; char f8[12]; char f14[16]; short f24; short f26; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cCharActionMsg_RegisterFields() != 0
        && NetMessageField(&L.file, L.f8, 12, 1) == 0
        && NetMessageField(&L.file, L.f14, 16, 1) == 0
        && NetMessageField(&L.file, &L.f24, 2, 1) == 0
        && NetMessageField(&L.file, &L.f26, 2, 1) == 0
        && NetRegisterApplicationMessage(&D_0055A210, func_003E4430) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E5120 */
