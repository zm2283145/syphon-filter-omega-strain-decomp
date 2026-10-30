/*
 * SFOGame/Source/GuiMissionList: 1 file, 002AAD40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AAD40 */
#pragma push /* merge_units */
/* GuiMissionList::onElementRender, reconstructed from the January 2004
 * AgentElem/AgentStats layouts and checked against the retail executable.
 * Matrix quad copies and identity use the existing R5900/VU0 idioms. */
#pragma cplusplus on
#include "types.h"
struct Rect { float x, y, w, h; };
struct TextArea { int x,y,w,h; char pad10[0x48]; unsigned char wrap; char pad59[2]; unsigned char ellipsis; };
struct AgentElem { int id; char name[32]; int status,ping,lanIpMatch,gameStatus,gameAgents,gameAgentsMax,gameSeconds,gameMissionID,gameFilter,gameID; };
struct SelectElem { int a,b,flags; };
struct SelectArray { SelectElem* data; SelectElem*& Data() { return data; } SelectElem& At(unsigned i) { return Data()[i]; } };
struct GuiMissionList {
    char pad0[0xA8]; TextArea* text; unsigned char displayMode; char padAD[7]; unsigned char displayMissionName; char padB5[0x1B];
    char* statusLabel[4]; char padE0[0x14]; char* filterLabel[6]; int extra10C; unsigned count; SelectArray select; int extra118; void* lobby;
};
struct AgentStats { unsigned char versionID,rank,marksmanship,efficiency; char rest[248]; };
struct RankRow { char pad0[32]; int text; };
struct RankArray { int a,count; RankRow* data; RankRow& At(int i) { return data[i]; } };
struct Mat { __int128 r[4]; };
extern "C" {
void GuiArrayWidget_onElementRender(GuiMissionList*,unsigned,unsigned,const Rect&);
AgentElem* SFOLobbyList_GetSlot(void*,int);
void cTextArea_SetColor(TextArea*,void*);
void cTextArea_SetText(TextArea*,const char*);
void TextObj_Draw(TextArea*);
char* Libc_Strcpy(char*,const char*);
int sprintf(char*,const char*,...);
char* nGlobalization_GetString_int(int);
void* cDME_GetLobby(void);
int func_00450CF0(void*,int,AgentStats*);
extern char g_Video[];
extern int D_00538C64;
extern unsigned char D_00538C68;
extern char D_00587C40[],D_00587C50[],D_00587C70[];
extern char* D_0048BC30;
extern int D_0048BC64[5][4];
extern int g_OnlineMissionTable[];
extern int D_0051EF10[];
extern RankArray g_RankRows;
extern char D_004AB980[];
}
struct Render { char pad[0xA80]; Mat mtx[20]; };
static inline Mat* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void CopyM(void* d,void* s) { __int128 qa,qb; __asm__ volatile("lq %0,0(%3); lq %1,0x10(%3); sq %0,0(%2); lq %0,0x20(%3); sq %1,0x10(%2); lq %1,0x30(%3); sq %0,0x20(%2); sq %1,0x30(%2)" : "=&r"(qa),"=&r"(qb) : "r"(d),"r"(s) : "memory"); }
static inline void Identity(void* p) { int t; __asm__ volatile("sqc2 $vf0,0x30(%1); qmfc2.ni %0,$vf0; pcpyud %0,%0,$zero; sq %0,0x10(%1); pexcw %0,%0; sq %0,0x20(%1); pcpyud %0,%0,$zero; sq %0,0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline int TimeMin(AgentElem* e) { if(e->gameSeconds==-1) return 0; return e->gameSeconds/60; }
static inline int TimeSec(AgentElem* e) { if(e->gameSeconds==-1) return 0; return e->gameSeconds%60; }
static inline int Agents(AgentElem* e) { int a=e->gameAgents; if(a==-1) return 0; return a; }
static inline int AgentsMax(AgentElem* e) { int a=e->gameAgentsMax; if(a==-1) return 0; return a; }
static inline void SetXY(TextArea* t,int x,int y) { t->x=x;t->y=y; }
static inline void SetWH(TextArea* t,int w,int h) { t->w=w;t->h=h; }
extern "C" void GuiMissionList_onElementRender(GuiMissionList* self,unsigned column,unsigned row,const Rect& bounds) {
    GuiArrayWidget_onElementRender(self,column,row,bounds);
    if(!self->text) return;
    if(!self->lobby) return;
    if(row>=self->count) return;
    AgentElem* elem=SFOLobbyList_GetSlot(self->lobby,self->select.At(row).b);
    if(!elem) return;
    int timeMin=TimeMin(elem);
    int timeSec=TimeSec(elem);
    int gameAgents=Agents(elem);
    int gameAgentsMax=AgentsMax(elem);
    unsigned char inGame=(elem->status==0 || elem->status==1);
    { int i=D_00538C64; CopyM(MtxAt(i+1),MtxAt(i)); }
    D_00538C64++;
    Identity(MtxAt(D_00538C64));
    D_00538C68=1;
    SetXY(self->text,(int)bounds.x,(int)bounds.y);
    SetWH(self->text,(int)bounds.w,(int)bounds.h);
    self->text->wrap=1;
    int flags=self->select.At(row).flags;
    if(flags&1) cTextArea_SetColor(self->text,D_00587C40);
    else cTextArea_SetColor(self->text,D_00587C70);
    char text[80];text[0]=0;
    unsigned char ellipsis=0;
    if(self->displayMode<0 || self->displayMode>=5) return;
    if(flags&4) Libc_Strcpy(text,D_0048BC30);
    else {
        int type=D_0048BC64[self->displayMode][column];
        switch(type) {
        case 0:
        case 3:
            ellipsis=1;Libc_Strcpy(text,elem->name);break;
        case 1: {
            unsigned char set=0;
            if(self->displayMissionName && (elem->status==0 || elem->status==1) && elem->gameMissionID>=0 && elem->gameMissionID<9) {
                int missionIdx=g_OnlineMissionTable[elem->gameMissionID];
                char* value=nGlobalization_GetString_int(D_0051EF10[missionIdx]);
                if(value) { Libc_Strcpy(text,value);set=1; }
                if(elem->gameStatus!=1) cTextArea_SetColor(self->text,D_00587C50);
            }
            if(!set) Libc_Strcpy(text,self->statusLabel[elem->status]);
            break;
        }
        case 2: {
            unsigned char set=0;
            void* lobby=cDME_GetLobby();
            if(lobby) {
                AgentStats stats;
                if(func_00450CF0(lobby,elem->id,&stats)) {
                    RankArray& ranks=g_RankRows;
                    int rank=stats.rank;
                    if(rank>=0 && rank<ranks.count) {
                        char* rankText=nGlobalization_GetString_int(ranks.At(rank).text);
                        if(rankText) { Libc_Strcpy(text,rankText);set=1; }
                    }
                }
            }
            if(!set) Libc_Strcpy(text,D_0048BC30);
            break;
        }
        case 4:
            if((unsigned)elem->gameFilter<6) Libc_Strcpy(text,self->filterLabel[elem->gameFilter]);
            else Libc_Strcpy(text,D_0048BC30);
            break;
        case 5: {
            unsigned char offline=elem->status==3;
            if(offline || !inGame) Libc_Strcpy(text,D_0048BC30);
            else sprintf(text,D_004AB980,gameAgents,gameAgentsMax);
            break;
        }
        }
    }
    cTextArea_SetText(self->text,text);
    self->text->ellipsis=ellipsis;
    TextObj_Draw(self->text);
    D_00538C64--;
    D_00538C68=1;
}
static inline void merge_flush_func_002AAD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AAD40 */
