#pragma cplusplus on
#include "types.h"
#include "loose02_types.h"
#include "gui_widget_vslots.h"
/* The shared command-center view omits child bindings; this view supplies those fields. */
struct CcBindings {
 GuiScreen screen;GuiWidget* root;GuiWidget* child8c;GuiWidget* child90;GuiWidget* child94;
 GuiWidget* child98;GuiWidget* child9c;GuiWidget* childa0;GuiWidget* childa4;GuiWidget* childa8;GuiWidget* childac;GuiWidget* childb0;
 GuiWidget* main[17];unsigned char states[18];char pad10a[2];GuiWidget* extra[3];GuiWidget* buttons[24];unsigned char unlocked[24];
 GuiWidget* child190;GuiWidget* child194;GuiWidget* labels[6];char pad1b0[4];signed char actions[24];int selection;int x1d0;unsigned char mode;char pad1d5[3];GuiWidget* groups[6];char pad1f0[0xe0];GuiWidget* focus[6];char pad2e8[4];GuiWidget* child2ec;GuiWidget* child2f0;char pad2f4[4];int popupId;GuiWidget* tail[10];int objective;
};
#include "sso_string.h"
struct CcGameState {char pad[0x30];bool online;char pad31;bool mode;};
struct CcNetwork {char pad[0x255c];int state;};
extern "C" {
GuiManager*Gui_GetScreenStack();CcNetwork*DME_GetLobby();int func_00442750(void*,void(*)());void func_002CC260();
void func_0041BEB0(void*,const char*,int);void func_0041E0F0(void*,void*,int,int,int);char*Loc_LookupText(const char*);int sprintf(char*,const char*,...);
int Agent_GetSelected(void*,int);const char*func_00336170(int);const char*func_00336110(int);int AgentData_TotalPoints(int);int func_00336060(int,const char*);int AgentData_IsObjectiveComplete(int,const char*);
void func_00297020(void*);void func_002972E0(void*);void func_002C9AF0(void*,int);void func_00298250(void*);const char*func_0033CE30(void*,int,int,int,int,int);int FrontEnd_OpenPopup(void*,int,const char*,const char*,void*,int);
extern CcGameState*D_004FFC04;extern char D_004FFB50[];extern char*D_0048C1A0;
extern char*D_0048B658;extern char*D_0048B660;extern char*D_0048B680;extern char*D_0048B688;extern char*D_0048B690;extern char*D_0048B698;extern char*D_0048B6A0;extern char*D_0048B6F8;extern char*D_0048B708;
extern char D_004A7520[],D_004A9870[],D_004AA270[],D_004AA288[],D_004AA2C8[],D_004AA2E8[],D_004AA308[],D_004AA4A8[],D_004AA4B8[],D_004AA4C8[];
}
extern "C" void func_002973B0(CcBindings*self){
 SsoString title,message;char score[32],key[16];
 if(!self->screen.active){
  GuiManager*stack=Gui_GetScreenStack();stack->flags|=12;
  unsigned char popup=0;
  int online=D_004FFC04->online,mode=D_004FFC04->mode;
  CcNetwork*net=DME_GetLobby();
  if(net){if(net->state!=4&&!func_00442750(net,func_002CC260))popup=1;self->screen.unk78=1;}else self->screen.unk78=0;
  GuiWidget*w=(GuiWidget*)GuiFindAs(self,D_0048B6F8,D_004A9870);
  if(w){char*s=Loc_LookupText(online?D_004AA4A8:D_004AA4B8);func_0041BEB0(w,s?s:D_004AA288,0);}
  GuiWidget*w2=(GuiWidget*)func_0041DB80(self,D_0048B708);if(w2){if(online)w2->flags|=2;else w2->flags&=0xfffd;}
  if(self->childa8){bool enabled=online&&!mode;if(enabled)self->childa8->flags|=4;else self->childa8->flags&=0xfffb;if(!online||mode)func_0041E0F0(self,self->childa8,6,(int)D_004AA308,0);}
  GuiWidget*w3=(GuiWidget*)func_0041DB80(self,D_0048B658);if(w3){bool enabled=online&&!mode;if(enabled)w3->flags|=2;else w3->flags&=0xfffd;}
  GuiWidget*w4=(GuiWidget*)func_0041DB80(self,D_0048B660);if(w4){bool enabled=!online||mode;if(enabled)w4->flags|=2;else w4->flags&=0xfffd;}
  GuiWidget*name=(GuiWidget*)GuiFindAs(self,D_0048B680,D_004A7520);if(name)func_0041BEB0(name,func_00336170(Agent_GetSelected(D_004FFB50,-1)),0);
  GuiWidget*rank=(GuiWidget*)GuiFindAs(self,D_0048B688,D_004A7520);if(rank)func_0041BEB0(rank,func_00336110(Agent_GetSelected(D_004FFB50,-1)),0);
  GuiWidget*points=(GuiWidget*)GuiFindAs(self,D_0048B690,D_004A7520);if(points){sprintf(score,D_004AA4C8,AgentData_TotalPoints(Agent_GetSelected(D_004FFB50,-1)));func_0041BEB0(points,score,0);}
  if(D_004FFC04->mode||!D_004FFC04->online){GuiWidget*a=(GuiWidget*)func_0041DB80(self,D_0048B6A0);if(a)a->flags&=0xfffd;GuiWidget*b=(GuiWidget*)func_0041DB80(self,D_0048B698);if(b)b->flags&=0xfffd;}
  else{GuiWidget*a=(GuiWidget*)GuiFindAs(self,D_0048B698,D_004A7520);if(a){func_0041BEB0(a,(char*)(Agent_GetSelected(D_004FFB50,-1)+0x95c),0);a->flags|=2;}GuiWidget*b=(GuiWidget*)func_0041DB80(self,D_0048B6A0);if(b)b->flags|=2;}
  func_00297020(self);self->unlocked[17]=0;self->unlocked[18]=0;self->unlocked[19]=0;self->unlocked[21]=D_004FFC04->online;self->unlocked[20]=0;
  const char*current=D_0048C1A0;
  if(current){int record=func_00336060(Agent_GetSelected(D_004FFB50,-1),current);if(record){sprintf(key,D_004AA270,record);if(AgentData_IsObjectiveComplete(Agent_GetSelected(D_004FFB50,-1),key))self->unlocked[20]=1;}}
  func_002972E0(self);
  {int i;CcBindings*walk;i=0;walk=self;for(;i<24;i++,walk=(CcBindings*)((char*)walk+4)){if(walk->buttons[0]){if(!self->unlocked[i])func_0041E0F0(self,walk->buttons[0],6,(int)D_004AA2E8,0);else if((i<17&&self->states[i])||(i==20&&self->states[17]))func_0041E0F0(self,walk->buttons[0],6,(int)D_004AA2C8,0);}}
  }func_002C9AF0(D_004FFC04,0);func_00298250(self);
  if(popup){String_CtorCStr_13B480(&title,func_0033CE30(self,20,0,0,0,0));String_CtorCStr_13B480(&message,func_0033CE30(self,134,0,0,0,0));char*msg=String_CStr(&message);self->popupId=FrontEnd_OpenPopup(D_004FFC04,2,String_CStr(&title),msg,self,25);func_00138B70(&message,0);func_00138B70(&title,0);}
  self->screen.active=1;
 }
}










