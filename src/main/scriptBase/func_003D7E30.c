#include "types.h"

typedef struct Node4 {
    int unk0;
    int next;
} Node4;

extern Node4* D_00554F18;
extern Node4* D_00554F20;
extern Node4* D_00554F28;
extern Node4* D_00554F30;
extern int D_00554F38;
extern int D_00554F40;
extern int D_00554F48;
extern int D_00554F50;

/* Caches the second word of four list heads. */
void func_003D7E30(void) {
    D_00554F48 = D_00554F28->next;
    D_00554F50 = D_00554F30->next;
    D_00554F40 = D_00554F20->next;
    D_00554F38 = D_00554F18->next;
}
