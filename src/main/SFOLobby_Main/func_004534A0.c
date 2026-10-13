#pragma cplusplus on
#include "types.h"
extern "C" {
int func_002EC580(int *);
int Lobby_GetTime(void);
int func_00468D38(void);
int func_00468DD8(void);
int func_00468EF0(void);
extern int D_00497928;
extern char D_004C0FB0[];
extern unsigned char D_005721C8;
extern char D_005723B8;
extern unsigned char D_00585FC0;
}

typedef struct {
    char pad0[0x180];
    int port;               /* 0x180 */
    char pad184[0x2564 - 0x184];
    unsigned char state;    /* 0x2564 */
    char pad2565[3];
    char* stateName;        /* 0x2568 */
    int stateLine;          /* 0x256C */
    char pad2570[0x255C - 0x2570 + 0x20];
} Dummy4534A0;

typedef struct {
    char pad0[0x180];
    int port;               /* 0x180 */
    char pad184[0x255C - 0x184];
    int mode;               /* 0x255C */
    char pad2560[4];
    unsigned char state;    /* 0x2564 */
    char pad2565[3];
    char* stateName;        /* 0x2568 */
    int stateLine;          /* 0x256C */
    char pad2570[8];
    int now;                /* 0x2578 */
    char pad257C[0x2660 - 0x257C];
    int deadline;           /* 0x2660 */
} Conn4534A0;

inline bool Port_IsReady(int arg0) {
    struct { int size; int st[4]; int pad[3]; } s;
    if ((arg0 < 0) || (arg0 >= 4)) {
        return false;
    }
    s.size = 0x18;
    func_002EC580((int*)&s);
    if (s.st[arg0] == 2)
        return true;
    return false;
}

extern "C" int SFOLobby_Poll(Conn4534A0* self, int start, int timeout, int flag) {
    int now;
    int ok;
    bool fallback;
    if (self->mode == 0) {
        self->now = 0;
        return 0;
    }
    if (D_00585FC0 != 0) {
        return 1;
    }
    D_00585FC0 = 1;
    now = Lobby_GetTime();
    fallback = false;
    self->now = now;
    if (flag != 0) {
        ok = func_00468DD8();
    } else if (self->mode == 0xA && D_005721C8 != 0) {
        ok = func_00468EF0();
    } else {
        fallback = true;
        ok = func_00468D38();
    }
    if (self->deadline == 0) {
        self->deadline = now + D_00497928;
    }
    if (ok != 0) {
        if (!Port_IsReady(self->port) || self->deadline <= now) {
            if (fallback) {
                D_005723B8 = 1;
            }
            if (self->state != 5) {
                self->state = 5;
                self->stateName = D_004C0FB0;
                self->stateLine = 0x26C;
            }
            D_00585FC0 = 0;
            return 0;
        }
    } else {
        self->deadline = now + D_00497928;
    }
    if (start != 0 && timeout > 0 && timeout < now - start) {
        D_00585FC0 = 0;
        return 0;
    }
    D_00585FC0 = 0;
    return 1;
}


