/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int _ipuSetMPEG1(int);

int _initSeqAgain(int a0) {
    *(int*)((char*)a0 + 2144) = 0;
    return _ipuSetMPEG1(1);
}
