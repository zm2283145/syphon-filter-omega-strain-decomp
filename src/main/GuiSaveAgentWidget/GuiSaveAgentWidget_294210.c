/*
 * main/GuiSaveAgentWidget: 4 files, 00294210-00294300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00294210 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AA600[] = "GuiCommandCenter";   /* "GuiCommandCenter" */

/* Class name getter: "GuiCommandCenter". */
char* GuiCommandCenter_GetClassName(void) {
    return D_004AA600;
}
#pragma pop /* merge_units */
/* merge_units: end func_00294210 */

/* merge_units: begin func_00294220 */
#pragma push /* merge_units */
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string "GuiCommandCenter". */
int func_00294220(void* self, const char* name)
{
    return strcmp("GuiCommandCenter", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00294220 */

/* merge_units: begin func_00294250 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; int id; } T294250;
typedef struct { char pad[0x20]; T294250* t; } G294250;
typedef struct {
    char pad0[0x1D4];
    unsigned char idx;
    char pad1[3];
    int ids[62];
    T294250* objs[6];
    unsigned char flag;
} S294250;
extern G294250* Gui_GetScreenStack(void);
extern T294250* GuiWidget_FocusFirst(S294250* s);
T294250* GuiCommandCenter_First(S294250* s)
{
    int id;
    T294250* o = s->objs[s->idx];
    if (o && o->id == s->ids[s->idx]) {
        if (s->flag || (Gui_GetScreenStack()->t && (id = Gui_GetScreenStack()->t->id, id != s->ids[s->idx]))) {
            s->flag = 0;
            return s->objs[s->idx];
        }
    }
    return GuiWidget_FocusFirst(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_00294250 */

/* merge_units: begin func_00294300 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "loose02_types.h"
#include "gui_widget_vslots.h"
/* The shared command-center view omits child bindings; this view supplies those fields. */
struct CcBindings {
 char pad0[0x88];GuiWidget* root;GuiWidget* child8c;GuiWidget* child90;GuiWidget* child94;
 GuiWidget* child98;GuiWidget* child9c;GuiWidget* childa0;GuiWidget* childa4;GuiWidget* childa8;GuiWidget* childac;GuiWidget* childb0;
 GuiWidget* main[17];unsigned char states[18];char pad10a[2];GuiWidget* extra[3];GuiWidget* buttons[24];char pad178[0x18];
 GuiWidget* child190;GuiWidget* child194;GuiWidget* labels[6];char pad1b0[4];signed char actions[24];int selection;int x1d0;unsigned char mode;char pad1d5[3];GuiWidget* groups[6];char pad1f0[0xe0];GuiWidget* focus[6];char pad2e8[4];GuiWidget* child2ec;GuiWidget* child2f0;char pad2f4[4];int popupId;GuiWidget* tail[10];int objective;
};
#include "vslot_pad.h"
struct CcFocus {VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual GuiWidget*GetFocus();};
extern "C" {
#if 0 /* merge_units */
void*Gui_GetScreenStack();
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */
void GuiScreen_SetFocus(void*,void*);void GuiWidget_SendEvent(void*,void*,int,int,int);void GuiTextWidget_SetText(void*,const char*,int);
int Agent_GetSelected(void*,int);int AgentData_IsObjectiveComplete(int,const char*);int AgentData_HasZeus(int,int,int,int);int AgentData_GetLevelShortName(int,const char*);
int String_CompareNoCase(const char*,const char*);void String_Copy(char*,const char*);int atoi(const char*);char*Loc_LookupText(const char*);int sprintf(char*,const char*,...);
extern char D_004AA200[],D_004AA210[],D_004AA228[],D_004AA238[],D_004AA248[],D_004AA250[],D_004AA260[],D_004AA268[],D_004AA270[],D_004AA280[],D_004FFB50[],D_004FFC90[];
}
extern "C" void GuiCommandCenter_OpenPanel(CcBindings*self,unsigned char requested){
 char label[32],text[32];int objective;
 unsigned prev=self->mode;if(prev){if(self->groups[prev]){self->groups[prev]->flags&=0xfffd;self->groups[self->mode]->flags&=0xfffb;}}
 int mode=requested;
 if(self->mode!=mode)GuiWidget_SendEvent(self,Gui_GetScreenStack(),16,7,0);
 self->mode=requested;
 switch(self->mode){
 case 0:
  self->focus[0]=0;self->focus[1]=0;self->focus[2]=0;self->focus[3]=0;self->focus[4]=0;self->focus[5]=0;((GuiWidget*)self)->unk20=(int)self;break;
 case 5:{
  for(int i=0;i<10;i++){if(self->tail[i]){self->tail[i]->flags&=0xfffd;self->tail[i]->flags&=0xfffb;self->tail[i]->unk10=-1;}else return;}
  char*locked=Loc_LookupText(D_004AA200);int agent=Agent_GetSelected(D_004FFB50,-1);
  if(self->selection==20){
   for(int i=0;i<10;i++){
    self->tail[i]->flags|=2;bool missing=1;
    if(AgentData_HasZeus(agent,18,5,i)){sprintf(label,D_004AA210,i);char*s=Loc_LookupText(label);if(s){self->tail[i]->flags|=4;self->tail[i]->unk10=i+10000;GuiTextWidget_SetText(self->tail[i],s,0);missing=0;}}
    if(missing)GuiTextWidget_SetText(self->tail[i],locked,0);
   }
  }else{
   char*name=D_004FFC90;int i=0;
   if(!String_CompareNoCase(name,D_004AA228)){self->tail[0]->flags|=2;self->tail[0]->flags|=4;self->tail[0]->unk10=0;GuiTextWidget_SetText(self->tail[i++],Loc_LookupText(D_004AA238),0);}
   self->tail[i]->flags|=2;
   if(AgentData_HasZeus(agent,self->selection+1,5,0)){self->tail[i]->flags|=4;self->tail[i]->unk10=2;sprintf(text,D_004AA248,name);GuiTextWidget_SetText(self->tail[i++],Loc_LookupText(text),0);}
   else{GuiTextWidget_SetText(self->tail[i++],locked,0);}
   sprintf(text,D_004AA250,D_004FFC90);char*title=Loc_LookupText(text);
   sprintf(text,D_004AA260,D_004FFC90);char*requirement=Loc_LookupText(text);
   if(title&&*title&&requirement&&*requirement){
    self->tail[i]->flags|=2;bool missing=1;
    if(requirement[1]==':'&&requirement[2]){text[0]=requirement[0];text[1]=0;objective=atoi(text);String_Copy(text,requirement+2);if(AgentData_IsObjectiveComplete(Agent_GetSelected(D_004FFB50,-1),text)){missing=0;self->objective=objective;self->tail[i]->unk10=3;}}
    if(missing)GuiTextWidget_SetText(self->tail[i],locked,0);else{GuiTextWidget_SetText(self->tail[i],title,0);self->tail[i]->flags|=4;}i++;
   }
   self->tail[i]->flags|=2;bool enabled=0;
   sprintf(text,D_004AA268,name);char*title2=Loc_LookupText(text);
   int record=AgentData_GetLevelShortName(Agent_GetSelected(D_004FFB50,-1),name);
   if(title2&&record){sprintf(text,D_004AA270,record);if(AgentData_IsObjectiveComplete(Agent_GetSelected(D_004FFB50,-1),text)){enabled=1;if(!String_CompareNoCase(name,D_004AA280))self->tail[i]->unk10=1;else self->tail[i]->unk10=4;}}
   if(enabled){GuiTextWidget_SetText(self->tail[i],title2,0);self->tail[i]->flags|=4;}else GuiTextWidget_SetText(self->tail[i],Loc_LookupText(D_004AA200),0);
  }
  break;
 }
 }
 if(self->child8c){if(self->mode==0)self->child8c->flags|=2;else self->child8c->flags&=0xfffd;}
 if(self->child90){if(self->mode!=0)self->child90->flags|=2;else self->child90->flags&=0xfffd;}
 if(self->child94){if(self->mode!=0)self->child94->flags|=2;else self->child94->flags&=0xfffd;}
 if(self->groups[requested]){
  self->groups[requested]->flags|=2;self->groups[requested]->flags|=4;
  if(self->child2ec){bool show=mode!=1||(GuiWidget*)self->x1d0!=self->childb0;if(show)self->child2ec->flags|=2;else self->child2ec->flags&=0xfffd;}
  GuiWidget*w=self->focus[requested];if(w&&w->unk1C==(int)self->groups[requested]){GuiScreen_SetFocus(Gui_GetScreenStack(),w);return;}
  void*stack=Gui_GetScreenStack();GuiScreen_SetFocus(stack,((CcFocus*)self)->GetFocus());
 }
}
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00294300 */
