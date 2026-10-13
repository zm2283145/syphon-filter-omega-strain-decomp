#include "SFOLobby.h"
typedef struct { char messageId[0x18]; int id; } Req_4516E0;
extern void* memset(void*, int, unsigned int);
extern void String_Copy(char*, const char*);
extern int func_0046C290(Req_4516E0* a, void* b);
extern int Lobby_GetTime(void);
extern void func_00447A30(void);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void LobbyArray_SetDirty(LobbyArray*, int);
extern void func_00450B30(SFOLobby*);
extern void func_00453FA0(SFOLobby*, void*);
extern void func_004498C0(SFOLobby*);
extern void func_0044D700(SFOLobby*, int);
extern void func_00449800(SFOLobby*, int);
extern void func_00451B30(SFOLobby*);
extern int D_00497788;              /* list8C refresh interval */
extern char D_004C0F68[];           /* "1" */
/* Re-requests list8C (reply callback func_00447A30) once the interval has passed. */
static inline void Tick_4516E0(SFOLobby* self) {
    if (Lobby_GetTime() - self->list8CTime > D_00497788) {
        Req_4516E0 r;
        memset(&r, 0, sizeof(r));
        String_Copy(r.messageId, D_004C0F68);
        r.id = self->list8CId;
        self->requestResult = func_0046C290(&r, func_00447A30);
        if (self->requestResult != 0)
            return;
        self->list8CTime = Lobby_GetTime();
        LobbyArray_Clear(&self->list8C);
        LobbyArray_SetRefreshing(&self->list8C, 1);
    }
    if (*(unsigned char*)&self->list8C.dirty && self->list8C.count > 0)
        LobbyArray_SetDirty(&self->list8C, 0);
}
/* Per-frame lobby update while in state 5: refreshes the lists for the current
 * mode, then runs the other periodic updates. */
void func_004516E0(SFOLobby* self) {
    if (self->state == 5 && !self->inUpdateHook) {
    switch (self->mode) {
    case 0:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, &self->list8C);
        break;
    case 1:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, &self->listA8);
        break;
    }
    func_004498C0(self);
    func_0044D700(self, 0);
    func_00449800(self, 0);
    func_00451B30(self);
    }
}
