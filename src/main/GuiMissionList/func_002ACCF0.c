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
    char pad[0x5C];
    int unk5C;            /* +0x5C */
    char pad60[0x90 - 0x60];
    const char* textE[6]; /* +0x90 */
    char padA8[0xB0 - 0xA8];
    Widget* child;        /* +0xB0 */
    char padB4[0xD0 - 0xB4];
    const char* textA[4]; /* +0xD0 */
    const char* textB[5]; /* +0xE0 */
    const char* textC[5]; /* +0xF4 */
} Screen;
extern int D_0048BC28;
extern char D_004ABAB0[];
extern char D_004AB9D0[]; /* fallback text */
/* key formats */
extern "C" void GuiArrayWidget_onAdd(Screen* self);
extern "C" Widget* GuiWidget_FindChild_charP(Screen* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" const char* nGlobalization_GetString_charP(const char* key);

/* Screen init: base init, caches the D_0048BC28 child (type D_004ABAB0) at +0xB0 and looks up the localized text tables (+0xD0/+0xE0/+0xF4/+0x90) from formatted keys. */
extern "C" void GuiMissionList_onAdd(Screen* self)
{
    char key4[0x10];
    char key3[0x20];
    char key2[0x20];
    char key1[0x20];
    Widget* child;
    GuiArrayWidget_onAdd(self);
    child = GuiWidget_FindChild_charP(self, D_0048BC28);
    if (!child || !child->IsA(D_004ABAB0))
    child = 0;
    self->child = child;
    {
    Screen* p;
    unsigned int i;
    for (i = 0, p = self; i < 4; i++, p = (Screen*)((char*)p + 4)) {
    sprintf(key1, "AgentStatus%d", i);
    p->textA[0] = nGlobalization_GetString_charP(key1);
    if (!p->textA[0])
    p->textA[0] = D_004AB9D0;
    }
    }
    {
    Screen* p;
    unsigned int i;
    for (i = 0, p = self; i < 5; i++, p = (Screen*)((char*)p + 4)) {
    sprintf(key2, "PingResult%d", i);
    p->textB[0] = nGlobalization_GetString_charP(key2);
    if (!p->textB[0])
    p->textB[0] = D_004AB9D0;
    }
    }
    {
    Screen* p;
    unsigned int i;
    for (i = 0, p = self; i < 5; i++, p = (Screen*)((char*)p + 4)) {
    sprintf(key3, "FilterType%d", i);
    p->textC[0] = nGlobalization_GetString_charP(key3);
    if (!p->textC[0])
    p->textC[0] = D_004AB9D0;
    }
    }
    {
    Screen* p;
    int i;
    for (i = 0, p = self; i < 6; i++, p = (Screen*)((char*)p + 4)) {
    sprintf(key4, "MisListHeader%d", i);
    p->textE[0] = nGlobalization_GetString_charP(key4);
    }
    }
    self->unk5C -= 4;
}
