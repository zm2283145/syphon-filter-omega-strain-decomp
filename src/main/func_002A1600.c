#include "types.h"

typedef struct State2A1 {
    char pad[0x45];
    unsigned char mode;
} State2A1;

typedef struct Obj2A1 {
    char pad[0xE0];
    int target;
    char pad2[0x10];
    State2A1* state;
} Obj2A1;

extern int func_002A1A50(int mode, int a, int b, int c);
extern void func_002A1670(Obj2A1* self);
extern int func_004147A0(void);
extern void func_0041E0F0(int target, int value, int a, int b, int c);

/* Advances the state's mode byte, refreshes, then notifies the target. */
void func_002A1600(Obj2A1* self, int arg) {
    self->state->mode = func_002A1A50(self->state->mode, 0, 2, arg);
    func_002A1670(self);
    func_0041E0F0(self->target, func_004147A0(), 0x10, 0, 0);
}
