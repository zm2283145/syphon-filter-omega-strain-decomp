#pragma cplusplus on
#include "types.h"
typedef unsigned long u_long64;
struct XLib {
    unsigned int displayFlags;
    char p4[0x10 - 4];
    int width, height, depth, buffWidth, buffHeight, buffDepth, buffZDepth, psm;
    char p30[0x64 - 0x30];
    unsigned char ishalf;
    char p65[0x12C - 0x65];
    int frameBuffAddr[2];
    int zBuffAddr, frameFxBuffAddr, txtrBuffAddr, currFrameBuf;
    char p144[0x1100 - 0x144];
    int scrBlendTID;
};
static inline u_long64 SetDisplay(unsigned int dx, unsigned int dy, unsigned int magh, unsigned int magv, unsigned int dw, unsigned int dh)
{ return (u_long64)dx | ((u_long64)dy << 12) | ((u_long64)magh << 23) | ((u_long64)magv << 27) | ((u_long64)dw << 32) | ((u_long64)dh << 44); }
extern "C" void XLib_DisplayBlendedLastFrame(const XLib* o);
extern "C" void XLib_DisplayLastFrame(const XLib* o);
void XLib_DisplayLastFrame(const XLib* o)
{
    if (o->scrBlendTID != -1) {
        XLib_DisplayBlendedLastFrame(o);
    } else {
        int dispBuffAddr;
        unsigned char isInterlace, isPal, isPscan;
        int kPScanOffX;
        int xpos, ypos;
        int kMagH;
        dispBuffAddr = o->frameBuffAddr[!o->currFrameBuf];
        isInterlace = !((o->displayFlags & 4) != 0);
        isPscan = (o->displayFlags & 4) != 0;
        isPal = (o->displayFlags & 2) != 0;
        *(volatile u_long64*)0x12000000 = 0xFF61;
        *(volatile u_long64*)0x12000020 = (u_long64)isInterlace | ((u_long64)o->ishalf << 1);
        *(volatile u_long64*)0x12000070 = (u_long64)dispBuffAddr | ((u_long64)(o->buffWidth >> 6) << 9) | ((u_long64)o->psm << 15);
        kPScanOffX = -o->width / 2;
        xpos = 0;
        ypos = 0;
        if (isPscan) xpos += kPScanOffX;
        else if (isPal) ypos += 4;
        kMagH = (o->width + 2559) / o->width - 1;
        if (isPscan) kMagH = 1;
        {unsigned int dx, dy, dw, dh;
        dh = o->height - 1;
        dw = o->width * (kMagH + 1) - 1;
        dx = (isPal ? 656 : 636);
        dy = (isPal ? (isInterlace ? 72 : 36) : (isInterlace ? 50 : 25));
        *(volatile u_long64*)0x12000080 = SetDisplay(dx + xpos, dy + ypos, kMagH, 0, dw, dh);}
    }
}


