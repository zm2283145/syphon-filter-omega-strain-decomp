#include "types.h"

typedef struct Color4 {
    float r, g, b, a;
} Color4;

extern char* D_004FFC2C;
extern int D_0049A8E0;
extern void func_003FA190(void*);
extern void Notify_Insert(void*, void*, Color4*, int, int);

/* Global: SetScrollDelay - resets the HUD scroller and starts it with a white color. */
void Global_SetScrollDelay(void) {
    char* hud = D_004FFC2C;
    Color4 white;
    func_003FA190(hud + 0x100);
    white.r = 1.0f;
    white.g = 1.0f;
    white.b = 1.0f;
    white.a = 1.0f;
    Notify_Insert(hud + 0x100, &D_0049A8E0, &white, 1, 0);
}
