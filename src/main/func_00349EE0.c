/* func_00349EE0: fill list widget (f48) with the selected agent's entry + D_00532B70 entries; enum-typed 4th param + ternary gives the movz. */
enum OnOff { ON0, ON1 };
#pragma opt_strength_reduction off
typedef struct { int a; int pad[8]; } Ent;
typedef struct { int unk00; int count; Ent* data; } EntVec;
typedef struct { char pad[0x48]; void* f48; } Self;
extern char D_004FFB50[];
extern EntVec D_00532B70;
void* Agent_GetSelected(void* list, int idx);
int AgentData_GetName(void* ag);
void GuiTextListWidget_AddItem(void* w, int text, int i, enum OnOff dis);
int Loc_LookupText(int id);
int func_00332BB0(void* self, int i);
void func_00349EE0(Self* self)
{
    void* ag = Agent_GetSelected(D_004FFB50, -1);
    EntVec* v = &D_00532B70;
    int i;
    GuiTextListWidget_AddItem(self->f48, AgentData_GetName(ag), 0, 0);
    for (i = 1; i < v->count; i++) {
        int text = Loc_LookupText(v->data[i].a);
        GuiTextListWidget_AddItem(self->f48, text, i, func_00332BB0(ag, i) ? ON0 : ON1);
    }
}






