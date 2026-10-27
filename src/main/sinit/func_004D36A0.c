#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cNetMsg_RegisterMsg(char *, char *, char *);                   
extern char *D_0052ACD8;
extern char D_0052ACE0;
extern int D_0052ACE8;
extern char func_00323EA0;

void StaticInit_NetQuickChatMsg(void) {
    D_0052ACD8 = "cNetQuickChatMsg";
    D_0052ACE8 = cNetMsg_RegisterMsg(&func_00323EA0, &D_0052ACE0, "cNetQuickChatMsg");
}
