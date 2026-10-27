/*
 * SFOGame/Source/GuiEquipmentModify: 3 files, 002BCAF0-002BCB50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002BCAF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char D_004AC7F0[] = "GuiEquipmentModify";   /* "GuiEquipmentModify" */
extern int sceNetcnfifDeleteCallbackThread(void);

int sceNetcnfifDeleteMc2Thread(void) {
    sceNetcnfifDeleteCallbackThread();
    return 0;
}

/* Class name getter: "GuiEquipmentModify". */
char* GuiEquipmentModify_GetClassName(void) {
    return D_004AC7F0;
}
static inline void merge_flush_func_002BCAF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BCAF0 */

/* merge_units: begin func_002BCB20 */
#pragma push /* merge_units */
/* "GuiEquipmentModify" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiEquipmentModify::IsA: returns 1 if the given class name is "GuiEquipmentModify". */
int GuiEquipmentModify_IsClass(void* self, const char* name)
{
    return strcmp("GuiEquipmentModify", name) == 0;
}
static inline void merge_flush_func_002BCB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BCB20 */

/* merge_units: begin func_002BCB50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "gui_grid_types.h"
#include "gui_widget_vslots.h"
struct Item { char pad[0x40A]; short unk40A; };
struct Slots { char pad[0x2410]; Item* unk2410; Item* unk2414; char pad2418[8]; Item* unk2420; };
struct Agent { char pad0[0x2470]; Item* unk2470; Item* unk2474; char pad2478[0x3524-0x2478]; void* unk3524; };
struct Widget : GuiWidgetV { char pad4[0x10]; unsigned short unk14; };
struct Screen { char pad0[0x48]; Agent* unk48; Agent* unk4C; char pad50[0x34]; int unk84; int unk88; int unk8C; int unk90; Widget* unk94; char pad98[0x34]; Widget* unkCC; char padD0[0x2C]; int unkFC; };
struct Stack { char pad0[0x20]; Widget* unk20; };
extern "C" {
void cGameFrontEnd_PushMessageBox(void*,int,char*,char*,void* =0,int=0);
void cGameSystem_SendAgentData(void*,int,int);
void GuiCanvas_SetFocus(Stack*,Widget*);
void GuiCanvas_Transition(Stack*,Screen*,void*);
void* Gui_Manager();
Stack* Gui_Canvas();
char* nGlobalization_GetString_charP(char*);
void cJoystick_Poll(void*);
void cWeapon_Add(void*,short,int,int,int=1,int=0);
void cWeapon_DrawWeapon_eWpnSlot(void*,int);
void cWeapon_StoreWeapon_void(void*);
void cWeapon_RemoveWeapon(void*,int,int,int,int=0);
int cWeapon_GetWeaponSlot(short);
void* GuiManager_OpenGui(void*,char*,char*);
void GuiWidget_SendMessage(void*,void*,int,int,int=0);
extern signed char D_00489D62[];
extern char D_004A9870[],D_004AC2B0[],D_004AC2C8[],D_004AC2D0[],D_004AC2E0[],D_004AC2F0[],D_004AC300[],D_004AC310[],D_004AC320[],D_004AC330[],D_004AC340[],D_004AC350[],D_004AC360[],g_Game[],D_0055A300[];
extern void* D_004FFC04;
extern signed char g_LoadoutPending;
extern unsigned char g_IsMultiplayer;
}
// Return an integer short-circuit result without a final byte conversion.
#pragma push
#pragma bool off
static inline int Press(GuiGridInput*p,int button) { return p->type==1 && p->device==0 && p->button==button && p->action==0; }
#pragma pop
extern "C" int GuiEquipmentModify_onInput(Screen* arg0, GuiGridInput* arg1) {
    void* temp_s0;
    char* temp_s0_2;
    int temp_v0_6;
    char* temp_v0_8;
    Item* temp_v1_2;
    int temp_v1_3;
    int temp_v1_6;
    bool var_t0;
    bool var_a3;
    void* var_s0_2;
    int var_s2;
    int var_s1;
    unsigned char var_a2;
    int var_v0;
    int var_v0_2;
    int var_v0_3;
    signed char *var_s0;
    unsigned short temp_a0;
    Widget* temp_v1_5;
    Widget* var_s0_3;
    Widget* var_s0_4;
    Agent* temp_a0_2;
    Item* temp_v0_5;
    Item* temp_v0_7;
    Widget* temp_v1_4;
    Widget* temp_v1_7;
    Widget* temp_v1_8;

    var_t0 = 0;
    var_a3 = 0;
    temp_a0 = arg1->type;
    var_a2 = 0;
    if ((temp_a0 == 1) && (arg1->device == 0)) {
        var_a2 = 1;
    }
    if ((var_a2) && (arg1->button == 0x80)) {
        var_a3 = 1;
    }
    if ((var_a3) && (arg1->action == 0)) {
        var_t0 = 1;
    }
    if (var_t0) {
        Agent* temp_v0 = arg0->unk4C;
        Slots* firstSlots;
        Item* temp_v1 = temp_v0->unk2470;
        firstSlots=(Slots*)((int)temp_v0+0x60);
        if (temp_v1 != 0) {
            int temp_v0_2 = arg0->unkFC;
            if (temp_v0_2 != 0) {
                ((Slots*)((temp_v0_2 << 2) + (int)firstSlots))->unk2410 = temp_v1;
                arg0->unk4C->unk2470 = 0;
                Agent* temp_v0_3 = arg0->unk4C;
                Slots* secondSlots=(Slots*)((int)temp_v0_3+0x60);
                Item* temp_v0_4 = temp_v0_3->unk2474;
                if (temp_v0_4 != 0) {
                    secondSlots->unk2420 = temp_v0_4;
                    arg0->unk4C->unk2474 = 0;
                }
            }
        }
        cWeapon_StoreWeapon_void(arg0->unk48->unk3524);
        var_s2 = 2;
        var_s1 = 8;
        var_s0 = D_00489D62;
        do {
            temp_a0_2 = arg0->unk48;
            temp_v1_2 = ((Slots*)((int)((Slots*)((int)temp_a0_2+0x60)) + var_s1))->unk2410;
            if (((Agent*)(var_s1 + (int)arg0->unk4C))->unk2470 != temp_v1_2) {
                if (temp_v1_2 != 0) {
                    cWeapon_RemoveWeapon(temp_a0_2->unk3524, *var_s0, 0, 0);
                }
                temp_v0_5 = ((Slots*)((int)((Slots*)((int)arg0->unk4C+0x60)) + var_s1))->unk2410;
                if (temp_v0_5 != 0) {
                    cWeapon_Add(arg0->unk48->unk3524, temp_v0_5->unk40A, 1, 0);
                }
            }
            var_s2 += 1;
            var_s1 += 4;
            var_s0 += 1;
        } while (var_s2 < 0xA);
        temp_v0_6 = arg0->unkFC;
        if (temp_v0_6 != 0) {
            // Preserve index evaluation before the actor pointer read.
            int off=temp_v0_6*4;
            Agent* agent=*(Agent* volatile*)&arg0->unk4C;
            temp_v0_7=((Slots*)(off+((int)agent+0x60)))->unk2410;
            if (temp_v0_7 != 0) {
                cWeapon_DrawWeapon_eWpnSlot(arg0->unk48->unk3524, cWeapon_GetWeaponSlot(temp_v0_7->unk40A));
            }
        }
        var_s0_2 = 0;
        if (g_IsMultiplayer != 0) {
            var_s0_2 = GuiManager_OpenGui(Gui_Manager(), D_004AC2B0, D_004AC2C8);
        } else {
            g_LoadoutPending = 0;
            cJoystick_Poll(D_0055A300);
        }
        GuiCanvas_Transition(Gui_Canvas(), arg0, var_s0_2);
        cGameSystem_SendAgentData(g_Game, 0, 0);
        return 1;
    }
    var_v0 = Press(arg1,0x10);
    if (var_v0 != 0) {
        if (g_IsMultiplayer != 0) {
            temp_s0 = GuiManager_OpenGui(Gui_Manager(), D_004AC2B0, D_004AC2C8);
            GuiCanvas_Transition(Gui_Canvas(), arg0, temp_s0);
            cGameSystem_SendAgentData(g_Game, 0, 0);
            return 1;
        }
        temp_s0_2 = nGlobalization_GetString_charP(D_004AC2D0);
        temp_v0_8 = nGlobalization_GetString_charP(D_004AC2E0);
        if ((temp_s0_2 != 0) && (temp_v0_8 != 0)) {
            cGameFrontEnd_PushMessageBox(D_004FFC04, 5, temp_s0_2, temp_v0_8,arg0);
        }
        return 1;
    }
    var_v0_2 = Press(arg1,0x8000);
    if (var_v0_2 != 0) {
        temp_v1_3 = arg0->unk84;
        var_s0_3 = 0;
        if (temp_v1_3 == 1) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
        }
        else if (temp_v1_3 == 2) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
        }
        else if (temp_v1_3 == 3) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
        }
        else if (temp_v1_3 == 4) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
        }
        else if (temp_v1_3 == 5) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
        }
        else if (temp_v1_3 == 6) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
        }
        else if (temp_v1_3 == 0) {
            var_s0_3 = (Widget*)GuiFindAs(arg0, D_004AC350, D_004A9870);
        }
        if (var_s0_3 != 0) {
            if (Gui_Canvas()->unk20 == var_s0_3) {
                return 1;
            }
            arg0->unk8C = 0;
            GuiCanvas_SetFocus(Gui_Canvas(), var_s0_3);
            temp_v1_4 = arg0->unkCC;
            temp_v1_4->unk14 = (unsigned short) (temp_v1_4->unk14 & 0xFF7F);
            temp_v1_5 = arg0->unk94;
            temp_v1_5->unk14 = (unsigned short) (temp_v1_5->unk14 & 0xFF7F);
            GuiWidget_SendMessage(var_s0_3, Gui_Canvas(), 0x10, 0);
            goto block_88;
        }
block_88:
        return 1;
    }
    if (arg0->unk84 > 0) {
        var_v0_3 = Press(arg1,0x2000);
        if (var_v0_3 != 0) {
            if (Gui_Canvas()->unk20 == arg0->unk94) {
                return 1;
            }
            arg0->unk8C = 1;
            temp_v1_6 = arg0->unk84;
            var_s0_4 = 0;
            if (temp_v1_6 == 1) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
            }
            else if (temp_v1_6 == 2) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
            }
            else if (temp_v1_6 == 3) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
            }
            else if (temp_v1_6 == 4) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
            }
            else if (temp_v1_6 == 5) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
            }
            else if (temp_v1_6 == 6) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
            }
            else if (temp_v1_6 == 0) {
                var_s0_4 = (Widget*)GuiFindAs(arg0, D_004AC350, D_004A9870);
            }
            GuiCanvas_SetFocus(Gui_Canvas(), arg0->unk94);
            temp_v1_7 = arg0->unkCC;
            temp_v1_7->unk14 = (unsigned short) (temp_v1_7->unk14 | 2);
            temp_v1_8 = arg0->unkCC;
            temp_v1_8->unk14 = (unsigned short) (temp_v1_8->unk14 | 8);
            if (var_s0_4 != 0) {
                GuiWidget_SendMessage(arg0, var_s0_4, 6, (int)D_004AC360);
                GuiWidget_SendMessage(var_s0_4, Gui_Canvas(), 0x10, 0);
            }
            return 1;
        }
        goto block_136;
    }
block_136:
    return 0;
}
static inline void merge_flush_func_002BCB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002BCB50 */
