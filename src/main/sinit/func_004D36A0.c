#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002824D0(char *, char *, char *);                   
extern char *D_0052ACD8;
extern char D_0052ACE0;
extern int D_0052ACE8;
extern char func_00323EA0;

void func_004D36A0(void) {
    D_0052ACD8 = "cNetQuickChatMsg";
    D_0052ACE8 = func_002824D0(&func_00323EA0, &D_0052ACE0, "cNetQuickChatMsg");
}
