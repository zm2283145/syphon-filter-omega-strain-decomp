/*
 * Libs/SFOLib/Source/DME: 7 files, 0042A150-0042A640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A150 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetLevelInfoMsg_dtor, D_004E1180, cMessage_dtor)
static inline void merge_flush_func_0042A150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A150 */

/* merge_units: begin func_0042A1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "DME.h"
typedef struct NetHostCfg_A1B0 {
    int unk00;
    int handle;
    char name[0xC];
    int unk14;
    int unk18;
    int unk1C;
    void* onJoinResult;
    int unk24;
    void* onClientJoined;
    int unk2C;
} NetHostCfg_A1B0;
typedef struct NetHostOut_A1B0 { int a, b, c; } NetHostOut_A1B0;
extern "C" {
extern int g_DmeThreadId;
extern int g_DmeMainThreadId;
extern unsigned char g_DmeThreadStopRequest;
extern bool g_DmeThreadExited;
extern unsigned char D_00572528;
extern int D_00572508;
extern unsigned char g_ProfileLockEnabled;
extern unsigned char D_005724B0;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00497540;
extern unsigned char D_005721D8;
extern char D_005721E0[];
extern char D_004BFA10[]; /* "Foo" */
extern char D_004BFA18[]; /* "F_TO_JOINGAME" */
#if 0 /* merge_units */
int ReferThreadStatus(int tid, EeThreadParam* st);
#endif /* merge_units */
int ReferThreadStatus(int, void*); /* merge_units */
#define ReferThreadStatus(a0, a1) (ReferThreadStatus((a0), (void *)(a1))) /* merge_units */

int ChangeThreadPriority(int tid, int prio);
int iWakeupThread(int tid);
int DelayThread(int prio);
void NetSetDefaultJoinParams(NetHostCfg_A1B0* cfg);
int NetJoin(NetHostCfg_A1B0* cfg, NetHostOut_A1B0* out);
int NetGetLocalTime(int* t);
int DME_Update(void);
void cDME_LocalJoinCallback(void);
void cNetObj_RemoteClientJoinCallback(void);
int cHeadSet_ShutdownAudio(void);
int NetLeave(int);
int NetDisconnect(int);
void cDME_ExitGame(void);
char* strncpy(char* d, const char* s, unsigned int n);
int sprintf(char* d, const char* f, ...);
}
static inline int NetTimeMs(void) { int t; return NetGetLocalTime(&t) == 0 ? t : -1; }
enum NetRole_A1B0 { ROLE_CLIENT_A1B0, ROLE_HOST_A1B0 };
static inline int IsHost(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
/* leaves the game and records "F_TO_JOINGAME" as the disconnect reason */
static inline void AbortJoin(void)
{
    D_00497540 = 1;
    cHeadSet_ShutdownAudio();
    NetLeave(0);
    NetDisconnect(0);
    cDME_ExitGame();
    D_005721D8 = 1;
    sprintf(D_005721E0, D_004BFA18);
}
#pragma opt_propagation off
/* Stops the DME thread, then joins the game and polls DME_Update until the join
   completes (cDME_LocalJoinCallback) or 15 s pass. */
extern "C" void cDME_JoinGame(void)
{
    NetHostOut_A1B0 out;
    NetHostCfg_A1B0 cfg;
    EeThreadParam worker;
    EeThreadParam caller;
    const char* name;
    int err;
    int deadline;
    int woken;
    ReferThreadStatus(g_DmeThreadId, &worker);
    ReferThreadStatus(g_DmeMainThreadId, &caller);
    if (worker.currentPriority <= caller.currentPriority) {
        ChangeThreadPriority(g_DmeThreadId, 0);
    }
    g_DmeThreadStopRequest = 1;
    woken = iWakeupThread(g_DmeThreadId);
    DelayThread(10);
    if (woken == g_DmeThreadId) {
        while (!g_DmeThreadExited) {
            DelayThread(10);
        }
    }
    g_DmeThreadStopRequest = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    g_DmeThreadExited = 0;
    g_ProfileLockEnabled = 0;
    if (D_005724B0 != DME_STATE_JOINED && D_005724B0 != DME_STATE_DISCONNECTED) {
    D_005724B0 = DME_STATE_JOINING;
    name = D_004BFA10;
    NetSetDefaultJoinParams(&cfg);
    cfg.handle = D_005721A8;
    strncpy(cfg.name, name, 0xC);
    cfg.unk14 = 0x1F4;
    cfg.unk18 = 0;
    cfg.unk1C = IsHost() ? ROLE_HOST_A1B0 : ROLE_CLIENT_A1B0;
    cfg.onJoinResult = cDME_LocalJoinCallback;
    cfg.unk24 = 0;
    cfg.onClientJoined = cNetObj_RemoteClientJoinCallback;
    cfg.unk2C = 0;
    err = NetJoin(&cfg, &out);
    if (err == 0) {
    deadline = NetTimeMs() + 15000;
    if (IsHost()) {
        while (!err && D_005724B0 == DME_STATE_JOINING) {
            err = DME_Update();
            if (deadline < NetTimeMs()) { err = 1; break; }
        }
    } else {
        while (!err && (D_005724B0 == DME_STATE_JOINING || D_005724B0 == DME_STATE_JOIN_WAIT)) {
            err = DME_Update();
            if (deadline < NetTimeMs()) { err = 1; break; }
        }
    }
    if (!err) {
        if (D_005724B0 != DME_STATE_JOINED && D_005724B0 == DME_STATE_JOIN_FAILED) {
            AbortJoin();
        }
    } else {
        AbortJoin();
    }
    }
    }
}
#undef ReferThreadStatus /* merge_units */
static inline void merge_flush_func_0042A1B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A1B0 */

/* merge_units: begin func_0042A520 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "network_session_types.h"

extern "C" {
extern signed char D_005724C0; /* set on first use (lazy-init guard) */
static unsigned int dat_004941A0[4] = { 0x1, 0x0, 0x0, 0x0 }; /* byte 0: restart from the list head */
extern NetworkGameList D_005724A0;
extern NetworkGameIterator g_DmeGameIter;
#if 0 /* merge_units */
void std_vector_tServerPtr_begin(NetworkGameIterator* result, NetworkGameList* list);
#endif /* merge_units */
struct Iter; /* merge_units */
struct PtrVec; /* merge_units */
void std_vector_tServerPtr_begin(Iter* out, PtrVec* v); /* merge_units */
#define std_vector_tServerPtr_begin(a0, a1) (std_vector_tServerPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_vector_tServerPtr_end(NetworkGameIterator* result, NetworkGameList* list);
#endif /* merge_units */
struct Iter; /* merge_units */
struct PtrVec; /* merge_units */
void std_vector_tServerPtr_end(Iter* out, PtrVec* v); /* merge_units */
#define std_vector_tServerPtr_end(a0, a1) (std_vector_tServerPtr_end((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cArray_tServerPtr_Iterator_ctor(NetworkGameIterator* destination, const NetworkGameIterator* source);
#endif /* merge_units */
struct Word; /* merge_units */
Word* cArray_tServerPtr_Iterator_ctor(Word* dst, Word* src); /* merge_units */
#define cArray_tServerPtr_Iterator_ctor(a0, a1) ((void)cArray_tServerPtr_Iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
char* strncpy(char* destination, const char* source, unsigned int count);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (a2))) /* merge_units */

}

