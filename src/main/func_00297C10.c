#pragma cplusplus on
#include "types.h"
#include "loose02_types.h"
#include "gui_widget_vslots.h"
/* The shared command-center view omits child bindings; this view supplies those fields. */
struct CcBindings {
 char pad0[0x88];GuiWidget* root;GuiWidget* child8c;GuiWidget* child90;GuiWidget* child94;
 GuiWidget* child98;GuiWidget* child9c;GuiWidget* childa0;GuiWidget* childa4;GuiWidget* childa8;GuiWidget* childac;GuiWidget* childb0;
 GuiWidget* main[17];unsigned char states[18];char pad10a[2];GuiWidget* extra[3];GuiWidget* buttons[24];char pad178[0x18];
 GuiWidget* child190;GuiWidget* child194;GuiWidget* labels[6];char pad1b0[4];signed char actions[24];int selection;int x1d0;signed char mode;char pad1d5[3];GuiWidget* groups[6];char pad1f0[0xfc];GuiWidget* child2ec;GuiWidget* child2f0;char pad2f4[8];GuiWidget* tail[10];
};
extern "C" {
extern char* D_0048B650;extern char* D_0048B668;extern char* D_0048B670;extern char* D_0048B678;extern char* D_0048B6A8;extern char* D_0048B6B0;extern char* D_0048B6B8;extern char* D_0048B6C0;extern char* D_0048B6C8;extern char* D_0048B6D0;extern char* D_0048B6D8;extern char* D_0048B6E0[];extern char* D_0048B700;extern char* D_0048B728;extern char* D_0048B770[];extern char* D_0048B788;extern char* D_0048B790;
extern char D_004A7520[],D_004A9870[],D_004AA4D0[],D_004AA4D8[],D_004AA4E0[],D_004AA4E8[],D_004AA4F8[],D_004AA640[];
int sprintf(char*,const char*,...);void func_0033D3F0(void*);void func_00421670(void*,int);void func_00421690(void*,const char*);
}
extern "C" void func_00297C10(CcBindings*self){
 char a[32],b[32],c[32];int i;CcBindings*walk;
 self->root=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B650);
 self->child8c=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6C8);
 self->child90=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6D0);
 self->child94=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6D8);
 i=0;walk=self;for(;i<17;i++,walk=(CcBindings*)((char*)walk+4)){self->states[i]=0;sprintf(a,D_004AA4D0,i);walk->main[0]=(GuiWidget*)GuiWidget_FindChildByName(self,a);if(walk->main[0]){walk->main[0]->unk10=i;walk->buttons[0]=walk->main[0];}}
 self->states[17]=0;
 {int j;CcBindings*w1;CcBindings*w2;j=0;w1=self;w2=self;for(;j<3;j++,w1=(CcBindings*)((char*)w1+4),w2=(CcBindings*)((char*)w2+4)){sprintf(b,D_004AA4D8,j+1);w1->extra[0]=(GuiWidget*)GuiWidget_FindChildByName(self,b);if(w1->extra[0]){w1->extra[0]->unk10=j+17;w2->buttons[17]=w1->extra[0];}}}
 self->childac=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6B8);if(self->childac){self->childac->unk10=20;self->buttons[20]=self->childac;}
 self->childa8=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6B0);if(self->childa8){self->childa8->unk10=21;self->buttons[21]=self->childa8;}
 self->childa4=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6A8);if(self->childa4){self->childa4->unk10=22;self->buttons[22]=self->childa4;}
 self->childb0=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6C0);if(self->childb0){self->childb0->unk10=23;self->buttons[23]=self->childb0;}
 for(int i=0;i<6;i++){self->labels[i]=(GuiWidget*)GuiFindAs(self,D_0048B770[i],D_004A9870);if(self->labels[i])self->labels[i]->unk10=i;}
 for(int i=0;i<24;i++){if(i==21)self->actions[i]=2;else if(i==22)self->actions[i]=3;else if(i==20)self->actions[i]=4;else self->actions[i]=1;}
 for(int i=0;i<6;i++)self->groups[i]=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B6E0[i]);
 for(int i=0;i<24;i++)if(self->buttons[i])self->buttons[i]->flags&=0xff7f;
 self->child98=(GuiWidget*)GuiFindAs(self,D_0048B668,D_004A7520);
 self->child9c=(GuiWidget*)GuiFindAs(self,D_0048B670,D_004A7520);
 self->childa0=(GuiWidget*)GuiFindAs(self,D_0048B678,D_004A7520);
 for(int i=0;i<3;i++)if(self->extra[i])self->extra[i]->flags&=0xfffd;
 self->child2ec=(GuiWidget*)GuiFindAs(self,D_0048B700,D_004A9870);
 self->child2f0=(GuiWidget*)GuiFindAs(self,D_0048B728,D_004A9870);
 for(int i=0;i<10;i++){sprintf(c,D_004AA4E0,i+1);self->tail[i]=(GuiWidget*)GuiFindAs(self,c,D_004A9870);}
 GuiWidget*w=(GuiWidget*)GuiWidget_FindChildByName(self,D_004AA4E8);if(w)w->flags&=0xfffd;
 func_0033D3F0(self);
 self->child190=(GuiWidget*)GuiWidget_FindChildByName(self,D_0048B788);if(self->child190)self->child190->flags&=0xfffd;
 self->child194=(GuiWidget*)GuiFindAs(self,D_0048B790,D_004AA640);if(self->child194){func_00421670(self->child194,2);func_00421690(self->child194,D_004AA4F8);self->child194->flags&=0xff7f;}
}



