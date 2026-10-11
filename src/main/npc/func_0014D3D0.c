#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define V4CopyQ V4Copy
typedef struct { char pad[0xE8]; unsigned char ok; char pad2[7]; __int128 q; } B_D3D0;
typedef struct { char pad[0x3310]; B_D3D0* b; } A_D3D0;
#pragma push

int func_0014D3D0(A_D3D0* a, __int128* out) {
    B_D3D0* b = a->b;
    if (b && b->ok) {
        VCopyF(out, &b->q);
        return 1;
    }
    return 0;
}
#pragma pop