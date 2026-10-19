/*
 * main/frontCharacter: 2 files, 0022A200-0022A220
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022A200 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "frontCharacter_types.h"

extern int func_0022A360(FcVec* v, int* pos, int n, int value);  /* vector insert */

/* push_back(v, value) */
int func_0022A200(FcVec* v, int value) {
    return func_0022A360(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0022A200 */

/* merge_units: begin func_0022A220 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
char * Archive_Open();                   
int Expression_Init();                                
int Skf_Register(char *, char * );                        
int func_00391B30(char * , char *);                       
int AgentPartCache_LoadRules(char *, char *);                          
int TexCache_RegisterNpcTex(char *, char * );                       
int MeshCache_RegisterNpcSkm(char *, char * );                       
extern char g_AgentPartCache;

typedef struct { char p0[4]; int f4; int f8; int fC; int f10; int f14; } PS0_0022A220;
void FrontCharacter_Setup(PS0_0022A220 *arg0, int arg1) {
    char * temp_a0;
    char * temp_a1;
    char * temp_a1_2;
    char * temp_a1_3;

    arg0->f4 = NULL;
    arg0->f8 = NULL;
    arg0->fC = NULL;
    arg0->f10 = 0;
    arg0->f14 = NULL;
    AgentPartCache_LoadRules(&g_AgentPartCache, "GAMEDATA\\FRONTEND\\SWAPIT.TBL");
    arg0->f14 = (int)(Archive_Open(arg1, "GAMEDATA\\FRONTEND\\MANTEX.HOG", 0, 0));
    temp_a1 = (char *)(arg0->f14);
    if (F_(temp_a1, 0x14C, unsigned char) != 0) {
        TexCache_RegisterNpcTex(&g_AgentPartCache, temp_a1);
    }
    arg0->f4 = (int)(Archive_Open(arg1, "GAMEDATA\\FRONTEND\\MORPH.HOG", 0, 0));
    temp_a1_2 = (char *)(arg0->f4);
    if (F_(temp_a1_2, 0x14C, unsigned char) != 0) {
        Skf_Register(&g_AgentPartCache, temp_a1_2);
    }
    arg0->f8 = (int)(Archive_Open(arg1, "GAMEDATA\\FRONTEND\\MANSKM.HOG", 0, 0));
    temp_a1_3 = (char *)(arg0->f8);
    if (F_(temp_a1_3, 0x14C, unsigned char) != 0) {
        MeshCache_RegisterNpcSkm(&g_AgentPartCache, temp_a1_3);
    }
    Expression_Init();
    arg0->fC = (int)(Archive_Open(arg1, "GAMEDATA\\FRONTEND\\LIPS.HOG", 0, 0));
    temp_a0 = (char *)(arg0->fC);
    if (F_(temp_a0, 0x14C, unsigned char) != 0) {
        func_00391B30(temp_a0, "cdrom0:GAMEDATA\\FRONTEND\\LIPS.BNK");
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0022A220 */
