#pragma cplusplus on
#include "types.h"
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
void*Gui_GetScreenStack();void GuiScreen_SetFocus(void*,void*);void func_0041E0F0(void*,void*,int,int,int);void func_0041BEB0(void*,const char*,int);
int Agent_GetSelected(void*,int);int AgentData_IsObjectiveComplete(int,const char*);int func_003329B0(int,int,int,int);int func_00336060(int,const char*);
int String_CompareNoCase(const char*,const char*);void String_Copy(char*,const char*);int atoi(const char*);char*Loc_LookupText(const char*);int sprintf(char*,const char*,...);
extern char D_004AA200[],D_004AA210[],D_004AA228[],D_004AA238[],D_004AA248[],D_004AA250[],D_004AA260[],D_004AA268[],D_004AA270[],D_004AA280[],D_004FFB50[],D_004FFC90[];
}
extern "C" void func_00294300(CcBindings*self,unsigned char requested){
 char label[32],text[32];int objective;
 unsigned prev=self->mode;if(prev){if(self->groups[prev]){self->groups[prev]->flags&=0xfffd;self->groups[self->mode]->flags&=0xfffb;}}
 int mode=requested;
 if(self->mode!=mode)func_0041E0F0(self,Gui_GetScreenStack(),16,7,0);
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
    if(func_003329B0(agent,18,5,i)){sprintf(label,D_004AA210,i);char*s=Loc_LookupText(label);if(s){self->tail[i]->flags|=4;self->tail[i]->unk10=i+10000;func_0041BEB0(self->tail[i],s,0);missing=0;}}
    if(missing)func_0041BEB0(self->tail[i],locked,0);
   }
  }else{
   char*name=D_004FFC90;int i=0;
   if(!String_CompareNoCase(name,D_004AA228)){self->tail[0]->flags|=2;self->tail[0]->flags|=4;self->tail[0]->unk10=0;func_0041BEB0(self->tail[i++],Loc_LookupText(D_004AA238),0);}
   self->tail[i]->flags|=2;
   if(func_003329B0(agent,self->selection+1,5,0)){self->tail[i]->flags|=4;self->tail[i]->unk10=2;sprintf(text,D_004AA248,name);func_0041BEB0(self->tail[i++],Loc_LookupText(text),0);}
   else{func_0041BEB0(self->tail[i++],locked,0);}
   sprintf(text,D_004AA250,D_004FFC90);char*title=Loc_LookupText(text);
   sprintf(text,D_004AA260,D_004FFC90);char*requirement=Loc_LookupText(text);
   if(title&&*title&&requirement&&*requirement){
    self->tail[i]->flags|=2;bool missing=1;
    if(requirement[1]==':'&&requirement[2]){text[0]=requirement[0];text[1]=0;objective=atoi(text);String_Copy(text,requirement+2);if(AgentData_IsObjectiveComplete(Agent_GetSelected(D_004FFB50,-1),text)){missing=0;self->objective=objective;self->tail[i]->unk10=3;}}
    if(missing)func_0041BEB0(self->tail[i],locked,0);else{func_0041BEB0(self->tail[i],title,0);self->tail[i]->flags|=4;}i++;
   }
   self->tail[i]->flags|=2;bool enabled=0;
   sprintf(text,D_004AA268,name);char*title2=Loc_LookupText(text);
   int record=func_00336060(Agent_GetSelected(D_004FFB50,-1),name);
   if(title2&&record){sprintf(text,D_004AA270,record);if(AgentData_IsObjectiveComplete(Agent_GetSelected(D_004FFB50,-1),text)){enabled=1;if(!String_CompareNoCase(name,D_004AA280))self->tail[i]->unk10=1;else self->tail[i]->unk10=4;}}
   if(enabled){func_0041BEB0(self->tail[i],title2,0);self->tail[i]->flags|=4;}else func_0041BEB0(self->tail[i],Loc_LookupText(D_004AA200),0);
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





