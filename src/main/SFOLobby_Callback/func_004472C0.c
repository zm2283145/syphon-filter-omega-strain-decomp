#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef struct { int x; char s[0x3EC]; } E4472C0;
extern SFOLobby* D_00585E60;
extern char D_004C0CD0[]; /* "{SFOLOBBY_SETTINGS}" */
extern int SFOLobby_NoInstance();
extern void String_Copy(char* d, const char* s);
extern int strlen(const char* s);
extern int String_CompareN(const char* a, const char* b, int n);
extern void func_00443BF0(SFOLobby* g, char* s, int n, int f);
extern void LobbyArray_Append(LobbyArray* a, E4472C0* e);
extern void* memcpy(void* dst, const void* src, int n);
#pragma opt_propagation off
/* Reply callback: flags gotReply1BC. A text record starting with
 * "{SFOLOBBY_SETTINGS}" is handed (without the prefix) to func_00443BF0; any other
 * record goes to outList2400. On error the end-of-list byte (+0x408) is forced. */
void func_004472C0(int d0, int d1, int d2, char* msg)
{
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotReply1BC = 1;
        if (F_(msg, 0x18, int) != 0) {
            F_(msg, 0x408, char) = 1;
        } else {
            E4472C0 e;
            char* pfx;
            int n;
            e.x = F_(msg, 0x1C, int);
            String_Copy(e.s, msg + 0x20);
            pfx = D_004C0CD0;
            n = strlen(pfx);
            if (String_CompareN(e.s, pfx, n) == 0) {
                func_00443BF0((SFOLobby*)D_00585E60, e.s + n, strlen(e.s) - n, 1);
            } else {
                LobbyArray_Append(D_00585E60->outList2400, &e);
            }
        }
        memcpy(D_00585E60->reply5A4, msg, 0x40C);
    }
}
