#include "types.h"
extern char Array_SOBJ_init[];
extern char Script_AddMaterialProperties[];
extern char Script_AddMaterialProperties_2[];
extern char Script_AddMaterialProperties_3[];
extern char Script_Array_AddElem[];
extern char Script_Array_ChangeIndex[];
extern char Script_Array_Count[];
extern char Script_Array_FindElem[];
extern char Script_Array_GetAndRemoveIndex[];
extern char Script_Array_GetIndex[];
extern char Script_Array_Print[];
extern char Script_Array_RandomizeArray[];
extern char Script_Array_RemoveIndex[];
extern char Script_Array_Sort[];
extern char Script_ClearCallout[];
extern char Script_ClearCallout_2[];
extern char Script_CreateArray[];
extern char Script_CreateNodeList[];
extern char Script_Distance[];
extern char Script_Distance_2[];
extern char Script_Distance_3[];
extern char Script_Distance_4[];
extern char Script_Distance_5[];
extern char Script_Print[];
extern char Script_Random[];
extern char Script_RandomInt[];
extern char Script_RandomInt_2[];
extern char Script_Random_2[];
extern char Script_Randomize[];
extern char Script_RemoveArray[];
extern char Script_RoundToInt[];
extern char Script_SetCallout[];
extern char Script_SetCalloutLabel[];
extern char Script_SetCalloutLabel_2[];
extern char Script_SetCalloutLabel_3[];
extern char Script_SetCalloutLabel_4[];
extern char Script_SetCallout_2[];
extern char Script_SetCallout_3[];
extern char Script_SetCallout_4[];
extern char Script_SetPersonalTimer[];
extern char Script_SetPersonalTimer_2[];
extern char Script_cNodeList_Add[];
extern char Script_cNodeList_AddDup[];
extern char Script_cNodeList_Contains[];
extern char Script_cNodeList_Find[];
extern char Script_cNodeList_Get[];
extern char Script_cNodeList_GetSize[];
extern char Script_cNodeList_Randomize[];
extern char Script_cNodeList_Remove[];
int __register_global_object();
int* cGOBJ_SOBJ_getClassId();
int* cGroup_SOBJ_getClassId();
extern char cLList_ArrayPtr_dtor[];
extern char cLList_cNodeListPtr_dtor[];
int* cNPC_SOBJ_getClassId();
extern char cNetLocalTimerMsg_NetReceive[];
int cNetMsg_RegisterMsg();
extern char cNodeList_SOBJ_init[];
int* cNode_SOBJ_getClassId();
int* cPlayer_SOBJ_getClassId();
int cScriptBase_addClass();
int cScriptBase_registerEnum();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int std_list_deleter_voidPtr_ctor_void();
extern char D_0048B1E0[];
extern char D_0048B210[];
extern char D_00493878[];
extern char D_00493880[];
extern char D_00493888[];
extern char D_00493890[];
extern char D_00493898[];
extern char D_004938A0[];
extern char D_004F2D18[];
extern char D_004F83B0[];
extern char D_004F83C0[];
extern char D_004F83D0[];
extern char D_004F83E0[];
extern char D_004F8588[];
extern char D_00571730[];
extern char D_00571738[];
extern char* D_004F83F0; /* cNodeList class name */
extern int D_004F83F8;
extern int D_004F8400;
extern int D_004F8408;
extern int D_004F8410;
extern int D_004F8418;
extern int D_004F8420;
extern int D_004F8428;
extern int D_004F8430;
extern int D_004F8438;
extern int D_004F8440;
extern int D_004F8448;
extern int D_004F8450;
extern int D_004F8458;
extern int D_004F8460;
extern int D_004F8468;
extern int D_004F8470;
extern int D_004F8478;
extern int D_004F8480;
extern int D_004F8488;
extern int D_004F8490;
extern int D_004F8498;
extern int D_004F84A0;
extern int D_004F84A8;
extern int D_004F84B0;
extern int D_004F84B8;
extern int D_004F84C0;
extern int D_004F84C8;
extern int D_004F84D0;
extern int D_004F84D8;
extern int D_004F84E0;
extern int D_004F84E8;
extern int D_004F84F0;
extern int D_004F84F8;
extern int D_004F8500;
extern int D_004F8508;
extern int D_004F8510;
extern int D_004F8518;
extern int D_004F8520;
extern int D_004F8528;
extern int D_004F8530;
extern int D_004F8538;
extern int D_004F8540;
extern int D_004F8548;
extern int D_004F8550;
extern int D_004F8558;
extern int D_004F8560;
extern int D_004F8568;
extern int D_004F8570;
extern int D_004F8578;
extern char* D_004F8580; /* cNetLocalTimerMsg name */
extern int D_004F8590;
extern int D_004F8598;
extern int D_004F85A0;
extern int D_004F85A8;
extern int D_004F85B0;
extern int D_004F85B8;
extern int D_004F8488;

