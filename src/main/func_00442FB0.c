#include "types.h"
extern char D_00584200[];
extern char D_004C05E8[];
extern int sprintf(char* b, const char* f, ...);
char* SFOLobby_UnpackIPAddress(unsigned int ip)
{
    D_00584200[0] = 0;
    if (!ip) return D_00584200;
    sprintf(D_00584200, D_004C05E8, (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    return D_00584200;
}
