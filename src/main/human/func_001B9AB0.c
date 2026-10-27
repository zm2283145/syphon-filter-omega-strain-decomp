#pragma cplusplus on
#include "msg_clone.h"
#include "vc_copy.h"
extern "C" char D_0049D8D0[];
extern "C" char D_004DFD80[];
extern "C" char D_004DCF10[];
extern "C" char D_004DA8D0[];
MSG_CLONE_BEGIN(cNetThrowStarMsg_Clone, 0x40, D_0049D8D0, 0x331C)
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
    p->vt = D_004DA8D0;
    F(int, 0x24) = S(int, 0x24);
    {
        char* d = (char*)p + 0x30;
        char* s = (char*)self + 0x30;
        VCopyF(d, s);
    }
MSG_CLONE_END
