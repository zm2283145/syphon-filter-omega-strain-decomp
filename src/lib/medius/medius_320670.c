#include "types.h"

extern int nciDecodeVoicePropSase3200(int, int, int);

int nciDecodeSase3200(int a0, int a1) {
    return nciDecodeVoicePropSase3200(a0, a1, 0);
}
