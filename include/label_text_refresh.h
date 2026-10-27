#ifndef LABEL_TEXT_REFRESH_H
#define LABEL_TEXT_REFRESH_H

/*
 * Screen refresh: clear the global flag byte (+0x2F of *D_004FFC04), find
 * the child widget D_004A9CF8 and, when it is a text widget, set its text
 * to the localized textKey; then run GuiAgentDirectoryWidget_UpdateNameList and the base update.
 * C++ only (#pragma cplusplus on before including).
 */
#include "vslot_pad.h"

class LtrWidget {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
};

struct LtrGlobal { char pad[0x2F]; unsigned char flag2F; };

extern "C" {
extern LtrGlobal* D_004FFC04;
extern char D_004A9CF8[];
extern char D_004A7520[];
LtrWidget* GuiWidget_FindChild_charP(void* self, char* name);
char* nGlobalization_GetString_charP(char* key);
void GuiTextWidget_SetText(LtrWidget* w, char* text, int flags);
void GuiAgentDirectoryWidget_UpdateNameList(void* self);
void GuiWidget_onWake(void* self);
}

static inline LtrWidget* Ltr_Cast(LtrWidget* w)
{
    return (w && w->IsA(D_004A7520)) ? w : 0;
}

#define DEFINE_LABEL_TEXT_REFRESH(name, textKey)                              \
    extern "C" char textKey[];                                                \
    extern "C" void name(void* self)                                          \
    {                                                                         \
        LtrWidget* w;                                                         \
        D_004FFC04->flag2F = 0;                                               \
        w = Ltr_Cast(GuiWidget_FindChild_charP(self, D_004A9CF8));                        \
        if (w)                                                                \
            GuiTextWidget_SetText(w, nGlobalization_GetString_charP(textKey), 0);                     \
        GuiAgentDirectoryWidget_UpdateNameList(self);                                                  \
        GuiWidget_onWake(self);                                                  \
    }

#endif /* LABEL_TEXT_REFRESH_H */