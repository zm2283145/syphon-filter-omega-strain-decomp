/*
 * SFOGame/Source/GuiSlideShow: 4 files, 00326DA0-00327020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326DA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004B8910[] = "GuiSlideShow";   /* "GuiSlideShow" */

/* Class name getter: "GuiSlideShow". */
char* GuiSlideShow_GetClassName(void) {
    return D_004B8910;
}
static inline void merge_flush_func_00326DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326DA0 */

/* merge_units: begin func_00326DB0 */
#pragma push /* merge_units */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiSlideShow". */
int GuiSlideShow_IsClass(void* self, const char* name)
{
    return strcmp("GuiSlideShow", name) == 0;
}
static inline void merge_flush_func_00326DB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326DB0 */

/* merge_units: begin func_00326DE0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x1C]; unsigned char used; char pad1D[3]; int cat; int idx; int sub; } Item6DE0;
typedef struct { char pad[0x14]; Item6DE0* items; char pad18[4]; int sel; char pad20[0]; } Grp6DE0;
typedef struct { char pad[0x48]; char list[8]; Grp6DE0* groups; char pad54[4]; int sel; } Menu6DE0;
typedef struct { char pad[0x25C]; int db; } G6DE0;
extern G6DE0* D_004FFC04;
extern char g_Game[];
extern char D_004B8748[];
extern char D_004B8758[];
extern char D_004B8768[];
extern char D_004B8778[];
int cGameSystem_GetAgentData(void*, int);
int nGlobalization_GetString_charP(char*);
void Libc_Strcpy(char*, char*);
int GuiSlideShow_AddSlide(Menu6DE0*, int, char*, int, char*);
void GuiSlideShow_AddSection(Menu6DE0*, int);
void std_vector_deleter_Section_clear(void*);
int cAgentData_HasZeusItem(int, int, int, int);
int cHogFile_GetBlockIndex(int, char*, int);
int sprintf(char*, const char*, ...);
static inline Grp6DE0* G(Menu6DE0* m, int i) { return &m->groups[i]; }
void GuiSlideShow_BuildZeusSlideShow(Menu6DE0* self, int cat, int selIdx, int selVal, int flag)
{
    int i;
    int j;
    unsigned char ok;
    int agent;
    int db;
    int r;
    char buf[32];
    char buf2[16];
    std_vector_deleter_Section_clear(self->list);
    self->sel = -1;
    if (cat <= 0 || cat > 18) return;
    db = D_004FFC04->db;
    if (db == 0) return;
    agent = cGameSystem_GetAgentData(g_Game, -1);
    for (i = 0; i < 5; i++) {
        sprintf(buf, D_004B8748, i);
        GuiSlideShow_AddSection(self, nGlobalization_GetString_charP(buf));
        for (j = 1; ; j++) {
            sprintf(buf, D_004B8758, cat, i + 1, j);
            if (cHogFile_GetBlockIndex(db, buf, 1) == -1) break;
            ok = 1;
            if (!cAgentData_HasZeusItem(agent, cat, i, j - 1)) {
                if (flag) continue;
                Libc_Strcpy(buf, D_004B8768);
                ok = 0;
            }
            if (ok) {
                sprintf(buf2, D_004B8778, cat, i + 1, j);
                r = GuiSlideShow_AddSlide(self, i, buf, db, buf2);
                if (r != -1) {
                    Item6DE0* it = &G(self, i)->items[r];
                    it->used = 1;
                    it->cat = cat;
                    it->idx = i;
                    it->sub = j - 1;
                }
            } else {
                GuiSlideShow_AddSlide(self, i, buf, db, 0);
            }
        }
    }
    self->sel = selIdx;
    G(self, selIdx)->sel = selVal;
}
static inline void merge_flush_func_00326DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326DE0 */

/* merge_units: begin func_00327020 */
#pragma push /* merge_units */
/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

typedef struct ObjF4 {
    char pad[0x90];
    char target[0x44];
    unsigned char pending;      /* 0xD4 */
} ObjF4;

#if 0 /* merge_units */
extern int g_Game;
#endif /* merge_units */
#define g_Game (*(int*)&g_Game) /* merge_units */

extern int D_004DADF0;
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
extern void cFileMan_dtor(void*, int);
extern void cMessage_dtor(EventMsg*, int);

/* Clears the pending flag and sends an immediate event message for the target. */
void GuiSlideShow_StopPlayback(ObjF4* o) {
    EventMsg msg;
    o->pending = 0;
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, o->target, 0);
    msg.immediate = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 1);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
#undef g_Game /* merge_units */
static inline void merge_flush_func_00327020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327020 */
