/*
 * SFOGame/Source/NetNPCMsgs: 2 files, 002D63E0-002D7020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D63E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
#include "types.h"
struct Npc_2D63E0;
typedef Npc_2D63E0 Obj_2D63E0;
struct Bits_2D63E0 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 5; };
struct Npc_2D63E0 {
    virtual void p8();
    virtual void pC();
    virtual void p10();
    virtual void p14();
    virtual void p18();
    virtual void p1C();
    virtual void p20();
    virtual void p24();
    virtual void p28();
    virtual void p2C();
    virtual void p30();
    virtual void p34();
    virtual void p38();
    virtual void p3C();
    virtual void p40();
    virtual void p44();
    virtual void p48();
    virtual void v4C();
    virtual void p50();
    virtual void p54();
    virtual int IsActive();
    virtual void p5C();
    virtual void p60();
    virtual void p64();
    virtual void p68();
    virtual void p6C();
    virtual void p70();
    virtual void p74();
    virtual void p78();
    virtual void p7C();
    virtual void p80();
    virtual void p84();
    virtual void p88();
    virtual void p8C();
    virtual void p90();
    virtual void p94();
    virtual void p98();
    virtual void p9C();
    virtual void vA0(int a);
    virtual void pA4();
    virtual void pA8();
    virtual void pAC();
    virtual void pB0();
    virtual void pB4();
    virtual void pB8();
    virtual void pBC();
    virtual void pC0();
    virtual void pC4();
    virtual void pC8();
    virtual void pCC();
    virtual void vD0(float f, unsigned char a, Obj_2D63E0* o);
    virtual void pD4();
    virtual void pD8();
    virtual void vDC(unsigned char a, int n);
    virtual void vE0();
    virtual void vE4(Obj_2D63E0* o);
    virtual void vE8(Obj_2D63E0* o);
    virtual void vEC();
    virtual void pF0();
    virtual void vF4(Obj_2D63E0* o);
    virtual void vF8();
    virtual void pFC();
    virtual void v100(int n);
    virtual void v104(Obj_2D63E0* o);
    virtual void v108(Obj_2D63E0* o, int n);
    virtual void v10C(int n);
    virtual void v110(float f);
    virtual void v114(unsigned char a);
    virtual void v118(signed char a);
    virtual void v11C();
    virtual void v120(unsigned char a, int b);
    virtual void v124();
    virtual void v128(Obj_2D63E0* o, float f, int i);
    virtual void v12C(Obj_2D63E0* o, float f, int i);
    virtual void p130();
    virtual void v134(int a);
    virtual void p138();
    virtual void v13C(int a);
    virtual void v140(float f);
    virtual void p144();
    virtual void p148();
    virtual void p14C();
    virtual void v150(unsigned char a, int b);
    virtual void v154(float f, int b);
    virtual void v158();
    virtual void p15C();
    virtual void p160();
    virtual void p164();
    virtual void v168();
    virtual void v16C(float f);
    virtual void p170();
    virtual void v174(int a);
    virtual void p178();
    virtual void p17C();
    virtual void p180();
    virtual void p184();
    virtual void p188();
    virtual void p18C();
    virtual void p190();
    virtual void p194();
    virtual void p198();
    virtual void v19C(Obj_2D63E0* o, float f, bool b);
    virtual void p1A0();
    virtual void p1A4();
    virtual void v1A8();
    virtual void v1AC(int a);
    virtual void p1B0();
    virtual void p1B4();
    virtual void p1B8();
    virtual void p1BC();
    virtual void p1C0();
    virtual void p1C4();
    virtual void p1C8();
    virtual void v1CC(float f);
    virtual void v1D0();
    virtual void v1D4(bool a, int b);
    virtual void v1D8(bool a, int b);
    virtual void p1DC();
    virtual void p1E0();
    virtual void p1E4();
    virtual void v1E8(bool a, int b);
    virtual void p1EC();
    virtual void p1F0();
    virtual void v1F4(int n);
    virtual void v1F8(int n);
    virtual void v1FC(int n);
    char pad04[0x54];
    Npc_2D63E0* f58;
    char pad5C[0xE5];
    Bits_2D63E0 f141;
};

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
extern "C" char D_004E0840[]; extern "C" void cMessage_dtor(void* msg, int flags);
struct H_2D63E0 { int v; H_2D63E0() {} H_2D63E0(int x) { v = x; } H_2D63E0(const H_2D63E0& o) { v = o.v; } };
struct V4_2D63E0 { float x, y, z, w; V4_2D63E0() {} V4_2D63E0& operator=(const V4_2D63E0& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; } V4_2D63E0(const V4_2D63E0& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); } };
struct MsgA_2D63E0 { void* vtbl; char pad04[0x20]; int a24; unsigned char a28; char pad29[3]; int a2C; inline MsgA_2D63E0(const H_2D63E0& h); __declspec(weak) __declspec(MSG_DTOR) ~MsgA_2D63E0() { vtbl = D_004E0840; cMessage_dtor(this, 0); } };
struct MsgB_2D63E0 { void* vtbl; char pad04[0x20]; int a24; unsigned char a28; char pad29[7]; V4_2D63E0 v; inline MsgB_2D63E0(const V4_2D63E0& v); __declspec(weak) __declspec(MSG_DTOR) ~MsgB_2D63E0() { vtbl = D_004E0840; cMessage_dtor(this, 0); } };
struct MsgC_2D63E0 { void* vtbl; char pad04[0x20]; int a24; unsigned char a28; char pad29[3]; unsigned char a2C; char pad2D[3]; inline MsgC_2D63E0(); __declspec(weak) __declspec(MSG_DTOR) ~MsgC_2D63E0() { vtbl = D_004E0840; cMessage_dtor(this, 0); } };
extern "C" {
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004E01A0[];
extern char D_004E0140[];
extern char D_004D9320[];
extern unsigned char D_0048C420;
Obj_2D63E0* nGobjManager_LookupGOBJ_cObjectIdR(const H_2D63E0& h);
int cAIPathData_GetNode(int n);
void cNPC_Deactivate_cGOBJP(Npc_2D63E0* n, Obj_2D63E0* o);
void cGameGobjController_SetSkill_float_2(Npc_2D63E0* n, float f);
void cNPC_ActivateByRadius(Npc_2D63E0* n, float f);
void cNPC_ActivateByRadiusOff(Npc_2D63E0* n);
void MakeNPCNetInteractable(Obj_2D63E0* o, H_2D63E0 h);
void cNetNPC_NetFollow(Npc_2D63E0* n, Obj_2D63E0* o, float a, float b);
void cNetNPC_NetTeleport(Npc_2D63E0* n, int a);
void cNetNPC_NodeReachedByLocalNpc(Npc_2D63E0* n, int a);
void cMessage_ctor_cMessageNameR(void* msg, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
void cMessage_dtor(void* msg, int flags);
}
#define F_(x) (*(float*)&(x))
#define U8_(x) (*(unsigned char*)&(x))
#define S8_(x) (*(signed char*)&(x))
MsgA_2D63E0::MsgA_2D63E0(const H_2D63E0& h) { MsgA_2D63E0* m = (MsgA_2D63E0*)(void*)this;
    cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
    m->vtbl = D_004E0840;
    m->a24 = 0x3D;
    m->a28 = 5;
    m->vtbl = D_004E01A0;
    m->a2C = h.v;
}
MsgB_2D63E0::MsgB_2D63E0(const V4_2D63E0& v) { MsgB_2D63E0* m = (MsgB_2D63E0*)(void*)this;
    cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
    m->vtbl = D_004E0840;
    m->a24 = 0x3D;
    m->a28 = 4;
    m->vtbl = D_004E0140; m->v = v;

}
MsgC_2D63E0::MsgC_2D63E0() { MsgC_2D63E0* m = (MsgC_2D63E0*)(void*)this;
    cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
    m->vtbl = D_004E0840;
    m->a24 = 0x3D;
    m->a28 = 1;
    m->vtbl = D_004D9320;
    m->a2C = D_0048C420;
}



static inline void SendA_2D63E0(Obj_2D63E0* o, const H_2D63E0& h) { MsgA_2D63E0 m(h); QueueMessage_cMessageR_cSystemP_int(&m, o, 0); }
static inline void SendB_2D63E0(Obj_2D63E0* o, const V4_2D63E0& v) { MsgB_2D63E0 m(v); QueueMessage_cMessageR_cSystemP_int(&m, o, 0); }
static inline void SendC_2D63E0(Obj_2D63E0* o) { MsgC_2D63E0 m; QueueMessage_cMessageR_cSystemP_int(&m, o, 0); }
#pragma push
#pragma opt_lifetimes off
extern "C" void cNetNPCMsgs_DoNPCMethod(Obj_2D63E0* obj, int cmd, int a, int b, int c)
{
    if (obj && obj->f58) {
    if (obj->f58->IsActive()) {
        Npc_2D63E0* npc = obj->f58;
        Obj_2D63E0* t = 0;
        switch ((unsigned char)cmd) {
        case 0x27:
            npc->v4C();
            break;
        case 0x28: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) cNPC_Deactivate_cGOBJP(npc, t);
            break;
        }
        case 0xE: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) npc->v128(t, F_(b), c);
            break;
        }
        case 0xF: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) npc->v12C(t, F_(b), c);
            break;
        }
        case 0x10:
            npc->v134(a);
            break;
        case 0x24:
            npc->vA0(a);
            break;
        case 0x1:
            if (b != -1) npc->vDC(U8_(a), cAIPathData_GetNode(b));
            else npc->vDC(U8_(a), 0);
            break;
        case 0x25: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            npc->v108(t, cAIPathData_GetNode(b));
            break;
        }
        case 0x2:
            npc->vE0();
            break;
        case 0x3: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) npc->vE4(t);
            break;
        }
        case 0x4:
            npc->vEC();
            break;
        case 0x6:
            npc->v100(cAIPathData_GetNode(a));
            break;
        case 0x2C: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            npc->v104(t);
            break;
        }
        case 0x7:
            npc->v10C(cAIPathData_GetNode(a));
            break;
        case 0x8:
            npc->v110(F_(a));
            break;
        case 0x9:
            npc->v114(U8_(a));
            break;
        case 0xA:
            npc->v118(S8_(a));
            break;
        case 0xB:
            npc->v11C();
            break;
        case 0xC:
            npc->v120(U8_(a), b);
            break;
        case 0xD:
            npc->v124();
            break;
        case 0x11:
            npc->v13C(a);
            break;
        case 0x12:
            npc->v140(F_(a));
            break;
        case 0x14:
            npc->v150(U8_(a), b);
            break;
        case 0x15:
            npc->v154((float)(unsigned int)a, b);
            break;
        case 0x16:
            npc->v158();
            break;
        case 0x18:
            npc->f141.b2 = a != 0;
            break;
        case 0x19:
            npc->v168();
            break;
        case 0x2E:
            npc->v1E8(a != 0, 1);
            break;
        case 0x37:
            cGameGobjController_SetSkill_float_2(npc, F_(a));
            break;
        case 0x1A:
            npc->v16C(F_(a));
            break;
        case 0x1E: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) npc->v19C(t, (float)(unsigned int)b, c != 0);
            break;
        }
        case 0x1F:
            npc->v1A8();
            break;
        case 0x20:
            npc->v1AC(a);
            break;
        case 0x21:
            npc->v1D4(a != 0, 0);
            break;
        case 0x29: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) npc->vE8(t);
            break;
        }
        case 0x2A: {
            t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a));
            if (t) MakeNPCNetInteractable(t, H_2D63E0(b));
            break;
        }
        case 0x2F:
            npc->v1F4(cAIPathData_GetNode(a));
            break;
        case 0x30:
            npc->v1F8(cAIPathData_GetNode(a));
            break;
        case 0x31:
            npc->v1FC(cAIPathData_GetNode(a));
            break;
        case 0x35:
            if (a != -1) { t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a)); }
            npc->vF4(t);
            break;
        case 0x36:
            npc->vF8();
            break;
        case 0x33:
            npc->v1CC((float)(unsigned int)a);
            break;
        case 0x34:
            npc->v1D0();
            break;
        case 0x38:
            npc->v174(a);
            break;
        case 0x39:
            npc->v1D8(a != 0, 0);
            break;
        case 0x3B:
            if (b != -1) {
                t = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(b));
                if (t) npc->vD0(0.0f, U8_(a), t);
            }
            break;
        }
    } else {
        Npc_2D63E0* npc = obj->f58; Obj_2D63E0* t2;
        switch ((unsigned char)cmd) {
        case 0x2D:
            cNetNPC_NodeReachedByLocalNpc(npc, a);
            break;
        case 0x18:
            npc->f141.b2 = a != 0;
            break;
        case 0xE:
            if (a) {
                if (!b) {
                    if (nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a))) {
                                                SendA_2D63E0(obj, H_2D63E0(a));
                    }
                } else {
                                        V4_2D63E0 v;
                    float tx, ty, tz; tz = F_(c); ty = F_(b); tx = F_(a); v.w = 1.0f;
                    v.z = tz;
                    v.y = ty;
                    v.x = tx;
                    SendB_2D63E0(obj, v);
                }
            } else {
                                SendC_2D63E0(obj);
            }
            break;
        case 0x24:
            break;
        case 0x2A: {
            if ((t2 = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a)))) MakeNPCNetInteractable(t2, H_2D63E0(b));
            break;
        }

        case 0x21:
            npc->v1D4(a != 0, 0);
            break;
        case 0x39:
            npc->v1D8(a != 0, 0);
            break;
        case 0x2E:
            npc->v1E8(a != 0, 1);
            break;
        case 0x32: {
            t2 = nGobjManager_LookupGOBJ_cObjectIdR(H_2D63E0(a)); cNetNPC_NetFollow(npc, t2, F_(b), F_(c));
            break;
        }
        case 0x33:
            cNPC_ActivateByRadius(npc, (float)(unsigned int)a);
            break;
        case 0x34:
            cNPC_ActivateByRadiusOff(npc);
            break;
        case 0x37:
            cGameGobjController_SetSkill_float_2(npc, F_(a));
            break;
        case 0x7:
            cNetNPC_NetTeleport(npc, a);
            break;
        case 0x3A:
            break;
        }
    }
}
}
#pragma pop
static inline void merge_flush_func_002D63E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D63E0 */

/* merge_units: begin func_002D7020 */
#pragma push /* merge_units */
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[1]; } F6ObjNet;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(F6ObjNet*);
extern int NetMessageField(F6ObjNet*, void*, int, int);
extern int NetRegisterMessage(void*, int, void*);
extern char D_0051F0A0[];
extern void cNetNPCMsgs_NetNPCMsgsCallback(void);
unsigned char cNetNPCMsgs_InitNet(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&s) && err == 0
        && NetMessageField(&s, &s.b8, 1, 1) == 0 && NetMessageField(&s, &s.iC, 4, 1) == 0 && NetMessageField(&s, &s.i10, 4, 1) == 0 && NetMessageField(&s, s.name, 4, 1) == 0
        && NetRegisterMessage(D_0051F0A0, 2, cNetNPCMsgs_NetNPCMsgsCallback) == 0) {
        ok = 1;
    }
    return ok;
}
static inline void merge_flush_func_002D7020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7020 */
