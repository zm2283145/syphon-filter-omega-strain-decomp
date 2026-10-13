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
