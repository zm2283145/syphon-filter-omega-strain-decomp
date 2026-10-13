#ifndef SND989_H
#define SND989_H

/*
 * 989snd: EE side of Sony's 989 sound library (src/main/989snd).
 * Most of the EE API is thin wrappers that copy their arguments into a local
 * buffer and queue it for the IOP with
 *   snd_SendIOPCommandNoWait(command, data_size, data, done_callback, user_data)
 * (the files declare the prototype with different integer types; that is kept
 * per file because it affects codegen). snd_SendIOPCommandAndWait (same
 * arguments minus the callback) is the blocking variant whose reply lands in
 * a shared buffer. Bank loads use a separate synchronous-style RPC on
 * snd_bankCd. The command ids below are the ones the wrappers send; the
 * wrapper names follow the public 989snd API where the arguments and the
 * callers fit (hedged: no symbols survive).
 *
 * The globals keep their splat names (defined in generated src/data); the
 * aliases below name them. Types match every declaration in src/main/989snd.
 */

/* IOP command ids (first argument of snd_SendIOPCommandNoWait/AndWait) */
#define SND_CMD_UNLOAD_BANK          6    /* snd_UnloadBank(bank handle) */
#define SND_CMD_SET_MASTER_VOLUME    9    /* snd_SetMasterVolume(which, vol) */
#define SND_CMD_GET_MASTER_VOLUME    10   /* snd_GetMasterVolume(which), AndWait */
#define SND_CMD_STOP_SOUND           0x15 /* snd_StopSound(sound handle) */
#define SND_CMD_PAUSE_GROUPS         0x16 /* snd_PauseAllSoundsInGroup(group mask; -1 = all) */
#define SND_CMD_CONTINUE_GROUPS      0x17 /* snd_ContinueAllSoundsInGroup(group mask) */
#define SND_CMD_AUTO_VOL             0x22 /* snd_AutoVol(handle, vol, duration, dir) */
/*
 * Ids whose wrapper is not identified yet (kept as literals in the source):
 *   8    func_003A8240()        no arguments
 *   0xB  func_003A80F0(x)       one word
 *   0x18 func_003A7FE0()        no arguments, sent at sound shutdown
 *   0x21 func_003A7F00(...)     six words plus callback/user data
 *   0x56 func_003A8000(...)     0x30-byte block
 *   0x5C func_003A8070(...)     0x30-byte block with a field mask (0x3C | 1)
 *   0x60 func_003A8120(x, p)    word + six-word block (-1 when p is NULL)
 *   0x61 func_003A7F50(x)       one word
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
