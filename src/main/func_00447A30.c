#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma cplusplus on
extern "C" {
int String_Copy(char *, char *);
int SFOLobby_NoInstance();
void *memset(void *, int, int);
void LobbyArray_Append(char *, void *);
void SFOLobby_CacheAccount(char *, int, char *, int, int);
void LobbyArray_SetRefreshing(char *, int);
void LobbyArray_Copy(int, char *);
extern char *D_00585E60;
}

typedef struct {
    int id;
    char name[0x20];
    int f24;
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
} Req447A30;

extern "C" void func_00447A30(int d0, int d1, int d2, char *arg3)
{
    Req447A30 req;
    char *list;
    bool ok;

    if (SFOLobby_NoInstance() == 0) {
        list = D_00585E60 + 0x8C;
        if (list != NULL) {
            if (F_(arg3, 0x18, int) == 0) {
                memset(&req, 0, 0x50);
                req.id = F_(arg3, 0x1C, int);
                String_Copy(req.name, arg3 + 0x20);
                req.f30 = 0;
                req.f34 = -1;
                req.f44 = 5;
                req.f38 = -1;
                req.f3C = -1;
                req.f40 = -1;
                req.f28 = 2;
                req.f24 = 3;
                req.f2C = 0;
                ok = true;
                switch (F_(arg3, 0x40, int)) {
                case 0: ok = false; break;
                case 1: ok = false; break;
                case 2: req.f24 = 2; break;
                case 3: req.f24 = 1; break;
                }
                if (ok)
                    LobbyArray_Append(list, &req);
                SFOLobby_CacheAccount(D_00585E60, req.id, (char*)&req + 4, 0, 0);
            }
            if (F_(arg3, 0xCC, signed char) != 0) {
                LobbyArray_SetRefreshing(list, 0);
                if (F_(D_00585E60, 0x23F4, int) != 0)
                    LobbyArray_Copy(F_(D_00585E60, 0x23F4, int), list);
            }
        }
    }
}


