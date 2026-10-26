#pragma cplusplus on
#include "msg_clone.h"
#include "vc_copy.h"
static inline void CpSD(const void* s, void* d) { VCopyF(d, s); }
extern "C" char D_004DFD80[];
extern "C" char D_004E0840[];
extern "C" char D_004E0120[];
MSG_CLONE_BEGIN(cCharActionMsg_MotionParams_Clone, 0x50, "character.hh", 0x3C8)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0840;
    F(int, 0x24) = S(int, 0x24);
    F(char, 0x28) = S(char, 0x28);
    {
        char* d = (char*)p + 0x30;
        char* s = (char*)self + 0x30;
        CpSD(s, d);
    }
    F(float, 0x40) = S(float, 0x40);
    F(float, 0x44) = S(float, 0x44);
    F(char, 0x48) = S(char, 0x48);
    p->vt = D_004E0120;
MSG_CLONE_END