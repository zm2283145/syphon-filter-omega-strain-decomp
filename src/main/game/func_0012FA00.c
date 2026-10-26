#include "types.h"

typedef struct Color4 {
    float r, g, b, a;
} Color4;

extern char* g_Hud;
extern void cInfoBar_SetScrollDelay(void*);
extern void Notify_Insert(void*, void*, Color4*, int, int);

/* Global: SetScrollDelay - resets the HUD scroller and starts it with a white color. */
void Global_SetScrollDelay(void) {
    char* hud = g_Hud;
    Color4 white;
    cInfoBar_SetScrollDelay(hud + 0x100);
    white.r = 1.0f;
    white.g = 1.0f;
    white.b = 1.0f;
    white.a = 1.0f;
    Notify_Insert(hud + 0x100, ((int*)"this is a test..only a test"), &white, 1, 0);
}
