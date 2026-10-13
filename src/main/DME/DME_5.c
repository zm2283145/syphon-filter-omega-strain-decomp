/*
 * main/DME: 3 files, 0042A150-0042A520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A150 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetLevelInfoMsg_dtor, D_004E1180, cMessage_dtor)
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
extern unsigned char D_00533880;
extern unsigned char D_005724B0;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00497540;
extern unsigned char D_005721D8;
extern char D_005721E0[];
extern char D_004BFA10[]; /* "Foo" */
extern char D_004BFA18[]; /* "F_TO_JOINGAME" */
int ReferThreadStatus(int tid, EeThreadParam* st);
int ChangeThreadPriority(int tid, int prio);
int iWakeupThread(int tid);
int DelayThread(int prio);
void func_002EABF0(NetHostCfg_A1B0* cfg);
int func_002EAC88(NetHostCfg_A1B0* cfg, NetHostOut_A1B0* out);
int func_002EBC48(int* t);
int DME_Update(void);
void DME_OnJoinResult(void);
void Net_OnRemoteClientJoined(void);
int func_00437BF0(void);
int func_002EC6A0(int);
int func_002EC738(int);
void Net_ResetSession(void);
char* strncpy(char* d, const char* s, unsigned int n);
int sprintf(char* d, const char* f, ...);
}
static inline int NetTimeMs(void) { int t; return func_002EBC48(&t) == 0 ? t : -1; }
enum NetRole_A1B0 { ROLE_CLIENT_A1B0, ROLE_HOST_A1B0 };
static inline int IsHost(void) { return D_005721C8 ? D_005721C0 : 1; }
/* leaves the game and records "F_TO_JOINGAME" as the disconnect reason */
static inline void AbortJoin(void)
{
    D_00497540 = 1;
    func_00437BF0();
    func_002EC6A0(0);
    func_002EC738(0);
    Net_ResetSession();
    D_005721D8 = 1;
    sprintf(D_005721E0, D_004BFA18);
}
#pragma opt_propagation off
/* Stops the DME thread, then joins the game and polls DME_Update until the join
   completes (DME_OnJoinResult) or 15 s pass. */
extern "C" void DME_JoinGame(void)
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
    D_00533880 = 0;
    if (D_005724B0 != DME_STATE_JOINED && D_005724B0 != DME_STATE_DISCONNECTED) {
    D_005724B0 = DME_STATE_JOINING;
    name = D_004BFA10;
    func_002EABF0(&cfg);
    cfg.handle = D_005721A8;
    strncpy(cfg.name, name, 0xC);
    cfg.unk14 = 0x1F4;
    cfg.unk18 = 0;
    cfg.unk1C = IsHost() ? ROLE_HOST_A1B0 : ROLE_CLIENT_A1B0;
    cfg.onJoinResult = DME_OnJoinResult;
    cfg.unk24 = 0;
    cfg.onClientJoined = Net_OnRemoteClientJoined;
    cfg.unk2C = 0;
    err = func_002EAC88(&cfg, &out);
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
void PtrVec_Begin_42A670(NetworkGameIterator* result, NetworkGameList* list);
void PtrVec_End_42A640(NetworkGameIterator* result, NetworkGameList* list);
void Iter_Copy_42A660(NetworkGameIterator* destination, const NetworkGameIterator* source);
char* strncpy(char* destination, const char* source, unsigned int count);
}

static inline int different_iterator(const NetworkGameIterator& first, const NetworkGameIterator& second)
{
    return (first.entry == second.entry) ^ 1;
}

/* Enumerate a game address and restart from the beginning after reaching the end. */
extern "C" bool DME_NextGameAddress(NetworkGameAddress* destination)
{
    NetworkGameIterator begin;
    NetworkGameIterator end;
    NetworkGameIterator rawBegin;
    NetworkGameIterator rawEnd;
    if (!D_005724C0)
        D_005724C0 = 1;
    bool found = false;
    if ((*(unsigned char*)dat_004941A0)) {
        PtrVec_Begin_42A670(&rawBegin, &D_005724A0);
        Iter_Copy_42A660(&begin, &rawBegin);
        g_DmeGameIter = begin;
        (*(unsigned char*)dat_004941A0) = 0;
    }
    PtrVec_End_42A640(&rawEnd, &D_005724A0);
    Iter_Copy_42A660(&end, &rawEnd);
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
#pragma pop /* merge_units */
/* merge_units: end func_0042A520 */
