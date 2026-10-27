/*
 * SFOGame/Source/GuiEndGameObjectives: 3 files, 00462350-004624E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiEndGameObjectives_462350 */
#pragma push /* merge_units */
#include "types.h"

char D_004C2760[] = "GuiEndGameObjectives"; /* "GuiEndGameObjectives" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiEndGameObjectives::IsA: returns 1 if the given class name is "GuiEndGameObjectives". */
int GuiEndGameObjectives_IsClass(void* self, const char* name)
{
    return strcmp(D_004C2760, name) == 0;
}
static inline void merge_flush_GuiEndGameObjectives_462350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiEndGameObjectives_462350 */

/* merge_units: begin func_00462380 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_00462380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462380 */

/* merge_units: begin GuiGameScreen_4624E0 */
#pragma push /* merge_units */
typedef struct {
    char voice[8];
    int duration;
} Line_4624E0;

typedef struct {
    char pad0[0x14];
    unsigned short flags;
} W_4624E0;

typedef struct {
    char pad0[0xD4];
    float fD4;
    char padD8[0xB71 - 0xD8];
    unsigned char bB71;
} Agent_4624E0;

typedef struct {
    char pad0[0x90];
    char lines[0xC];        /* 0x90 */
} Self_4624E0;

extern char g_Game[];
extern char g_LevelDirName[];
extern int D_004FFD28;
extern char D_004C2698[];
extern char D_004C26B0[];
extern char D_004C26C8[];
void GuiObjectives_onWake(Self_4624E0* self);
Agent_4624E0* cGameSystem_GetAgentData(void* mgr, int idx);
int cAgentData_GetStat(Agent_4624E0* agent, int stat);
int sprintf(char* buf, const char* fmt, ...);
Line_4624E0* cQuipList_tQuip_ctor(Line_4624E0* line, char* voice, int duration);
void cArray_tQuip_PushBackActual(void* vec, Line_4624E0* line);
W_4624E0* GuiWidget_FindChild_charP(void* self, char* name);
int cAgentData_GetParTime(void* p, unsigned char f);
void GuiEndGameObjectives_onWake(Self_4624E0* self);

void GuiEndGameObjectives_onWake(Self_4624E0* self)
{
    Agent_4624E0* agent;
    int n;
    char buf[32];
    W_4624E0* w;
    GuiObjectives_onWake(self);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    n = D_004FFD28;
    if (cAgentData_GetStat(agent, 0x19) > 0)
        sprintf(buf, D_004C2698, n + 1);
    {
        Line_4624E0 line;
        cQuipList_tQuip_ctor(&line, buf, 0x1E);
        cArray_tQuip_PushBackActual(self->lines, &line);
    }
    w = GuiWidget_FindChild_charP(self, D_004C26B0);
    if (agent->bB71) {
        int r;
        if (w) w->flags &= ~2;
        r = cAgentData_GetParTime(g_LevelDirName, g_IsMultiplayer);
        if ((int)agent->fD4 <= r) {
            Line_4624E0 line;
            cQuipList_tQuip_ctor(&line, D_004C26C8, 0x1E);
            cArray_tQuip_PushBackActual(self->lines, &line);
        }
    } else {
        if (w) w->flags |= 2;
    }
}
static inline void merge_flush_GuiGameScreen_4624E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_4624E0 */
