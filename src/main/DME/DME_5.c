/*
 * main/DME: 3 files, 0042A150-0042A520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A150 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(func_0042A150, D_004E1180, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0042A150 */

/* merge_units: begin func_0042A1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct ThStat_A1B0 { int status; void* func; void* stack; int stackSize; void* gp; int initPrio; int curPrio; char pad[0x14]; } ThStat_A1B0;
typedef struct NetHostCfg_A1B0 {
    int unk00;
    int handle;
    char name[0xC];
    int unk14;
    int unk18;
    int unk1C;
    void* cb20;
    int unk24;
    void* cb28;
    int unk2C;
} NetHostCfg_A1B0;
typedef struct NetHostOut_A1B0 { int a, b, c; } NetHostOut_A1B0;
extern "C" {
extern int D_00572510;
extern int D_00572520;
extern unsigned char D_00572530;
extern bool D_00572500;
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
extern char D_004BFA10[];
extern char D_004BFA18[];
int func_0010D060(int tid, ThStat_A1B0* st);
int func_0010CFF0(int tid, int prio);
int func_0010E010(int tid);
int func_0010E1C0(int prio);
void func_002EABF0(NetHostCfg_A1B0* cfg);
int func_002EAC88(NetHostCfg_A1B0* cfg, NetHostOut_A1B0* out);
int func_002EBC48(int* t);
int func_00429D30(void);
void func_00429C00(void);
void Net_OnRemoteClientJoined(void);
int func_00437BF0(void);
int func_002EC6A0(int);
int func_002EC738(int);
void Net_ResetSession(void);
char* strncpy(char* d, const char* s, unsigned int n);
int sprintf(char* d, const char* f, ...);
}
static inline int Now_A1B0(void) { int t; return func_002EBC48(&t) == 0 ? t : -1; }
enum NetRole_A1B0 { ROLE_CLIENT_A1B0, ROLE_HOST_A1B0 };
static inline int IsHost_A1B0(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void Drop_A1B0(void)
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
extern "C" void func_0042A1B0(void)
{
    NetHostOut_A1B0 out;
    NetHostCfg_A1B0 cfg;
    ThStat_A1B0 cur;
    ThStat_A1B0 net;
    const char* name;
    int err;
    int deadline;
    int self;
    func_0010D060(D_00572510, &cur);
    func_0010D060(D_00572520, &net);
    if (cur.curPrio <= net.curPrio) {
        func_0010CFF0(D_00572510, 0);
    }
    D_00572530 = 1;
    self = func_0010E010(D_00572510);
    func_0010E1C0(10);
    if (self == D_00572510) {
        while (!D_00572500) {
            func_0010E1C0(10);
        }
    }
    D_00572530 = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    D_00572500 = 0;
    D_00533880 = 0;
    if (D_005724B0 != 10 && D_005724B0 != 7) {
    D_005724B0 = 8;
    name = D_004BFA10;
    func_002EABF0(&cfg);
    cfg.handle = D_005721A8;
    strncpy(cfg.name, name, 0xC);
    cfg.unk14 = 0x1F4;
    cfg.unk18 = 0;
    cfg.unk1C = IsHost_A1B0() ? ROLE_HOST_A1B0 : ROLE_CLIENT_A1B0;
    cfg.cb20 = func_00429C00;
    cfg.unk24 = 0;
    cfg.cb28 = Net_OnRemoteClientJoined;
    cfg.unk2C = 0;
    err = func_002EAC88(&cfg, &out);
    if (err == 0) {
    deadline = Now_A1B0() + 15000;
    if (IsHost_A1B0()) {
        while (!err && D_005724B0 == 8) {
            err = func_00429D30();
            if (deadline < Now_A1B0()) { err = 1; break; }
        }
    } else {
        while (!err && (D_005724B0 == 8 || D_005724B0 == 9)) {
            err = func_00429D30();
            if (deadline < Now_A1B0()) { err = 1; break; }
        }
    }
    if (!err) {
        if (D_005724B0 != 10 && D_005724B0 == 11) {
            Drop_A1B0();
        }
    } else {
        Drop_A1B0();
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
extern signed char D_005724C0;
static unsigned int dat_004941A0[4] = { 0x1, 0x0, 0x0, 0x0 };
extern NetworkGameList D_005724A0;
extern NetworkGameIterator D_005724C8;
void func_0042A670(NetworkGameIterator* result, NetworkGameList* list);
void func_0042A640(NetworkGameIterator* result, NetworkGameList* list);
void func_0042A660(NetworkGameIterator* destination, const NetworkGameIterator* source);
char* strncpy(char* destination, const char* source, unsigned int count);
}

static inline int different_iterator(const NetworkGameIterator& first, const NetworkGameIterator& second)
{
    return (first.entry == second.entry) ^ 1;
}

/* Enumerate a game address and restart from the beginning after reaching the end. */
extern "C" bool func_0042A520(NetworkGameAddress* destination)
{
    NetworkGameIterator begin;
    NetworkGameIterator end;
    NetworkGameIterator rawBegin;
    NetworkGameIterator rawEnd;
    if (!D_005724C0)
        D_005724C0 = 1;
    bool found = false;
    if ((*(unsigned char*)dat_004941A0)) {
        func_0042A670(&rawBegin, &D_005724A0);
        func_0042A660(&begin, &rawBegin);
        D_005724C8 = begin;
        (*(unsigned char*)dat_004941A0) = 0;
    }
    func_0042A640(&rawEnd, &D_005724A0);
    func_0042A660(&end, &rawEnd);
    if (different_iterator(D_005724C8, end)) {
        strncpy(destination->name, (*D_005724C8.entry)->name, 16);
        destination->value = (*D_005724C8.entry)->value;
        ++D_005724C8.entry;
        found = true;
    } else {
        (*(unsigned char*)dat_004941A0) = 1;
    }
    return found;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A520 */
