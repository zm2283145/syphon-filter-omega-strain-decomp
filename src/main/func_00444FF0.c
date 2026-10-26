#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char *);                            
int memset(char *, int, int);                                
static const unsigned int dat_004C0B48[2] = { 0x0, 0x0 };
extern char D_00584220;
extern signed char D_00584231;
extern signed char D_00584232;
extern signed char D_00584233;
extern signed char D_00584234;
extern signed char D_00584235;
extern signed char D_00584236;
extern signed char D_00584237;
extern signed char D_00584238;
extern signed char D_00584239;
extern signed char D_0058423A;
extern signed char D_0058423B;
extern int D_0058423C;
extern signed char D_00584240;
extern signed char D_00584241;
extern signed char D_00584242;
extern signed char D_00584262;
extern signed char D_00584282;
extern signed char D_005842A2;
extern int D_005842C4;
extern signed char D_005842C8;
extern signed char D_00584378;
extern short D_0058438A;
extern short D_0058438C;
extern short D_0058438E;
extern short D_00584390;

int SFOMGCL_Initialize_Module(short arg0, short arg1, short arg2, short arg3) {
    memset(&D_00584220, 0, 0x2F8);
    String_Copy(&D_00584220, &(*(char*)dat_004C0B48));
    D_0058438A = arg0;
    D_005842C4 = -1;
    D_0058438C = arg1;
    D_0058438E = arg2;
    D_00584390 = arg3;
    D_00584231 = 0;
    D_00584232 = 0;
    D_00584233 = 0;
    D_00584234 = 0;
    D_00584235 = 0;
    D_00584236 = 0;
    D_00584237 = 0;
    D_00584238 = 0;
    D_00584239 = 0;
    D_0058423A = 0;
    D_0058423B = 0;
    D_00584240 = 0;
    D_00584241 = 0;
    D_0058423C = 0;
    D_00584242 = 0;
    D_00584262 = 0;
    D_00584282 = 0;
    D_005842A2 = 0;
    D_005842C8 = 0;
    D_00584378 = 0;
    return 1;
}