/* scriptUtils.cc's Array_SOBJ / cNodeList_SOBJ live in an anonymous namespace (prototype
 * symbols getClassId__Q224@unnamed@scriptUtils_cc@...), so MW knew their register use when it
 * compiled the static initialiser and keeps values in v1/a2 across these calls. That only
 * happens for a static callee defined earlier in the same file. These are copies of the
 * functions at 0x002690E0 (scriptUtils_20.c) and 0x00269830 (scriptUtils_25.c), kept in their
 * own sections so the linker can map them onto those addresses (NOLOAD) instead of emitting
 * them here. */
#pragma define_section IPA_ARRAY ".ipa_002690E0" ".ipa_002690E0"
#pragma define_section IPA_NODELIST ".ipa_00269830" ".ipa_00269830"

__declspec(IPA_ARRAY) static int* Array_SOBJ_getClassId(void) {
    return &D_004F8488;
}

__declspec(IPA_NODELIST) static int* cNodeList_SOBJ_getClassId(void) {
    return &D_004F83F8;
}

/* __sinit_scriptUtils.cc. Retail gives the 4-byte literals "Add"/"Get" 8-byte alignment; MW aligns
 * literals of <=4 bytes to 4, so they carry padding NULs (precedent: playerControls_12 "X\0\0\0"). */
