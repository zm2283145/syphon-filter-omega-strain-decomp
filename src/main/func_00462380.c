#pragma cplusplus on
#include "types.h"
struct Ev_462380 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Stack_462380 {
    virtual void _v00(); virtual void _v01(); virtual void _v02(); virtual void _v03(); virtual void _v04();
    virtual void _v05(); virtual void _v06(); virtual void _v07(); virtual void _v08(); virtual void _v09();
    virtual void _v0A(); virtual void _v0B(); virtual void _v0C(); virtual void _v0D(); virtual void _v0E();
    virtual void _v0F(); virtual void _v10(); virtual void _v11(); virtual void _v12(); virtual void _v13();
    virtual void _v14(); virtual void _v15(); virtual void _v16();
    virtual void Push(void* screen, int flag);
    virtual void Pop(void* screen);
};
extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_004C2660[];
extern char D_004C2668[];
extern char D_004C2680[];
Stack_462380* Gui_Canvas(void);
void* Gui_Manager(void);
void* GuiManager_OpenGui(void* a, char* b, char* c);
int GuiObjectives_onInput(void* self, Ev_462380* ev);
}
static inline unsigned char Down_462380(Ev_462380* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline bool Btn_462380(Ev_462380* e, unsigned int b)
{
    bool r = 0;
    if (Down_462380(e) && e->btn == b)
        r = 1;
    return r;
}
static inline bool Press_462380(Ev_462380* e, unsigned int b)
{
    bool r = 0;
    if (Btn_462380(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int GuiEndGameObjectives_HandleInput(void* self, Ev_462380* ev)
{
    if (Press_462380(ev, 0x40)) {
        char* name;
        void* pg;
        Gui_Canvas()->Pop(self);
        name = g_IsMultiplayer ? D_004C2660 : D_004C2668;
        pg = GuiManager_OpenGui(Gui_Manager(), D_004C2680, name);
        Gui_Canvas()->Push(pg, 1);
        return 1;
    }
    {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x10 && ev->f6 == 0;
        if (b)
            return 1;
    }
    return GuiObjectives_onInput(self, ev);
}
