/*
 * main/frontCharacter: range (3 files, 00229EB0-0022A140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00229EB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int func_001AF7A0(...);                                  
int Hog_Unload(...);                            
int func_003B62E0(...);                            
int func_00404FD0(...);                            
extern int D_004F77A0;
extern unsigned char g_ProfileLockEnabled;
extern char g_AgentPartCache;
extern int D_005712F0;
extern int D_005712F4;
}
#pragma opt_common_subs off
extern "C" void func_00229EB0(char * arg0) {
    int temp_s0;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;
    char * temp_a0_4;
    char * temp_a0_5;

    func_00404FD0(&g_AgentPartCache, -1);
    D_005712F0 = 0;
    D_005712F4 = 0;
    temp_a0 = (char *)(F_(arg0, 0x4, int));
    if ((temp_a0 != NULL) && (F_(temp_a0, 0x14C, unsigned char) != 0)) {
        Hog_Unload(temp_a0);
    }
    temp_a0_2 = (char *)(F_(arg0, 0x8, int));
    if ((temp_a0_2 != NULL) && (F_(temp_a0_2, 0x14C, unsigned char) != 0)) {
        Hog_Unload(temp_a0_2);
    }
    temp_a0_3 = (char *)(F_(arg0, 0xC, int));
    if ((temp_a0_3 != NULL) && (F_(temp_a0_3, 0x14C, unsigned char) != 0)) {
        Hog_Unload(temp_a0_3);
    }
    temp_a0_4 = (char *)(F_(arg0, 0x10, int));
    if ((temp_a0_4 != NULL) && (F_(temp_a0_4, 0x14C, unsigned char) != 0)) {
        Hog_Unload(temp_a0_4);
    }
    temp_a0_5 = (char *)(F_(arg0, 0x14, int));
    if ((temp_a0_5 != NULL) && (F_(temp_a0_5, 0x14C, unsigned char) != 0)) {
        Hog_Unload(temp_a0_5);
    }
    F_(arg0, 0x4, int) = NULL;
    F_(arg0, 0x8, int) = NULL;
    F_(arg0, 0xC, int) = NULL;
    F_(arg0, 0x10, int) = NULL;
    F_(arg0, 0x14, int) = NULL;
    temp_s0 = D_004F77A0;
    {
        AllocGuard g;
    func_003B62E0(temp_s0, -1);
    Mem_Free(0, temp_s0, "frontCharacter.cc", 0x8F);
    }
    D_004F77A0 = 0;
    func_001AF7A0();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00229EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00229EB0 */

/* merge_units: begin func_0022A040 */
#pragma push /* merge_units */
#include "fileman_entry.h"
void FrontEnd_LoadIdleClip(void); /* gsynth: defined below */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(int, int, char *, int);                      
int func_001C0540(char * );                            
int func_001C05E0(char * );                            
int func_001C0720(char * );                            
int func_001C07C0(char * );                            
int func_001C0810(char * );                            
#if 0 /* merge_units */
int FrontEnd_LoadIdleClip();
#endif /* merge_units */
#define FrontEnd_LoadIdleClip() (FrontEnd_LoadIdleClip()) /* merge_units */
                                  
int FrontCharacter_Setup(int, int);                            
extern char D_004A6320;
#if 0 /* merge_units */
extern char * D_004F77A0;
#endif /* merge_units */
#define D_004F77A0 (*(char **)&D_004F77A0) /* merge_units */

}
extern "C" void func_0022A040(int arg0, int arg1) {
    char * temp_s2;

    {
        AllocGuard g;
    temp_s2 = Mem_Alloc(0, 0x5C, &D_004A6320, 0x70);
    }
    if (temp_s2 != NULL) {
        F_(temp_s2, 0x0, int) = 0;
        func_001C0810(temp_s2 + 4);
        func_001C07C0(temp_s2 + 0x14);
        func_001C0720(temp_s2 + 0x24);
        func_001C05E0(temp_s2 + 0x34);
        func_001C0540(temp_s2 + 0x44);
        F_(temp_s2, 0x54, int) = 0;
        F_(temp_s2, 0x58, int) = 0;
    }
    D_004F77A0 = temp_s2;
    FrontEnd_LoadIdleClip();
    FrontCharacter_Setup(arg0, arg1);
}
#undef FrontEnd_LoadIdleClip /* merge_units */
#undef D_004F77A0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022A040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022A040 */

/* merge_units: begin func_0022A140 */
#pragma push /* merge_units */
extern void Human_InitStatics(void);
extern int func_0036E140(void* h, const char* name, int arg, int opt);
extern void func_003B5310(void* a, void* e);
extern int func_0022A200(void* v, void* value);
extern char D_004A6340[];
extern char D_004A6360[];
#if 0 /* merge_units */
extern char* D_004F77A0;
#endif /* merge_units */
#define D_004F77A0 (*(char **)&D_004F77A0) /* merge_units */


/* Loads the front-end idle animation and pushes an empty 4-char tag onto the character list. */
void FrontEnd_LoadIdleClip(void)
{
    char tag[4];
    FileManEntry e;
    unsigned char done;
    unsigned int i;
    const char* s;
    Human_InitStatics();
    Resource_Construct(&e);
    func_0036E140(&e, D_004A6340, 0, 0);
    func_003B5310(D_004F77A0, &e);
    done = 0;
    for (i = 0, s = D_004A6360; i < 4; i++) {
        char c = *s;
        if (c == 0)
            done = 1;
        tag[i] = done ? 0 : c;
        s++;
    }
    func_0022A200(D_004F77A0 + 4, tag);
    FileMan_Release(&e, -1);
}
#undef D_004F77A0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022A140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022A140 */
