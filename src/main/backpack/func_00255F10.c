#include "types.h"
typedef struct { char pad[0x134]; unsigned char b134; char pad2[0x2F1 - 0x135]; unsigned char b2F1; unsigned char b2F2; } Obj255F;
extern void func_00255F60(Obj255F* s);
extern void func_00254990(Obj255F* s);
void func_00255F10(Obj255F* s) {
    func_00255F60(s);
    func_00254990(s);
    s->b2F2 = 0;
    if (s->b2F1) {
        s->b134 = 0;
        s->b2F1 = 0;
    }
}