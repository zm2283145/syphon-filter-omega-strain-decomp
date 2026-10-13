/*
 * lib/lgaud: 4 files, 00325960-00325BB8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "lgaud.h"

/* merge_units: begin func_00325960 */
int lgAudStartRecording(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_START_RECORDING, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudStartRecording: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325960 */

/* merge_units: begin func_00325A28 */
extern char D_004B82C8[]; /* the "lgAudStartRecording: rpc call failed\n" string above (library bug) */

/* The game treats a 0x80000006 result as "headset removed". */
int lgAudStopRecording(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_STOP_RECORDING, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return device;
    }
    printf(D_004B82C8);
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325A28 */

/* merge_units: begin func_00325AF0 */
int lgAudStartPlayback(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_START_PLAYBACK, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudStartPlayback: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325AF0 */

/* merge_units: begin func_00325BB8 */
int lgAudStopPlayback(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_STOP_PLAYBACK, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudStopPlayback: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325BB8 */