void StaticInit_scriptUtils(void) {
    std_list_deleter_voidPtr_ctor_void(D_004F83C0);
    __register_global_object(D_004F83C0, cLList_cNodeListPtr_dtor, D_004F83B0);
    std_list_deleter_voidPtr_ctor_void(D_004F83E0);
    __register_global_object(D_004F83E0, cLList_ArrayPtr_dtor, D_004F83D0);
    D_004F83F0 = "NodeList";
    D_004F83F8 = cScriptBase_addClass("cNodeList", cNodeList_SOBJ_init, 0, 1);
    D_004F8400 = *cNodeList_SOBJ_getClassId();
    D_004F8408 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Add, D_00493880, "Add\0\0", 2, cNodeList_SOBJ_getClassId(), cNode_SOBJ_getClassId());
    D_004F8410 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_AddDup, D_00493880, "AddDup", 2, cNodeList_SOBJ_getClassId(), cNode_SOBJ_getClassId());
    D_004F8418 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Remove, D_00493880, "Remove", 2, cNodeList_SOBJ_getClassId(), cNode_SOBJ_getClassId());
    D_004F8420 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Randomize, D_00493880, "Randomize", 1, cNodeList_SOBJ_getClassId());
    D_004F8428 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Find, D_00493888, "Find", 2, cNodeList_SOBJ_getClassId(), cNode_SOBJ_getClassId());
    D_004F8430 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Contains, D_00493878, "Contains", 2, cNodeList_SOBJ_getClassId(), cNode_SOBJ_getClassId());
    D_004F8438 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_GetSize, D_00493888, "GetSize", 1, cNodeList_SOBJ_getClassId());
    D_004F8440 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cNodeList_SOBJ_getClassId(), Script_cNodeList_Get, cNode_SOBJ_getClassId(), "Get\0\0", 2, cNodeList_SOBJ_getClassId(), D_00493888);
    D_004F8448 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_CreateNodeList, cNodeList_SOBJ_getClassId(), "CreateNodeList", 1, cGroup_SOBJ_getClassId());
    D_004F8450 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Print, D_00493880, "Print", 1, D_00493898);
    D_004F8458 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Random, D_00493890, "Random", 1, D_00493890);
    D_004F8460 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Random_2, D_00493890, "Random", 2, D_00493890, D_00493890);
    D_004F8468 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RandomInt, D_00493890, "RandomInt", 1, D_00493890);
    D_004F8470 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RandomInt_2, D_00493890, "RandomInt", 2, D_00493890, D_00493890);
    D_004F8478 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Randomize, D_00493880, "Randomize", 0);
    D_004F8480 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RoundToInt, D_00493888, "RoundToInt", 1, D_00493890);
    D_004F8488 = cScriptBase_addClass("Array", Array_SOBJ_init, 0, 0);
    D_004F8490 = *Array_SOBJ_getClassId();
    D_004F8498 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_AddElem, D_00493878, "AddElem", 2, Array_SOBJ_getClassId(), D_00493890);
    D_004F84A0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_RemoveIndex, D_00493878, "RemoveIndex", 2, Array_SOBJ_getClassId(), D_00493888);
    D_004F84A8 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_Count, D_00493888, "Count", 1, Array_SOBJ_getClassId());
    D_004F84B0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_FindElem, D_00493888, "FindElem", 2, Array_SOBJ_getClassId(), D_00493890);
    D_004F84B8 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_Print, D_00493880, "Print", 1, Array_SOBJ_getClassId());
    D_004F84C0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_Sort, D_00493880, "Sort", 1, Array_SOBJ_getClassId());
    D_004F84C8 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_RandomizeArray, D_00493880, "RandomizeArray", 1, Array_SOBJ_getClassId());
    D_004F84D0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_GetIndex, D_00493890, "GetIndex", 2, Array_SOBJ_getClassId(), D_00493888);
    D_004F84D8 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_GetAndRemoveIndex, D_00493890, "GetAndRemoveIndex", 2, Array_SOBJ_getClassId(), D_00493888);
    D_004F84E0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*Array_SOBJ_getClassId(), Script_Array_ChangeIndex, D_00493880, "ChangeIndex", 3, Array_SOBJ_getClassId(), D_00493888, D_00493890);
    D_004F84E8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_CreateArray, Array_SOBJ_getClassId(), "CreateArray", 1, D_00493888);
    D_004F84F0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RemoveArray, D_00493880, "RemoveArray", 1, Array_SOBJ_getClassId());
    D_004F84F8 = cScriptBase_registerEnum("testEnum", D_0048B1E0, 3);
    D_004F8500 = cScriptBase_registerEnum("BOOL", D_0048B210, 2);
    D_004F8508 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCallout, D_00493880, "SetCallout", 3, cGOBJ_SOBJ_getClassId(), D_00493898, D_00493888);
    D_004F8510 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCallout_2, D_00493880, "SetCallout", 4, cGOBJ_SOBJ_getClassId(), D_00493898, D_00493888, D_00493878);
    D_004F8518 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCalloutLabel, D_00493880, "SetCalloutLabel", 3, cGOBJ_SOBJ_getClassId(), D_004938A0, D_00493888);
    D_004F8520 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCalloutLabel_2, D_00493880, "SetCalloutLabel", 4, cGOBJ_SOBJ_getClassId(), D_004938A0, D_00493888, D_00493878);
    D_004F8528 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCallout_3, D_00493880, "SetCallout", 3, cNPC_SOBJ_getClassId(), D_00493898, D_00493888);
    D_004F8530 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCallout_4, D_00493880, "SetCallout", 4, cNPC_SOBJ_getClassId(), D_00493898, D_00493888, D_00493878);
    D_004F8538 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCalloutLabel_3, D_00493880, "SetCalloutLabel", 3, cNPC_SOBJ_getClassId(), D_004938A0, D_00493888);
    D_004F8540 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCalloutLabel_4, D_00493880, "SetCalloutLabel", 4, cNPC_SOBJ_getClassId(), D_004938A0, D_00493888, D_00493878);
    D_004F8548 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ClearCallout, D_00493880, "ClearCallout", 1, cGOBJ_SOBJ_getClassId());
    D_004F8550 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ClearCallout_2, D_00493880, "ClearCallout", 1, cNPC_SOBJ_getClassId());
    D_004F8558 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Distance, D_00493890, "Distance", 2, cGOBJ_SOBJ_getClassId(), cGOBJ_SOBJ_getClassId());
    D_004F8560 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Distance_2, D_00493890, "Distance", 2, cPlayer_SOBJ_getClassId(), cGOBJ_SOBJ_getClassId());
    D_004F8568 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Distance_3, D_00493890, "Distance", 2, cPlayer_SOBJ_getClassId(), cNPC_SOBJ_getClassId());
    D_004F8570 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Distance_4, D_00493890, "Distance", 2, cNPC_SOBJ_getClassId(), cGOBJ_SOBJ_getClassId());
    D_004F8578 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Distance_5, D_00493890, "Distance", 2, cNPC_SOBJ_getClassId(), cNPC_SOBJ_getClassId());
    D_004F8580 = "cNetLocalTimerMsg";
    D_004F8590 = cNetMsg_RegisterMsg(cNetLocalTimerMsg_NetReceive, D_004F8588, "cNetLocalTimerMsg");
    D_004F8598 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetPersonalTimer, D_00493880, "SetPersonalTimer", 3, cGOBJ_SOBJ_getClassId(), D_00493890, D_004938A0);
    D_004F85A0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetPersonalTimer_2, D_00493880, "SetPersonalTimer", 2, cGOBJ_SOBJ_getClassId(), D_00493890);
    D_004F85A8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AddMaterialProperties, D_00493878, "AddMaterialProperties", 6, D_00493898, D_00571730, D_00493898, D_004F2D18, D_00493898, D_00493898);
    D_004F85B0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AddMaterialProperties_2, D_00493878, "AddMaterialProperties", 7, D_00493898, D_00571730, D_00493898, D_004F2D18, D_00493898, D_00493898, D_00493890);
    D_004F85B8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AddMaterialProperties_3, D_00493878, "AddMaterialProperties", 8, D_00493898, D_00571730, D_00493898, D_004F2D18, D_00493898, D_00493898, D_00493890, D_00571738);
}
