#ifndef FRONTEND_H
#define FRONTEND_H

/*
 * main/frontend (frontend.cc): the front-end (menu) scene object.
 * gameFrontEnd allocates it (0x3C bytes), constructs it with cFrontendSystem_ctor
 * (cFrontendSystem_ctor, installs FrontEndScene_vtable) and then calls cFrontendSystem_Init.
 * Plain C or C++ (MW).
 *
 * The front end keeps its own copy of the common skeletons: cFrontendSystem_Init
 * opens "<GAMEDATA>\COMMON\SKEL.HOG" into `archives` and loads FEMALE.SKEL /
 * MALE.SKEL (the same as cLoader_LoadSkeletons does for a level);
 * cFrontendSystem_DestroySkeletons frees them and closes the archive again.
 */
typedef struct FrontEndScene {
    /* 0x00 */ void* vtable;        /* FrontEndScene_vtable (D_004DB810) */
    /* 0x04 */ char unk_04[0x28];   /* base object (cSystemContainer_ctor_void ctor, cSystemContainer_dtor dtor) */
    /* 0x2C */ char archives[0xC];  /* archive list (std_list_deleter_cHogFile_ctor ctor, cLList_cHogFile_dtor dtor) */
    /* 0x38 */ void* characters;    /* front-end character set: 0x18 bytes, built by CCI_Screen_ScreenInit,
                                       torn down by CCI_Screen_ScreenCleanup (frontCharacter.cc) */
} FrontEndScene; /* 0x3C */

#define FrontEndScene_vtable D_004DB810

/* "%s\\COMMON\\SKEL.HOG", formatted with the data root */
#define FrontEndScene_skelHogFmt D_004A62F0
/* data root directory name, "GAMEDATA" */
#define g_dataRoot D_0048B2F8
/* skeleton manager (cSkeletonDataBank_AddSkeletonData_charP_cHogFileR / cSkeletonDataBank_Clear) */
#define g_skelManager D_0053BB70

#endif /* FRONTEND_H */
