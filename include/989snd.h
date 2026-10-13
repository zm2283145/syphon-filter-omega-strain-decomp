#ifndef SND989_H
#define SND989_H

/*
 * 989snd: EE side of Sony's 989 sound library (src/main/989snd).
 * Most of the EE API is thin wrappers that copy their arguments into a local
 * buffer and queue it for the IOP with
 *   snd_SendIOPCommandNoWait(command, data_size, data, done_callback, user_data)
 * (the files declare the prototype with different integer types; that is kept
 * per file because it affects codegen). The numeric command ids are not named
 * yet. Bank loads use a separate synchronous-style RPC on snd_bankCd.
 *
 * The globals keep their splat names (defined in generated src/data); the
 * aliases below name them. Types match every declaration in src/main/989snd.
 */

#define SND_ERR_RPC_FAILED 0x106 /* stored to snd_lastError when sceSifCallRpc fails */

/* sceSifCallRpc function numbers on snd_bankCd */
#define SND_BANK_RPC_LOAD        2 /* send: snd_bankLoadReq {arg, name}, recv: snd_rpcResult */
#define SND_BANK_RPC_LOAD_BY_LOC 3 /* send: {loc, size} (D_00542900/04), recv: snd_rpcResult */

extern int D_0053DBF8;
extern int D_00542878;
extern int D_00542990;
extern int D_005428C0;
extern char D_00542850[];
extern char D_004BCA30[];

#define snd_lastError      D_0053DBF8 /* 0 on entry, SND_ERR_RPC_FAILED on RPC failure */
#define snd_loadInProgress D_00542878 /* "Load already in progress!" */
#define snd_quiet          D_00542990 /* nonzero suppresses the diagnostic printfs */
#define snd_rpcResult      D_005428C0 /* -1 while the bank RPC is pending, then its result */
#define snd_bankCd         D_00542850 /* SifRpcClientData of the bank-load RPC server */
#define snd_rpcCollisionMsg D_004BCA30 /* "989snd.c: RPC collision!\n" */

#endif /* SND989_H */
