#include "types.h"

typedef struct Words15D00 { int w[15]; } Words15D00;
typedef struct Elem5CD00 {
    char base[0xC];
    unsigned char flag;
    char pad0D[3];
    Words15D00 data;
    char tail[0x10];
} Elem5CD00;

extern void func_00329930(Elem5CD00* dst, Elem5CD00* src);
extern void func_003517B0(void* dst, void* src);

/* Fills n elements starting at dest with copies of value. */
void func_00351D00(Elem5CD00* dest, int n, Elem5CD00* value) {
    for (; n != 0; --n, ++dest) {
        func_00329930(dest, value);
        dest->flag = value->flag;
        dest->data = value->data;
        func_003517B0(dest->tail, value->tail);
    }
}
