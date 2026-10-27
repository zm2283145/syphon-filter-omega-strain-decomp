/*
 * Libs/SFOLib/Source/DME: 6 files, 00429660-00429770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429660 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);
int EnableIntc(int);
char * cMemMan_Allocate(int, int, char *, int);
#if 0 /* merge_units */
int std_vector_tServerPtr_push_back(char *, void **);
#endif /* merge_units */
int std_vector_tServerPtr_push_back(); /* merge_units */

int strncpy(char * , int, int);
extern char D_004BF9B0; /* "DME.cc" */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern unsigned char D_005723C8;
extern char D_005724A0; /* game address list (NetworkGameList) */

#pragma push
#pragma opt_common_subs off
/* Appends a { char name[16]; int value; } entry to the game address list. */
void cDME_SvrResponseCallback(int name, int value) {
    struct { char pad40[8]; char * f48[2]; } sl;
    char * entry;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    entry = cMemMan_Allocate(0, 0x14, &D_004BF9B0, 0x72F);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (entry != NULL) {
        F_(entry, 0x10, int) = 0xE4A;
    }
    sl.f48[0] = entry;
    strncpy(entry, name, 0x10);
    F_(sl.f48[0], 0x10, int) = value;
    std_vector_tServerPtr_push_back(&D_005724A0, sl.f48);
    D_005723C8 = 0;
}
#pragma pop
static inline void merge_flush_func_00429660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429660 */

/* merge_units: begin func_00429770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "DME.h"

extern int std_vector_pod_int_insert(int, int, int, int);

int std_vector_tServerPtr_push_back(int vec, int value) {
    int count;
    int data;

    count = *(int*)((char*)vec + 4);
    data = *(int*)((char*)vec + 8);
    return std_vector_pod_int_insert(vec, (data + (count << 2)), 1, value);
}
static inline void merge_flush_func_00429770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429770 */

/* merge_units: begin func_00429790 */
#pragma push /* merge_units */
/* status 3 = connect failed */
typedef struct NetConnInfo_h5 { int session; int status; } NetConnInfo_h5;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern int g_DmeConnectRetries;
extern int g_DmeConnectMaxRetries;
extern signed char D_005724B0;
extern int Gui_Canvas(void);
extern void GuiWidget_SendMessage(int a, int b, int c, int d, int e);
extern void NetGetMyClientIndex(int* out, int session);
extern void NetGetPeerToPeerHostClientIndex(int session, int* out);
static inline int LocalSlot_h5(int session)
{
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) {
            NetGetMyClientIndex(&D_00494178, session);
        }
        return D_00494178;
    }
    return 0;
}
/* Connect callback (NetHostPeerToPeer / Net_ConnectGame). */
void DME_OnConnectResult(NetConnInfo_h5* info)
{
    int slot[2];
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    D_005721A8 = info->session;
    if (info->status == 3) {
        D_005724B0 = DME_STATE_DISCONNECTED;
        if (Gui_Canvas()) {
            GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 0x1E, 0, (int)"F_TO_CONNECT");
        }
    } else {
        D_005724B0 = DME_STATE_CONNECTED;
        g_IsMultiplayer = 1;
        NetGetMyClientIndex(slot, info->session);
        D_00494178 = slot[0];
        NetGetPeerToPeerHostClientIndex(info->session, slot);
        if (slot[0] == LocalSlot_h5(D_005721A8) && Gui_Canvas()) {
            GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 0x1E, 1, 0);
        }
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
    D_005723C8 = 0;
}
static inline void merge_flush_func_00429790(void) {} /* merge_units */
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
extern void cGenInfoObject_ctor(void* p);
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
extern "C" void cDME_RemoteClientDisconnectCallback(Pk429920* p)
{
    Guard_9920 g;
    int buf;
    int slot;
    unsigned char ok;
    D_005723F0--;
    NetGetPeerToPeerHostClientIndex(D_005721A8, &slot);
    if (p->id == slot) {
        D_00572410 = 1;
        D_005721D8 = 1;
        snprintf(D_005721E0, 0x10, D_004BF9D0);
        D_005724B0 = DME_STATE_DISCONNECTED;
    }
    D_00572418[p->id] = 1;
    if (g_IsMultiplayer) ok = D_005721C0; else ok = 1;
    if (ok) {
        if (g_DmeClientLevelInfo[3] == -1) g_DmeClientLevelInfo[3] = 0;
        else if (g_DmeClientLevelInfo[2] == -1) g_DmeClientLevelInfo[2] = 0;
        else if (g_DmeClientLevelInfo[1] == -1) g_DmeClientLevelInfo[1] = 0;
    }
    cGenInfoObject_ctor(&buf);
    func_0043ACB0(&buf, p->id);
}
#undef D_005724B0 /* merge_units */
static inline void merge_flush_func_00429920(void) {} /* merge_units */
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
void cDME_HostChangeCallback(void)
{
    D_00572410 = 1;
    D_005721D8 = 1;
    snprintf(D_005721E0, 16, D_004BF9D0);
}
#undef D_005721E0 /* merge_units */
static inline void merge_flush_func_00429A60(void) {} /* merge_units */
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
    if (g_IsMultiplayer) ok = D_005721C0; else ok = 1;
    if (ok && p->id) g_DmeClientLevelInfo[p->id] = DME_LEVELINFO_PENDING;
    D_005723C8 = 0;
}
#pragma pop
static inline void merge_flush_func_00429A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429A90 */
