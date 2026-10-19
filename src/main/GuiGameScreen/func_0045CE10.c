#include "types.h"
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */
typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x20 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x78 - 0x16]; int x78; } Sub_5CE10;
typedef struct { char pad[0x68]; Sub_5CE10* sub; } Scr_5CE10;
extern char g_Game[];
extern char D_004DAE10[];
extern char D_004C21F8[];
extern char* Loc_LookupText(char* key);
extern int GuiSubTitleDisplay_SetText(Sub_5CE10* d, char* text);
extern void GuiWidget_SendEvent(Scr_5CE10* w, Sub_5CE10* to, int ev, int name, int x);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, char* name, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg* msg, SoundRequest* req);
extern void Event_Send(SoundMsg* msg, void* target, int flags);
extern void FileMan_Release(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);
void GuiGameScreen_ShowSubtitle(Scr_5CE10* self, char* name, int unused, int sound)
{
    char* text;
    if (!name || !*name || !self->sub) {
        self->sub->flags &= ~2;
        return;
    }
    text = Loc_LookupText(name);
    if (text && GuiSubTitleDisplay_SetText(self->sub, text)) {
        if (!(self->sub->flags & 2)) GuiWidget_SendEvent(self, self->sub, 6, (int)D_004C21F8, 0);
        self->sub->x78 = 4;
        self->sub->flags |= 2;
    }
    if (sound) {
        SoundMsg msg;
        SoundRequest req;
        SoundRequest_Ctor(&req, 4, name, 0, 100);
        SoundMsg_WrapAction(&msg, &req);
        FileMan_Release(req.partB, -1);
        FileMan_Release(req.partA, -1);
        msg.flag = 1;
        Event_Send(&msg, g_Game, 1);
        msg.vtbl = D_004DAE10;
        FileMan_Release(msg.partB, -1);
        FileMan_Release(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
