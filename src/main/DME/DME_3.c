/*
 * main/DME: 5 files, 00429770-00429A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "DME.h"

extern int PtrVec_Insert(int, int, int, int);

int PtrVec_PushBack_429770(int vec, int value) {
    int count;
    int data;

    count = *(int*)((char*)vec + 4);
    data = *(int*)((char*)vec + 8);
    return PtrVec_Insert(vec, (data + (count << 2)), 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_00429770 */

/* merge_units: begin func_00429790 */
#pragma push /* merge_units */
/* status 3 = connect failed */
typedef struct NetConnInfo_h5 { int session; int status; } NetConnInfo_h5;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern int g_DmeConnectRetries;
extern int g_DmeConnectMaxRetries;
extern signed char D_005724B0;
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(int a, int b, int c, int d, int e);
extern void NetGame_InitLocalSlot(int* out, int session);
extern void func_002EBBA0(int session, int* out);
static inline int LocalSlot_h5(int session)
{
    if (D_005721C8) {
        if (D_00494178 == -1) {
            NetGame_InitLocalSlot(&D_00494178, session);
        }
        return D_00494178;
    }
    return 0;
}
/* Connect callback (NetGame_Create / Net_ConnectGame). */
void DME_OnConnectResult(NetConnInfo_h5* info)
{
    int slot[2];
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    D_005721A8 = info->session;
    if (info->status == 3) {
        D_005724B0 = DME_STATE_DISCONNECTED;
        if (Gui_GetScreenStack()) {
            GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)"F_TO_CONNECT");
        }
    } else {
        D_005724B0 = DME_STATE_CONNECTED;
        D_005721C8 = 1;
        NetGame_InitLocalSlot(slot, info->session);
        D_00494178 = slot[0];
        func_002EBBA0(info->session, slot);
        if (slot[0] == LocalSlot_h5(D_005721A8) && Gui_GetScreenStack()) {
            GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 1, 0);
        }
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429790 */

/* merge_units: begin func_00429920 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int kind; int id; } Pk429920; /* id = client id */
extern "C" {
extern int D_005723F0;            /* connected client count */
extern unsigned char D_00572410;
extern unsigned char D_005721D8;   /* disconnect pending; reason in D_005721E0 */
extern char D_005721E0[];
extern char D_004BF9D0[]; /* "HOST_DISCONNECT" */
#if 0 /* merge_units */
extern unsigned char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(unsigned char*)&D_005724B0) /* merge_units */

extern unsigned char D_00572418[];  /* per-client "disconnected" flags */
extern int g_DmeClientLevelInfo[];
extern unsigned char D_005721C0;   /* this machine is the host */
extern int snprintf(char* buf, int n, const char* fmt, ...);
extern void func_0043B190(void* p);
extern void func_0043ACB0(void* p, int id);
}

#pragma define_section GUARD_DTOR_9920 ".dtors_drop" far_absolute RX
/* Scoped busy flag; the guard object also reserves the top stack slot retail has. */
struct Guard_9920 {
    char c;
    Guard_9920() { if (!D_005723C8) D_005723C8 = 1; }
    /* order matters: weak first, then the section (see alloc_guard.h) */
    __declspec(weak) __declspec(GUARD_DTOR_9920) ~Guard_9920() { D_005723C8 = 0; }
};
/* Client-left callback: drops the session if the host left, marks the client
   disconnected and (on the host) clears a pending level-info slot. */
extern "C" void DME_OnClientDisconnect(Pk429920* p)
{
    Guard_9920 g;
    int buf;
    int slot;
    unsigned char ok;
    D_005723F0--;
    func_002EBBA0(D_005721A8, &slot);
    if (p->id == slot) {
        D_00572410 = 1;
        D_005721D8 = 1;
        snprintf(D_005721E0, 0x10, D_004BF9D0);
        D_005724B0 = DME_STATE_DISCONNECTED;
    }
    D_00572418[p->id] = 1;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok) {
        if (g_DmeClientLevelInfo[3] == -1) g_DmeClientLevelInfo[3] = 0;
        else if (g_DmeClientLevelInfo[2] == -1) g_DmeClientLevelInfo[2] = 0;
        else if (g_DmeClientLevelInfo[1] == -1) g_DmeClientLevelInfo[1] = 0;
    }
    func_0043B190(&buf);
    func_0043ACB0(&buf, p->id);
}
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429920 */

/* merge_units: begin func_00429A60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_005721E0[16];
#endif /* merge_units */
#define D_005721E0 ((char*)&D_005721E0) /* merge_units */

extern int snprintf(char* buf, int size, const char* fmt, ...); /* snprintf-like */

/* Join-failure callback: records the "HOST_DISCONNECT" disconnect reason. */
void DME_OnHostDisconnect(void)
{
    D_00572410 = 1;
    D_005721D8 = 1;
    snprintf(D_005721E0, 16, D_004BF9D0);
}
#undef D_005721E0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429A60 */

/* merge_units: begin func_00429A90 */
#pragma push /* merge_units */
typedef struct { int kind; int id; } Pk429A90; /* id = client id */
#pragma push

/* Client-joined callback; the host then sends that client a NetLevelInfoMsg (DME_Update). */
void DME_OnClientConnect(Pk429A90* p) {
    unsigned char ok;
    if (!D_005723C8) D_005723C8 = 1;
    D_005723F0++;
    D_00572418[p->id] = 0;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok && p->id) g_DmeClientLevelInfo[p->id] = DME_LEVELINFO_PENDING;
    D_005723C8 = 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00429A90 */
