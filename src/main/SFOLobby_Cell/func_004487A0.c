#pragma cplusplus on

typedef struct {
    char pad[0xEC];
    int host;
    int key;
    unsigned int ip;
    char pad2[0x100 - 0xF8];
} CellSub;

struct CellInfo {
    char tag[0x15];
    int status;
    int id;
    char name[0x20];
    char sub[0x100];
    int kind[0x23];
    int f1CC;
    int f1D0;
    int f1D4;
    char flag;
};

typedef struct {
    int id;
    char name[0x20];
    int f24;
    int f28;
    char* addr;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int key;
    int pad4C;
} CellEntry;

typedef struct {
    int pad0;
    int f4;
    int f8;
    int padC;
    int f10;
    int pad14;
    int f18;
    int f1C;
    int pad20;
    int f24;
} CellPlayer;

extern "C" {
extern void* memset(void*, int, int);
extern void String_Copy(char*, const char*);
extern char* Net_FormatIPv4(unsigned int);
extern int SFOLobby_NoInstance(void);
extern CellPlayer* func_0044F0C0(char*, int);
extern int func_00450A90(char*, int, int);
extern void LobbyArray_Append(char*, void*);
extern void SFOLobby_CacheAccount(char*, int, char*, unsigned int, CellSub*);
extern void SFOLobby_SetError(char*, int, char*, int);
extern void LobbyArray_SetRefreshing(char*, int);
extern void LobbyArray_SetDirty(char*, int);
extern void LobbyArray_Copy(void*, char*);
extern char* D_00585E60;
extern char D_004C0D10[];
}

extern "C" void func_004487A0(int a0, int a1, int a2, CellInfo* info) {
    if (SFOLobby_NoInstance()) return;
    if (info->id >= 0 && info->status == 0) {
        CellEntry e;
        CellSub* sub;
        CellPlayer* p;
        memset(&e, 0, sizeof(e));
        e.id = info->id;
        String_Copy(e.name, info->name);
        e.f30 = 0;
        e.f34 = -1;
        e.f38 = -1;
        e.f3C = -1;
        e.f40 = -1;
        e.f44 = 5;
        e.f28 = 2;
        e.f24 = 3;
        sub = (CellSub*)info->sub;
        e.addr = Net_FormatIPv4(sub->ip);
        switch (info->kind[0]) {
        case 0:
            e.f24 = 3;
            break;
        case 1:
            e.f24 = 3;
            break;
        case 2:
            e.f24 = 2;
            break;
        case 3:
            e.f24 = 1;
            if (sub->host == info->id) e.f24 = 0;
            e.key = sub->key;
            p = func_0044F0C0(D_00585E60, e.key);
            if (p) {
                e.f30 = p->f24;
                e.f34 = p->f4;
                e.f38 = p->f8;
                e.f3C = p->f1C;
                e.f40 = p->f10;
                e.f44 = p->f18;
            }
            break;
        }
        if (!func_00450A90(D_00585E60 + 0xC4, e.id, 0))
            LobbyArray_Append(D_00585E60 + 0xC4, &e);
        {
            /* Preserve the host, entry id, and subrecord IP read order. */
            char* host = *(char* volatile*)&D_00585E60;
            char* nm = e.name;
            int eid = *(volatile int*)&e.id;
            unsigned int ip = *(volatile unsigned int*)&sub->ip;
            SFOLobby_CacheAccount(host, eid, nm, ip, sub);
        }
    }
    switch (info->status) {
    case 0:
    case 1:
        break;
    case -0x3DC:
    case -0x3DD:
    default:
        SFOLobby_SetError(D_00585E60, 1, D_004C0D10, 0x7E9);
        break;
    }
    if (info->flag) {
        LobbyArray_SetRefreshing(D_00585E60 + 0xC4, 0);
        LobbyArray_SetDirty(D_00585E60 + 0xC4, 1);
        if (*(int*)(D_00585E60 + 0x23E4))
            LobbyArray_Copy(*(void**)(D_00585E60 + 0x23E4), D_00585E60 + 0xC4);
        LobbyArray_Copy(D_00585E60 + 0x134, D_00585E60 + 0xC4);
    }
    *(CellInfo*)(D_00585E60 + 0x1050) = *info;
}
