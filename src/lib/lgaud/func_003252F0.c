#include "lgaud.h"

int lgAudEnumerate(int idx, lgAudInfo *info)
{
    lgAudRpcPkt *pkt;
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (info == 0) {
        printf("lgAudEnumerate: invalid parameter (description)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->arg = idx;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_ENUMERATE, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x170, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        *info = lgAud_pkt->u.info;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf("lgAudEnumerate: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
