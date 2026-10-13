/*
 * lib/lgaud: 2 files, 00324958-00324AC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "lgaud.h"

/* merge_units: begin func_00324958 */
int lgAudWrite(int device, int flag, void *src, int *len)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (src == 0) {
        printf("lgAudWrite: invalid parameter (src)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudWrite: invalid parameter (size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        memcpy(LGAUD_PKT_DATA(pkt), src, *len);
    }
    lgAud_pkt->flag = (unsigned char)flag;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_WRITE, LGAUD_RPC_SYNC, lgAud_pkt, LGAUD_XFER_SIZE(*len), lgAud_pkt, 0x30, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        *len = lgAud_pkt->u.size;
        SignalSema(lgAud_sema);
        return ret;
    }
    *len = 0;
    printf("lgAudWrite: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00324958 */

/* merge_units: begin func_00324AC8 */
int lgAudWriteVag(int device, int flag, void *src, int *len)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (src == 0) {
        printf("lgAudWriteVag: invalid parameter (src)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudWriteVag: invalid parameter (size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        memcpy(LGAUD_PKT_DATA(pkt), src, *len);
    }
    lgAud_pkt->flag = (unsigned char)flag;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_WRITE_VAG, LGAUD_RPC_SYNC, lgAud_pkt, LGAUD_XFER_SIZE(*len), lgAud_pkt, 0x30, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        *len = lgAud_pkt->u.size;
        SignalSema(lgAud_sema);
        return ret;
    }
    *len = 0;
    printf("lgAudWriteVag: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00324AC8 */
