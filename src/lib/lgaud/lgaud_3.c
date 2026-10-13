/*
 * lib/lgaud: 2 files, 00325728-00325848
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */
#include "lgaud.h"

/* merge_units: begin func_00325728 */
int lgAudGetMixer(int device, lgAudMixer *mr)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (mr == 0) {
        printf("lgAudGetMixer: invalid parameter (mr)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    lgAud_pkt->device = device;
    lgAud_pkt->u.mixer = *mr;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_GET_MIXER, LGAUD_RPC_SYNC, lgAud_pkt, 0x30, lgAud_pkt, 0x30, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        mr->v[6] = lgAud_pkt->u.mixer.v[6];
        SignalSema(lgAud_sema);
        return ret;
    }
    printf("lgAudGetMixer: rpc call failed\n");
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325728 */

/* merge_units: begin func_00325848 */
extern char D_004B8210[]; /* the "lgAudGetMixer: rpc call failed\n" string above (library bug) */

int lgAudSetMixer(int device, lgAudMixer *mr)
{
    int ret;
    if (lgAud_sema == -1)
        return LGAUD_ERR_NOT_INITIALIZED;
    if (mr == 0) {
        printf("lgAudSetMixer: invalid parameter (mr)\n");
        return LGAUD_ERR_INVALID_PARAMETER;
    }
    WaitSema(lgAud_sema);
    lgAud_pkt->device = device;
    lgAud_pkt->u.mixer = *mr;
    if (sceSifCallRpc(&lgAud_cd, LGAUD_RPC_SET_MIXER, LGAUD_RPC_SYNC, lgAud_pkt, 0x30, lgAud_pkt, 0x30, 0, 0) == 0) {
        ret = lgAud_pkt->ret;
        SignalSema(lgAud_sema);
        return ret;
    }
    printf(D_004B8210);
    SignalSema(lgAud_sema);
    return LGAUD_ERR_RPC_FAILED;
}
/* merge_units: end func_00325848 */
