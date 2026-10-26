/*
 * main/skybox: 2 files, 003BBBC0-003BBC90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BBBC0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FileMan_Release(char *, int);                            
int cFileMan_ctor_charP_cFileIOP_bool(char *, char *, int, int);                    
int XLib_RequestDeleteDmaData(char *, int, int);                       
int Fstream_ReleaseNoCallback(int, char *, int);                       
int Fstream_GetLoader();                                
int operator_delete(char * );                          
int sprintf(char *, char *, char * );                        
extern char g_Video;

char * cTexture_dtor(char * arg0, short arg1) {
    int spD0[32];
    int sp30[40];
    int temp_v1;

    if (arg0 != NULL) {
        temp_v1 = F_(arg0, 0x48, int);
        if (temp_v1 & 0x1000) {
            if (temp_v1 & 0x2000) {
                sprintf(spD0, "%s.TDX", arg0);
                cFileMan_ctor_charP_cFileIOP_bool(sp30, spD0, 0, 0);
                Fstream_ReleaseNoCallback(Fstream_GetLoader(), sp30, 1);
                FileMan_Release(sp30, -1);
            } else {
                XLib_RequestDeleteDmaData(&g_Video, F_(arg0, 0x44, int), -1);
            }
        }
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BBBC0 */

/* merge_units: begin func_003BBC90 */
#pragma push /* merge_units */
static inline void MemClear_3BB(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a1, dst, 0xF
        andi $v1, n, 0xF
        or $a1, $a1, $v1
        nop
        bgtz $a1, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}
#pragma opt_propagation off
void* cTexture_ctor(void* d)
{
    MemClear_3BB(d, 0x70);
    return d;
}
#pragma opt_propagation reset
#pragma pop /* merge_units */
/* merge_units: end func_003BBC90 */
