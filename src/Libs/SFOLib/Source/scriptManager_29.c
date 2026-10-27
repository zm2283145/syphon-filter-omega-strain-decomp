/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003E1520-003E1540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E1520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00559FA0[];

void* cScriptInterpreter_SOBJ_convert(void* self) {
    return self;
}

int cScriptInterpreter_SOBJ_getClassId(void) {
    return (int)D_00559FA0;
}
static inline void merge_flush_func_003E1520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E1520 */

/* merge_units: begin func_003E1540 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

extern char D_00559F20[];
extern char* strrchr(const char* s, int c);
extern char* strchr(const char* s, int c);
char* stripPathAndExt(const char* path)
{
    const char* s = strrchr(path, '\\');
    char* d;
    path = s ? s + 1 : path;
    Libc_Strcpy(D_00559F20, path);
    d = strchr(D_00559F20, '.');
    if (d)
        *d = 0;
    return D_00559F20;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E1540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E1540 */

/* merge_units: begin func_003E15B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cScriptInterpreter_LoadScript(int, int, int);                
char * cScriptInterpreter_findScriptObj();                        
unsigned int D_004938D0[2] = { 0x1, 0x0 };

int cScriptInterpreter_FindScriptObj(int arg0, int arg1, int *arg2, int *arg3) {
    char * var_s0;

    if ((*(unsigned char*)D_004938D0) != 0) {
        var_s0 = cScriptInterpreter_findScriptObj();
        if (var_s0 != NULL) {
            *arg2 = F_(var_s0, 0x38, int);
            *arg3 = F_(var_s0, 0x48, int);
        } else if (cScriptInterpreter_LoadScript(arg0, arg1, 0) != 0) {
            var_s0 = cScriptInterpreter_findScriptObj(arg0, arg1);
            if (var_s0 != NULL) {
                *arg2 = F_(var_s0, 0x38, int);
                *arg3 = F_(var_s0, 0x48, int);
            }
        }
        return var_s0 != NULL;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E15B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E15B0 */