static inline int different_iterator(const NetworkGameIterator& first, const NetworkGameIterator& second)
{
    return (first.entry == second.entry) ^ 1;
}

/* Enumerate a game address and restart from the beginning after reaching the end. */
extern "C" bool cDME_GetServerFromList(NetworkGameAddress* destination)
{
    NetworkGameIterator begin;
    NetworkGameIterator end;
    NetworkGameIterator rawBegin;
    NetworkGameIterator rawEnd;
    if (!D_005724C0)
        D_005724C0 = 1;
    bool found = false;
    if ((*(unsigned char*)dat_004941A0)) {
        std_vector_tServerPtr_begin(&rawBegin, &D_005724A0);
        cArray_tServerPtr_Iterator_ctor(&begin, &rawBegin);
        g_DmeGameIter = begin;
        (*(unsigned char*)dat_004941A0) = 0;
    }
    std_vector_tServerPtr_end(&rawEnd, &D_005724A0);
    cArray_tServerPtr_Iterator_ctor(&end, &rawEnd);
    if (different_iterator(g_DmeGameIter, end)) {
        strncpy(destination->name, (*g_DmeGameIter.entry)->name, 16);
        destination->value = (*g_DmeGameIter.entry)->value;
        ++g_DmeGameIter.entry;
        found = true;
    } else {
        (*(unsigned char*)dat_004941A0) = 1;
    }
    return found;
}
#undef std_vector_tServerPtr_begin /* merge_units */
#undef std_vector_tServerPtr_end /* merge_units */
#undef cArray_tServerPtr_Iterator_ctor /* merge_units */
#undef strncpy /* merge_units */
static inline void merge_flush_func_0042A520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A520 */

