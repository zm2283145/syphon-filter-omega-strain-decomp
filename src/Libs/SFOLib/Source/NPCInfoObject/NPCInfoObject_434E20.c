/*
 * main/NPCInfoObject: range (3 files, 00434E20-004352C0)
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
int cMemMan_Deallocate();

/* merge_units: begin func_00434E20 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char * cMemMan_Allocate(...);                      
int std_list_deleter_voidPtr_erase_listdeleter(...);                     
                          
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);                      
                        
                          
                      
int std_list_tNPCInfoPtr_push_back(...);                      
extern char D_004BFCA0;
extern unsigned char g_ProfileLockEnabled;
extern char D_00582AB0;
extern char D_00582AD0;
}
struct Raw_4E20 { int p; Raw_4E20() {} };
extern "C" Raw_4E20 std_list_deleter_voidPtr_begin_void(void*);
extern "C" Raw_4E20 std_list_tNPCInfoPtr_end(void*);
extern "C" void std_list_tNPCInfoPtr_generic_iterator_ctor(char**, const Raw_4E20&);
extern "C" void cLListIterator_tNPCInfoPtr_ctor(char**, const Raw_4E20&);
static inline void Begin_4E20(char** out) { std_list_tNPCInfoPtr_generic_iterator_ctor(out, std_list_deleter_voidPtr_begin_void(&D_00582AB0)); }
static inline void End_4E20(char** out) { cLListIterator_tNPCInfoPtr_ctor(out, std_list_tNPCInfoPtr_end(&D_00582AB0)); }


extern "C" void cNPCInfoObject_AddPendingDeactivate(int d0, char * arg1) {
    char * sp7C;
    char * sp78;
    char * temp_s0;
    {
        AllocGuard g;
    temp_s0 = cMemMan_Allocate(0, 0x14, &D_004BFCA0, 0x2D5);
    }
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp7C = temp_s0;
    std_list_tNPCInfoPtr_push_back(&D_00582AD0, &sp7C);
    {
    char * sp70;
    int * temp_s2;
    char * temp_s0_2;
    char * var_s1;
    Begin_4E20(&sp70);
    var_s1 = sp70;
    while ((End_4E20(&sp78), (int)(var_s1) != (int)(sp78))) {
            temp_s2 = (int *)(F_(var_s1, 0x8, int));
            char * temp_s0_2 = var_s1;
            var_s1 = (char *)(F_(var_s1, 0x4, int));
            if (*temp_s2 == F_(arg1, 0x0, int)) {
                {
                    AllocGuard g;
                cMemMan_Deallocate(0, temp_s2, &D_004BFCA0, 0x2E6);
                }
                {
                char * sp68;
                int sp64;
                int sp60;
                sp68 = temp_s0_2;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp60, &sp68);
                std_list_deleter_voidPtr_erase_listdeleter(&sp64, &D_00582AB0, &sp60);
                }
            }
    }

    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434E20 */

/* merge_units: begin func_00435070 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
}
static inline void Begin_4E20_00435070(char** out) { std_list_tNPCInfoPtr_generic_iterator_ctor(out, std_list_deleter_voidPtr_begin_void(&D_00582AD0)); }
static inline void End_4E20_00435070(char** out) { cLListIterator_tNPCInfoPtr_ctor(out, std_list_tNPCInfoPtr_end(&D_00582AD0)); }


extern "C" void cNPCInfoObject_AddPendingActivate(int d0, char * arg1) {
    char * sp7C;
    char * sp78;
    char * temp_s0;
    {
        AllocGuard g;
    temp_s0 = cMemMan_Allocate(0, 0x14, &D_004BFCA0, 0x2B5);
    }
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp7C = temp_s0;
    std_list_tNPCInfoPtr_push_back(&D_00582AB0, &sp7C);
    {
    char * sp70;
    int * temp_s2;
    char * temp_s0_2;
    char * var_s1;
    Begin_4E20_00435070(&sp70);
    var_s1 = sp70;
    while ((End_4E20_00435070(&sp78), (int)(var_s1) != (int)(sp78))) {
            temp_s2 = (int *)(F_(var_s1, 0x8, int));
            char * temp_s0_2 = var_s1;
            var_s1 = (char *)(F_(var_s1, 0x4, int));
            if (*temp_s2 == F_(arg1, 0x0, int)) {
                {
                    AllocGuard g;
                cMemMan_Deallocate(0, temp_s2, &D_004BFCA0, 0x2C6);
                }
                {
                char * sp68;
                int sp64;
                int sp60;
                sp68 = temp_s0_2;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp60, &sp68);
                std_list_deleter_voidPtr_erase_listdeleter(&sp64, &D_00582AD0, &sp60);
                }
            }
    }

    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00435070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00435070 */

/* merge_units: begin func_004352C0 */
#pragma push /* merge_units */
#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#pragma mpwc_relax on
int NetGetObject(void **, int);                      
int NetGetMyClientIndex(int *, int);                        
int NetReleaseObjectPrivateOwnership(int);                               
extern int D_00494178;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005827A0;
extern unsigned char D_005827A8;
extern unsigned char D_005827B0;
extern unsigned char D_005827B8;
extern unsigned char D_005827C0;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;

void cNPCInfoObject_CheckForPendingRelease(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    int sp2C;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;
    int var_a0;
    int var_a0_2;
    int var_a0_3;
    int var_a0_4;
    int var_a0_5;

    if (D_005827A0 != 0) {
        temp_s0 = D_00582A78;
        NetGetObject(&sp3C, temp_s0);
        if (sp3C != NULL) {
            LOCALID_(var_a0)
            if (F_(sp3C, 0x4, int) == var_a0) {
                NetReleaseObjectPrivateOwnership(temp_s0);
            }
        }
        D_005827A0 = 0;
    }
    if (D_005827A8 != 0) {
        temp_s0_2 = D_00582A80;
        NetGetObject(&sp38, temp_s0_2);
        if (sp38 != NULL) {
            LOCALID_(var_a0_2)
            if (F_(sp38, 0x4, int) == var_a0_2) {
                NetReleaseObjectPrivateOwnership(temp_s0_2);
            }
        }
        D_005827A8 = 0;
    }
    if (D_005827B0 != 0) {
        temp_s0_3 = D_00582A88;
        NetGetObject(&sp34, temp_s0_3);
        if (sp34 != NULL) {
            LOCALID_(var_a0_3)
            if (F_(sp34, 0x4, int) == var_a0_3) {
                NetReleaseObjectPrivateOwnership(temp_s0_3);
            }
        }
        D_005827B0 = 0;
    }
    if (D_005827B8 != 0) {
        temp_s0_4 = D_00582A90;
        NetGetObject(&sp30, temp_s0_4);
        if (sp30 != NULL) {
            LOCALID_(var_a0_4)
            if (F_(sp30, 0x4, int) == var_a0_4) {
                NetReleaseObjectPrivateOwnership(temp_s0_4);
            }
        }
        D_005827B8 = 0;
    }
    if (D_005827C0 != 0) {
        temp_s0_5 = D_00582A98;
        NetGetObject(&sp2C, temp_s0_5);
        if (sp2C != NULL) {
            LOCALID_(var_a0_5)
            if (F_(sp2C, 0x4, int) == var_a0_5) {
                NetReleaseObjectPrivateOwnership(temp_s0_5);
            }
        }
        D_005827C0 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004352C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004352C0 */
