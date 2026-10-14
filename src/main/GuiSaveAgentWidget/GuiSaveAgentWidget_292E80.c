/*
 * main/GuiSaveAgentWidget: 6 files, 00292E80-00293660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00292E80 */
#pragma push /* merge_units */
/* Build the memory-card slot list, migrate legacy names, and refresh labels.
 * Count references preserve the original loop-address setup. The byte-buffer
 * wrapper prevents folding its address into separate byte-store relocations.
 * The volatile flags read keeps the widget update in its original order.
 */
#pragma opt_strength_reduction off
#pragma cplusplus on
#include "types.h"
#include "loose02_types.h"
#include "gui_widget_vslots.h"
#include "vslot_pad.h"
typedef OwnedRel AoVec;
struct AoStack {
    char pad[0x20];
    GuiWidget*focus;
};
struct AoFocus {
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual GuiWidget*GetFocus();
};
extern "C" {
    AoStack*Gui_GetScreenStack();
    void GuiScreen_SetFocus(void*,void*);
    void func_002888C0(AoVec*);
    void func_002887C0(AoVec*,int);
    char**func_002888B0(AoVec*,int);
    void PtrVector_Resize(AoVec*,int,int*);
    void MemCardWrap_Enumerate(void*,AoVec*);
    void MemCardWrap_Rename(void*,const char*,const char*);
    char*strchr(const char*,int);
    int strncasecmp(const char*,const char*,int);
    char*strncpy(char*,const char*,int);
    int AgentFile_DecodeName(const char*,char*,int*,int);
    int AgentFile_EncodeName(const char*,char*,int,int);
    int FrontEnd_OpenPopup(void*,int,const char*,const char*,void*,int);
    void FrontEnd_ClosePopup(void*,int);
    char*Loc_LookupText(const char*);
    void func_0041BEB0(void*,const char*,int);
    void func_00293650();
    extern char D_0055A830[];
    extern void(*D_0055A838)();
    extern void*D_004FFC04;
    extern signed char D_00499C70[];
    struct NameBuf {
        char data[2];
    };
    extern NameBuf D_004A9DB0;
    extern char D_004A9870[],D_004A9D78[],D_004A9D80[],D_004A9D90[],D_004A9DB8[];
}
#define AO_DATA(x) ((char**)(x).vec.c)
static inline int AoCount(AoVec*const&v) {
    return v->vec.b;
}
extern "C" void AgentOpen_BuildSlotList(GuiSaveAgentWidget*self) {
    int slot,unused,zero;
    AoVec files,slots;
    char decoded[16],oldname[32],newname[32],label[16];
    GuiWidget* focus=Gui_GetScreenStack()->focus;
    unsigned char clearFocus=0,haveSlot=0;
    func_002888C0(&files);
    files.owned=1;
    func_002888C0(&slots);
    slots.owned=1;
    MemCardWrap_Enumerate(D_0055A830,&files);
    zero=0;
    PtrVector_Resize(&slots,8,&zero);
    for(int i=0;i<slots.vec.b;i++)AO_DATA(slots)[i]=0;
    for(int i=0;i<files.vec.b;i++) {
        if(!strchr(AO_DATA(files)[i],'.')&&(D_00499C70[(signed char)**func_002888B0(&files,i)+1]&4)&&AgentFile_DecodeName(AO_DATA(files)[i],decoded,&slot,16))AO_DATA(slots)[slot]=AO_DATA(files)[i];
    }
    unsigned char popup=0;
    int popupId;
    int filesCount=files.vec.b;
    for(int i=0;i<filesCount;i++,filesCount=AoCount(&files)) {
        char*ext=strchr(AO_DATA(files)[i],'.');
        if(ext&&!strncasecmp(ext,D_004A9D78,4)&&ext[4]) {
            char**data;
            int n=slots.vec.b;
            int j=0;
            if(j<n) {
                data=AO_DATA(slots);
                do {
                    if(!data[j]) {
                        if(!popup) {
                            D_0055A838=func_00293650;
                            popup=1;
                            popupId=FrontEnd_OpenPopup(D_004FFC04,0,D_004A9D80,D_004A9D90,self,0);
                        }
                        char*ext=strchr(AO_DATA(files)[i],'.');
                        strncpy(oldname,AO_DATA(files)[i],ext-AO_DATA(files)[i]);
                        oldname[ext-AO_DATA(files)[i]]=0;
                        if(AgentFile_EncodeName(oldname,newname,j,32)) {
                            MemCardWrap_Rename(D_0055A830,AO_DATA(files)[i],newname);
                            AO_DATA(slots)[j]=newname;
                        }
                        break;
                    }
                }while(++j<n);
            }
        }
    }
    if(popup) {
        FrontEnd_ClosePopup(D_004FFC04,popupId);
        D_0055A838=0;
    }
    char*name=(char*)&D_004A9DB0;
    name[0]='0';
    int slotsCount=slots.vec.b;
    for(int i=0;i<slotsCount;i++,slotsCount=AoCount(&slots)) {
        unsigned char valid;
        GuiWidget*w=(GuiWidget*)GuiFindAs(self,name,D_004A9870);
        if(w) {
            valid=0;
            if(AO_DATA(slots)[i]&&AgentFile_DecodeName(AO_DATA(slots)[i],label,&unused,16)) {
                func_0041BEB0(w,label,0);
                unsigned short flags=*(volatile unsigned short*)&w->flags;
                haveSlot=1;
                valid=haveSlot;
                w->flags=flags|4;
            }
            if(!valid) {
                if(!self->unk7C&&w==focus)clearFocus=1;
                func_0041BEB0(w,Loc_LookupText(D_004A9DB8),0);
                if(self->unk7C)w->flags|=4;
                else w->flags&=0xfffb;
            }
        }
        name[0]++;
    }
    if(clearFocus||(haveSlot&&focus==(GuiWidget*)self)) {
        AoStack*stack=Gui_GetScreenStack();
        GuiScreen_SetFocus(stack,((AoFocus*)self)->GetFocus());
    }
    func_002887C0(&slots,-1);
    func_002887C0(&files,-1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00292E80 */

/* merge_units: begin func_002933E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_002933E0, func_002886D0)
#pragma pop /* merge_units */
/* merge_units: end func_002933E0 */

/* merge_units: begin func_00293440 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00293440)
#pragma pop /* merge_units */
/* merge_units: end func_00293440 */

/* merge_units: begin func_00293530 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00293530)
#pragma pop /* merge_units */
/* merge_units: end func_00293530 */

/* merge_units: begin func_00293620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void func_002CC260(int, int);

int* func_00293620(PtrVec* v, int i) {
    return v->data + i;
}

Rel* func_00293630(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

void func_00293650(void) {
    func_002CC260(0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00293620 */

/* merge_units: begin func_00293660 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; float t; } S293660;
#if 0 /* merge_units */
extern void AgentOpen_BuildSlotList(S293660*);
#endif /* merge_units */
#define AgentOpen_BuildSlotList(a0) ((void)AgentOpen_BuildSlotList((GuiSaveAgentWidget *)(a0))) /* merge_units */

extern void func_0041E3B0(S293660*, float);
void func_00293660(S293660* s, float dt) {
    s->t += dt;
    if (!(s->t <= 1.0f)) {
        AgentOpen_BuildSlotList(s);
        s->t -= 1.0f;
    }
    func_0041E3B0(s, dt);
}
#undef AgentOpen_BuildSlotList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00293660 */
