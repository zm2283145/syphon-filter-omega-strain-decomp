#include "types.h"
#include "sound_event.h"
typedef struct { char pad[0x4C]; void* f4C; char f50[4]; } S_4546C0;
extern char g_Game[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void GuiSubTitleDisplay_Clear(void*);
extern void GuiSubTitleDisplay_AddMessage(void*, char*);
extern char* nGlobalization_GetString_charP(char*);
extern void cSndFx_SetSndFx(void* action, int kind, char* name, int a, int b);

void GuiRadioLog_StartPlayback(S_4546C0* self, char* name)
{
    SoundEventP m2;
    SoundEvent m1;
    char* t;

    cStopSoundMsg_ctor_cSndFxR_bool(&m1, self->f50, 0);
    m1.kind = 1;
    QueueMessage_cMessageR_cSystemP_int(&m1, g_Game, 1);
    if (self->f4C)
        GuiSubTitleDisplay_Clear(self->f4C);
    m1.vtable = D_004DADF0;
    cFileMan_dtor(&m1.req.b, -1);
    cFileMan_dtor(&m1.req.a, -1);
    cMessage_dtor(&m1, 0);
    t = nGlobalization_GetString_charP(name);
    if (t && self->f4C)
        GuiSubTitleDisplay_AddMessage(self->f4C, t);
    cSndFx_SetSndFx(self->f50, 4, name, 0, 0x3E8);
    SoundMsg_WrapAction(&m2, self->f50);
    m2.kind = 1;
    QueueMessage_cMessageR_cSystemP_int(&m2, g_Game, 1);
    m2.vtable = D_004DAE10;
    cFileMan_dtor(&m2.req.b, -1);
    cFileMan_dtor(&m2.req.a, -1);
    cMessage_dtor(&m2, 0);
}
