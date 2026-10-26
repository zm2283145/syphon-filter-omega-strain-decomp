#pragma cplusplus on
#include "msg_clone.h"
#include "v4_asm_copy.h"
static inline void CpSD(const void* s, void* d) { V4Copy(d, s); }
extern "C" char D_004E0140[];
extern "C" char D_004DFD80[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(cCharActionMsg_Vector_Clone, 0x40, "character.hh", 0x239)
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
    p->vt = D_004E0140;
    {
        char* d = (char*)p + 0x30;
        char* s = (char*)self + 0x30;
        CpSD(s, d);
    }
MSG_CLONE_END
