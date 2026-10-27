/*
 * main/game: range (2 files, 0012EE30-0012EEE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0012EE30 */
#pragma push /* merge_units */
char* cGameSystem_GetAgentData(int, int);
int NetGetMyClientIndex(int*, int);
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;

void Game_ClearOtherAgentsB70(int arg0)
{
    int i;
    i = 0;
    do {
        int v;
        int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            v = D_00494178;
        } else v = 0;
        if (i != v) {
            char* p = cGameSystem_GetAgentData(arg0, i);
            if (p) p[0xB70] = 0;
        }
        i++;
    } while (i < 4);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012EE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012EE30 */

/* merge_units: begin func_0012EEE0 */
#pragma push /* merge_units */
typedef struct {
    void* vt;
    char pad04[0x18];
    int f1C;
    signed char kind;
    char pad21[3];
    signed char id;
    char pad25[3];
    char* agent;
    unsigned char flag;
    unsigned char b2D;
} Msg_12EEE0;
extern char D_004EA098[];
extern char D_004D91A0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Msg_12EEE0* m, void* type);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_12EEE0* m, int b, int c);
extern void cMessage_dtor(Msg_12EEE0* m, int f);

void cGameSystem_SendAgentData(int arg0, unsigned char arg1, unsigned char arg2)
{
    Msg_12EEE0 m;
    Msg_12EEE0* p;
    if (g_IsMultiplayer) {
        int id;
        int a = D_005721A8;
        if (g_IsMultiplayer) {
            if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
        {
            char* agent = cGameSystem_GetAgentData(arg0, -1);
            p = &m;
            cMessage_ctor_cMessageNameR(p, D_004EA098);
            m.agent = agent;
            m.vt = D_004D91A0;
            m.id = id;
            m.kind = 4;
            {
                unsigned char* f = &m.flag;
                *f = arg1;
                if (!*f) p->f1C = 0x40;
            }
            p->b2D = arg2;
            cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012EEE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012EEE0 */
