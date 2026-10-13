#include "lgaud.h"

int lgAudClose(int device)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_CLOSE, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x20, 0, 0) == 0) {
        device = lgAud_pkt->ret; /* the original reuses `device` for the result */
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudClose: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
