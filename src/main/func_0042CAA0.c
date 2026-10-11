#pragma cplusplus on
#include "msg_clone.h"
struct V2CAA0 { union { struct { unsigned int a, b; char* c; } l; struct { unsigned char f : 1; unsigned char n : 7; char buf[11]; } s; } u; };
extern "C" char D_004BFA90[];
extern "C" char D_004DFD80[];
extern "C" char D_004E0EA0[];
MSG_CLONE_BEGIN(func_0042CAA0, 0x30, D_004BFA90, 0x1C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0EA0;
    F(V2CAA0, 0x24) = S(V2CAA0, 0x24);
MSG_CLONE_END
