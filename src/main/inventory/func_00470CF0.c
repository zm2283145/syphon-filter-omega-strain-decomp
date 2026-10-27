#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004C3348[];
extern "C" char D_004DCF10[];
extern "C" char D_004DFD80[];
extern "C" char D_004E1AC0[];
MSG_CLONE_BEGIN(cNetInventoryMsg_Clone, 0x28, D_004C3348, 0x36)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCF10;
    p->vt = D_004E1AC0;
    F(short, 0x24) = S(short, 0x24);
    F(char, 0x26) = S(char, 0x26);
    F(char, 0x27) = S(char, 0x27);
MSG_CLONE_END
