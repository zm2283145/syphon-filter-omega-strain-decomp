#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma cplusplus on
extern "C" {
int String_Copy(char *, char *);
int func_00128C68(char *, char *, ...);
void LobbyArray_SetRefreshing(char *, int);
void LobbyArray_Copy(int, char *);
int LobbyArray_Append(char *, void *);
int SFOLobby_NoInstance();
void SFOLobby_CacheAccount(char *, int, char *, int, int);
void *memset(void *, int, int);
unsigned int strlen(char *);
extern char D_004C0CF0[];
extern char *D_00585E60;
}

static inline bool IsNul(char c) { return !c; }


typedef struct {
    int id;
    char name[0x20];
    int pad24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
} Req447790;

extern "C" void func_00447790(int d0, int d1, int d2, char *arg3)
{
    int n1;
    int n2;
    int n3;
    int n4;
    Req447790 req;
    char *list;
    bool ok;
    int i;
    char *p;

    if (SFOLobby_NoInstance() == 0) {
        list = D_00585E60 + 0xA8;
        if (list != NULL) {
            if (F_(arg3, 0x18, int) == 0) {
                memset(&req, 0, 0x50);
                n4 = n3 = n2 = n1 = 0;
                char name[0x40] = {0};
                char buf[0x40];
                String_Copy(buf, arg3 + 0x20);
                i = 0;
                p = buf;
                while (!IsNul(*p) && *p != 9 && i < 0x40) {
                    if (*p == ' ')
                        *p = -1;
                    p++;
                    i++;
                }
                ok = true;
                if (func_00128C68(buf, D_004C0CF0, name, &n1, &n2, &n3, &n4) != 5)
                    ok = false;
                if (name[0] != 0) {
                    p = name;
                    do {
                        if (*(unsigned char *)p == 0xFF)
                            *p = ' ';
                        p++;
                    } while (*p != 0);
                }
                if (strlen(name) > 0x1F)
                    ok = false;
                if (n1 < 1 || n1 > 4)
                    ok = false;
                if (n2 < 0 || n2 >= F_(D_00585E60, 0x58, int))
                    ok = false;
                if (n3 < 0 || (unsigned int)n3 >= 6)
                    ok = false;
                if (ok) {
                    SFOLobby_CacheAccount(D_00585E60, n4, name, 0, 0);
                    String_Copy(req.name, name);
                    req.f30 = F_(arg3, 0x60, int);
                    req.f34 = F_(arg3, 0x68, int);
                    req.f38 = n1;
                    req.f48 = F_(arg3, 0x1C, int);
                    req.id = n4;
                    req.f40 = n2;
                    req.f44 = n3;
                    req.pad24 = 0;
                    LobbyArray_Append(list, &req);
                }
            }
            if (F_(arg3, 0x6C, signed char) != 0) {
                LobbyArray_SetRefreshing(list, 0);
                if (F_(D_00585E60, 0x23F0, int) != 0)
                    LobbyArray_Copy(F_(D_00585E60, 0x23F0, int), list);
            }
        }
    }
}
