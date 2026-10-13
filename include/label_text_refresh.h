#ifndef LABEL_TEXT_REFRESH_H
#define LABEL_TEXT_REFRESH_H

/*
 * Screen refresh: clear the global flag byte (+0x2F of *D_004FFC04), find
 * the child widget D_004A9CF8 and, when it is a text widget, set its text
 * to the localized textKey; then run AgentOpen_BuildSlotList and the base update.
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
LtrWidget* func_0041DB80(void* self, char* name);
char* Loc_LookupText(char* key);
void func_0041BEB0(LtrWidget* w, char* text, int flags);
void AgentOpen_BuildSlotList(void* self);
void func_0041EFA0(void* self);
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
        w = Ltr_Cast(func_0041DB80(self, D_004A9CF8));                        \
        if (w)                                                                \
            func_0041BEB0(w, Loc_LookupText(textKey), 0);                     \
        AgentOpen_BuildSlotList(self);                                                  \
        func_0041EFA0(self);                                                  \
    }

#endif /* LABEL_TEXT_REFRESH_H */