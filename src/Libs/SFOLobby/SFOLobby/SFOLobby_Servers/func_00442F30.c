#include "types.h"
void SFOLobby_ServerScreenIntel(char *arg0) {
    unsigned char c = *(volatile unsigned char *)(arg0 + 0x2409); if (c) return;
}