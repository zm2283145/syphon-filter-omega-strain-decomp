#include "types.h"

#define WATERFX_SLOTS 20

extern void WaterFx_DestroyRecord(int item, int a, int b, const char* file, int line);
extern char D_004ABFE0[]; /* source file name */

/* Releases every active water effect slot (+0x400, 20 slots) and decrements the count at +0x450. */
void WaterFx_Clear(char* self) {
    char* slot = self;
    int i;
    for (i = 0; i < WATERFX_SLOTS; i++, slot += 4) {
        if (*(int*)(slot + 0x400) && i >= 0 && i < WATERFX_SLOTS) {
            WaterFx_DestroyRecord(*(int*)(slot + 0x400), 0, 1, D_004ABFE0, 0x1B6);
            *(int*)(slot + 0x400) = 0;
            (*(int*)(self + 0x450))--;
        }
    }
}
