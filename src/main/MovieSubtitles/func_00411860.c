#pragma cplusplus on
#include "types.h"

typedef struct DmaBuf {
    int unk00;
    unsigned int packet; /* 0x04 */
    int unk08;
} DmaBuf; /* size 0x0C */

typedef struct DblBuf {
    DmaBuf bufs[2];        /* 0x00 */
    int current;           /* 0x18 */
    unsigned int tag;      /* 0x1C */
    unsigned int cur;      /* 0x20 */
    unsigned long long* tags[4]; /* 0x24 */
} DblBuf;

extern "C" void func_00411860(DblBuf* db, int i, int j) {
    unsigned long long* p = db->tags[j + i * 2];
    bool other;
    *p &= 0x8FFFFFFF;
    *p |= 0x20000000;
    other = !db->current;
    *p |= (unsigned long long)db->bufs[other].packet << 32;
}
