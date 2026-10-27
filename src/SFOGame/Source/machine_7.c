/*
 * SFOGame/Source/machine: 1 file, 001674E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001674E0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock();                                    
int EnableIntc();                                  
int cHogList_Open();                   
char * cMemMan_Allocate(int, int, char *, int);                      
int func_0027B680();                            
char * cHudNetLobby_ctor(char * , int, char *);              
int cFileMan_Open();                             
int cFileMan_dtor();                            
int cFileMan_ctor_charP_cFileIOP_bool();                    
int sprintf();                           
extern char D_0048B2F8;
extern char D_0049C390;
extern char D_004FFB8C;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

#pragma opt_common_subs off
void cMachine_CreateNetworkLobbyScreen(char * arg0) {
    int spE0[36];
    int sp40[40];
    int temp_s0;
    char * var_s2;

    if (F_(arg0, 0x27C, int) == NULL) {
        sprintf(spE0, "%s\\COMMON\\IALOBBYN.HOG", &D_0048B2F8);
        cFileMan_ctor_charP_cFileIOP_bool(sp40, spE0, 0, 0);
        if (!(cFileMan_Open(sp40) & 0xFF)) {
            temp_s0 = cHogList_Open(&D_004FFB8C, spE0, 0, 0);
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            var_s2 = (char *)(cMemMan_Allocate(0, 0x58, &D_0049C390, 0x5B7));
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
            if (var_s2 != NULL) {
                var_s2 = (char *)(cHudNetLobby_ctor(var_s2, temp_s0, "IALOBBYN"));
            }
            F_(arg0, 0x27C, int) = (int)(var_s2);
            F_(F_(arg0, 0x27C, int), 0x56, signed char) = 1;
            func_0027B680(F_(arg0, 0x27C, int));
        }
        cFileMan_dtor(sp40, -1);
    }
}
static inline void merge_flush_func_001674E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001674E0 */
