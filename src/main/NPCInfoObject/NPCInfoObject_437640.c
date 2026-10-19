/*
 * main/NPCInfoObject: 4 files, 00437640-00437950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00437640 */
#pragma push /* merge_units */
#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
#pragma opt_dead_code off
typedef struct { int f0; int f4; } P_437640;
extern unsigned char D_005723C8;
extern unsigned char D_00582B88;
extern void* D_00583870;
extern unsigned char D_00582D28;
extern unsigned char D_00582D20;
extern unsigned char D_00583050;
extern void* D_00497548;
extern int D_00582D08;
extern unsigned char D_00583860;
int func_002EB650(P_437640** out, void* s);
void func_002EC460(void* s);
int lgAudStartRecording(void* p);
int lgAudStopRecording(void* p);
int Net_GetClock(int v);

static inline int Owner_437640(void)
{
    P_437640* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline void Release_437640(void)
{
    int o = Owner_437640();
    if (o == NetLocalId()) {
        func_002EC460(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = Net_GetClock(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437640(int id, void* sess, int kind)
{
    P_437640* x;
    P_437640* h;
    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(&h, sess) == 0 && kind == -2 && h->f4 == NetLocalId()) {
        if (D_00583860) {
            if (D_00582B88) {
                int r = lgAudStartRecording(D_00497548);
                if (r == 0) D_00583050 = 1;
                else if (r == 0x80000006) D_00582B88 = 0;
            }
            D_00583860 = 0;
            D_00582D20 = 1;
        } else {
            Release_437640();
        }
    }
    if (0) func_002EB650(&x, 0); /* dead under opt_dead_code off: reserves retail's unused 0x2C stack slot */
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00437640 */

/* merge_units: begin func_00437830 */
#pragma push /* merge_units */
#include "NetObjectMgr_types.h"

#if 0 /* merge_units */
extern volatile unsigned char D_005723C8;
#endif /* merge_units */
#define D_005723C8 (*(volatile unsigned char*)&D_005723C8) /* merge_units */

extern int D_00582CF0;
#if 0 /* merge_units */
extern int func_002EB650(NetSessionEntry** result, void* key);
#endif /* merge_units */
#define func_002EB650(a0, a1) (func_002EB650((P_437640 * *)(a0), (a1))) /* merge_units */


/* Cache the selected session entry's value when lookup succeeds. */
void func_00437830(void* unused, void* key)
{
    NetSessionEntry* result[2];
    if (!D_005723C8)
        D_005723C8 = 1;
    if (!func_002EB650(result, key)) {
        int value = result[0]->value;
        D_00583870 = key;
        D_00582CF0 = value;
    }
    D_005723C8 = 0;
}
#undef D_005723C8 /* merge_units */
#undef func_002EB650 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437830 */

/* merge_units: begin func_004378A0 */
#pragma push /* merge_units */
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm78A0;
extern int func_002E9B60(void);
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm78A0* prm);
extern int func_002E9CD0(int* table, char* name, int size);
extern int func_002E9D88(int table, void* a, void* b, void* c);
extern int D_00583868;
extern void func_00437830();
extern void func_00437640();
extern void func_004375D0();

unsigned char Voice_RegisterHeadsetSemaphore(void)
{
    int db;
    Prm78A0 prm;
    unsigned char ok;
    ok = 0;
    prm.max = 1000;
    prm.ver = 1;
    prm.mode = 0;
    prm.flags = 0;
    if (func_002E9B60() == 0 &&
        func_002E9BE8(&db, 0, 1, 1, 1, &prm) == 0 &&
        func_002E9CD0(&D_00583868, "HeadsetSemaphore", 1) == 0) {
        func_002E9D88(D_00583868, func_00437830, func_00437640, func_004375D0);
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_004378A0 */

/* merge_units: begin func_00437950 */
#pragma push /* merge_units */
#pragma inline_depth(10)
typedef struct { int f0; int f4; } P_437950;
#if 0 /* merge_units */
void func_002EB650(P_437950** out, void* s);
#endif /* merge_units */
#define func_002EB650(a0, a1) ((void)func_002EB650((P_437640 * *)(a0), (a1))) /* merge_units */

int func_002EC3C8(void* s);

static inline int Owner_437950(void)
{
    P_437950* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}

static inline int OwnerW_437950(void) { return Owner_437950(); }
static inline void Release_437950(void)
{
    int o = Owner_437950();
    if (o == NetLocalId()) {
        func_002EC460(D_00583870);
        D_00582D28 = 1;
    }
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = Net_GetClock(1) + 2000;
    }
    D_00583860 = 0;
}

void func_00437950(int on)
{
    if (D_00582B88) {
        if (!on) {
            Release_437950();
        } else if (on) {
            if (D_00582D08 < Net_GetClock(1)) {
                int o = OwnerW_437950();
                if (o != NetLocalId()) {
                    D_00583860 = 1;
                    if (func_002EC3C8(D_00583870)) D_00583860 = 0;
                }
            }
        }
    } else {
        Release_437950();
    }
}
#undef func_002EB650 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437950 */
