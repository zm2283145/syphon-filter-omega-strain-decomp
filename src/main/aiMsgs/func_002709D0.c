#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004A8C40[];
extern "C" char D_004DCC50[];
extern "C" char D_004DCD70[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIDisguiseTakenMsg_v01, 0x28, D_004A8C40, 0x13C)
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
    p->vt = D_004DCC50;
MSG_CLONE_END
