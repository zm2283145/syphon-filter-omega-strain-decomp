#include "lgaud.h"

int lgAudPrepareForReboot(void)
{
    int ret;
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (lgAudASync(1, 0)) {
        printf("lgAudPrepareForReboot: error: an async call is in progress...\n");
        return LGAUD_ERR_BUSY;
    }
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = -1;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_PREPARE_FOR_REBOOT, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf("lgAudPrepareForReboot: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
