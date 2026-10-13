#include "SFOLobby.h"
extern int D_00585FA8;
extern int D_004977A0;              /* refresh interval */
extern int D_00497938;
extern char D_004C0F68[];           /* "1" */
extern char func_00447790[];
extern void func_00450060(SFOLobby*);
extern int Lobby_GetTime(void);
extern void String_Copy(char*, char*);
extern int func_00476998(void);
extern int func_00469DC8(void*, void*);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void LobbyArray_SetDirty(LobbyArray*, int);
extern void* memset(void*, int, int);
static inline int Off450B30(SFOLobby* self)
{
    return D_00585FA8 != 0 && !self->unk17C;
}
/* Re-requests listA8 (reply callback func_00447790) once the refresh interval has
 * passed, and marks it dirty when it has entries. */
void func_00450B30(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int f28; short f2C; short f2E; } req;
    int dt;
    if (Off450B30(s)) {
        func_00450060(s);
        return;
    }
    dt = Lobby_GetTime() - s->listA8Time;
    if (D_004977A0 < dt) {
        memset(&req, 0, sizeof(req));
        String_Copy(req.messageId, D_004C0F68);
        String_Copy(req.sessionKey, s->sessionKey);
        req.f28 = func_00476998();
        req.f2C = 1;
        req.f2E = D_00497938;
        s->requestResult = func_00469DC8(&req, func_00447790);
        if (s->requestResult != 0) return;
        s->listA8Time = Lobby_GetTime();
        LobbyArray_Clear(&s->listA8);
        LobbyArray_SetRefreshing(&s->listA8, 1);
    }
    if (*(unsigned char*)&s->listA8.dirty && s->listA8.count > 0)
        LobbyArray_SetDirty(&s->listA8, 1);
}