/* merge_units: begin func_0042A640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_tServerPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_tServerPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_tServerPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_0042A640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A640 */

/* merge_units: begin func_0042A680 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
extern unsigned char g_DmeThreadExited;
#endif /* merge_units */
#define g_DmeThreadExited (*(unsigned char*)&g_DmeThreadExited) /* merge_units */

#if 0 /* merge_units */
void ReferThreadStatus(int thread, EeThreadParam* status);
#endif /* merge_units */
#define ReferThreadStatus(a0, a1) ((void)ReferThreadStatus((a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void ChangeThreadPriority(int thread, int priority);
#endif /* merge_units */
#define ChangeThreadPriority(a0, a1) ((void)ChangeThreadPriority((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int iWakeupThread(int thread);
#endif /* merge_units */
#define iWakeupThread(a0) (iWakeupThread((a0))) /* merge_units */

#if 0 /* merge_units */
void DelayThread(int delay);
#endif /* merge_units */
#define DelayThread(a0) ((void)DelayThread((a0))) /* merge_units */

}

/* Stop the DME thread: request the stop, wake it and wait until cDME_ThrFunction
   exits, then clear the thread and allocator-locking flags. */
extern "C" void cDME_StopUpdateThread(void)
{
    EeThreadParam worker;
    EeThreadParam current;
    ReferThreadStatus(g_DmeThreadId, &worker);
    ReferThreadStatus(g_DmeMainThreadId, &current);
    if (worker.currentPriority <= current.currentPriority)
        ChangeThreadPriority(g_DmeThreadId, 0);
    g_DmeThreadStopRequest = 1;
    int woken = iWakeupThread(g_DmeThreadId);
    DelayThread(10);
    if (woken == g_DmeThreadId) {
        while ((g_DmeThreadExited != 0) ^ 1)
            DelayThread(10);
    }
    g_DmeThreadStopRequest = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    g_DmeThreadExited = 0;
    g_ProfileLockEnabled = 0;
}
#undef g_DmeThreadExited /* merge_units */
#undef ReferThreadStatus /* merge_units */
#undef ChangeThreadPriority /* merge_units */
#undef iWakeupThread /* merge_units */
#undef DelayThread /* merge_units */
static inline void merge_flush_func_0042A680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A680 */

/* merge_units: begin func_0042A770 */
#pragma push /* merge_units */
extern int cThreadMgr_AddThread(int);
extern int cDME_ThrFunction(void);

/* Starts the DME thread running cDME_ThrFunction. */
int cDME_StartUpdateThread(void) {
    return cThreadMgr_AddThread((int)cDME_ThrFunction);
}
static inline void merge_flush_func_0042A770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A770 */

/* merge_units: begin func_0042A780 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int NetGetTime(char *);
int Gui_Canvas();
int GuiWidget_SendMessage(int, int, int, int, int);
int Net_ConnectGameByName();
#if 0 /* merge_units */
extern signed char D_005721E0;
#endif /* merge_units */
#define D_005721E0 (*(signed char*)&D_005721E0) /* merge_units */

extern signed char D_005721F0;
extern signed char D_005723B0;
extern signed char D_00572468;
extern int g_DmeConnectRetries;
extern int g_DmeConnectMaxRetries;
#if 0 /* merge_units */
extern signed char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(signed char*)&D_005724B0) /* merge_units */


extern char D_004BF9B8; /* "F_TO_CONNECT" */
/* Retries the connection; after g_DmeConnectMaxRetries failures shows the
   "F_TO_CONNECT" error, otherwise flags another retry (D_00572468). */
void Net_RetryConnect(void) {
    int netTime;
    int retries;
    int screens;

    D_005723B0 = 0;
    D_005721E0 = 0; /* clears the disconnect-reason string */
    D_005724B0 = DME_STATE_CONNECTING;
    D_005721F0 = 0;
    if (Net_ConnectGameByName() == 0) {
        NetGetTime(&netTime);
        return;
    }
    retries = g_DmeConnectRetries + 1;
    g_DmeConnectRetries = retries;
    if (retries < g_DmeConnectMaxRetries) {
        D_00572468 = 1;
        return;
    }
    if (Gui_Canvas(retries) != 0) {
        screens = Gui_Canvas();
        GuiWidget_SendMessage(screens, Gui_Canvas(), 0x1E, 0, (int)&D_004BF9B8);
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
}
#undef D_005721E0 /* merge_units */
#undef D_005724B0 /* merge_units */
static inline void merge_flush_func_0042A780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042A780 */
