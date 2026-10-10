#include "types.h"

typedef struct Sub78 {
    char pad[0xC];
    unsigned char unkC;
    char pad2[3];
} Sub78;

typedef struct Obj116 {
    char pad[0x60];
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Sub78 sub;
    char pad2[0xD0 - 0x88];
    unsigned char unkD0;
    char pad3;
    unsigned char unkD2;
    char pad4[0xF0 - 0xD3];
    int unkF0;
    int unkF4;
    char pad5[0x115 - 0xF8];
    unsigned char unk115;
} Obj116;

extern void func_00278440(Sub78*);
extern int func_001361D0(int*);
extern void func_00278430(Sub78*, int);

/* Constructor body: resets three (0, -2) pairs, sets up the sub-object and clears flags. */
Obj116* func_002783A0(Obj116* o) {
    int kind;
    Sub78* sub;
    o->unk64 = -2;
    sub = &o->sub;
    o->unk60 = 0;
    o->unk6C = -2;
    o->unk68 = 0;
    o->unk74 = -2;
    o->unk70 = 0;
    kind = 5;
    func_00278440(sub);
    func_00278430(sub, func_001361D0(&kind));
    sub->unkC = 0;
    o->unkD0 = 0;
    o->unkD2 = 0;
    o->unkF0 = 0;
    o->unkF4 = 0;
    o->unk115 = 0;
    return o;
}
