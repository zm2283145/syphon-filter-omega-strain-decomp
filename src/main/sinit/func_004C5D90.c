#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4C5D90;
extern char g_HotboxList[], D_004EE678[], D_004EE6A8[], g_RuntimeHotboxes[], D_004EE6C8[];
extern char* D_004EE6B8;
extern char* D_004EE698;
extern char* D_004EE6C0;
extern char D_0049C930[], D_0049C940[], D_0049C948[], D_0049C960[], D_0049C980[], D_0049C998[];
extern char D_0049C9A8[], D_0049C9B0[], D_0049C9B8[], D_0049C9C0[], D_0049C9D0[], D_0049C9E8[];
extern char D_0049C9F0[], D_0049C9F8[], D_0049CA00[], D_0049CA20[], D_0049CA38[];
extern char D_0048A110[];
extern char D_00493880[], D_00493878[], D_004938A0[];
extern char cLList_cHotboxPtr_dtor[], cSubclassId_dtor[], cArray_cHotboxPtr_dtor[];
extern char Script_MakeGOBJInteractable[], Script_MakeNPCInteractable[];
extern char cHotboxMsg_SOBJ_init[], cHotbox_SOBJ_init[];
extern char Script_cHotboxMsg_Action[], Script_cHotboxMsg_Who[], Script_cHotboxMsg_WhoNPC[], Script_cHotboxMsg_WhoPlayer[];
extern char Script_cHotbox_Enable[], Script_cHotbox_Disable[], Script_cHotbox_SetInteractMessage[];
extern char Script_cHotbox_ClearInteractMessage[], Script_cHotbox_Occupied[];
extern int D_004EE6F0, D_004EE6F8, D_004EE700, D_004EE708, D_004EE710, D_004EE718, D_004EE720, D_004EE728;
extern int D_004EE730, D_004EE738, D_004EE740, D_004EE748, D_004EE750, D_004EE758, D_004EE760, D_004EE768;
extern void std_list_cHotboxPtr_ctor(void* p);
extern void std_vector_cHotboxPtr_ctor(void* p);
extern void PtrVec_Reserve_Thunk_173900(void* p, int n);
extern int cArrayCapacity_Int(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int cScriptBase_registerEnum();
extern int cScriptBase_addClass();
extern int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
extern int cGOBJ_SOBJ_getClassId();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cNPC_SOBJ_getClassId();
extern int cPlayer_SOBJ_getClassId();
void StaticInit_hotbox(void)
{
    std_list_cHotboxPtr_ctor(g_HotboxList);
    __register_global_object(g_HotboxList, cLList_cHotboxPtr_dtor, D_004EE678);
    D_004EE698 = D_0049C930;
    D_004EE6B8 = D_0049C940;
    __register_global_object(&D_004EE6B8, cSubclassId_dtor, D_004EE6A8);
    {
        int n[1];
        Obj_4C5D90* o;
        D_004EE6C0 = D_0049C948;
        n[0] = 0x14;
        o = (Obj_4C5D90*)g_RuntimeHotboxes;
        std_vector_cHotboxPtr_ctor(o);
        PtrVec_Reserve_Thunk_173900(o, cArrayCapacity_Int(n));
        o->ready = 0;
        __register_global_object(o, cArray_cHotboxPtr_dtor, D_004EE6C8);
    }
    D_004EE6F0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_MakeGOBJInteractable, &D_004EE738, D_0049C960, 1, cGOBJ_SOBJ_getClassId());
    D_004EE6F8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_MakeNPCInteractable, &D_004EE738, D_0049C980, 1, cNPC_SOBJ_getClassId());
    D_004EE700 = cScriptBase_addClass(D_0049C998, cHotboxMsg_SOBJ_init, 1, 0);
    D_004EE708 = D_004EE700;
    D_004EE710 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE700, Script_cHotboxMsg_Action, &D_004EE730, D_0049C9A8, 1, &D_004EE700);
    D_004EE718 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE700, Script_cHotboxMsg_Who, cGOBJ_SOBJ_getClassId(), D_0049C9B0, 1, &D_004EE700);
    D_004EE720 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE700, Script_cHotboxMsg_WhoNPC, cNPC_SOBJ_getClassId(), D_0049C9B8, 1, &D_004EE700);
    D_004EE728 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE700, Script_cHotboxMsg_WhoPlayer, cPlayer_SOBJ_getClassId(), D_0049C9C0, 1, &D_004EE700);
    D_004EE730 = cScriptBase_registerEnum(D_0049C9D0, D_0048A110, 3);
    D_004EE738 = cScriptBase_addClass(D_0049C9E8, cHotbox_SOBJ_init, 0, 1);
    D_004EE740 = D_004EE738;
    D_004EE748 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE738, Script_cHotbox_Enable, D_00493880, D_0049C9F0, 1, &D_004EE738);
    D_004EE750 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE738, Script_cHotbox_Disable, D_00493880, D_0049C9F8, 1, &D_004EE738);
    D_004EE758 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE738, Script_cHotbox_SetInteractMessage, D_00493880, D_0049CA00, 2, &D_004EE738, D_004938A0);
    D_004EE760 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE738, Script_cHotbox_ClearInteractMessage, D_00493880, D_0049CA20, 1, &D_004EE738);
    D_004EE768 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE738, Script_cHotbox_Occupied, D_00493878, D_0049CA38, 1, &D_004EE738);
}
