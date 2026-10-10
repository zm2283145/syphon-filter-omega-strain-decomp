#ifndef SFOLOBBY_MAIN_TYPES_H
#define SFOLOBBY_MAIN_TYPES_H

typedef void (*LobbyMainCallback)(int a0, int a1);

/* Lobby main object (partial). */
typedef struct LobbyMain {
    char pad0000[0x180];
    int unk180;                 /* 0x180 positive values require cleanup */
    char pad0184[0x1EA8 - 0x184];
    int unk1EA8;                /* 0x1EA8 cleared by func_00452C70 */
    char pad1EAC[0x2550 - 0x1EAC];
    int unk2550;                /* 0x2550 */
    LobbyMainCallback callback; /* 0x2554 optional notification callback */
    char pad2558[0x2564 - 0x2558];
    unsigned char state;        /* 0x2564 */
    char pad2565[0x2570 - 0x2565];
    int unk2570;                /* 0x2570 */
} LobbyMain;

#endif
