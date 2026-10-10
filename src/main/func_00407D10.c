#include "types.h"

typedef struct Msg {
    char b[0x170];
} Msg;

typedef struct Text {
    char b[0x80];
} Text;

extern int D_004BE988;
extern int D_0055D4F8;
extern void func_0036D630(Msg*);
extern void sprintf(Text*, void*, int, int);
extern void Hog_Load(Msg*, Text*, int, int);
extern void func_00407830(void*, Msg*);
extern void func_0036CD80(Msg*);
extern void func_0036D5D0(Msg*, int);

/* Formats a message from (a, b) and posts it to the D_0055D4F8 queue. */
void func_00407D10(int a, int b) {
    Msg msg;
    Text text;
    func_0036D630(&msg);
    sprintf(&text, &D_004BE988, a, b);
    Hog_Load(&msg, &text, 0, 0);
    func_00407830(&D_0055D4F8, &msg);
    func_0036CD80(&msg);
    func_0036D5D0(&msg, -1);
}
