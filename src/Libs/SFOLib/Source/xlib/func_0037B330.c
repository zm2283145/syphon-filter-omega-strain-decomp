/* 0037B330 XLib_DisplayBlendedLastFrame - xlib.cc */
#pragma cplusplus on
#include "types.h"
typedef unsigned long u_long64;
struct BTexHdr { char p0[4]; unsigned short width; unsigned short height; char p8[2]; unsigned short psm; };
struct BTex { char p0[0x44]; BTexHdr* hdr; char p48[8]; u_long64 tex0; };
struct BTexMan { char p0[8]; BTex** tex; };
struct XLib {
    unsigned int displayFlags;
    char p4[0x10 - 4];
    int width, height, depth, buffWidth, buffHeight, buffDepth, buffZDepth, psm;
    char p30[0x64 - 0x30];
    unsigned char ishalf;
    char p65[0x12C - 0x65];
    int frameBuffAddr[2];
    int zBuffAddr, frameFxBuffAddr, txtrBuffAddr, currFrameBuf;
    char p144[0x1058 - 0x144];
    BTexMan* texMan;
    char p105C[0x1100 - 0x105C];
    int scrBlendTID;
    int scrBlendAlpha;
};
static inline u_long64 SetDispFB(int fbp, int fbw, int psm)
{ return (u_long64)fbp | ((u_long64)fbw << 9) | ((u_long64)psm << 15); }
static inline u_long64 SetDisplay(unsigned int dx, unsigned int dy, unsigned int magh, unsigned int magv, unsigned int dw, unsigned int dh)
{ return (u_long64)dx | ((u_long64)dy << 12) | ((u_long64)magh << 23) | ((u_long64)magv << 27) | ((u_long64)dw << 32) | ((u_long64)dh << 44); }
static inline int Max(int a, int b) { return a > b ? a : b; }
extern "C" void XLib_DisplayBlendedLastFrame(const XLib* o)
{
    int dispBuffAddr;
    unsigned char isInterlace;
    unsigned char isPal;
    int magh;
    BTex* tex; u_long64 pm; unsigned int dx; int tw; int th; int ps; unsigned int ta;
    dispBuffAddr = o->frameBuffAddr[!o->currFrameBuf];
    tex = o->texMan->tex[o->scrBlendTID];
    isInterlace = !((o->displayFlags & 4) != 0);
    isPal = (o->displayFlags & 2) != 0;
    pm = ((u_long64)o->scrBlendAlpha << 8) | 0x63;
    ta = (unsigned int)(tex->tex0 & 0x3fff);
    tw = tex->hdr->width;
    th = tex->hdr->height;
    ps = tex->hdr->psm;
    *(volatile u_long64*)0x12000000 = pm;
    dx = isPal ? 656 : 636;
    *(volatile u_long64*)0x12000020 = (u_long64)isInterlace | ((u_long64)o->ishalf << 1);
    *(volatile u_long64*)0x12000070 = SetDispFB(dispBuffAddr, o->buffWidth >> 6, o->psm);
    *(volatile u_long64*)0x12000090 = SetDispFB(ta >> 5, tw >> 6, ps);
    magh = (o->width + 2559) / o->width - 1;
    *(volatile u_long64*)0x12000080 = SetDisplay(dx, isPal ? (isInterlace ? 72 : 36) : (isInterlace ? 50 : 25), magh, 0, o->width * 4 - 1, o->height - 1);
    {
    int magh2 = Max(0, o->width * 4 / tw - 1);
    int magv = Max(0, o->height / th - 1);
    int dh = o->height - 1;
    int dw = o->width * 4 - 1;
    unsigned int dx2 = isPal ? 656 : 636;
    *(volatile u_long64*)0x120000A0 = SetDisplay(dx2, isPal ? (isInterlace ? 72 : 36) : (isInterlace ? 50 : 25), magh2, magv, dw, dh);
    }
}
