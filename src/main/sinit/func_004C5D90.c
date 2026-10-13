#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4C5D90;
extern char D_004EE688[], D_004EE678[], D_004EE6A8[], D_004EE6E0[], D_004EE6C8[];
extern char* D_004EE6B8;
extern char* D_004EE698;
extern char* D_004EE6C0;
extern char D_0049C930[], D_0049C940[], D_0049C948[], D_0049C960[], D_0049C980[], D_0049C998[];
extern char D_0049C9A8[], D_0049C9B0[], D_0049C9B8[], D_0049C9C0[], D_0049C9D0[], D_0049C9E8[];
extern char D_0049C9F0[], D_0049C9F8[], D_0049CA00[], D_0049CA20[], D_0049CA38[];
extern char D_0048A110[];
extern char D_00493880[], D_00493878[], D_004938A0[];
extern char func_00171740[], func_00144930[], func_001737B0[];
extern char Script_MakeGOBJInteractable[], Script_MakeNPCInteractable[];
extern char ScriptType_cHotboxMsg_Init[], ScriptType_cHotbox_Init[];
extern char Script_cHotboxMsg_Action[], Script_cHotboxMsg_Who[], Script_cHotboxMsg_WhoNPC[], Script_cHotboxMsg_WhoPlayer[];
extern char Script_cHotbox_Enable[], Script_cHotbox_Disable[], Script_cHotbox_SetInteractMessage[];
extern char Script_cHotbox_ClearInteractMessage[], Script_cHotbox_Occupied[];
extern int D_004EE6F0, D_004EE6F8, D_004EE700, D_004EE708, D_004EE710, D_004EE718, D_004EE720, D_004EE728;
extern int D_004EE730, D_004EE738, D_004EE740, D_004EE748, D_004EE750, D_004EE758, D_004EE760, D_004EE768;
extern void LinkList_Ctor(void* p);
extern void func_00173910(void* p);
extern void func_00173900(void* p, int n);
extern int func_001361D0(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int func_003D8F60();
extern int Script_RegisterType();
extern int Script_RegisterNative();
extern int cGOBJ_GetScriptTypeKeyPtr();
extern int Script_RegisterNative_2();
extern int func_0014A6A0();
extern int func_00175FB0();
void func_004C5D90(void)
{
    LinkList_Ctor(D_004EE688);
    __register_global_object(D_004EE688, func_00171740, D_004EE678);
    D_004EE698 = D_0049C930;
    D_004EE6B8 = D_0049C940;
    __register_global_object(&D_004EE6B8, func_00144930, D_004EE6A8);
    {
        int n[1];
        Obj_4C5D90* o;
        D_004EE6C0 = D_0049C948;
        n[0] = 0x14;
        o = (Obj_4C5D90*)D_004EE6E0;
        func_00173910(o);
        func_00173900(o, func_001361D0(n));
        o->ready = 0;
        __register_global_object(o, func_001737B0, D_004EE6C8);
    }
    D_004EE6F0 = Script_RegisterNative_2(Script_MakeGOBJInteractable, &D_004EE738, D_0049C960, 1, cGOBJ_GetScriptTypeKeyPtr());
    D_004EE6F8 = Script_RegisterNative_2(Script_MakeNPCInteractable, &D_004EE738, D_0049C980, 1, func_0014A6A0());
    D_004EE700 = Script_RegisterType(D_0049C998, ScriptType_cHotboxMsg_Init, 1, 0);
    D_004EE708 = D_004EE700;
    D_004EE710 = Script_RegisterNative(D_004EE700, Script_cHotboxMsg_Action, &D_004EE730, D_0049C9A8, 1, &D_004EE700);
    D_004EE718 = Script_RegisterNative(D_004EE700, Script_cHotboxMsg_Who, cGOBJ_GetScriptTypeKeyPtr(), D_0049C9B0, 1, &D_004EE700);
    D_004EE720 = Script_RegisterNative(D_004EE700, Script_cHotboxMsg_WhoNPC, func_0014A6A0(), D_0049C9B8, 1, &D_004EE700);
    D_004EE728 = Script_RegisterNative(D_004EE700, Script_cHotboxMsg_WhoPlayer, func_00175FB0(), D_0049C9C0, 1, &D_004EE700);
    D_004EE730 = func_003D8F60(D_0049C9D0, D_0048A110, 3);
    D_004EE738 = Script_RegisterType(D_0049C9E8, ScriptType_cHotbox_Init, 0, 1);
    D_004EE740 = D_004EE738;
    D_004EE748 = Script_RegisterNative(D_004EE738, Script_cHotbox_Enable, D_00493880, D_0049C9F0, 1, &D_004EE738);
    D_004EE750 = Script_RegisterNative(D_004EE738, Script_cHotbox_Disable, D_00493880, D_0049C9F8, 1, &D_004EE738);
    D_004EE758 = Script_RegisterNative(D_004EE738, Script_cHotbox_SetInteractMessage, D_00493880, D_0049CA00, 2, &D_004EE738, D_004938A0);
    D_004EE760 = Script_RegisterNative(D_004EE738, Script_cHotbox_ClearInteractMessage, D_00493880, D_0049CA20, 1, &D_004EE738);
    D_004EE768 = Script_RegisterNative(D_004EE738, Script_cHotbox_Occupied, D_00493878, D_0049CA38, 1, &D_004EE738);
}
