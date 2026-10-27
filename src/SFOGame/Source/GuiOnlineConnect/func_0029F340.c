#include "types.h"
extern short g_DnasErrorTable[];
extern signed char D_0048B992[];
extern signed char D_0048B993[];
extern char D_004AACB8[];
extern char D_004AACC8[];
extern char D_004AACD8[];
extern char D_004AACE8[];
extern char* nGlobalization_GetString_charP(char* key);
extern void Libc_Strcpy(char* d, char* s);
extern int sprintf(char* d, const char* f, ...);
void GetDNASErrorStrings(int err, char* title, char* body, char* extra)
{
    char buf[16];
    int code = 0;
    unsigned int i;
    int a = 0;
    int b = 0;
    char* t;
    for (i = 0; i < 0x22; i++) {
        if (-err == *(short*)((char*)g_DnasErrorTable + i * 4)) {
            code = *(short*)((char*)g_DnasErrorTable + i * 4);
            a = *(signed char*)((char*)D_0048B992 + i * 4);
            b = *(signed char*)((char*)D_0048B993 + i * 4);
            break;
        }
    }
    if (code != -1) {
        t = (err != -701 && err != -703) ? nGlobalization_GetString_charP(D_004AACB8) : nGlobalization_GetString_charP(D_004AACC8);
        if (t) Libc_Strcpy(title, t);
    }
    if (a != -1) {
        if (a == 0 && !(err < -699) && err < -600) a = 15;
        sprintf(buf, D_004AACD8, a);
        t = nGlobalization_GetString_charP(buf);
        if (t) sprintf(body, t, err);
    }
    if (b != -1) {
        sprintf(buf, D_004AACE8, b);
        t = nGlobalization_GetString_charP(buf);
        if (t) Libc_Strcpy(extra, t);
    }
}
