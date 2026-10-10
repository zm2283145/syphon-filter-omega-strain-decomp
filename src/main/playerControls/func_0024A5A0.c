#include "types.h"
typedef struct {
    char p00[0x24];
    unsigned char b24;
    char p25[0x3C - 0x25];
    int flags;
} PlayerInput_24A5A0;
extern unsigned char PlayerInput_TryStand(PlayerInput_24A5A0* p);
extern unsigned char func_0024A7A0(PlayerInput_24A5A0* p);
unsigned char PlayerInput_CrouchToggle(PlayerInput_24A5A0* p) {
    unsigned char result = 0;
    int crouched = (p->flags >> 4) & 1;
    if (crouched)
        result = PlayerInput_TryStand(p);
    else if (!crouched && p->b24)
        result = func_0024A7A0(p);
    return result;
}