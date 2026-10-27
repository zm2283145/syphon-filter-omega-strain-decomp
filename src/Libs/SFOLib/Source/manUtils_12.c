/*
 * Libs/SFOLib/Source/manUtils: 1 file, 00407D10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin manUtils_407D10 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Msg {
    char b[0x170];
} Msg;

typedef struct Text {
    char b[0x80];
} Text;

extern int D_0055D4F8;
extern void cHogFile_ctor(Msg*);
extern void sprintf(Text*, void*, int, int);
extern void cHogFile_OpenHog(Msg*, Text*, int, int);
extern void SKLHog_LoadSKLHog(void*, Msg*);
extern void cHogFile_CloseHog(Msg*);
extern void cHogFile_dtor(Msg*, int);

/* Formats a message from (a, b) and posts it to the D_0055D4F8 queue. */
void SKLHog_LoadIdentities(int a, int b) {
    Msg msg;
    Text text;
    cHogFile_ctor(&msg);
    sprintf(&text, ((int*)"%s\\%s\\SKL.HOG"), a, b);
    cHogFile_OpenHog(&msg, &text, 0, 0);
    SKLHog_LoadSKLHog(&D_0055D4F8, &msg);
    cHogFile_CloseHog(&msg);
    cHogFile_dtor(&msg, -1);
}
static inline void merge_flush_manUtils_407D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end manUtils_407D10 */
