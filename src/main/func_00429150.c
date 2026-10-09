/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_005721A0;            /* message type id */
extern int Event_PackHeader(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf);

/* Serializer for a message with no payload: header plus type id, 8 bytes. */
int func_00429150(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf) {
    Event_PackHeader(msg, a1, outType, a3, a4, a5, buf);
    *outType = D_005721A0;
    return 8;
}
