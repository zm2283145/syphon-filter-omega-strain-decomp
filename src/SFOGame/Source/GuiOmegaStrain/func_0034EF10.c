#pragma cplusplus on
#include "types.h"
struct GuiWidget {
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
    virtual int IsA(void* t);
};
typedef struct { char id[8]; unsigned char state; char pad9[0x1C - 9]; } tRequirementInfo;
struct cAgentData;
struct cArray;
extern "C" {
void GuiPersonnelScreen_onWake(GuiWidget* o);
GuiWidget* GuiWidget_FindChild_charP(GuiWidget* o, const char* name);
cAgentData* cGameSystem_GetAgentData(char* g, int idx);
void func_00296F20(cArray* l);
void std_vector_deleter_tRequirementInfo_dtor(cArray* l, int flags);
void cAgentData_GetRequirements(cAgentData* ag, int a, int b, cArray* l);
int sprintf(char* b, const char* f, ...);
unsigned long SoftFloat_FloatToDouble(float);
void GuiTextWidget_SetText(GuiWidget* w, const char* s, int f);
extern char* D_00492BC0;
extern char D_004A7520[];
extern char g_Game[];
extern char D_004BA9F8[];
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
/* TU context: a preceding function in the original file used soft-double arithmetic */
__declspec(weak) __declspec(DROPDTOR) int k7_ctx(double a, double b) { return a >= b; }
struct cArray {
    int x0; int count; tRequirementInfo* data; unsigned char mCanExpand;
    cArray() { func_00296F20(this); mCanExpand = 1; }
    const tRequirementInfo& operator[](unsigned int k) const { return data[k]; }
    int size() const { return count; }
    __declspec(weak) __declspec(DROPDTOR) ~cArray() { std_vector_deleter_tRequirementInfo_dtor(this, 0); }
};

extern "C" void GuiOmegaStrain_onWake(GuiWidget* self)
{
    GuiWidget* text;
    GuiPersonnelScreen_onWake(self);
    text = GuiWidget_FindChild_charP(self, D_00492BC0);
    text = (text && text->IsA(D_004A7520)) ? text : 0;
    if (text) {
        cAgentData* data = cGameSystem_GetAgentData(g_Game, -1);
        cArray info;
        int numComplete;
        int i;
        char buf[32];
        cAgentData_GetRequirements(data, 4, 0, &info);
        numComplete = 0;
        for (i = 0; i < info.size(); i++) {
            if (info[i].state == 2) numComplete++;
        }
        sprintf(buf, D_004BA9F8, 100.0f * ((float)numComplete / (float)info.size()));
        GuiTextWidget_SetText(text, buf, 0);
    }
}


