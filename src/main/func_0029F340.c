#include "types.h"
extern short D_0048B990[];
extern signed char D_0048B992[];
extern signed char D_0048B993[];
extern char D_004AACB8[];
extern char D_004AACC8[];
extern char D_004AACD8[];
extern char D_004AACE8[];
extern char* Loc_LookupText(char* key);
extern void String_Copy(char* d, char* s);
extern int sprintf(char* d, const char* f, ...);
void GuiOnlineConnect_GetDnasText(int err, char* title, char* body, char* extra)
{
    char buf[16];
    int code = 0;
    unsigned int i;
    int a = 0;
    int b = 0;
    char* t;
    for (i = 0; i < 0x22; i++) {
        if (-err == *(short*)((char*)D_0048B990 + i * 4)) {
            code = *(short*)((char*)D_0048B990 + i * 4);
            a = *(signed char*)((char*)D_0048B992 + i * 4);
            b = *(signed char*)((char*)D_0048B993 + i * 4);
            break;
        }
    }
    if (code != -1) {
        t = (err != -701 && err != -703) ? Loc_LookupText(D_004AACB8) : Loc_LookupText(D_004AACC8);
        if (t) String_Copy(title, t);
    }
    if (a != -1) {
        if (a == 0 && !(err < -699) && err < -600) a = 15;
        sprintf(buf, D_004AACD8, a);
        t = Loc_LookupText(buf);
        if (t) sprintf(body, t, err);
    }
    if (b != -1) {
        sprintf(buf, D_004AACE8, b);
        t = Loc_LookupText(buf);
        if (t) String_Copy(extra, t);
    }
}
