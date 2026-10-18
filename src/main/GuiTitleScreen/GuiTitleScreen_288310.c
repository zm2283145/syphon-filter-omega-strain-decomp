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
extern Mgr288310 D_0055A830;
extern void* D_004FFC04;
extern int D_004FFBBC;
extern char D_004FFB50[];
extern char D_004A95F0[];
extern char D_004A9600[];
extern char D_004A9610[];
extern char D_004A9618[];
extern char D_004A9628[];

extern void MemCard_Refresh(Mgr288310* m);
extern int GuiTitleScreen_SavedAgentExists(void);
extern char* Loc_LookupText(const char* key);
extern int FrontEnd_OpenPopup(void* ui, int kind, const char* a, const char* b, Self288310* owner, int flag);
extern int Agent_GetSelected(void* list, int idx);
extern int AgentData_GetSaveSize(int agent);
extern int MemCard_GetSpaceNeeded(Mgr288310* m, int v);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* strstr(const char* s, const char* sub);
extern char* strncpy(char* d, const char* s, int n);
extern void func_00128F58(char* d, const char* s);
extern void String_Copy(char* d, const char* s);

void GuiTitleScreen_CheckMemCard(Self288310* self, int force)
{
    char buf[0x108];
    char num[8];
    Mgr288310* m;

    if (D_00506330 && !force)
        return;
    D_00506330 = 1;
    m = &D_0055A830;
    MemCard_Refresh(m);
    if (!GuiTitleScreen_SavedAgentExists()) {
        if (!m->cfg->x59D) {
            void* ui = D_004FFC04;
            char* a = Loc_LookupText(D_004A95F0);
            self->x50 = FrontEnd_OpenPopup(ui, 4, a, Loc_LookupText(D_004A9600), self, 1);
        } else if (m->cfg->x59E) {
            int have = m->cfg->x5A4;
            int need = MemCard_GetSpaceNeeded(m, AgentData_GetSaveSize(Agent_GetSelected(D_004FFB50, -1)));
            if (have < need) {
                char* text;
                char* p;
                void* ui;
                sprintf(num, D_004A9610, need);
                text = Loc_LookupText(D_004A9618);
                p = strstr(text, D_004A9628);
                if (p) {
                    int n = p - text;
                    strncpy(buf, text, n);
                    buf[n] = 0;
                    func_00128F58(buf, num);
                    func_00128F58(buf, p + 4);
                } else {
                    String_Copy(buf, text);
                }
                ui = D_004FFC04;
                self->x50 = FrontEnd_OpenPopup(ui, 4, Loc_LookupText(D_004A95F0), buf, self, 1);
            } else {
                D_004FFBBC = m->cfg->x5A8;
            }
        }
    }
    D_004FFBBC = m->cfg->x5A8;
}
