/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Main: 1 file, 00453C70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin SFOLobby_Main_453C70 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int SFOLobby_ParseConfigFile();                   
int SFOLobbyList_ClearList();                               
int SFOLobbyList_AllocList();                      
int SFOLobby_ResetConnectionFlags(char * );                            
int SFOLobby_Reset(char * , int);                         
int memcpy(char * , int, int);                           
int memset(char *, int, int);                                
extern char * D_00585E60;
extern signed char D_00585E68;
extern char D_00585E70;
extern char D_00585E90;

void SFOLobby_Init(char * arg0, int arg1, int arg2, int arg3, char * arg4, char * arg5) {
    SFOLobbyList_AllocList(arg0 + 0x70, 0x20, 0x20, 0x114);
    SFOLobbyList_AllocList(arg0 + 0xFC, 0x200, 0, 0x140);
    SFOLobbyList_AllocList(arg0 + 0x118, 0x400, 0x200, 0x2C);
    SFOLobbyList_AllocList(arg0 + 0xC4, 0x40, 0x20, 0x50);
    SFOLobbyList_AllocList(arg0 + 0xE0, 0x40, 0x20, 0x50);
    SFOLobbyList_AllocList(arg0 + 0x134, 0x40, 0x20, 0x50);
    SFOLobbyList_AllocList(arg0 + 0x150, 0x40, 0x20, 0x50);
    SFOLobbyList_ClearList(arg0 + 0x1C);
    SFOLobbyList_ClearList(arg0 + 0x38);
    SFOLobbyList_ClearList(arg0 + 0x54);
    SFOLobby_ResetConnectionFlags(arg0);
    F_(arg0, 0x240C, int) = 0;
    F_(arg0, 0x26A8, int) = 0;
    F_(arg0, 0x1EB0, int) = -1;
    F_(arg0, 0x2564, signed char) = 0;
    F_(arg0, 0x2660, int) = 0;
    SFOLobby_ParseConfigFile(arg0, arg3, arg4, 0);
    D_00585E60 = arg0;
    if (arg2 != 0) {
        memcpy(arg0 + 0x2488, arg2, 0xC4);
    }
    F_(arg0, 0x254C, int) = arg1;
    D_00585E68 = (signed char)(arg5);
    memset(&D_00585E90, 0, 0xFC);
    memset(&D_00585E70, 0, 0x18);
    if (F_(arg0, 0x1EA8, int) != 0) {
        SFOLobby_Reset(arg0, 1);
    }
    F_(arg0, 0x26A4, int) = 1;
}
static inline void merge_flush_SFOLobby_Main_453C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_Main_453C70 */
