#ifndef EZNET_H
#define EZNET_H

/*
 * lib/libezcnf (libezcnf.c) and lib/libezctl (libezctl.c): EE clients of the
 * SCE "ezNetCnf"/"ezNetCtl" sample IOP modules (eznetcnf.irx and
 * eznetctl_inet.irx) that read network configurations and bring the
 * interface up. Both follow the same pattern:
 *   Init: sceSifSearchModuleByName(module) -> modId, then bind the RPC server
 *         (retrying with a busy-wait until cd.server is set) and set rpcBound;
 *   Exit: sceSifStopModule + sceSifUnloadModule, clear rpcBound;
 *   calls: refuse with "RPC service not running" unless rpcBound, then
 *         sceSifCallRpc(&cd, fno, 0, rpcBuf, size, rpcBuf, size, 0, 0) with
 *         the reply in the first word of rpcBuf.
 * Every diagnostic is printed as scePrintf(logPrefix, srcFile) ("%s> ",
 * "libezcnf.c"/"libezctl.c") followed by the message.
 * The globals keep their splat names; the aliases below name them.
 */

#define EZNET_RPC_BUF_SIZE 0x1340 /* size of each module's rpcBuf */
#define EZNET_RPC_NAMES_SIZE 0x130 /* request with two 0x100-byte names at +0x10/+0x110 */

/* ezNetCnf (eznetcnf.irx) */
#define EZNETCNF_RPC_ID 0x75499128
#define EZNETCNF_FNO_GET_COMBINATION_LIST 1
#define EZNETCNF_FNO_GET_PROPERTIES       2

#define ezNetCnf_modId     D_004928E8 /* module id from sceSifSearchModuleByName */
#define ezNetCnf_rpcBound  D_004928EC /* 1 between ezNetCnfInit and ezNetCnfExit */
#define ezNetCnf_cd        D_00533040 /* SifRpcClientData */
#define ezNetCnf_rpcBuf    D_00533080 /* EZNET_RPC_BUF_SIZE send/receive buffer */
#define ezNetCnf_logPrefix D_004B9D10 /* "%s> " */
#define ezNetCnf_srcFile   D_004B9D18 /* "libezcnf.c" */
#define ezNetCnf_msgModuleNotFound D_004B9D28 /* "%s module not found\n" */
#define ezNetCnf_msgBindFailed     D_004B9D40 /* "Could not bind to RPC service\n" */
#define ezNetCnf_msgNotRunning     D_004B9D60 /* "RPC service not running\n" */

/* ezNetCtl (eznetctl_inet.irx) */
#define EZNETCTL_RPC_ID 0x75488909
#define EZNETCTL_FNO_GET_PROPERTIES_ADDRESS 0 /* reply: IOP address for the properties DMA */
#define EZNETCTL_FNO_SET_PROPERTIES         1
#define EZNETCTL_FNO_SET_COMBINATION        2
#define EZNETCTL_FNO_GET_STATUS             3
#define EZNETCTL_FNO_5                      5 /* func_00353130, no arguments */
#define EZNETCTL_FNO_6                      6 /* func_003531B8, no arguments */
#define EZNETCTL_FNO_PRELOAD_MODEM_CNF      7

#define ezNetCtl_modId     D_00492C30
#define ezNetCtl_rpcBound  D_00492C34
#define ezNetCtl_cd        D_00533280 /* SifRpcClientData */
#define ezNetCtl_rpcBuf    D_005332C0
#define ezNetCtl_logPrefix D_004BADB8 /* "%s> " */
#define ezNetCtl_srcFile   D_004BADC0 /* "libezctl.c" */
#define ezNetCtl_msgModuleNotFound D_004BADD0 /* "%s module not found\n" */
#define ezNetCtl_msgBindFailed     D_004BADE8 /* "could not bind to RPC service\n" */
#define ezNetCtl_msgNotRunning     D_004BAE08 /* "RPC service not running\n" */

#endif /* EZNET_H */