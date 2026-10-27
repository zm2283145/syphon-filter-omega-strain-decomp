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