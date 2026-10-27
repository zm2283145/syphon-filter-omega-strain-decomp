/*
 * main/DME: 3 files, 00429BA0-00429CB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetPlayGameMsg_dtor, D_004E0EC0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00429BA0 */

/* merge_units: begin func_00429C00 */
#pragma push /* merge_units */
#include "types.h"
#include "DME.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005723C8;
extern unsigned char D_005724B0;

/* Join callback (cDME_JoinGame): a client needs two successful results
   (JOIN_WAIT, then JOINED); the host is joined after the first. */
void cDME_LocalJoinCallback(int *result) {
    int isHost;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (*result == 0) {
        isHost = g_IsMultiplayer ? D_005721C0 : 1;
        if (isHost != 0) {
            D_005724B0 = DME_STATE_JOINED;
        } else if (D_005724B0 == DME_STATE_JOIN_WAIT) {
            D_005724B0 = DME_STATE_JOINED;
        } else {
            D_005724B0 = DME_STATE_JOIN_WAIT;
        }
    } else {
        D_005724B0 = DME_STATE_JOIN_FAILED;
    }
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429C00 */

/* merge_units: begin func_00429CB0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
extern float g_DmeLatencyAvg;
extern float g_DmeLatencySum;
extern int g_DmeLatencyCount;

/* Accumulates a round-trip sample in ms (0..999) into a running average in seconds. */
void cDME_AddToAvgLatency(int ms) {
    if (ms < 0x3E8 && 0 <= ms) {
        g_DmeLatencyCount += 1;
        g_DmeLatencySum += 0.001f * (float) ms;
        g_DmeLatencyAvg = g_DmeLatencySum / (float) g_DmeLatencyCount;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00429CB0 */
