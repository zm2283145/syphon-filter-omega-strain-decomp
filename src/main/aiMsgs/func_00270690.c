#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004A8C70[];
extern "C" char D_004DCBF0[];
extern "C" char D_004DCD70[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIWeaponFiredMsg_v01, 0x34, D_004A8C70, 0xFC)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCBF0;
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
    F(unsigned char, 0x30) = S(unsigned char, 0x30);
MSG_CLONE_END
