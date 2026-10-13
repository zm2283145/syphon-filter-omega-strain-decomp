#pragma cplusplus on
#include "types.h"
struct W_0029B360 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x10 - 4]; int index; unsigned short flags; char pad16[0x88 - 0x16]; W_0029B360* link;
};
struct S_0029B360 {
    char pad0[0x80]; W_0029B360* p80; W_0029B360* p84; W_0029B360* p88; W_0029B360* tab[4]; W_0029B360* tabLabel[4];
    W_0029B360* pAC; W_0029B360* pB0; char padB4[0x401 - 0xB4]; unsigned char b401; char pad402[0x408 - 0x402];
    W_0029B360* p408; W_0029B360* p40C; W_0029B360* p410; W_0029B360* p414; W_0029B360* p418; W_0029B360* p41C;
    W_0029B360* p420; W_0029B360* p424; W_0029B360* p428; W_0029B360* p42C; W_0029B360* p430; W_0029B360* p434;
    char* t438[2]; char* t440[2]; char* t448[4]; char* t458; char* t45C; char* t460; char* t464;
};
extern "C" {
extern char* D_00506420[4];
extern char* D_00506430[4];
extern char* D_0048B8D0;
extern char* D_0048B8F8;
extern char D_004A7520[];
extern char D_004A9870[];
extern char D_004AA640[];
extern char D_004AAA80[];
void func_0041F150(S_0029B360* self);
W_0029B360* GuiWidget_FindChildByName(S_0029B360* self, char* name);
char* Loc_LookupText(char* key);
int sprintf(char* buf, const char* fmt, ...);
}
static inline W_0029B360* FindAs_0029B360(S_0029B360* self, char* name, char* type)
{
    W_0029B360* w = GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
/* Looks up the child widgets and localised strings of the page. */
extern "C" void func_0029B360(S_0029B360* self)
{
    char buf[32];
    int i;
    func_0041F150(self);
    for (i = 0; i < 4; i++) {
        self->tab[i] = GuiWidget_FindChildByName(self, D_00506420[i]);
        if (self->tab[i])
            self->tab[i]->flags &= ~4;
        self->tabLabel[i] = FindAs_0029B360(self, D_00506430[i], D_004A9870);
        if (self->tabLabel[i])
            self->tabLabel[i]->index = i;
    }
    self->pB0 = FindAs_0029B360(self, D_0048B8F8, D_004A7520);
    self->pAC = GuiWidget_FindChildByName(self, D_0048B8D0);
    self->p80 = GuiWidget_FindChildByName(self, "buttonsquare");
    self->p84 = GuiWidget_FindChildByName(self, "buttonx");
    self->p88 = FindAs_0029B360(self, "label_to_map", D_004A7520);
    self->p408 = FindAs_0029B360(self, "value_manualaim", D_004A9870);
    self->p40C = FindAs_0029B360(self, "value_rumble", D_004A9870);
    self->p410 = FindAs_0029B360(self, "value_freelookx", D_004A9870);
    self->p414 = FindAs_0029B360(self, "value_freelooky", D_004A9870);
    self->p418 = FindAs_0029B360(self, "slider_sfx", D_004AAA80);
    self->p41C = FindAs_0029B360(self, "slider_voices", D_004AAA80);
    self->p420 = FindAs_0029B360(self, "slider_music", D_004AAA80);
    self->p424 = FindAs_0029B360(self, "value_mode_btn", D_004A9870);
    self->p428 = FindAs_0029B360(self, "slider_gamma", D_004AAA80);
    self->p42C = FindAs_0029B360(self, "value_videomode", D_004A9870);
    self->p430 = FindAs_0029B360(self, "player_list", D_004AA640);
    self->p434 = GuiWidget_FindChildByName(self, "select_config_select");
    if (self->p430)
        self->p430->link = self->p434;
    { int j;
    for (j = 0; j < 2; j++) {
        sprintf(buf, "AudioMode%d", j);
        self->t438[j] = Loc_LookupText(buf);
    } }
    { int j;
    for (j = 0; j < 2; j++) {
        sprintf(buf, "VideoMode%d", j);
        self->t440[j] = Loc_LookupText(buf);
    } }
    { int j;
    for (j = 0; j < 4; j++) {
        sprintf(buf, "OptionsHeader%d", j);
        self->t448[j] = Loc_LookupText(buf);
    } }
    self->t458 = Loc_LookupText("ControlInvert");
    self->t45C = Loc_LookupText("ControlNormal");
    self->t460 = Loc_LookupText("MB_On");
    self->t464 = Loc_LookupText("MB_Off");
    self->b401 = 1;
}