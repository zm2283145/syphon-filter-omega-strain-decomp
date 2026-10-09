#ifndef SFOLOBBY_MAIN_TYPES_H
#define SFOLOBBY_MAIN_TYPES_H

typedef void (*LobbyMainCallback)(int a0, int a1);

/* Lobby main object (partial). */
typedef struct LobbyMain {
    char pad0000[0x2550];
    int unk2550;                /* 0x2550 */
    LobbyMainCallback callback; /* 0x2554 optional notification callback */
    char pad2558[0x2564 - 0x2558];
    unsigned char state;        /* 0x2564 */
    char pad2565[0x2570 - 0x2565];
    int unk2570;                /* 0x2570 */
} LobbyMain;

#endif
