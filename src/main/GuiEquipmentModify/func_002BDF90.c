#pragma cplusplus on
#include "types.h"
struct W_002BDF90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
extern "C" {
extern char D_004AC370[];
extern char D_004A7520[];
extern char D_004AC388[];
void* GuiWidget_FindChildByName(void* self, char* name);
void func_0041BEB0(W_002BDF90* w, char* s, int a);
}
static inline W_002BDF90* FindAs_002BDF90(void* self, char* name, char* type)
{
    W_002BDF90* w = (W_002BDF90*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Clear_002BDF90(void* self, char* name)
{
    W_002BDF90* w = FindAs_002BDF90(self, name, D_004A7520);
    if (w)
        func_0041BEB0(w, D_004AC388, 0);
}
extern "C" void func_002BDF90(void* self)
{
    Clear_002BDF90(self, D_004AC370);
    Clear_002BDF90(self, "value_firerate1");
    Clear_002BDF90(self, "value_damage1");
    Clear_002BDF90(self, "value_clip_size1");
    Clear_002BDF90(self, "value_max_rounds1");
    Clear_002BDF90(self, "value_weaponname2");
    Clear_002BDF90(self, "value_firerate2");
    Clear_002BDF90(self, "value_damage2");
    Clear_002BDF90(self, "value_clip_size2");
    Clear_002BDF90(self, "value_max_rounds2");
}