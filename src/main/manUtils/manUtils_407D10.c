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
extern void Hog_Load(Msg*, Text*, int, int);
extern void SklRegistry_AddArchive(void*, Msg*);
extern void Hog_Unload(Msg*);
extern void cHogFile_dtor(Msg*, int);

/* Formats a message from (a, b) and posts it to the D_0055D4F8 queue. */
void SklRegistry_LoadMission(int a, int b) {
    Msg msg;
    Text text;
    cHogFile_ctor(&msg);
    sprintf(&text, ((int*)"%s\\%s\\SKL.HOG"), a, b);
    Hog_Load(&msg, &text, 0, 0);
    SklRegistry_AddArchive(&D_0055D4F8, &msg);
    Hog_Unload(&msg);
    cHogFile_dtor(&msg, -1);
}
