#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { int a; int pad4; int b; int padC; int c; int pad14; int d; int pad1C; } Block;
extern void nciQuadrupleDecodeVoicePropSase3200(void* p);

/* Forwards p to nciQuadrupleDecodeVoicePropSase3200; clears an (unused) local block first. */
void nciQuadrupleDecodeSase3200(void* p)
{
    Block blk;
    blk.a = 0;
    blk.b = 0;
    blk.c = 0;
    blk.d = 0;
    nciQuadrupleDecodeVoicePropSase3200(p);
}
