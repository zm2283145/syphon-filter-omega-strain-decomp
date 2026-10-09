/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_0055D4C0;            /* cEnableMsg type id */
extern int Event_PackHeader(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf);

/* Serializes a cEnableMsg: header plus one word, 12 bytes. */
int cEnableMsg_v02(L4Msg24* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf) {
    Event_PackHeader(msg, a1, outType, a3, a4, a5, buf);
    buf->unk08 = msg->unk24;
    *outType = D_0055D4C0;
    return 12;
}
