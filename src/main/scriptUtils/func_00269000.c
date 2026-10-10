#include "types.h"
typedef struct { float* data; int cap; int count; } E7Arr;
extern E7Arr* func_002690C0(int h);
static inline unsigned char E7Push(E7Arr* a, float v) {
    if (a->count < a->cap) {
        a->data[a->count++] = v;
        return 1;
    }
    return 0;
}
int Script_Array_AddElem(int* args) {
    volatile int iv = args[1];
    float v = *(float*)&iv;
    return E7Push(func_002690C0(args[0]), v);
}
