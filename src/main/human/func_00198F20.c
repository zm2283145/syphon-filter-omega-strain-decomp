/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int func_00198D00(char*, int);
extern char* Deque_Back(char*);
extern char* func_00198F70(char*);

void* func_00198F20(void* self) {
    return self;
}

int func_00198F30(char* self, int key) {
    char* last;
    int found;

    last = func_00198F70(self);
    found = func_00198D00(last, key);
    return found != 0;
}

/* Last element of the deque at +0x3C, offset +0xE8 into it. */
char* func_00198F70(char* self) {
    char* last;

    last = Deque_Back(self + 60);
    return last + 232;
}
