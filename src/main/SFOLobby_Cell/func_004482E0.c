#include "types.h"
int LobbyArray_At();
int LobbyArray_Append();
int SFOLobby_NoInstance();
int SFOLobby_SetError(char *, int, char *, int);
int memset();
int strncpy();
extern char D_004C0D10;
extern char *D_00585E60;
typedef struct { int st; int f4; int id; } E48;
typedef struct { int f40; int f44; int f48; char s4C[0x20]; char s6C[0x20]; char rest[0x60]; } L48;
typedef struct { char p[0x18]; int a; int b; char q[8]; char s28[0xC8]; int id; char sF4[0x20]; } R482;
void func_004482E0(int d0, int d1, int d2, R482 *src) {
    if (SFOLobby_NoInstance() == 0) {
        int i;
        int n;
        switch (src->a) {
        case 0:
            break;
        case 1:
            return;
        case -988:
        case -991:
        case -989:
        case -990:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x8CE);
            return;
        }
        n = *(int *)(D_00585E60 + 0x20);
        for (i = 0; i < n; i++) {
            E48 *e = (E48 *)LobbyArray_At(D_00585E60 + 0x1C, i);
            if (e != 0 && e->st == 0 && e->id == src->id) return;
        }
        if (src->id >= 0 && src->id != *(int *)(D_00585E60 + 0xEAC)) {
            L48 l;
            memset(&l, 0, 0xAC);
            if (src->id >= 0) {
                l.f40 = 0;
                l.f48 = src->b;
                strncpy(l.s4C, src->sF4, 0x20);
                strncpy(l.s6C, src->s28, 0x20);
                LobbyArray_Append(D_00585E60 + 0x1C, &l);
            }
        }
    }
}
