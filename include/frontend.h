#ifndef FRONTEND_H
#define FRONTEND_H

/*
 * main/frontend (frontend.cc): the front-end (menu) scene object.
 * gameFrontEnd allocates it (0x3C bytes), constructs it with FrontEndScene_ctor
 * (FrontEndScene_ctor, installs FrontEndScene_vtable) and then calls FrontEndScene_Init.
 * Plain C or C++ (MW).
 *
 * The front end keeps its own copy of the common skeletons: FrontEndScene_Init
 * opens "<GAMEDATA>\COMMON\SKEL.HOG" into `archives` and loads FEMALE.SKEL /
 * MALE.SKEL (the same as Skel_LoadCommonModels does for a level);
 * FrontEndScene_UnloadSkeletons frees them and closes the archive again.
 */
typedef struct FrontEndScene {
    /* 0x00 */ void* vtable;        /* FrontEndScene_vtable (D_004DB810) */
    /* 0x04 */ char unk_04[0x28];   /* base object (func_003CB110 ctor, func_003CAD70 dtor) */
    /* 0x2C */ char archives[0xC];  /* archive list (func_001391E0 ctor, func_00137670 dtor) */
    /* 0x38 */ void* characters;    /* front-end character set: 0x18 bytes, built by func_0022A040,
                                       torn down by func_00229EB0 (frontCharacter.cc) */
} FrontEndScene; /* 0x3C */

#define FrontEndScene_vtable D_004DB810

/* "%s\\COMMON\\SKEL.HOG", formatted with the data root */
#define FrontEndScene_skelHogFmt D_004A62F0
/* data root directory name, "GAMEDATA" */
#define g_dataRoot D_0048B2F8
/* skeleton manager (Skel_Load / Skel_FreeAll) */
#define g_skelManager D_0053BB70

#endif /* FRONTEND_H */
