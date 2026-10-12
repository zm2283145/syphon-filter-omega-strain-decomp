#include "types.h"

typedef struct {
    void* owner;
    float x;
    float y;
    int pad;
} FxSlot232050;

extern FxSlot232050 D_0055A890[384];
extern int D_0055C090;
extern void* func_002320F0(void* list, FxSlot232050** value);

void func_00232050(void* list, void* owner, float x, float y) {
    FxSlot232050* found = 0;
    FxSlot232050* tmp;
    float off = *(float*)((char*)list + 0x10);
    float fy = y + off;
    float fx = x + off;
    int i;

    for (i = 0; i < 384; i++) {
        if (D_0055A890[i].owner == 0) {
            found = &D_0055A890[i];
            found->owner = owner;
            found->x = fx;
            found->y = fy;
            D_0055C090++;
            break;
        }
    }
    tmp = found;
    if (found != 0) {
        func_002320F0(list, &tmp);
    }
}
