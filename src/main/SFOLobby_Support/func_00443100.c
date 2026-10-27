#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern "C" {
void* memset(void*, int, unsigned int);
void Libc_Strcpy(char*, const char*);
int SFOLobby_GetMillisecs(void);
int MediusTextFilter(void*, void*);
void SFOLobby_Callback_TextFilter(void);
void SFOLobby_GuiCallback(char*, int, int);
int SFOLobby_Poll(char*, int, int, int);
void SFOLobby_SetError(char*, int, char*, int);
extern int D_00497890;
extern char D_004C05F8[];
extern char D_004C0600[];
}

struct ConnReq {
    char proto[0x15];
    char host[0x13];
    int port;
    char name[0x40];
};

extern "C" int SFOLobby_ServerTextFilter(char* self, char* name, int port) {
    ConnReq req;
    int st;

    memset(&req, 0, sizeof(req));
    Libc_Strcpy(req.proto, D_004C05F8);
    Libc_Strcpy(req.host, self + 0x2418);
    req.port = port;
    Libc_Strcpy(req.name, name);
    F_(self, 0x1D0, int) = 0;
    F_(self, 0x2410, int) = SFOLobby_GetMillisecs();
    F_(self, 0x24C, int) = MediusTextFilter(&req, (void*)SFOLobby_Callback_TextFilter);
    if (F_(self, 0x24C, int) != 0) return 0;
    while (F_(self, 0x1D0, int) == 0) {
        SFOLobby_GuiCallback(self, 0, 0);
        if (!SFOLobby_Poll(self, F_(self, 0x2410, int), D_00497890, 0)) {
            SFOLobby_SetError(self, 2, D_004C0600, 0x19F);
            return 0;
        }
    }
    st = F_(self, 0x1030, int);
    if (st == -966) {
        SFOLobby_SetError(self, 3, D_004C0600, 0x1A7);
        return 0;
    }
    if (st == -967) {
        SFOLobby_SetError(self, 0x19, D_004C0600, 0x1AE);
        return 0;
    }
    return 1;
}


