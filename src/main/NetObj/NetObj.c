/*
 * main/NetObj: 4 files, 003FAD50-003FB340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FAD50 */
#pragma push /* merge_units */
extern int NetSendMessage(char type, int session, int target, int flags, int a, int b, void *c);
extern void printf(const char *fmt, ...);
extern int DME_Update(void);
extern int cDME_GetTime(int);
extern char *strncpy(char *d, const char *s, unsigned int n);

extern unsigned char D_005721D0;
extern unsigned char D_0055C9E0;
extern int D_0055C9D8;
extern int D_0055C9A0;
extern int D_0055C9A4[4];
extern int D_0055C9A8;
extern int D_0055C9AC;
extern int D_0055C9B0;
extern unsigned char D_0055C780[];
extern int D_005721A8;
extern char D_005723B0;
extern char D_005721D8;
extern char D_005721E0[];
extern char D_005721F0;
extern char D_004BE2B0[];
extern char D_004BE2E0[];
extern char D_004BE320[];
extern char D_004BE330[];

unsigned char cNetObj_SendMessage_int_int_ucharP_int_etc(int a, int b, void *c, int target, int type)
{
    unsigned char ok;
    int r;
    int r2;
    unsigned char st;

    ok = 0;
    if (D_005721D0) {
        if (D_0055C9E0 || D_0055C9D8 + 1000 < cDME_GetTime(1)) {
            D_0055C9D8 = cDME_GetTime(1);
            D_0055C9A0 = 0;
            D_0055C9A4[0] = 0;
            D_0055C9A8 = 0;
            D_0055C9AC = 0;
            D_0055C9B0 = 0;
            D_0055C9E0 = 0;
        }
        if (target > -1) {
            st = D_0055C780[target];
            if (st != 1 && st != 2) {
                return 0;
            }
        }
        r = NetSendMessage(type, D_005721A8, target == -1 ? -1 : target, 2, a, b, c);
        if (r == 0) {
            ok = 1;
        } else {
            if (!DME_Update() && type != 0x40) {
                r2 = NetSendMessage(type, D_005721A8, target == -1 ? -1 : target, 2, a, b, c);
                if (r2 == 0) {
                    ok = 1;
                } else {
                    printf(D_004BE2B0, r2);
                }
            }
            if (r == 0x25 || r == 0x23) {
                if (target == -1) {
                    D_0055C9A0++;
                    if (D_0055C9A0 > 25) {
                        printf(D_004BE2E0);
                        D_005723B0 = 0;
                        D_005721D8 = 1;
                        strncpy(D_005721E0, D_004BE320, 0x10);
                        D_005721F0 = 0;
                    }
                } else {
                    D_0055C9A4[target]++;
                    if (D_0055C9A4[target] > 25) {
                        printf(D_004BE330);
                        D_005723B0 = 0;
                        D_005721D8 = 1;
                        strncpy(D_005721E0, D_004BE320, 0x10);
                        D_005721F0 = 0;
                    }
                }
            }
        }
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FAD50 */

/* merge_units: begin func_003FB020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Event3FB020 {
    virtual int Dummy0();
    virtual int Dummy1();
    virtual int Serialize(int target, int* handle, int time, int a4, int size, char* buf);
    char pad04[0x18];
    int f1C;
    unsigned char flags;
    char pad21[3];
    int kind;
    unsigned char sub;
};

extern "C" {
extern int D_0055C7B8;
extern int g_ActorActionMsgClass;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
int cDME_GetTime(int);
int* cMessage_Name(Event3FB020*);
unsigned char cNetObj_SendMessage_int_int_ucharP_int_etc(int a, int b, void* c, int target, int type);
void NetGetPeerToPeerHostClientIndex(int, int*);
}

extern "C" int cNetObj_SendMessage_int_cMessageR_int_int(int target, Event3FB020* e, int a2, int a3)
{
    char buf[0x400];
    int handle;
    int peer;
    int r;
    unsigned char send;

    r = e->Serialize(target, &handle, cDME_GetTime(0), D_0055C7B8, 0x400, buf);
    if (D_005721D0 && target > -1 && r > -1) {
        send = 1;
        int* ty = cMessage_Name(e);
        if (*ty == g_ActorActionMsgClass) {
            if (e->sub == 1 || e->sub == 0xC || e->kind == 1 || e->kind == 2 || e->kind == 0x43 ||
                e->kind == 0x3E || e->kind == 0x3F || e->kind == 0x39 || e->kind == 0x3A || e->kind == 0xD)
                send = 0;
        }
        if (send && e->flags != 1) {
            if ((e->flags & 0x15) || (e->flags & 5) || (e->flags & 4)) {
                if (!cNetObj_SendMessage_int_int_ucharP_int_etc(handle, r, buf, a3, e->f1C))
                    r = -1;
            }
            if (e->flags & 8) {
                if (!cNetObj_SendMessage_int_int_ucharP_int_etc(handle, r, buf, a2, e->f1C))
                    r = -1;
            }
            if (e->flags & 2) {
                if (!(g_IsMultiplayer ? D_005721C0 : 1)) {
                    int type = e->f1C;
                    NetGetPeerToPeerHostClientIndex(D_005721A8, &peer);
                    if (!cNetObj_SendMessage_int_int_ucharP_int_etc(handle, r, buf, peer, type))
                        r = -1;
                }
            }
        }
    }
    return r != 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB020 */

/* merge_units: begin func_003FB250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int cCharActionMsg_InteractParams_InitNet(void);
extern int cCharActionMsg_DestinationParams_InitNet(void);
extern int cCharActionMsg_MotionParams_InitNet(void);
extern int cCharActionMsg_ObjectId_Int_Scalar_Bool_InitNet(void);
extern int cCharActionMsg_ObjectId_Int_InitNet(void);
extern int cCharActionMsg_ObjectId_InitNet(void);
extern int cCharActionMsg_Vector_InitNet(void);
extern int cCharActionMsg_Scalar_InitNet(void);
extern int cCharActionMsg_Int_InitNet(void);
extern int cCharActionMsg_InitNet(void);
extern int cDisableMsg_InitNet(void);
extern int cEnableMsg_InitNet(void);
extern int cDamageMsg_InitNet(void);
extern int cActivateMsg_InitNet(void);
extern int cDeactivateMsg_InitNet(void);
extern int cNetActivateAndControlMsg_InitNet(void);
extern int cNetPlayGameMsg_InitNet(void);
extern int cNetSetGobjMsg_InitNet(void);
extern int cNetTerrainActivation_InitNet(void);
extern int cNetTransferMsg_InitNet(void);
extern int cNPCInfoObject_InitNet(void);
extern int HeadsetSemaphore_InitNet(void);
extern int cGenInfoObject_InitNet(void);
extern int cNetTransferRecvMsg_NetRegister(void);
extern int cNetMsg_InitNet(void);

/*
 * Runs the per-class registration functions of the message/event types (each
 * callee registers one class), then stores cDME_GetTime(0) in D_0055C7B8.
 */
void cNetObj_NetInit(void) {
    cCharActionMsg_InitNet();
    cCharActionMsg_Scalar_InitNet();
    cCharActionMsg_Int_InitNet();
    cCharActionMsg_Vector_InitNet();
    cCharActionMsg_ObjectId_InitNet();
    cCharActionMsg_ObjectId_Int_InitNet();
    cCharActionMsg_ObjectId_Int_Scalar_Bool_InitNet();
    cCharActionMsg_MotionParams_InitNet();
    cCharActionMsg_DestinationParams_InitNet();
    cCharActionMsg_InteractParams_InitNet();
    cNetActivateAndControlMsg_InitNet();
    cNetPlayGameMsg_InitNet();
    cNetSetGobjMsg_InitNet();
    cNetTransferMsg_InitNet();
    cNetTerrainActivation_InitNet();
    cDamageMsg_InitNet();
    cDeactivateMsg_InitNet();
    cActivateMsg_InitNet();
    cDisableMsg_InitNet();
    cEnableMsg_InitNet();
    cNetTransferRecvMsg_NetRegister();
    HeadsetSemaphore_InitNet();
    cNPCInfoObject_InitNet();
    cGenInfoObject_InitNet();
    cNetMsg_InitNet();
    D_0055C7B8 = cDME_GetTime(0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB250 */

/* merge_units: begin func_003FB340 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

struct Ctrl {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual unsigned char GetState();
};
struct NObj { char pad[0x49]; unsigned char type; char pad4A[0xE]; Ctrl* ctrl; };
struct NMap { NObj* obj; int index; };

extern "C" {
NMap* cNetObj_GetNetSystem(int id);
void* cMemMan_Allocate(int, int, char*, int);
void* cNPCInfoObject_ctor(void* p);
int cNPCInfoObject_GetOwner_uint(void* mgr, int id);
extern void* D_0055C988;
extern char D_004BE228[];
int cNetObj_GetOwner(int id);
}

extern "C" int cNetObj_GetOwner(int id) {
    NMap* m = cNetObj_GetNetSystem(id);
    int r = -1;
    if (m) {
        NObj* o = m->obj;
        if (o->ctrl && o->type == 2) {
            if (o->ctrl->GetState() == 2 || o->ctrl->GetState() == 1) {
                if (!D_0055C988) {
                    void* p;
                    {
                        AllocGuard g;
                        p = cMemMan_Allocate(0, 1, D_004BE228, 0x22F);
                    }
                    if (p) p = cNPCInfoObject_ctor(p);
                    D_0055C988 = p;
                }
                r = cNPCInfoObject_GetOwner_uint(D_0055C988, id);
            } else {
                r = m->index;
            }
        } else {
            r = m->index;
        }
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB340 */
