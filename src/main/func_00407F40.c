#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004BE9F0[];
extern "C" char D_004DFD80[];
extern "C" char D_004E08A0[];
MSG_CLONE_BEGIN(cDamageMsg_v01, 0x30, D_004BE9F0, 0x20)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E08A0;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(char, 0x2C) = S(char, 0x2C);
    F(char, 0x2D) = S(char, 0x2D);
    F(unsigned char, 0x2E) = S(unsigned char, 0x2E);
MSG_CLONE_END
