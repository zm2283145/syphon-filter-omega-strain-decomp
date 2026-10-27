#include "types.h"
#include "sound_event.h"
typedef struct { unsigned char flag; char pad1[0x10]; char name[0x10]; } Item_454440;
typedef struct { int pad0; int count; Item_454440* items; } List_454440;
typedef struct { char pad[0x94]; int count; } Box_454440;
typedef struct { char pad[0x48]; Box_454440* box; void* f4C; char f50[4]; } S_454440;
extern List_454440* g_Hud;
extern char g_Game[];
extern char D_004DADF0[];
extern void Libc_Strcpy(char*, char*);
extern void GuiSubTitleDisplay_Clear(void*);
extern void GuiRadioLog_StartPlayback(S_454440*, char*);
extern void GuiTextListWidget_SetItemState(Box_454440*, int, int);
extern int GuiWidget_onMessage(S_454440*, void*, unsigned short, int, int);

#pragma push
#pragma opt_propagation off
int GuiRadioLog_HandleEvent(S_454440* self, void* ev, unsigned short code, int a3, int idx)
{
    char buf[0x10];
    SoundEvent msg;

    if (code == 0x14) {
        cStopSoundMsg_ctor_cSndFxR_bool(&msg, self->f50, 0);
        msg.kind = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
        if (self->f4C)
            GuiSubTitleDisplay_Clear(self->f4C);
        msg.vtable = D_004DADF0;
        cFileMan_dtor(&msg.req.b, -1);
        cFileMan_dtor(&msg.req.a, -1);
        cMessage_dtor(&msg, 0);
        return 1;
    }
    if (code == 0x13) {
        List_454440* l = g_Hud;
        buf[0] = 0;
        if (l && idx < l->count) {
            Libc_Strcpy(buf, l->items[idx].name);
            l->items[idx].flag = 1;
        }
        GuiRadioLog_StartPlayback(self, buf);
        if (self->box && idx < self->box->count)
            GuiTextListWidget_SetItemState(self->box, idx, 1);
        return 1;
    }
    return GuiWidget_onMessage(self, ev, code, a3, idx);
}
#pragma pop

