/*
 * Libs/SFOLib/Source/interface: 2 files, 003E7560-003E75A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E7560 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
typedef __int128 Q128;
#pragma mpwc_relax on
char * cTargetInfo_ctor_cTargetInfoR(char * arg0, char * arg1) {
    F_(arg0, 0x0, int) = F_(arg1, 0x0, int);
    F_(arg0, 0x4, int) = F_(arg1, 0x4, int);
    F_(arg0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
    { typedef char uf_chk_[sizeof(F_(arg0, 0x10, Q128)) == 16 ? 1 : -1]; VCopyF(&(F_(arg0, 0x10, Q128)), &(F_(arg1, 0x10, Q128))); }
    F_(arg0, 0x20, float) = F_(arg1, 0x20, float);
    return arg0;
}
static inline void merge_flush_character_3E7560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E7560 */

/* merge_units: begin func_003E75A0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Libc_Strcpy(int, char *);
int String_CompareNoCase(char *, int);
char * GetTextSystem();
unsigned int D_00493948[2] = { 0x1, 0x0 };
extern char D_004BDE78;
extern char D_004BDE80;
extern char D_004BDE90;
extern char D_004BDEB0;

#pragma push
#pragma opt_propagation off
int confunc_INTERFACE(int arg0, int *arg1, int arg2) {
    if (arg0 == 1) {
        if (String_CompareNoCase(&D_004BDE78, *arg1) == 0) {
            (*(signed char*)D_00493948) = 1;
            { int r; char *o = GetTextSystem(); r = 1; F_(o, 0x1C, signed char) = r; return r; }
        }
        if (String_CompareNoCase(&D_004BDE80, *arg1) == 0) {
            (*(signed char*)D_00493948) = 0;
            F_(GetTextSystem(), 0x1C, signed char) = 0;
            return 1;
        }
        Libc_Strcpy(arg2, &D_004BDE90);
        return 0;
    }
    Libc_Strcpy(arg2, &D_004BDEB0);
    return 0;
}

#pragma pop
static inline void merge_flush_func_003E75A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E75A0 */
