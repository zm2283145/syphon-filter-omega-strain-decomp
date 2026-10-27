#include "types.h"
typedef struct { char pad[0x40]; char item[0x1C0]; } E36A;
typedef struct { int a; int count; char pad[0x38]; char items[1][0x1C0]; } H36A;
extern void cJoyPad_Read(void* p);
void cJoystick_Poll(H36A* h)
{
    int i;
    for (i = 0; i < h->count; i++) {
        cJoyPad_Read(h->items[i]);
    }
}