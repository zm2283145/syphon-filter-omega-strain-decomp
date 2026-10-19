/*
 * main/game: 7 files, 00275030-00275450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00275030 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int ObjMarkerMgr_Remove(int, char * , int);              
int Transport_Send(int, char **, int, int);                    
int cMessage_dtor(char **, int);                           
extern char D_004DE650;
extern int g_Hud;
extern char D_0052ACF8;
extern unsigned char g_IsMultiplayer;

void cNetRemoveHudObjectiveMsg_Send(char * arg0, int arg1) {
    struct { char * f30[8]; signed char f50[4]; int f54[3]; } sl;
    int temp_s0;

    if ((arg1 == 0) && (g_IsMultiplayer != 0)) {
        temp_s0 = F_(arg0, 0xC, int);
        Event_Construct(sl.f30, &D_0052ACF8);
        sl.f30[0] = &D_004DE650;
        sl.f50[0] = 4;
        sl.f54[0] = temp_s0;
        Transport_Send(0, sl.f30, -1, -1);
        sl.f30[0] = &D_004DE650;
        cMessage_dtor(sl.f30, 0);
    }
    ObjMarkerMgr_Remove(g_Hud + 0x90, arg0 + 0xC, 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00275030 */

/* merge_units: begin func_002750E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_2750E0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_2750E0;
extern "C" {
extern char D_0051F098[];
extern char D_004DE280[];
extern char D_004A8F80[];
#if 0 /* merge_units */
extern char* g_Hud;
#endif /* merge_units */
#define g_Hud (*(char **)&g_Hud) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(HudObjMsg_2750E0* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) ((void)Event_Construct((char * *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_2750E0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((char * *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Transport_Send(int, HudObjMsg_2750E0*, int, int);
#endif /* merge_units */
#define Transport_Send(a0, a1, a2, a3) ((void)Transport_Send((a0), (char * *)(a1), (a2), (a3))) /* merge_units */

extern char* Loc_LookupText(char*);
extern int Loc_FindKeyThunk(char*);
extern void printf(char*);
extern void ObjMarkerMgr_Insert(void*, int*, char*, char*);
}

extern "C" void Hud_AddObjective(HudObjGObj_2750E0* obj, char* a, char* b, int quiet)
{
    char* text = Loc_LookupText(a);
    if (!text || !*text) {
        printf(D_004A8F80);
        return;
    }
    if (!quiet && g_IsMultiplayer) {
        int marker = obj->marker;
        HudObjMsg_2750E0 m;
        HudObjMsg_2750E0* p = &m;
        Event_Construct(p, D_0051F098);
        p->vt = D_004DE280;
        p->w24 = marker;
        p->b28 = 1;
        p->key0 = a ? Loc_FindKeyThunk(a) : -1;
        p->key1 = b ? Loc_FindKeyThunk(b) : -1;
        m.kind = 4;
        Transport_Send(0, &m, -1, -1);
        m.vt = D_004DE280;
        cMessage_dtor(&m, 0);
    }
    ObjMarkerMgr_Insert(g_Hud + 0x90, &obj->marker, text, b);
}
#undef g_Hud /* merge_units */
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef Transport_Send /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002750E0 */

/* merge_units: begin func_00275250 */
#pragma push /* merge_units */
#pragma global_optimizer off

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern float D_004FFDF0, D_004FFDF4, D_004FFDF8, D_004FFDFC;

static inline void Global_SetRadarThreatCol(int r, int g, int b, float a)
{
    D_004FFDF0 = r / 255.0f;
    D_004FFDF4 = g / 255.0f;
    D_004FFDF8 = b / 255.0f;
    D_004FFDFC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarThreatCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarThreatCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00275250 */

/* merge_units: begin func_002752D0 */
#pragma push /* merge_units */
#pragma global_optimizer off

extern float D_004FFDE0, D_004FFDE4, D_004FFDE8, D_004FFDEC;

static inline void Global_SetRadarNoLosEnemyCol(int r, int g, int b, float a)
{
    D_004FFDE0 = r / 255.0f;
    D_004FFDE4 = g / 255.0f;
    D_004FFDE8 = b / 255.0f;
    D_004FFDEC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarNoLosEnemyCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarNoLosEnemyCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002752D0 */

/* merge_units: begin func_00275350 */
#pragma push /* merge_units */
#pragma global_optimizer off

extern float D_004FFDD0, D_004FFDD4, D_004FFDD8, D_004FFDDC;

static inline void Global_SetRadarEnemyCol(int r, int g, int b, float a)
{
    D_004FFDD0 = r / 255.0f;
    D_004FFDD4 = g / 255.0f;
    D_004FFDD8 = b / 255.0f;
    D_004FFDDC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarEnemyCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarEnemyCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00275350 */

/* merge_units: begin func_002753D0 */
#pragma push /* merge_units */
#pragma global_optimizer off

extern float D_004FFDB0, D_004FFDB4, D_004FFDB8, D_004FFDBC;

static inline void Global_SetRadarFriendCol(int r, int g, int b, float a)
{
    D_004FFDB0 = r / 255.0f;
    D_004FFDB4 = g / 255.0f;
    D_004FFDB8 = b / 255.0f;
    D_004FFDBC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarFriendCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarFriendCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002753D0 */

/* merge_units: begin func_00275450 */
#pragma push /* merge_units */
#pragma global_optimizer off

extern float g_HudPlayerMarkerColour, D_004FFDC4, D_004FFDC8, D_004FFDCC;

static inline void Global_SetRadarTeamCol(int r, int g, int b, float a)
{
    g_HudPlayerMarkerColour = r / 255.0f;
    D_004FFDC4 = g / 255.0f;
    D_004FFDC8 = b / 255.0f;
    D_004FFDCC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarTeamCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarTeamCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00275450 */
