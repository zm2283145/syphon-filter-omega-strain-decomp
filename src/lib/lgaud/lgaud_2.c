/*
 * lib/lgaud: 4 files, 00324D28-003251B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "lgaud.h"

/*
 * The async calls keep lgAud_sema after a successful sceSifCallRpc; the
 * completion callback (lgAudAReadCallback/lgAudAWriteCallback) releases it.
 */

/* merge_units: begin func_00324D28 */
int lgAudARead(int device, int flag, void *dest, int *len)
{
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (dest == 0) {
        printf("lgAudARead: invalid parameter (dest)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudARead: invalid parameter (*size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (sceSifCheckStatRpc(&lgAud_cd)) {
        printf("lgAudARead: error: another async call is in progress...\n");
        return LGAUD_ERR_BUSY;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        pkt->flag = flag;
    }
    lgAud_asyncReq.buf = dest;
    lgAud_asyncReq.len = len;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_READ, LGAUD_RPC_ASYNC, lgAud_pkt, 0x30, lgAud_pkt, LGAUD_XFER_SIZE(*len), lgAudAReadCallback, &lgAud_asyncReq) == 0)
        return 0;
    *len = 0;
    printf("lgAudARead: rpc call failed\n");
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00324D28 */

/* merge_units: begin func_00324EA0 */
int lgAudAWrite(int device, int flag, void *src, int *len)
{
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (src == 0) {
        printf("lgAudAWrite: invalid parameter (src)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudAWrite: invalid parameter (*size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (sceSifCheckStatRpc(&lgAud_cd)) {
        printf("lgAudAWrite: error: another async call is in progress...\n");
        return LGAUD_ERR_BUSY;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        pkt->flag = flag;
    }
    lgAud_asyncReq.buf = src;
    lgAud_asyncReq.len = len;
    memcpy(LGAUD_PKT_DATA(lgAud_pkt), src, lgAud_pkt->u.size);
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_WRITE, LGAUD_RPC_ASYNC, lgAud_pkt, LGAUD_XFER_SIZE(*len), lgAud_pkt, 0x30, lgAudAWriteCallback, &lgAud_asyncReq) == 0)
        return 0;
    *len = 0;
    printf("lgAudAWrite: rpc call failed\n");
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00324EA0 */

/* merge_units: begin func_00325028 */
int lgAudAWriteVag(int device, int flag, void *src, int *len)
{
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (src == 0) {
        printf("lgAudAWriteVag: invalid parameter (src)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudAWriteVag: invalid parameter (*size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (sceSifCheckStatRpc(&lgAud_cd)) {
        printf("lgAudAWriteVag: error: another async call is in progress...\n");
        return LGAUD_ERR_BUSY;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        pkt->flag = flag;
    }
    lgAud_asyncReq.buf = src;
    lgAud_asyncReq.len = len;
    memcpy(LGAUD_PKT_DATA(lgAud_pkt), src, lgAud_pkt->u.size);
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_WRITE_VAG, LGAUD_RPC_ASYNC, lgAud_pkt, LGAUD_XFER_SIZE(*len), lgAud_pkt, 0x30, lgAudAWriteCallback, &lgAud_asyncReq) == 0)
        return 0;
    *len = 0;
    printf("lgAudAWriteVag: rpc call failed\n");
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325028 */

/* merge_units: begin func_003251B0 */
int lgAudDeInit(void)
{
    if (lgAud_sema != -1) {
        WaitSema(lgAud_sema);
        lgAudASync(0, 0);
        if (lgAud_heapBuf) {
            if (lgAud_freeFunc)
                lgAud_freeFunc(lgAud_heapBuf);
            lgAud_heapBuf = 0;
        }
        sceSifCallRpc(&lgAud_cd, LGAUD_RPC_DEINIT, LGAUD_RPC_SYNC, lgAud_deinitPkt, 0x20, lgAud_deinitPkt, 0, 0, 0);
        lgAud_cd.server = 0; /* unbind */
        SignalSema(lgAud_sema);
        DeleteSema(lgAud_sema);
        lgAud_sema = -1;
    }
    return 0;
}
/* merge_units: end func_003251B0 */
