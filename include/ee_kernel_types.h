#ifndef EE_KERNEL_TYPES_H
#define EE_KERNEL_TYPES_H

/*
 * EE kernel semaphore parameter block (sceSifRpc/libcdvd/libpad style lib
 * code; ~20 src/lib files re-derive it as SemaParamXXXX / Sema).
 * Plain C for ee-gcc (any lib kind); also fine in MW.
 * Usual idiom: sp.initCount = 0/1; sp.maxCount = 1; sp.option = 0;
 *              id = CreateSema(&sp);   (store order follows the target)
 * #define EE_KERNEL_NO_PROTOS to keep typed local declarations.
 */
typedef struct SemaParam {
    int currentCount;        /* +0x00 */
    int maxCount;            /* +0x04 */
    int initCount;           /* +0x08 */
    int numWaitThreads;      /* +0x0C */
    unsigned int attr;       /* +0x10 */
    unsigned int option;     /* +0x14 */
} SemaParam; /* 0x18 */

typedef char ee_sema_param_size[(sizeof(SemaParam) == 0x18) ? 1 : -1];

#ifndef EE_KERNEL_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
int CreateSema(SemaParam* param);
int DeleteSema(int sema);
int SignalSema(int sema);
int WaitSema(int sema);
int PollSema(int sema);
#ifdef __cplusplus
}
#endif
#endif

#endif /* EE_KERNEL_TYPES_H */
