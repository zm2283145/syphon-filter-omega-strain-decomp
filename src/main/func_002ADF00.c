/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};

typedef struct Screen {
    char pad[0x94];
    unsigned char unk94;  /* +0x94 */
    char pad95[0x160 - 0x95];
    Widget* first;        /* +0x160 */
    Widget* second;       /* +0x164 */
} Screen;
extern "C" char D_004ABAE8[];
extern "C" char D_004ABAF8[];
static void * const dat_0048BCB8[2] = { (void*)D_004ABAE8, (void*)0x0 };
static void * const dat_0048BCC0[2] = { (void*)D_004ABAF8, (void*)0x0 };
extern char D_004A9870[];
extern "C" void GuiMissionLobbyScreen_onAdd(Screen* self);
extern "C" Widget* GuiWidget_FindChild_charP(Screen* self, int id);

/* Base init (GuiMissionLobbyScreen_onAdd), then caches the (*(int*)dat_0048BCB8) / (*(int*)dat_0048BCC0) children (+0x160/+0x164) when they are of type D_004A9870, and clears +0x94. */
extern "C" void GuiNetContacts_onAdd(Screen* self)
{
    Widget* child;
    GuiMissionLobbyScreen_onAdd(self);
    child = GuiWidget_FindChild_charP(self, (*(int*)dat_0048BCB8));
    if (!child || !child->IsA(D_004A9870))
    child = 0;
    self->first = child;
    child = GuiWidget_FindChild_charP(self, (*(int*)dat_0048BCC0));
    if (!child || !child->IsA(D_004A9870))
    child = 0;
    self->second = child;
    self->unk94 = 0;
}
