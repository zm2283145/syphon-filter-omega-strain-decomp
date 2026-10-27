/*
 * main/GuiGameOptions: 6 files, 00297020-00297C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00297020 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int pad0; int name; char pad8[0xC]; } Item_7020;
typedef struct { int a; int count; Item_7020* items; char flag; } List_7020;
extern char g_Game;
extern unsigned char D_0048B868;
extern char* D_0048C160[];
extern unsigned char D_004ACD30[];
extern int D_005063D0[];
extern unsigned char D_004ACC70[];
extern unsigned char D_004FFBB5;
extern unsigned char* D_004FFC04;
int cGameSystem_GetAgentData(void*, int);
void func_00296FA0(List_7020*);
void cAgentData_GetAchievements(int, int, List_7020*);
int HasBonusLevel__10cAgentDataF1(int, __int128);
__int128 nGlobalization_MakeTag(char*);
char* nGlobalization_GetStringTag(int);
int String_CompareNoCase(char*, char*);
void func_00299360(List_7020*, int);

#pragma opt_strength_reduction off
void GuiCommandCenter_ValidateMissions(char* self) {
    int k;
    int i;
    unsigned char ok;
    char* name;
    int j;
    int sel;
    List_7020 list;
    char** pn;
    unsigned char* pe;
    int* pi;
    unsigned char* pc;
    for (k = 0; k < 0x11; k++) self[0x178 + k] = 0;
    self[0x18F] = 0;
    sel = cGameSystem_GetAgentData(&g_Game, -1);
    func_00296FA0(&list);
    list.flag = 1;
    if (D_0048B868) cAgentData_GetAchievements(sel, 3, &list);
    for (i = 0, pn = D_0048C160, pe = D_004ACD30, pi = D_005063D0, pc = D_004ACC70; i <= 0x11; i++, pi++, pc++, pn++, pe++) {
        name = *pn;
        ok = 0;
        if (*pe) {
            if (D_004FFBB5) {
                if (name) {
                    if (i != 0x11) {
                        int s = cGameSystem_GetAgentData(&g_Game, -1);
                        if (HasBonusLevel__10cAgentDataF1(s, nGlobalization_MakeTag(name))) ok = 1;
                    } else {
                        ok = 1;
                    }
                }
            } else {
                ok = 1;
            }
        }
        if (D_0048B868) {
            *pi = -1;
            for (j = 0; j < list.count; j++) {
                nGlobalization_GetStringTag(list.items[j].name);
                if (String_CompareNoCase(nGlobalization_GetStringTag(list.items[j].name), name) == 0) {
                    *pi = j;
                    break;
                }
            }
        }
        if (i == 0x11) {
            self[0x18F] = ok && !D_004FFC04[0x30];
        } else {
            if (ok && D_004FFC04[0x30]) ok = *pc;
            self[0x178 + i] = ok;
        }
    }
    D_0048B868 = 0;
    func_00299360(&list, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00297020 */

/* merge_units: begin func_002972E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int cGameSystem_GetAgentData();                      
signed char cAgentData_HasUnseenZeusItems();

void GuiCommandCenter_RefreshSeenLevelZeus(int arg0) {
    int temp_s1;
    int var_s0;
    signed char temp_v0;
    char * temp_v1;

    temp_s1 = cGameSystem_GetAgentData(&g_Game, -1);
    var_s0 = 0;
    do {
        temp_v0 = cAgentData_HasUnseenZeusItems(temp_s1, var_s0 + 1, -1);
        temp_v1 = (char *)(arg0 + var_s0);
        var_s0 += 1;
        F_(temp_v1, 0xF8, signed char) = temp_v0;
    } while (var_s0 <= 0x11);
}
#pragma pop /* merge_units */
/* merge_units: end func_002972E0 */

