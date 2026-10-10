#include "types.h"

typedef struct Node425 {
    char pad[0xC];
    int flags;
    char pad2[0x10];
    float value[4];
} Node425;

extern Node425* func_00426590(int a, int b, int c);

/* Looks up a node and, if found, sets its 4-float value and flag bit 2. */
void func_00425C30(int a, int b, int c, float* value) {
    Node425* node = func_00426590(a, b, c);
    if (node) {
        node->value[0] = value[0];
        node->value[1] = value[1];
        node->value[2] = value[2];
        node->value[3] = value[3];
        node->flags |= 4;
    }
}
