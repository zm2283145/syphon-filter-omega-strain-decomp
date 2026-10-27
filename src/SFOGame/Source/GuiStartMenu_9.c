/*
 * SFOGame/Source/GuiStartMenu: 2 files, 00454A80-00454B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_454A80 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int QueueMessage_cMessageR_cSystemP_int();                         
int cStopSoundMsg_ctor_cSndFxR_bool();                    
int cMessage_dtor();                           
int cFileMan_dtor();                            
int GuiWidget_onSleep();                                  
int GuiSubTitleDisplay_Clear();                               
extern char D_004DADF0;
extern char g_Game;

void GuiRadioLog_onSleep(char * arg0) {
    struct { char *vt; char p04[0x1C]; signed char f40; char p41[0x57]; char f98[0x9C]; char f134[0xBC]; } m;
    int temp_a0;

    GuiWidget_onSleep();
    cStopSoundMsg_ctor_cSndFxR_bool(&m, arg0 + 0x50, 0);
    m.f40 = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, &g_Game, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        GuiSubTitleDisplay_Clear(temp_a0);
    }
    m.vt = &D_004DADF0;
    cFileMan_dtor(m.f134, -1);
    cFileMan_dtor(m.f98, -1);
    cMessage_dtor(&m, 0);
}
static inline void merge_flush_message_454A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_454A80 */

/* merge_units: begin func_00454B10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_454B10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_454B10;
typedef struct { char pad[0x33E7]; unsigned char b33E7; char pad33E8[0x3524 - 0x33E8]; void* f3524; } A_454B10;
typedef struct { char pad[0x30]; A_454B10* f30; } G_454B10;
typedef struct { char pad[0x48]; int f48; } S_454B10;
typedef struct { char pad[0x48]; S_454B10* f48; void* f4C; } O_454B10;
extern "C" {
extern G_454B10* g_LocalPlayer;
extern void* g_WeaponDatabase;
extern void* g_Hud;
#if 0 /* merge_units */
extern char g_Game[];
#endif /* merge_units */
#define g_Game ((char*)&g_Game) /* merge_units */

void GuiMLTextWidget_ScrollUp(void* p, int v);
void GuiMLTextWidget_ScrollDown(void* p, int v);
int cWeapon_GetWeaponSlot(int id);
void* cWeaponDB_GetEntry(void* db, int id);
void* cWeapon_GetWeaponEntry(void* p);
void cPlayer_SelectWeapon(G_454B10* g, int id);
void cHuman_CycleGadgetState(A_454B10* a);
M_454B10* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void GuiEquipmentPane_SelectNext(O_454B10* o, bool f);
void GuiStartMenu_ReturnToMenu(O_454B10* o);
void cHud_DeactivateObjectiveMenu(void* p);
void cGameSystem_PauseGame(void* p, int v);
int GuiEquipmentPane_onInput(O_454B10* o, Ev_454B10* ev);
}
static inline unsigned char Down_454B10(Ev_454B10* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_454B10(Ev_454B10* e, int b) { unsigned char r = 0; if (Down_454B10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_454B10(Ev_454B10* e, int b) { unsigned char r = 0; if (Btn_454B10(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_454B10(Ev_454B10* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_454B10(Ev_454B10* e, int b) { return Down2_454B10(e) && e->btn == b; }
static inline bool Plain2_454B10(Ev_454B10* e, int b) { return Btn2_454B10(e, b) && e->b6 == 0; }

int GuiEquipmentPane_onInput(O_454B10* o, Ev_454B10* ev)
{
    if (Plain_454B10(ev, 0x1000) && o->f4C) {
        GuiMLTextWidget_ScrollUp(o->f4C, 0);
        return 1;
    }
    if (Plain2_454B10(ev, 0x4000) && o->f4C) {
        GuiMLTextWidget_ScrollDown(o->f4C, 0);
        return 1;
    }
    if (Plain2_454B10(ev, 0x40)) {
        int wid = o->f48 ? o->f48->f48 : -1;
        if (wid != -1) {
            unsigned char sent;
            A_454B10* a = g_LocalPlayer->f30;
            sent = 0;
            unsigned char kind = cWeapon_GetWeaponSlot(wid);
            if (kind < 6) {
                void* wd = cWeaponDB_GetEntry(g_WeaponDatabase, wid);
                if (wd && wd != cWeapon_GetWeaponEntry(a->f3524)) {
                    sent = 1;
                    cPlayer_SelectWeapon(g_LocalPlayer, wid);
                }
            } else if (kind == 6 && !a->b33E7) {
                sent = 1;
                cHuman_CycleGadgetState(a);
            } else if (kind == 7 && a->b33E7) {
                sent = 1;
                cHuman_CycleGadgetState(a);
            }
            if (sent) GuiWidget_SendMessage(o->f48, Gui_Canvas(), 0x10, 1, 0);
        }
    }
    if (Plain_454B10(ev, 1) || Plain2_454B10(ev, 2)) {
        GuiEquipmentPane_SelectNext(o, Btn2_454B10(ev, 2));
        return 1;
    }
    if (Plain2_454B10(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_454B10(ev, 0x800)) {
        Gui_Canvas()->v24(o);
        cHud_DeactivateObjectiveMenu(g_Hud);
        cGameSystem_PauseGame(g_Game, 0);
        return 1;
    }
    return 0;
}
#undef g_Game /* merge_units */
static inline void merge_flush_func_00454B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454B10 */
