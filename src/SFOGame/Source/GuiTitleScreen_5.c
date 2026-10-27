/*
 * SFOGame/Source/GuiTitleScreen: 1 file, 00288310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiTitleScreen_288310 */
#pragma push /* merge_units */
#include "types.h"

typedef struct {
    char pad[0x59D];
    unsigned char x59D;
    unsigned char x59E;
    char pad59F[5];
    int x5A4;
    int x5A8;
} Cfg288310;

typedef struct {
    Cfg288310* cfg;
} Mgr288310;

typedef struct {
    char pad[0x50];
    int x50;
} Self288310;

extern unsigned char D_00506330;
extern Mgr288310 g_MemCard;
extern void* D_004FFC04;
extern int g_CardSlotId;
extern char g_Game[];
extern char D_004A95F0[];
extern char D_004A9600[];
extern char D_004A9610[];
extern char D_004A9618[];
extern char D_004A9628[];

extern void cMemCard_FullCheck(Mgr288310* m);
extern int GuiTitleScreen_SavedAgentExists(void);
extern char* nGlobalization_GetString_charP(const char* key);
extern int cGameFrontEnd_PushMessageBox(void* ui, int kind, const char* a, const char* b, Self288310* owner, int flag);
extern int cGameSystem_GetAgentData(void* list, int idx);
extern int cAgentData_GetNumSavedBytes(int agent);
extern int cMemCard_GetClustersNeeded(Mgr288310* m, int v);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* strstr(const char* s, const char* sub);
extern char* strncpy(char* d, const char* s, int n);
extern void Libc_Strcat(char* d, const char* s);
extern void Libc_Strcpy(char* d, const char* s);

void GuiTitleScreen_VerifyMemCard(Self288310* self, int force)
{
    char buf[0x108];
    char num[8];
    Mgr288310* m;

    if (D_00506330 && !force)
        return;
    D_00506330 = 1;
    m = &g_MemCard;
    cMemCard_FullCheck(m);
    if (!GuiTitleScreen_SavedAgentExists()) {
        if (!m->cfg->x59D) {
            void* ui = D_004FFC04;
            char* a = nGlobalization_GetString_charP(D_004A95F0);
            self->x50 = cGameFrontEnd_PushMessageBox(ui, 4, a, nGlobalization_GetString_charP(D_004A9600), self, 1);
        } else if (m->cfg->x59E) {
            int have = m->cfg->x5A4;
            int need = cMemCard_GetClustersNeeded(m, cAgentData_GetNumSavedBytes(cGameSystem_GetAgentData(g_Game, -1)));
            if (have < need) {
                char* text;
                char* p;
                void* ui;
                sprintf(num, D_004A9610, need);
                text = nGlobalization_GetString_charP(D_004A9618);
                p = strstr(text, D_004A9628);
                if (p) {
                    int n = p - text;
                    strncpy(buf, text, n);
                    buf[n] = 0;
                    Libc_Strcat(buf, num);
                    Libc_Strcat(buf, p + 4);
                } else {
                    Libc_Strcpy(buf, text);
                }
                ui = D_004FFC04;
                self->x50 = cGameFrontEnd_PushMessageBox(ui, 4, nGlobalization_GetString_charP(D_004A95F0), buf, self, 1);
            } else {
                g_CardSlotId = m->cfg->x5A8;
            }
        }
    }
    g_CardSlotId = m->cfg->x5A8;
}
static inline void merge_flush_GuiTitleScreen_288310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiTitleScreen_288310 */
