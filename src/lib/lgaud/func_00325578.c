#include "lgaud.h"

int lgAudGetRemainingPlaybackBytes(int device, int *bytes)
{
    lgAudRpcPkt *pkt;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    WaitSema(lgAud_sema);
    pkt = lgAud_pkt;
    pkt->device = device;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_GET_REMAINING_PLAYBACK_BYTES, LGAUD_RPC_SYNC, pkt, 0x20, pkt, 0x30, 0, 0) == 0) {
        device = lgAud_pkt->ret;
        *bytes = lgAud_pkt->u.size;
        SignalSema(lgAud_sema);
        return device;
    }
    printf("lgAudGetRemainingPlaybackBytes: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
