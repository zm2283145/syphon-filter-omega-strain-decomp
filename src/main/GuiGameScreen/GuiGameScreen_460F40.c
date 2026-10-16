/*
 * main/GuiGameScreen: 2 files, 00460F40-00461020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00460F40 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FileMan_Release(char * , int);                         
int GuiWidget_Destroy(char **, int);                           
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern char D_004E1730;

#pragma push
#pragma opt_common_subs off
char **func_00460F40(char **arg0, short arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &D_004E1730;
        if (((char *)arg0 + 0x350) != 0) {
            if (((char *)arg0 + 0x370) != NULL) {
                FileMan_Release((char *)arg0 + 0x454, -1);
                FileMan_Release((char *)arg0 + 0x3B8, -1);
            }
            temp_a0 = (char *)arg0 + 0x350;
            if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
                func_00461DC0(temp_a0, 0);
            }
        }
        if (((char *)arg0 + 0x1C0) != NULL) {
            FileMan_Release((char *)arg0 + 0x2A4, -1);
            FileMan_Release((char *)arg0 + 0x208, -1);
        }
        GuiWidget_Destroy(arg0, 0);
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00460F40 */

/* merge_units: begin func_00461020 */
#pragma push /* merge_units */
#include "fam5_timed_retry.h"
extern void GuiWidget_Update(char*, float);
DEFINE_TIMED_RETRY(func_00461020, 0x500, 0x350, GuiWidget_Update)
#pragma pop /* merge_units */
/* merge_units: end func_00461020 */
