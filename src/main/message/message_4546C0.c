#include "types.h"
#include "sound_event.h"
typedef struct { char pad[0x4C]; void* f4C; char f50[4]; } S_4546C0;
extern char g_Game[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void GuiSubTitleDisplay_Clear(void*);
extern void GuiSubTitleDisplay_SetText(void*, char*);
extern char* Loc_LookupText(char*);
extern void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);

void GuiRadioLog_Play(S_4546C0* self, char* name)
{
    SoundEventP m2;
    SoundEvent m1;
    char* t;

    SoundEvent_Ctor(&m1, self->f50, 0);
    m1.kind = 1;
    Event_Send(&m1, g_Game, 1);
    if (self->f4C)
        GuiSubTitleDisplay_Clear(self->f4C);
    m1.vtable = D_004DADF0;
    FileMan_Release(&m1.req.b, -1);
    FileMan_Release(&m1.req.a, -1);
    cMessage_dtor(&m1, 0);
    t = Loc_LookupText(name);
    if (t && self->f4C)
        GuiSubTitleDisplay_SetText(self->f4C, t);
    SoundAction_CtorVoice(self->f50, 4, name, 0, 0x3E8);
    SoundMsg_WrapAction(&m2, self->f50);
    m2.kind = 1;
    Event_Send(&m2, g_Game, 1);
    m2.vtable = D_004DAE10;
    FileMan_Release(&m2.req.b, -1);
    FileMan_Release(&m2.req.a, -1);
    cMessage_dtor(&m2, 0);
}
