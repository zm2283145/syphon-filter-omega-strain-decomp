/* GuiDossiers_PopulateList: fill list widget (f48) with the selected agent's entry + D_00532B70 entries; enum-typed 4th param + ternary gives the movz. */
enum OnOff { ON0, ON1 };
#pragma opt_strength_reduction off
typedef struct { int a; int pad[8]; } Ent;
typedef struct { int unk00; int count; Ent* data; } EntVec;
typedef struct { char pad[0x48]; void* f48; } Self;
extern char g_Game[];
extern EntVec D_00532B70;
void* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_GetUserName(void* ag);
void GuiTextListWidget_AddItem(void* w, int text, int i, enum OnOff dis);
int nGlobalization_GetString_charP(int id);
int cAgentData_IsDossierUnlocked(void* self, int i);
void GuiDossiers_PopulateList(Self* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    EntVec* v = &D_00532B70;
    int i;
    GuiTextListWidget_AddItem(self->f48, cAgentData_GetUserName(ag), 0, 0);
    for (i = 1; i < v->count; i++) {
        int text = nGlobalization_GetString_charP(v->data[i].a);
        GuiTextListWidget_AddItem(self->f48, text, i, cAgentData_IsDossierUnlocked(ag, i) ? ON0 : ON1);
    }
}