/* merge_units: begin func_00297350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern void GuiCommandCenter_StoreStaticGuiState(GuiCommandCenter* self);
extern GuiManager* Gui_Canvas(void);

/* Deactivates the screen: clears manager flags 0x0C and resets the selection. */
void GuiCommandCenter_Deactivate(GuiCommandCenter* self) {
    GuiManager* mgr;

    if (self->active != 0) {
        mgr = Gui_Canvas();
        mgr->flags &= ~0xC;
        GuiCommandCenter_StoreStaticGuiState(self);
        self->selection = -1;
        self->unk1D0 = 0;
        self->active = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00297350 */

/* merge_units: begin func_002973B0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#if 0 /* merge_units */
GuiManager*Gui_Canvas();
#endif /* merge_units */
#define Gui_Canvas() (Gui_Canvas()) /* merge_units */
CcNetwork*cDME_GetLobby();int func_00442750(void*,void(*)());void cGameFrontEnd_LobbyCallback();
void GuiTextWidget_SetText(void*,const char*,int);void GuiWidget_SendMessage(void*,void*,int,int,int);char*nGlobalization_GetString_charP(const char*);int sprintf(char*,const char*,...);const char*cAgentData_GetUserName(int);const char*AgentData_GetRankText(int);int cAgentData_GetClearancePoints(int);int cAgentData_GetLevelPrefix(int,const char*);int cAgentData_IsObjectiveComplete(int,const char*);
#if 0 /* merge_units */
void GuiCommandCenter_ValidateMissions(void*);
#endif /* merge_units */
#define GuiCommandCenter_ValidateMissions(a0) (GuiCommandCenter_ValidateMissions((char *)(a0))) /* merge_units */
#if 0 /* merge_units */
void GuiCommandCenter_RefreshSeenLevelZeus(void*);
#endif /* merge_units */
#define GuiCommandCenter_RefreshSeenLevelZeus(a0) (GuiCommandCenter_RefreshSeenLevelZeus((int)(a0))) /* merge_units */
void cGameFrontEnd_PlayMusic(void*,int);void GuiCommandCenter_RestoreGuiState(void*);const char*GuiLobbyScreen_GetLobbyString(void*,int,int,int,int,int);int cGameFrontEnd_PushMessageBox(void*,int,const char*,const char*,void*,int);
#if 0 /* merge_units */
extern CcGameState*D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(CcGameState **)&D_004FFC04) /* merge_units */
#if 0 /* merge_units */
extern char g_Game[];
#endif /* merge_units */
#define g_Game ((char*)&g_Game) /* merge_units */
extern char*D_0048C1A0;
extern char*D_0048B658;extern char*D_0048B660;extern char*D_0048B680;extern char*D_0048B688;extern char*D_0048B690;extern char*D_0048B698;extern char*D_0048B6A0;extern char*D_0048B6F8;extern char*D_0048B708;
extern char D_004A7520[],D_004A9870[],D_004AA270[],D_004AA288[],D_004AA2C8[],D_004AA2E8[],D_004AA308[],D_004AA4A8[],D_004AA4B8[],D_004AA4C8[];
}
extern "C" void GuiCommandCenter_Activate(CcBindings*self){
 SsoString title,message;char score[32],key[16];
 if(!self->screen.active){
  GuiManager*stack=Gui_Canvas();stack->flags|=12;
  unsigned char popup=0;
  int online=D_004FFC04->online,mode=D_004FFC04->mode;
  CcNetwork*net=cDME_GetLobby();
  if(net){if(net->state!=4&&!func_00442750(net,cGameFrontEnd_LobbyCallback))popup=1;self->screen.unk78=1;}else self->screen.unk78=0;
  GuiWidget*w=(GuiWidget*)GuiFindAs(self,D_0048B6F8,D_004A9870);
  if(w){char*s=nGlobalization_GetString_charP(online?D_004AA4A8:D_004AA4B8);GuiTextWidget_SetText(w,s?s:D_004AA288,0);}
  GuiWidget*w2=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B708);if(w2){if(online)w2->flags|=2;else w2->flags&=0xfffd;}
  if(self->childa8){bool enabled=online&&!mode;if(enabled)self->childa8->flags|=4;else self->childa8->flags&=0xfffb;if(!online||mode)GuiWidget_SendMessage(self,self->childa8,6,(int)D_004AA308,0);}
  GuiWidget*w3=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B658);if(w3){bool enabled=online&&!mode;if(enabled)w3->flags|=2;else w3->flags&=0xfffd;}
  GuiWidget*w4=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B660);if(w4){bool enabled=!online||mode;if(enabled)w4->flags|=2;else w4->flags&=0xfffd;}
  GuiWidget*name=(GuiWidget*)GuiFindAs(self,D_0048B680,D_004A7520);if(name)GuiTextWidget_SetText(name,cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game,-1)),0);
  GuiWidget*rank=(GuiWidget*)GuiFindAs(self,D_0048B688,D_004A7520);if(rank)GuiTextWidget_SetText(rank,AgentData_GetRankText(cGameSystem_GetAgentData(g_Game,-1)),0);
  GuiWidget*points=(GuiWidget*)GuiFindAs(self,D_0048B690,D_004A7520);if(points){sprintf(score,D_004AA4C8,cAgentData_GetClearancePoints(cGameSystem_GetAgentData(g_Game,-1)));GuiTextWidget_SetText(points,score,0);}
  if(D_004FFC04->mode||!D_004FFC04->online){GuiWidget*a=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6A0);if(a)a->flags&=0xfffd;GuiWidget*b=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B698);if(b)b->flags&=0xfffd;}
  else{GuiWidget*a=(GuiWidget*)GuiFindAs(self,D_0048B698,D_004A7520);if(a){GuiTextWidget_SetText(a,(char*)(cGameSystem_GetAgentData(g_Game,-1)+0x95c),0);a->flags|=2;}GuiWidget*b=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6A0);if(b)b->flags|=2;}
  GuiCommandCenter_ValidateMissions(self);self->unlocked[17]=0;self->unlocked[18]=0;self->unlocked[19]=0;self->unlocked[21]=D_004FFC04->online;self->unlocked[20]=0;
  const char*current=D_0048C1A0;
  if(current){int record=cAgentData_GetLevelPrefix(cGameSystem_GetAgentData(g_Game,-1),current);if(record){sprintf(key,D_004AA270,record);if(cAgentData_IsObjectiveComplete(cGameSystem_GetAgentData(g_Game,-1),key))self->unlocked[20]=1;}}
  GuiCommandCenter_RefreshSeenLevelZeus(self);
  {int i;CcBindings*walk;i=0;walk=self;for(;i<24;i++,walk=(CcBindings*)((char*)walk+4)){if(walk->buttons[0]){if(!self->unlocked[i])GuiWidget_SendMessage(self,walk->buttons[0],6,(int)D_004AA2E8,0);else if((i<17&&self->states[i])||(i==20&&self->states[17]))GuiWidget_SendMessage(self,walk->buttons[0],6,(int)D_004AA2C8,0);}}
  }cGameFrontEnd_PlayMusic(D_004FFC04,0);GuiCommandCenter_RestoreGuiState(self);
  if(popup){std_basic_string_char_char_traits_char_ctor_charP(&title,GuiLobbyScreen_GetLobbyString(self,20,0,0,0,0));std_basic_string_char_char_traits_char_ctor_charP(&message,GuiLobbyScreen_GetLobbyString(self,134,0,0,0,0));char*msg=std_basic_string_char_char_traits_char_c_str(&message);self->popupId=cGameFrontEnd_PushMessageBox(D_004FFC04,2,std_basic_string_char_char_traits_char_c_str(&title),msg,self,25);String_Dtor(&message,0);String_Dtor(&title,0);}
  self->screen.active=1;
 }
}
#undef Gui_Canvas /* merge_units */
#undef GuiCommandCenter_ValidateMissions /* merge_units */
#undef GuiCommandCenter_RefreshSeenLevelZeus /* merge_units */
#undef D_004FFC04 /* merge_units */
#undef g_Game /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002973B0 */

