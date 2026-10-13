#include "lgaud.h"

int lgAudRead(int device, int flag, void *dest, int *len)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (dest == 0) {
        printf("lgAudRead: invalid parameter (dest)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (len == 0 || *len > lgAud_maxDataSize) {
        printf("lgAudRead: invalid parameter (size too big)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    {
        lgAudRpcPkt *pkt = lgAud_pkt;
        pkt->device = device;
        pkt->u.size = *len;
        pkt->flag = flag;
    }
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_READ, LGAUD_RPC_SYNC, lgAud_pkt, 0x30, lgAud_pkt, LGAUD_XFER_SIZE(*len), 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        memcpy(dest, LGAUD_PKT_DATA(lgAud_pkt), lgAud_pkt->u.size);
        *len = lgAud_pkt->u.size;
        SignalSema(lgAud_sema);
        return ret;
    }
    *len = 0;
    printf("lgAudRead: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
