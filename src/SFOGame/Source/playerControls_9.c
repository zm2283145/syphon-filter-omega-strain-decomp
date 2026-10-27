/*
 * SFOGame/Source/playerControls: 1 file, 0024A5A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0024A5A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    char p00[0x24];
    unsigned char b24;
    char p25[0x3C - 0x25];
    int flags;
} PlayerInput_24A5A0;
extern unsigned char cPlayerControls_ExitCrawl_cHumanR(PlayerInput_24A5A0* p);
extern unsigned char cPlayerControls_EnterCrawl(PlayerInput_24A5A0* p);
unsigned char cPlayerControls_ToggleCrawl(PlayerInput_24A5A0* p) {
    unsigned char result = 0;
    int crouched = (p->flags >> 4) & 1;
    if (crouched)
        result = cPlayerControls_ExitCrawl_cHumanR(p);
    else if (!crouched && p->b24)
        result = cPlayerControls_EnterCrawl(p);
    return result;
}
static inline void merge_flush_func_0024A5A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024A5A0 */
