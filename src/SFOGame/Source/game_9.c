/*
 * SFOGame/Source/game: 2 files, 0012FA00-0012FA60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0012FA00 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Color4 {
    float r, g, b, a;
} Color4;

extern char* g_Hud;
extern void cInfoBar_SetScrollDelay(void*);
extern void cInfoBar_AddMessage(void*, void*, Color4*, int, int);

/* Global: SetScrollDelay - resets the HUD scroller and starts it with a white color. */
void Global_SetScrollDelay(void) {
    char* hud = g_Hud;
    Color4 white;
    cInfoBar_SetScrollDelay(hud + 0x100);
    white.r = 1.0f;
    white.g = 1.0f;
    white.b = 1.0f;
    white.a = 1.0f;
    cInfoBar_AddMessage(hud + 0x100, ((int*)"this is a test..only a test"), &white, 1, 0);
}
static inline void merge_flush_func_0012FA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012FA00 */

/* merge_units: begin func_0012FA60 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct {
    void* vt;
    char pad04[0x1C];
    signed char kind;
    char pad21[3];
    signed char id;
    char pad25[3];
    int f28;
} Msg_12FA60;
extern "C" char D_004F5398[];
extern "C" char D_004DADB0[];
extern "C" char g_Game[];
extern "C" unsigned char g_IsMultiplayer;
extern "C" unsigned char D_005721C0;
extern "C" void cMessage_ctor_cMessageNameR(Msg_12FA60* m, void* type);
extern "C" void QueueMessage_cMessageR_cSystemP_int(Msg_12FA60* m, void* target, int c);
extern "C" void cMessage_dtor(Msg_12FA60* m, int f);
extern "C" char* cGameSystem_GetAgentData(void*, int);
extern "C" void cAgentData_EndLevel(char*, bool);

#pragma opt_propagation off
extern "C" void cGameSystem_Restart(char* self, signed char arg1)
{
    bool end = false;
    unsigned char mode = arg1;
    Msg_12FA60 m;
    Msg_12FA60* p;
    if (mode == 2 || mode == 3) {
        self[0x1C4] = 1;
        self[0x1C5] = mode == 3;
        self[0x1C6] = 1;
        self[0x1C7] = 0;
    } else if (mode == 0) {
        self[0x1C4] = 0;
        self[0x1C5] = 0;
        if (g_IsMultiplayer) self[0x1C6] = 1;
        else self[0x1C6] = 0;
        self[0x1C7] = 0;
        end = true;
    } else if (mode == 1) {
        self[0x1C4] = 0;
        self[0x1C5] = 1;
        self[0x1C6] = 1;
        self[0x1C7] = 1;
    }
    cAgentData_EndLevel(cGameSystem_GetAgentData(self, -1), end);
    p = &m;
    cMessage_ctor_cMessageNameR(p, D_004F5398);
    m.vt = D_004DADB0;
    m.id = arg1;
    p->f28 = mode == 2;
    if (!(g_IsMultiplayer ? D_005721C0 : 1)) m.kind = 1;
    QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
    m.vt = D_004DADB0;
    cMessage_dtor(&m, 0);
}
static inline void merge_flush_func_0012FA60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0012FA60 */
