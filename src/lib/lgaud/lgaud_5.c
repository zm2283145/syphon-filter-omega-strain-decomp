/*
 * lib/lgaud: 5 files, 00325C80-00325FD8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "lgaud.h"

/* merge_units: begin func_00325C80 */
int lgAudResumePlayback(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_RESUME_PLAYBACK, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudResumePlayback: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325C80 */

/* merge_units: begin func_00325D48 */
/*
 * lgAudSetLevel0D/0E: RPC 0xD/0xE with two byte parameters; the game sends
 * (dev, 0, 0x58) and (dev, 0, 0x15) right after lgAudOpen. Real names unknown.
 */
extern char D_004B8318[]; /* "lgAudStopPlayback: rpc call failed\n" (library bug) */
int lgAudSetLevel0D(int device, unsigned char a, unsigned char b)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->param0 = a;
    }
    lgAud_pkt->param1 = b;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_SET_LEVEL_0D, LGAUD_RPC_SYNC, lgAud_pkt, 0x20, lgAud_pkt, 0x20, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf(D_004B8318);
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325D48 */

/* merge_units: begin func_00325E40 */
int lgAudSetLevel0E(int device, unsigned char a, unsigned char b)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->param0 = a;
    }
    lgAud_pkt->param1 = b;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_SET_LEVEL_0E, LGAUD_RPC_SYNC, lgAud_pkt, 0x20, lgAud_pkt, 0x20, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf(D_004B8318);
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325E40 */

/* merge_units: begin func_00325F38 */
/*
 * Waits for (poll == 0) or polls (poll != 0) the pending async call.
 * Returns nonzero while it is still busy; *result gets the async return code.
 */
int lgAudSync(int poll, int *result)
{
    int r;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (poll == 0) {
        while (sceSifCheckStatRpc(&lgAud_cd))
            ;
        if (result)
            *result = lgAud_asyncReq.ret;
        return 0;
    }
    r = sceSifCheckStatRpc(&lgAud_cd);
    if (r == 0 && result)
        *result = lgAud_asyncReq.ret;
    return r;
}
/* merge_units: end func_00325F38 */

/* merge_units: begin func_00325FD8 */
/* Completion callback of lgAudARead; releases the semaphore lgAudARead kept. */
void lgAudAReadCallback(lgAudAsyncReq *req)
{
    memcpy(req->buf, LGAUD_PKT_DATA(lgAud_pkt), lgAud_pkt->u.size);
    *req->len = lgAud_pkt->u.size;
    req->ret = lgAud_pkt->ret;
    iSignalSema(lgAud_sema);
}
/* merge_units: end func_00325FD8 */
