#pragma cplusplus on
#include "types.h"

extern "C" {
extern char D_004C05E8[];
int Libc_Sscanf(const char*, const char*, ...);
}

static inline int ParseIp(char* s) {
    int v[4];

    __clear((char*)v, 0x10);
    if (Libc_Sscanf(s, D_004C05E8, &v[0], &v[1], &v[2], &v[3]) != 4) return 0;
    return (v[0] << 24) | (v[1] << 16) | (v[2] << 8) | v[3];
}

extern "C" int SFOLobby_PackIPAddress(char* s) {
    if (s == 0 || *s == 0) return 0;
    return ParseIp(s);
}
