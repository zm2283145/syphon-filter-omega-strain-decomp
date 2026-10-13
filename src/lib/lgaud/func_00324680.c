#include "lgaud.h"

int lgAudOpen(int type, lgAudOpenParam *openparam, int *device)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (device == 0) {
        printf("lgAudOpen: invalid parameter (device)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (openparam == 0) {
        printf("lgAudOpen: invalid parameter (openparam)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    if (openparam->Mode == 0) {
        printf("lgAudOpen: invalid parameter (openparam->Mode)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    lgAud_pkt->arg = type;
    lgAud_pkt->u.open = *openparam;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_OPEN, LGAUD_RPC_SYNC, lgAud_pkt, 0x30, lgAud_pkt, 0x20, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        *device = lgAud_pkt->device;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf("lgAudOpen: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
