/*
 * SFOGame/Source/overlay: 1 file, 0045A7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiSubTitleDisplay_45A7F0 */
#pragma push /* merge_units */
#include "types.h"
extern int D_004979A8;
extern char* D_004E1B04;
extern char D_004C1FF0[];
extern char D_004C2008[];
extern char D_004C2010[];
extern char D_1E68000[];
extern char D_1FE8000[];
extern int cMemMan_HaveAllocationInRange(void*, void*);
extern void* memset(void*, int, unsigned int);
extern int sprintf(char*, const char*, ...);
extern int mwLoadOverlay(const char*, char*);

int SFO_RequestOverlay(int id)
{
    char path[256];
    char* buf;
    char* start;
    int size;

    if (D_004979A8 == id) {
        return 1;
    }
    D_004979A8 = id;
    switch (id) {
    case 1:
        return 1;
    case 2:
        buf = D_004E1B04;
        if (buf == 0) {
            return 0;
        }
        start = D_1E68000;
        size = D_1FE8000 - start;
        if (cMemMan_HaveAllocationInRange(start, D_1FE8000)) {
            return 0;
        }
        memset(start, 0, size);
        sprintf(path, D_004C1FF0, D_004C2008, D_004C2010);
        if (!mwLoadOverlay(path, buf)) {
            return 0;
        }
        break;
    }
    return 1;
}
static inline void merge_flush_GuiSubTitleDisplay_45A7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSubTitleDisplay_45A7F0 */
