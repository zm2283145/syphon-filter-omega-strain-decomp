/*
 * SFOGame/Source/hudTargets: 11 files, 00274C20-00275030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin game_274C20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetRemoveHudObjectiveMsg_dtor, D_004DE650, cMessage_dtor)
static inline void merge_flush_game_274C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_274C20 */

/* merge_units: begin func_00274C80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct HudObjMsg_e1 {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int id;
    char pad2[8];
} HudObjMsg_e1;
typedef struct { char pad[0xC]; int id; } GObjId_e1;
extern unsigned char g_IsMultiplayer;
extern char D_0052ACF8[];
extern char D_004DE650[];
extern char* g_Hud;
#if 0 /* merge_units */
extern GObjId_e1* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
void* cGOBJ_SOBJ_convert(int); /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((GObjId_e1 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_e1* msg, void* name);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(char**, char*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, HudObjMsg_e1* msg, int a, int b);
#endif /* merge_units */
int cNetObj_SendMessage_int_cMessageR_int_int(int, char**, int, int); /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) ((void)cNetObj_SendMessage_int_cMessageR_int_int((a0), (char * *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_e1* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cHudTargetManager_Remove(void*, int*, int);
#endif /* merge_units */
int cHudTargetManager_Remove(int, char*, int); /* merge_units */
#define cHudTargetManager_Remove(a0, a1, a2) ((void)cHudTargetManager_Remove((int)(a0), (char *)(a1), (a2))) /* merge_units */

int Game_RemoveHudObjective(int* args)
{
    HudObjMsg_e1 msg;
    GObjId_e1* obj = cGOBJ_SOBJ_convert(args[0]);
    if (g_IsMultiplayer) {
        int id = obj->id;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACF8);
        msg.vtable = D_004DE650;
        msg.kind = 4;
        msg.id = id;
        cNetObj_SendMessage_int_cMessageR_int_int(0, &msg, -1, -1);
        msg.vtable = D_004DE650;
        cMessage_dtor(&msg, 0);
    }
    cHudTargetManager_Remove(g_Hud + 0x90, &obj->id, 1);
    return 0;
}
#undef cGOBJ_SOBJ_convert /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cHudTargetManager_Remove /* merge_units */
static inline void merge_flush_func_00274C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274C80 */

/* merge_units: begin func_00274D40 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_274D40;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_274D40;
union HudObjArg_274D40 { int i; char* p; };
extern "C" {
extern char D_0051F098[];
extern char D_004DE280[];
extern char D_004A8F80[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_274D40* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274D40* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, HudObjMsg_274D40*, int, int);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) ((void)cNetObj_SendMessage_int_cMessageR_int_int((a0), (char * *)(a1), (a2), (a3))) /* merge_units */


extern char* nGlobalization_GetString_charP(char*);
extern int nGlobalization_GetStringIndex(char*);
extern void printf(char*);
#if 0 /* merge_units */
extern HudObjGObj_274D40* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((HudObjGObj_274D40 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */


extern void cHudTargetManager_AddObjective_cObjectIdR_charP_charP(void*, int*, char*, char*);
}
/* the script args are read through unions; with propagation off they stay in stack slots and are reloaded once into saved registers */
extern "C" int Game_AddHudObjective3(int* args)
{
    HudObjArg_274D40 ub; ub.i = args[2];
    HudObjArg_274D40 ua; ua.i = args[1];
    int marker;
    HudObjGObj_274D40* obj;
    char* text;
    HudObjMsg_274D40* p;
    char* b;
    char* a;
    a = ua.p;
    b = ub.p;
    obj = cGOBJ_SOBJ_convert(args[0]);
    text = nGlobalization_GetString_charP(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (g_IsMultiplayer) {
            HudObjMsg_274D40 m;
            marker = obj->marker;
            p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? nGlobalization_GetStringIndex(a) : -1;
            p->key1 = b ? nGlobalization_GetStringIndex(b) : -1;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        cHudTargetManager_AddObjective_cObjectIdR_charP_charP(g_Hud + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
static inline void merge_flush_func_00274D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274D40 */

/* merge_units: begin func_00274EC0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_274EC0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_274EC0;
union HudObjArg_274EC0 { int i; char* p; };
extern "C" {
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_274EC0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_274EC0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, HudObjMsg_274EC0*, int, int);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) ((void)cNetObj_SendMessage_int_cMessageR_int_int((a0), (char * *)(a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern HudObjGObj_274EC0* cGOBJ_SOBJ_convert(int);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((HudObjGObj_274EC0 *)cGOBJ_SOBJ_convert((a0))) /* merge_units */


}
/* the script args are read through unions; with propagation off they stay in stack slots and are reloaded once into saved registers */
extern "C" int Game_AddHudObjective2(int* args)
{
    HudObjArg_274EC0 ua; ua.i = args[1];
    HudObjGObj_274EC0* obj;
    char* text;
    HudObjMsg_274EC0* p;
    int marker;
    char* const b = 0;
    char* a;
    a = ua.p;
    obj = cGOBJ_SOBJ_convert(args[0]);
    text = nGlobalization_GetString_charP(a);
    if (!text || !*text) {
        printf(D_004A8F80);
    } else {
        if (g_IsMultiplayer) {
            HudObjMsg_274EC0 m;
            marker = obj->marker;
            p = &m;
            cMessage_ctor_cMessageNameR(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? nGlobalization_GetStringIndex(a) : -1;
            p->key1 = b ? nGlobalization_GetStringIndex(b) : -1;
            m.kind = 4;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        cHudTargetManager_AddObjective_cObjectIdR_charP_charP(g_Hud + 0x90, &obj->marker, text, b);
    }
    return 0;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cGOBJ_SOBJ_convert /* merge_units */
static inline void merge_flush_func_00274EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274EC0 */

/* merge_units: begin func_00275030 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int cHudTargetManager_Remove(int, char * , int);              
int cNetObj_SendMessage_int_cMessageR_int_int(int, char **, int, int);                    
#if 0 /* merge_units */
int cMessage_dtor(char **, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */
                           
#if 0 /* merge_units */
extern char D_004DE650;
#endif /* merge_units */
#define D_004DE650 (*(char*)&D_004DE650) /* merge_units */

#if 0 /* merge_units */
extern int g_Hud;
#endif /* merge_units */
#define g_Hud (*(int*)&g_Hud) /* merge_units */

#if 0 /* merge_units */
extern char D_0052ACF8;
#endif /* merge_units */
#define D_0052ACF8 (*(char*)&D_0052ACF8) /* merge_units */


void nHudTargets_RemoveHudObjective(char * arg0, int arg1) {
    struct { char * f30[8]; signed char f50[4]; int f54[3]; } sl;
    int temp_s0;

    if ((arg1 == 0) && (g_IsMultiplayer != 0)) {
        temp_s0 = F_(arg0, 0xC, int);
        cMessage_ctor_cMessageNameR(sl.f30, &D_0052ACF8);
        sl.f30[0] = &D_004DE650;
        sl.f50[0] = 4;
        sl.f54[0] = temp_s0;
        cNetObj_SendMessage_int_cMessageR_int_int(0, sl.f30, -1, -1);
        sl.f30[0] = &D_004DE650;
        cMessage_dtor(sl.f30, 0);
    }
    cHudTargetManager_Remove(g_Hud + 0x90, arg0 + 0xC, 1);
}
#undef cMessage_dtor /* merge_units */
#undef D_004DE650 /* merge_units */
#undef g_Hud /* merge_units */
#undef D_0052ACF8 /* merge_units */
static inline void merge_flush_func_00275030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00275030 */

/* merge_units: begin func_002750E0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_2750E0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_2750E0;
extern "C" {

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(HudObjMsg_2750E0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(HudObjMsg_2750E0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


#if 0 /* merge_units */
extern void cNetObj_SendMessage_int_cMessageR_int_int(int, HudObjMsg_2750E0*, int, int);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) ((void)cNetObj_SendMessage_int_cMessageR_int_int((a0), (char * *)(a1), (a2), (a3))) /* merge_units */

}

extern "C" void nHudTargets_AddHudObjective(HudObjGObj_2750E0* obj, char* a, char* b, int quiet)
{
    char* text = nGlobalization_GetString_charP(a);
    if (!text || !*text) {
        printf(D_004A8F80);
        return;
    }
    if (!quiet && g_IsMultiplayer) {
        int marker = obj->marker;
        HudObjMsg_2750E0 m;
        HudObjMsg_2750E0* p = &m;
        cMessage_ctor_cMessageNameR(p, D_0051F098);
        p->vt = D_004DE280;
        p->w24 = marker;
        p->b28 = 1;
        p->key0 = a ? nGlobalization_GetStringIndex(a) : -1;
        p->key1 = b ? nGlobalization_GetStringIndex(b) : -1;
        m.kind = 4;
        cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
        m.vt = D_004DE280;
        cMessage_dtor(&m, 0);
    }
    cHudTargetManager_AddObjective_cObjectIdR_charP_charP(g_Hud + 0x90, &obj->marker, text, b);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
static inline void merge_flush_func_002750E0(void) {} /* merge_units */
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
static inline void merge_flush_func_00275250(void) {} /* merge_units */
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
static inline void merge_flush_func_002752D0(void) {} /* merge_units */
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
static inline void merge_flush_func_00275350(void) {} /* merge_units */
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
static inline void merge_flush_func_002753D0(void) {} /* merge_units */
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
static inline void merge_flush_func_00275450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00275450 */