/* merge_units: begin func_00297B10 */
#pragma push /* merge_units */
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Panel { char pad[0xB0]; V4 c0; V4 c1; V4 c2; } Panel;
typedef struct Self { char pad[0x10]; int state; char pad2[0x194 - 0x14]; Panel* panel; } Self;
extern V4 D_00587BA0, D_00587BB0, D_00587BC0;
extern void GuiCommandCenter_ResetGuiState(Self*);
extern void GuiScreen_Wake(Self*);
static inline void SetV4(V4* d, V4 s) { d->x = s.x; d->y = s.y; d->z = s.z; d->w = s.w; }
void GuiCommandCenter_Wake(Self* self)
{
    if (self->state == 1) {
        GuiCommandCenter_ResetGuiState(self);
        self->state = -1;
    }
    if (self->panel) {
        SetV4(&self->panel->c0, D_00587BA0);
        SetV4(&self->panel->c1, D_00587BB0);
        SetV4(&self->panel->c2, D_00587BC0);
    }
    GuiScreen_Wake(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00297B10 */

/* merge_units: begin func_00297C10 */
#pragma push /* merge_units */
#pragma cplusplus on
/* The shared command-center view omits child bindings; this view supplies those fields. */
struct CcBindings_00297C10 {
 char pad0[0x88];GuiWidget* root;GuiWidget* child8c;GuiWidget* child90;GuiWidget* child94;
 GuiWidget* child98;GuiWidget* child9c;GuiWidget* childa0;GuiWidget* childa4;GuiWidget* childa8;GuiWidget* childac;GuiWidget* childb0;
 GuiWidget* main[17];unsigned char states[18];char pad10a[2];GuiWidget* extra[3];GuiWidget* buttons[24];char pad178[0x18];
 GuiWidget* child190;GuiWidget* child194;GuiWidget* labels[6];char pad1b0[4];signed char actions[24];int selection;int x1d0;signed char mode;char pad1d5[3];GuiWidget* groups[6];char pad1f0[0xfc];GuiWidget* child2ec;GuiWidget* child2f0;char pad2f4[8];GuiWidget* tail[10];
};
extern "C" {
extern char* D_0048B650;extern char* D_0048B668;extern char* D_0048B670;extern char* D_0048B678;extern char* D_0048B6A8;extern char* D_0048B6B0;extern char* D_0048B6B8;extern char* D_0048B6C0;extern char* D_0048B6C8;extern char* D_0048B6D0;extern char* D_0048B6D8;extern char* D_0048B6E0[];extern char* D_0048B700;extern char* D_0048B728;extern char* D_0048B770[];extern char* D_0048B788;extern char* D_0048B790;
extern char D_004A7520[],D_004A9870[],D_004AA4D0[],D_004AA4D8[],D_004AA4E0[],D_004AA4E8[],D_004AA4F8[],D_004AA640[];void GuiLobbyScreen_onAdd(void*);void GuiTextListWidget_SetTextFormat(void*,int);void GuiTextListWidget_SetFont(void*,const char*);
}
extern "C" void GuiCommandCenter_onAdd(CcBindings_00297C10*self){
 char a[32],b[32],c[32];int i;CcBindings_00297C10*walk;
 self->root=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B650);
 self->child8c=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6C8);
 self->child90=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6D0);
 self->child94=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6D8);
 i=0;walk=self;for(;i<17;i++,walk=(CcBindings_00297C10*)((char*)walk+4)){self->states[i]=0;sprintf(a,D_004AA4D0,i);walk->main[0]=(GuiWidget*)GuiWidget_FindChild_charP(self,a);if(walk->main[0]){walk->main[0]->unk10=i;walk->buttons[0]=walk->main[0];}}
 self->states[17]=0;
 {int j;CcBindings_00297C10*w1;CcBindings_00297C10*w2;j=0;w1=self;w2=self;for(;j<3;j++,w1=(CcBindings_00297C10*)((char*)w1+4),w2=(CcBindings_00297C10*)((char*)w2+4)){sprintf(b,D_004AA4D8,j+1);w1->extra[0]=(GuiWidget*)GuiWidget_FindChild_charP(self,b);if(w1->extra[0]){w1->extra[0]->unk10=j+17;w2->buttons[17]=w1->extra[0];}}}
 self->childac=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6B8);if(self->childac){self->childac->unk10=20;self->buttons[20]=self->childac;}
 self->childa8=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6B0);if(self->childa8){self->childa8->unk10=21;self->buttons[21]=self->childa8;}
 self->childa4=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6A8);if(self->childa4){self->childa4->unk10=22;self->buttons[22]=self->childa4;}
 self->childb0=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6C0);if(self->childb0){self->childb0->unk10=23;self->buttons[23]=self->childb0;}
 for(int i=0;i<6;i++){self->labels[i]=(GuiWidget*)GuiFindAs(self,D_0048B770[i],D_004A9870);if(self->labels[i])self->labels[i]->unk10=i;}
 for(int i=0;i<24;i++){if(i==21)self->actions[i]=2;else if(i==22)self->actions[i]=3;else if(i==20)self->actions[i]=4;else self->actions[i]=1;}
 for(int i=0;i<6;i++)self->groups[i]=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B6E0[i]);
 for(int i=0;i<24;i++)if(self->buttons[i])self->buttons[i]->flags&=0xff7f;
 self->child98=(GuiWidget*)GuiFindAs(self,D_0048B668,D_004A7520);
 self->child9c=(GuiWidget*)GuiFindAs(self,D_0048B670,D_004A7520);
 self->childa0=(GuiWidget*)GuiFindAs(self,D_0048B678,D_004A7520);
 for(int i=0;i<3;i++)if(self->extra[i])self->extra[i]->flags&=0xfffd;
 self->child2ec=(GuiWidget*)GuiFindAs(self,D_0048B700,D_004A9870);
 self->child2f0=(GuiWidget*)GuiFindAs(self,D_0048B728,D_004A9870);
 for(int i=0;i<10;i++){sprintf(c,D_004AA4E0,i+1);self->tail[i]=(GuiWidget*)GuiFindAs(self,c,D_004A9870);}
 GuiWidget*w=(GuiWidget*)GuiWidget_FindChild_charP(self,D_004AA4E8);if(w)w->flags&=0xfffd;
 GuiLobbyScreen_onAdd(self);
 self->child190=(GuiWidget*)GuiWidget_FindChild_charP(self,D_0048B788);if(self->child190)self->child190->flags&=0xfffd;
 self->child194=(GuiWidget*)GuiFindAs(self,D_0048B790,D_004AA640);if(self->child194){GuiTextListWidget_SetTextFormat(self->child194,2);GuiTextListWidget_SetFont(self->child194,D_004AA4F8);self->child194->flags&=0xff7f;}
}
#pragma pop /* merge_units */
/* merge_units: end func_00297C10 */
