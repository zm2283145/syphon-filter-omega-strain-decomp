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
