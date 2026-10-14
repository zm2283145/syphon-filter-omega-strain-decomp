/*
 * main/SFOLobby_Cell: SFOLobby_Cell.cc (42 files, 00447D90-0044B420)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
int strlen(const void *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_00447D90 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char * D_00585E60;

void func_00447D90(int d0, int d1, int d2, char * arg3) {
    int temp_a0;

    if (SFOLobby_NoInstance() == 0) {
        F_(D_00585E60, 0x224, int) = 1;
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -0x3DF:
        case -0x3DD:
        case -0x3DE:
        case -0x3DC:
            SFOLobby_SetError(D_00585E60, 1, "SFOLobby_Cell.cc", 0x9F1);
            break;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00447D90 */

/* merge_units: begin func_00447E30 */
#pragma push /* merge_units */
#pragma mpwc_relax on
extern char D_004C0D10;

#pragma push
#pragma opt_common_subs off
void func_00447E30(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    int temp_a0;
    signed char *var_a2;
    signed char *var_a1;
    int var_a0;

    if (SFOLobby_NoInstance() == 0) {
        F_(D_00585E60, 0x1F0, int) = 1;
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x9CC);
            break;
        }
        var_a0 = 0x15;
        var_a2 = arg3;
        temp_a3 = D_00585E60 + 0x1CEC;
        var_a1 = temp_a3;
        do {
            var_a0 -= 1;
            *var_a1 = *var_a2;
            var_a2 += 1;
            var_a1 += 1;
        } while (var_a0 > 0);
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00447E30 */

/* merge_units: begin func_00447F00 */
#pragma push /* merge_units */
typedef struct { char c[21]; } S21;
typedef struct { char c[32]; } S32;
typedef struct { char c[256]; } S256;
typedef struct { S21 name; int a; int b; int c; S32 d; S256 e; int f; } R47;
void func_00447F00(int d0, int d1, int d2, R47 *src) {
    if (SFOLobby_NoInstance() == 0) {
        R47 *d;
        *(int *)(D_00585E60 + 0x1EC) = 1;
        switch (src->a) {
        case 0:
        case -971:
            break;
        case -991:
        case -989:
        case -988:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x99F);
            break;
        }
        d = (R47 *)(D_00585E60 + 0x1394);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->c = src->c;
        d->d = src->d;
        d->e = src->e;
        d->f = src->f;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00447F00 */

/* merge_units: begin func_00448050 */
#pragma push /* merge_units */
typedef struct { S21 name; int a; int b; S32 c; int d; S32 e; S256 f; int g; } R48A;
void func_00448050(int d0, int d1, int d2, R48A *src) {
    if (SFOLobby_NoInstance() == 0) {
        R48A *d;
        *(int *)(D_00585E60 + 0x1EC) = 1;
        switch (src->a) {
        case 0:
            break;
        case -971:
            src->d = -1;
            break;
        case -991:
        case -989:
        case -988:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x970);
            break;
        }
        d = (R48A *)(D_00585E60 + 0x122C);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->c = src->c;
        d->d = src->d;
        d->e = src->e;
        d->f = src->f;
        d->g = src->g;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448050 */

/* merge_units: begin func_004481E0 */
#pragma push /* merge_units */
#pragma mpwc_relax on


void func_004481E0(int d0, int d1, int d2, char * arg3) {
    int temp_a0;

    if (SFOLobby_NoInstance() == 0) {
        F_(D_00585E60, 0x1DC, int) = 1;
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x941);
            break;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004481E0 */

/* merge_units: begin func_00448270 */
#pragma push /* merge_units */
#include "loose05_types.h"
#include "SFOLobby_Callback_types.h"

#if 0 /* merge_units */
extern SFOLobby* D_00585E60;
#endif /* merge_units */
#define D_00585E60 (*(SFOLobby **)&D_00585E60) /* merge_units */

extern int LobbyArray_Append(LobbyRecord1C* pool, const LobbyPoolResult* result);

/* Apply a successful result to the configured pool and record completion. */
void func_00448270(int unused0, int unused1, int unused2, const LobbyPoolResult* result)
{
    if (!SFOLobby_NoInstance()) {
        LobbyRecord1C* pool = &D_00585E60->pool70;
        if (pool->elemSize > 0) {
            if (result->status == 0)
                LobbyArray_Append(pool, result);
            if (result->complete == 1)
                D_00585E60->gotReply1F4 = 1;
        }
    }
}
#undef D_00585E60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00448270 */

/* merge_units: begin func_004482E0 */
#pragma push /* merge_units */
int LobbyArray_Append();
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
#pragma pop /* merge_units */
/* merge_units: end func_004482E0 */

/* merge_units: begin func_00448470 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern SFOLobby* D_00585E60;
#endif /* merge_units */
#define D_00585E60 (*(SFOLobby **)&D_00585E60) /* merge_units */


/* Mark the pending cell event when the lobby gate returns zero. */
void func_00448470(void)
{
    if (!SFOLobby_NoInstance())
        D_00585E60->gotReply21C = 1;
}
#undef D_00585E60 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00448470 */

/* merge_units: begin func_004484B0 */
#pragma push /* merge_units */
typedef struct { char c[200]; } S200;
typedef struct { S21 name; int a; int b; S200 data; int e8; char ec; } R48;
int func_00128C68();
/* the "%x" literal (0x004C0D28); retail places it 8-aligned, after 4 bytes of padding */
static char merge_str_004C0D28[] __attribute__((aligned(8))) = "%x";
void func_004484B0(int d0, int d1, int d2, R48 *src) {
    if (SFOLobby_NoInstance() == 0) {
        R48 *d;
        switch (src->a) {
        case 0: {
            int h[1];
            h[0] = 0;
            func_00128C68(src, merge_str_004C0D28, h);
            LobbyArray_Append(h[0], src);
            break;
        }
        case 1:
        case -991:
        case -989:
        case -988:
            break;
        }
        d = (R48 *)(D_00585E60 + 0x16DC);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->data = src->data;
        d->e8 = src->e8;
        d->ec = src->ec;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004484B0 */

/* merge_units: begin func_004485C0 */
#pragma push /* merge_units */
typedef struct { S21 name; int a; int b; S200 data; char e8; } R45;
const unsigned int D_004C0D30[2] = { 0x0, 0x0 };
void func_004485C0(int d0, int d1, int d2, R45 *src) {
    if (SFOLobby_NoInstance() == 0) {
        R45 *d;
        switch (src->a) {
        case 0:
            break;
        case 1:
            String_Copy(&src->data, &(*(char*)D_004C0D30));
            break;
        case -991:
        case -989:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x854);
            String_Copy(&src->data, &(*(char*)D_004C0D30));
            break;
        }
        strncpy(D_00585E60 + 0x2594, &src->data, 0xC8);
        d = (R45 *)(D_00585E60 + 0x15F0);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->data = src->data;
        d->e8 = src->e8;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004485C0 */

/* merge_units: begin func_00448700 */
#pragma push /* merge_units */
#pragma mpwc_relax on


void func_00448700(int d0, int d1, int d2, char * arg3) {
    int temp_a0;

    if (SFOLobby_NoInstance() == 0) {
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
        case -990:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x82A);
            break;
        }
        F_(D_00585E60, 0x220, int) = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448700 */

/* merge_units: begin func_004487A0 */
#pragma push /* merge_units */
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
extern char* Net_FormatIPv4(unsigned int);
extern CellPlayer* func_0044F0C0(char*, int);
extern int func_00450A90(char*, int, int);
#if 0 /* merge_units */
extern int LobbyArray_Append(char*, void*);
#endif /* merge_units */
#define LobbyArray_Append(a0, a1) (LobbyArray_Append((LobbyRecord1C *)(a0), (const LobbyPoolResult *)(a1))) /* merge_units */

extern void SFOLobby_CacheAccount(char*, int, char*, unsigned int, CellSub*);
extern void LobbyArray_SetDirty(char*, int);
extern void LobbyArray_Copy(void*, char*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

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
#undef LobbyArray_Append /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004487A0 */

/* merge_units: begin func_00448B70 */
#pragma push /* merge_units */
typedef struct { S21 name; int a; int b; int c; S32 d; int e; S32 f; S256 g; int h; signed char flag; } R4B;
void func_00448B70(int d0, int d1, int d2, R4B *src) {
    if (SFOLobby_NoInstance() == 0) {
        switch (src->a) {
        case 0:
            break;
        case 1:
            *(int *)(D_00585E60 + 0x1E0) = 1;
            return;
        case -989:
        case -991:
        case -988:
            break;
        }
        if (src->e >= 0) {
            R4B *d = (R4B *)(D_00585E60 + 0xCF8);
            d->name = src->name;
            d->a = src->a;
            d->b = src->b;
            d->c = src->c;
            d->d = src->d;
            d->e = src->e;
            d->f = src->f;
            d->g = src->g;
            d->h = src->h;
            d->flag = src->flag;
            *(int *)(D_00585E60 + 0x1E0) = 1;
        } else if (src->flag == 1) {
            *(int *)(D_00585E60 + 0x1E0) = 1;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448B70 */

/* merge_units: begin func_00448D10 */
#pragma push /* merge_units */
typedef struct { S21 name; int a; } R4D;
void func_00448D10(int d0, int d1, int d2, R4D *src) {
    if (SFOLobby_NoInstance() == 0) {
        R4D *d;
        *(int *)(D_00585E60 + 0x1D8) = 1;
        if (src->a != 0) SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x718);
        d = (R4D *)(D_00585E60 + 0xBF0);
        d->name = src->name;
        d->a = src->a;
        switch (src->a) {
        case 0:
            break;
        case -956:
            SFOLobby_SetError(D_00585E60, 0x2A, &D_004C0D10, 0x725);
            break;
        case -991:
        case -988:
        case -989:
        case -990:
        case -5:
        case -985:
            break;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448D10 */

/* merge_units: begin func_00448E30 */
#pragma push /* merge_units */
#pragma mpwc_relax on


typedef struct { char c[21]; } SCc21;
void func_00448E30(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    signed char *var_a1;
    signed char *var_a2;
    int var_a0;

    if (SFOLobby_NoInstance() == 0) {
        var_a0 = 0x15;
        var_a2 = arg3;
        F_(D_00585E60, 0x1D4, int) = 1;
        temp_a3 = D_00585E60 + 0xC0C;
        var_a1 = temp_a3;
        *(SCc21 *)(temp_a3) = *(SCc21 *)(arg3);
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448E30 */

/* merge_units: begin func_00448EB0 */
#pragma push /* merge_units */
typedef struct { S21 name; int a; int b; } R4E;
void func_00448EB0(int d0, int d1, int d2, R4E *src) {
    if (SFOLobby_NoInstance() == 0) {
        R4E *d;
        *(int *)(D_00585E60 + 0x1CC) = 1;
        switch (src->a) {
        case 0:
            break;
        case -992:
            SFOLobby_SetError(D_00585E60, 0x1C, &D_004C0D10, 0x6C1);
            break;
        case -970:
            SFOLobby_SetError(D_00585E60, 0x1A, &D_004C0D10, 0x6C6);
            break;
        case -989:
        case -988:
        case -991:
        default:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0D10, 0x6CE);
            break;
        }
        d = (R4E *)(D_00585E60 + 0xBD0);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00448EB0 */

/* merge_units: begin func_00448FF0 */
#pragma push /* merge_units */
typedef struct { char p0[0x1EC]; int done; char p1F0[0x103C]; char res[0x18]; int f1244; char p1248[0x11C0]; signed char busy; char p2409[0xF]; char name[0x68]; int f2480; } S449070;
char* func_00449070(S449070* s, int arg); /* gsynth: defined below */
#if 0 /* merge_units */
extern char* func_00449070(void*, int);
#endif /* merge_units */
#define func_00449070(a0, a1) (func_00449070((void *)(a0), (a1))) /* merge_units */

char* func_00448FF0(char* p, int id) {
    char* r;
    func_00451AE0(p);
    /* .set reorder barrier keeps the early-return arm */
    if (id < 0) { asm { .set reorder } return 0; }
    r = func_00449070(p, id);
    if (r == 0) return 0;
    if (((unsigned char*)p)[0x2564] == 0) return r + 0x20;
    return 0;
}
#undef func_00449070 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00448FF0 */

/* merge_units: begin func_00449070 */
#pragma push /* merge_units */
extern void func_00466C18(void*, void*);
extern int D_00497890;
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

extern char D_004C0D38[];
void func_00448050(); /* gsynth: address taken */
#define func_00448050 ((char *)func_00448050) /* merge_units */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
char* func_00449070(S449070* s, int arg)
{
    struct { char a[0x15]; char b[0x13]; int f58; int arg; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    String_Copy(req.b, s->name);
    req.arg = arg;
    req.f58 = s->f2480;
    func_00466C18(&req, func_00448050);
    s->f1244 = -0x3C6;
    h = Lobby_GetTime();
    s->done = 0;
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x683);
            break;
        }
    }
    s->busy = 0;
    return s->res;
}
#pragma pop
#undef func_00448050 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449070 */

/* merge_units: begin func_00449180 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct {
    char name[0x15];
    int a;
    int b;
    int c;
    char s1[0x20];
    int d;
    char s2[0x20];
    char s3[0x100];
    int e;
    char f;
} Info449A00;
typedef struct {
    char p0[0x1E0]; int done;
    char p1E4[0x68]; int f24C;
    char p250[0xAA8]; Info449A00 cur;
    Info449A00 last;
    char pFD8[0x1430]; signed char busy;
    char p2409[7]; int t0;
    char p2414[4]; char name[0x68];
    int f2480; int f2484;
    char p2488[0x100]; int f2588;
    char p258C[0xD0]; char b265C; char b265D;
} S449A00;
extern "C" int func_00449A00(S449A00* s); /* gsynth: defined below */
#pragma pop
typedef struct { char p0[0x1F0]; int done; char p1F4[0x58]; int f24C; char p250[0xC34]; int fE84; char pE88[0xE7C]; int f1D04; char p1D08[0x700]; signed char busy; char p2409[0xF]; char name[0x170]; int f2588; int f258C; char p2590[0xCC]; unsigned char f265C; unsigned char f265D; } S449180;
#if 0 /* merge_units */
extern int func_00449A00(S449180*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

extern int func_00466AD0(void*, void*);
extern int D_00497800;
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00447E30(); /* gsynth: address taken */
#define func_00447E30 ((char *)func_00447E30) /* merge_units */
int func_00449180(S449180* s)
{
    struct { char a[0x15]; char b[0x13]; int x; } req;
    int h;
    int last = s->f2588;
    int elapsed = Lobby_GetTime() - last;

    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->f265C == 0) {
        SFOLobby_SetError(s, 0x1F, D_004C0D10, 0x623);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = s->fE84;
    s->done = 0;
    s->f1D04 = -0x3C6;
    s->f24C = func_00466AD0(&req, func_00447E30);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x638);
        return 0;
    }
    s->busy = 1;
    h = Lobby_GetTime();
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x645);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x64D);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->f1D04 != 0) return 0;
    s->f2588 = 0;
    s->f258C = 0;
    s->f265D = 0;
    s->f265C = 0;
    return 1;
}
#undef func_00447E30 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449180 */

/* merge_units: begin func_00449360 */
#pragma push /* merge_units */
typedef struct {
    char p0[0xC4]; char fC4[0x70]; char f134[0x1D4 - 0x134]; int f1D4;
    char p1D8[0x24C - 0x1D8]; int f24C; char p250[0xC24 - 0x250]; int fC24;
    char pC28[0xE84 - 0xC28]; int fE84; char pE88[0x2408 - 0xE88];
    signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x68];
    int f2480; char p2484[0x255C - 0x2484]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C;
} S44A810;
int func_0044A810(S44A810* s, int id); /* gsynth: defined below */
typedef struct { char p0[0x1DC]; int done; char p1E0[0x6C]; int f24C; char p250[0x21B8]; signed char busy; char p2409[0xF]; char name[0x68]; int f2480; char p2484[0x104]; int f2588; int last; } S449360;
#if 0 /* merge_units */
extern int func_0044A810(S449360*, int);
#endif /* merge_units */
#define func_0044A810(a0, a1) (func_0044A810((void *)(a0), (a1))) /* merge_units */

extern int func_00467090(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_004481E0(); /* gsynth: address taken */
#define func_004481E0 ((char *)func_004481E0) /* merge_units */
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
int func_00449360(S449360* s, int a, int b, char* msg)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; char msg[0xC8]; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = a;
    req.y = b;
    strncpy(req.msg, msg, 0xC8);
    if (b == 1) func_0044A810(s, s->f2480);
    s->f24C = func_00467090(&req, func_004481E0);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x5ED);
        return 0;
    }
    h = Lobby_GetTime();
    s->done = 0;
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x5FB);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x603);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    s->f2588 = 0;
    s->last = 0;
    return 1;
}
#pragma pop
#undef func_004481E0 /* merge_units */
#undef func_0044A810 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449360 */

/* merge_units: begin func_00449510 */
#pragma push /* merge_units */
typedef struct { char p0[0x70]; char f70[0x184]; int done; char p1F8[0x54]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int t0; char p2414[4]; char name[0x20]; } S449510;
extern int func_00466FF0(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00448270(); /* gsynth: address taken */
#define func_00448270 ((char *)func_00448270) /* merge_units */
static inline int NonZero449510(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
#pragma opt_rotateloops off
int func_00449510(S449510* s)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; } req;
    LobbyArray_Clear(s->f70);
    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.x = 1;
    req.y = 0x100;
    s->done = 0;
    s->t0 = Lobby_GetTime();
    s->f24C = func_00466FF0(&req, func_00448270);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x5AC);
        return 0;
    }
    while (NonZero449510(s->done) ^ 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x5B8);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->t0, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x5C0);
            s->busy = 0;
            return 0;
        }
    }
    return 1;
}
#pragma pop
#undef func_00448270 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449510 */

/* merge_units: begin func_00449660 */
#pragma push /* merge_units */
typedef struct { char p0[0x224]; int done; char p228[0x24]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int t0; char p2414[4]; char name[0x20]; } S449660;
extern int func_00467138(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00447D90(); /* gsynth: address taken */
#define func_00447D90 ((char *)func_00447D90) /* merge_units */
static inline int NonZero449660(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
void func_00449660(S449660* s, int arg)
{
    struct { char a[0x15]; char b[0x13]; int arg; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.a, D_004C0D38);
    strncpy(req.b, s->name, 0x11);
    req.arg = arg;
    s->done = 0;
    s->f24C = func_00467138(&req, func_00447D90);
    if (s->f24C == 0) {
        s->t0 = Lobby_GetTime();
        while (NonZero449660(s->done) ^ 1) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (SFOLobby_Poll(s, s->t0, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0D10, 0x584);
                s->busy = 0;
                break;
            }
        }
    }
}
#pragma pop
#undef func_00447D90 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449660 */

/* merge_units: begin func_00449770 */
#pragma push /* merge_units */
typedef struct { char p0[0x1C]; int f1C; } E449770;
typedef struct { char p0[0x70]; char f70[4]; int n74; } S449770;
#if 0 /* merge_units */
extern int func_00449510(S449770*);
#endif /* merge_units */
#define func_00449510(a0) (func_00449510((void *)(a0))) /* merge_units */

#define LobbyArray_At(a0, a1) ((E449770 *)LobbyArray_At((a0), (a1))) /* merge_units */
#if 0 /* merge_units */
extern void func_00449660(S449770*, int);
#endif /* merge_units */
#define func_00449660(a0, a1) (func_00449660((void *)(a0), (a1))) /* merge_units */

extern unsigned char func_00452FF0(S449770*, int);
int func_00449770(S449770* s)
{
    int i;
    func_00451AE0(s);
    func_00449510(s);
    for (i = 0; i < s->n74; i++) {
        func_00449660(s, LobbyArray_At(s->f70, i)->f1C);
    }
    return func_00452FF0(s, 0) == 0;
}
#undef LobbyArray_At /* merge_units */
#undef func_00449510 /* merge_units */
#undef func_00449660 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449770 */

/* merge_units: begin func_00449800 */
#pragma push /* merge_units */
typedef struct {
    char p0[0xC4];
    char fC4[0x188];
    int f24C;           /* 0x24C */
    char p250[0xC34];
    int fE84;           /* 0xE84 */
    char pE88[0x1C8];
    char f1050[0x1D8];  /* 0x1050 */
    signed char f1228;  /* 0x1228 */
    char p1229[0x11DF];
    signed char busy;   /* 0x2408 */
    char p2409[7];
    int f2410;          /* 0x2410 */
    char p2414[0x174];
    int f2588;          /* 0x2588 */
    char p258C[0xD1];
    unsigned char f265D;
} S449D20;
int func_00449D20(S449D20* s, int wait); /* gsynth: defined below */
typedef struct { char p0[0x24C]; int f24C; char p250[0xE84 - 0x250]; int fE84; char pE88[0x15F0 - 0xE88]; char f15F0[0x20]; char f1610[0xC8]; signed char f16D8; char p16D9[0x2408 - 0x16D9]; signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x17C]; char out[0xC8]; } S44A290;
char* func_0044A290(S44A290* s); /* gsynth: defined below */
typedef struct { char p0[0x255C]; int state; char p2560[0x2C]; int last; } S449800;
#if 0 /* merge_units */
extern int func_00449D20(S449800*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(S449800*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

extern int D_00497818;
#pragma push
#pragma opt_common_subs off
void func_00449800(S449800* s, int arg1)
{
    int last = s->last;
    int dt = Lobby_GetTime() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->last = Lobby_GetTime();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->last = Lobby_GetTime();
    }
}
#pragma pop
#undef func_00449D20 /* merge_units */
#undef func_0044A290 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449800 */

/* merge_units: begin func_004498C0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int func_00466F50(char *, char *);                        
extern int D_004977E8;
#if 0 /* merge_units */
extern char D_004C0D38;
#endif /* merge_units */
#define D_004C0D38 (*(char*)&D_004C0D38) /* merge_units */

void func_004482E0(); /* gsynth: address taken */
#define func_004482E0 (*(char *)func_004482E0) /* merge_units */

#pragma push
#pragma opt_common_subs off
void func_004498C0(char * arg0) {
    struct { char name[0x15]; char ip[0x13]; int f58; int f5C; } sl;
    int temp_a0;
    int temp_s1;

    temp_s1 = F_(arg0, 0x2584, int);
    temp_a0 = Lobby_GetTime() - temp_s1;
    if ((temp_s1 == 0) || (D_004977E8 < temp_a0)) {
        memset(&sl, 0, 0x30);
        String_Copy(sl.name, &D_004C0D38);
        strncpy(sl.ip, arg0 + 0x2418, 0x11);
        sl.f58 = 1;
        sl.f5C = 0x3E7;
        F_(arg0, 0x24C, int) = func_00466F50(&sl, &func_004482E0);
        if (F_(arg0, 0x24C, int) != 0) {
            SFOLobby_SetError(arg0, 1, &D_004C0D10, 0x53F);
        }
        F_(arg0, 0x2584, int) = Lobby_GetTime();
    }
}
#pragma pop
#undef func_004482E0 /* merge_units */
#undef D_004C0D38 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004498C0 */

/* merge_units: begin func_004499A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "SFOLobby_Cell_types.h"

#if 0 /* merge_units */
extern int func_00449A00(LobbyCell* cell);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */


/* Refreshes the cell when it was never updated or the refresh interval has passed. */
void func_004499A0(LobbyCell* cell) {
    int last = cell->lastUpdate;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(cell);
    }
}
#undef func_00449A00 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004499A0 */

/* merge_units: begin func_00449A00 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
extern int func_004676F8(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

#define func_00448B70 ((char *)func_00448B70) /* merge_units */
}

extern "C" int func_00449A00(S449A00* s)
{
    struct { char a[0x15]; char b[0x13]; int x; int y; } req;
    int now = Lobby_GetTime();
    if (s->f2588 && now - s->f2588 < 50) return 1;
    s->f2588 = Lobby_GetTime();
    memset(&req, 0, sizeof(req));
    memset(&s->cur, 0, sizeof(s->cur));
    s->cur.b = -1;
    s->cur.d = -1;
    String_Copy(req.a, D_004C0D38);
    String_Copy(req.b, s->name);
    req.x = 1;
    req.y = 999;
    s->done = 0;
    s->t0 = Lobby_GetTime();
    s->f24C = func_004676F8(&req, func_00448B70);
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x4AE);
            s->f2484 = -1;
            s->busy = 0;
            s->b265D = 0;
            s->b265C = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->t0, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x4B9);
            s->f2484 = -1;
            s->busy = 0;
            s->b265D = 0;
            s->b265C = 0;
            return 0;
        }
    }
    s->busy = 0;
    s->last = s->cur;
    if (s->last.e == 1 || s->last.e == -1) {
        s->f2484 = -1;
        s->b265D = 0;
        s->b265C = 0;
    } else if (s->last.e == 0) {
        s->f2484 = s->last.b;
        if (s->last.d == s->f2480) {
            s->b265C = 1;
            s->b265D = 1;
        } else if (s->last.d >= 0) {
            s->b265C = 0;
            s->b265D = 1;
        } else {
            s->b265C = 0;
            s->b265D = 0;
            return 0;
        }
    } else {
        s->f2484 = -1;
        s->b265C = 0;
        s->b265D = 0;
        return 0;
    }
    return 1;
}
#undef func_00448B70 /* merge_units */
#undef D_004C0D10 /* merge_units */
/* merge_units: flush this C++ function's deferred code generation while still in C++ mode */
static inline void merge_flush_00449A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00449A00 */

/* merge_units: begin func_00449D20 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_00449A00(S449D20*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

extern int func_00467BE0(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_004487A0(); /* gsynth: address taken */
#define func_004487A0 ((char *)func_004487A0) /* merge_units */
int func_00449D20(S449D20* s, int wait)
{
    struct { char a[0x18]; int x; int y; int z; } req;
    int last = s->f2588;
    int elapsed = Lobby_GetTime() - last;

    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->f265D == 0)
        return 1;
    LobbyArray_Clear(s->fC4);
    LobbyArray_SetRefreshing(s->fC4, 0);
    last = s->f2588;
    elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(s);
    if (s->fE84 < 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x44D);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    memset(s->f1050, 0, 0x1DC);
    s->f2410 = Lobby_GetTime();
    String_Copy(req.a, D_004C0D38);
    req.x = s->fE84;
    req.y = 0;
    req.z = 0;
    s->f24C = func_00467BE0(&req, func_004487A0);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x460);
        return 0;
    }
    if (wait) {
        while (s->f1228 != 1) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (s->f24C != 0) {
                SFOLobby_SetError(s, 1, D_004C0D10, 0x46D);
                s->busy = 0;
                return 0;
            }
            if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0D10, 0x475);
                s->busy = 0;
                return 0;
            }
        }
    }
    return 1;
}
#undef func_004487A0 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449D20 */

/* merge_units: begin func_00449F40 */
#pragma push /* merge_units */
typedef struct { char p0[0x1EC]; int done; char p1F0[0x5C]; int f24C; char p250[0x1144]; char f1394[0x18]; int f13AC; char p13B0[0xAF8]; int f1EA8; char p1EAC[0x55C]; signed char busy; char p2409[0xF]; char name[0x20]; } S449F40;
extern int func_00466B70(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00447F00(); /* gsynth: address taken */
#define func_00447F00 ((char *)func_00447F00) /* merge_units */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
char* func_00449F40(S449F40* s, char* arg1)
{
    struct { char f30[0x15]; char f45[0x13]; int f58; char f5C[0x20]; } req;
    int h;

    memset(&req, 0, sizeof(req));
    String_Copy(req.f30, D_004C0D38);
    String_Copy(req.f45, s->name);
    String_Copy(req.f5C, arg1);
    req.f58 = s->f1EA8;
    s->f24C = func_00466B70(&req, func_00447F00);
    h = Lobby_GetTime();
    s->done = 0;
    s->f13AC = -0x3C6;
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x3D4);
            break;
        }
    }
    s->busy = 0;
    return s->f1394;
}
#pragma pop
#undef func_00447F00 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00449F40 */

/* merge_units: begin func_0044A060 */
#pragma push /* merge_units */
char* func_0044A060(LobbyCell* cell) {
    return cell->unk2594;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044A060 */

/* merge_units: begin func_0044A070 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_00449A00(LobbyCell* cell);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */


/* Refresh a stale cell and return its embedded object at +0xE8C. */
void* func_0044A070(LobbyCell* cell)
{
    int last = cell->lastUpdate;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed)
        func_00449A00(cell);
    return cell->unk0E8C;
}
#undef func_00449A00 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A070 */

/* merge_units: begin func_0044A0D0 */
#pragma push /* merge_units */
typedef struct { char p0[0xC4]; char listA[0x70]; char listB[0x2428]; int state; char p2560[0x2C]; int last; } S44A0D0;
#if 0 /* merge_units */
extern int func_00449A00(S44A0D0*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449D20(S44A0D0*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(S44A0D0*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00450A90(void*, int, int);
#endif /* merge_units */
#define func_00450A90(a0, a1, a2) (func_00450A90((void *)(a0), (a1), (a2))) /* merge_units */

static inline void Tick44A0D0(S44A0D0* s, int arg1)
{
    int last = s->last;
    int dt = Lobby_GetTime() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->last = Lobby_GetTime();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->last = Lobby_GetTime();
    }
}
#pragma push
int func_0044A0D0(S44A0D0* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44A0D0(s, 1);
    }
    if (func_00450A90(s->listB, key, 0)) return 1;
    return func_00450A90(s->listA, key, 0) != 0;
}
#pragma pop
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef func_00450A90 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A0D0 */

/* merge_units: begin func_0044A1D0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_00449A00(LobbyCell* cell);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */


/* Returns byte +0x265C after refreshing the cell if it is stale. */
int func_0044A1D0(LobbyCell* cell) {
    int last = cell->lastUpdate;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(cell);
    }
    return cell->unk265C;
}

/* Returns byte +0x265D after refreshing the cell if it is stale. */
int func_0044A230(LobbyCell* cell) {
    int last = cell->lastUpdate;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(cell);
    }
    return cell->unk265D;
}
#undef func_00449A00 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A1D0 */

/* merge_units: begin func_0044A290 */
#pragma push /* merge_units */
extern int func_004671D8(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_004485C0(); /* gsynth: address taken */
#define func_004485C0 ((char *)func_004485C0) /* merge_units */
char* func_0044A290(S44A290* s)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; int f30; } req;

    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, D_004C0D38);
    String_Copy(req.f15, s->name);
    req.f28 = s->fE84;
    req.f2C = 1;
    req.f30 = 1;
    s->f2410 = Lobby_GetTime();
    memset(s->f15F0, 0, 0xEC);
    s->f24C = func_004671D8(&req, func_004485C0);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x2FA);
        return 0;
    }
    s->busy = 1;
    while (s->f16D8 != 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x305);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x30D);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    memset(s->out, 0, 0xC8);
    strncpy(s->out, s->f1610, 0xC7);
    return s->out;
}
#undef func_004485C0 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A290 */

/* merge_units: begin func_0044A420 */
#pragma push /* merge_units */
typedef struct { char p0[0x21C]; int f21C; int f220; char p224[0x24C - 0x224]; int f24C; char p250[0x16DC - 0x250]; char f16DC[0xEC]; signed char f17C8; char p17C9[0x2410 - 0x17C9]; int f2410; char p2414[4]; char name[0x17C]; char out[0xC8]; } S44A420;
typedef struct { int f0; int count; char p8[8]; int f10; int f14; signed char f18; } List44A420;
extern int func_00443100(S44A420*, char*, int);
#if 0 /* merge_units */
extern int func_00452FF0(S44A420*, int);
#endif /* merge_units */
#define func_00452FF0(a0, a1) ((int)func_00452FF0((void *)(a0), (a1))) /* merge_units */

extern List44A420* LobbyArray_ctor(List44A420*);
extern void LobbyArray_Init(List44A420*, int, int, int);
#define LobbyArray_At(a0, a1) ((int *)LobbyArray_At((a0), (a1))) /* merge_units */
extern void func_0044F970(List44A420*, int);
extern int func_00467838(void*, void*);
extern int func_004673C8(void*, void*);
extern int func_00467278(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

extern char D_004C0D28[];
void func_004484B0(); /* gsynth: address taken */
#define func_004484B0 ((char *)func_004484B0) /* merge_units */
#if 0 /* merge_units */
void func_00448470(); /* gsynth: address taken */
#endif /* merge_units */

#define func_00448470 ((char *)func_00448470) /* merge_units */
void func_00448700(); /* gsynth: address taken */
#define func_00448700 ((char *)func_00448700) /* merge_units */
#pragma push
#pragma opt_common_subs off
int func_0044A420(S44A420* s, char* msg)
{
    List44A420 list;
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; } req1;
    struct { char f0[0x15]; char f15[0x13]; int f28; } req2;
    struct { char f0[0x15]; char f15[0x11]; char f26[0xC8]; } req3;
    int i;

    func_00451AE0();
    if (func_00443100(s, msg, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0D10, 0x268);
        return 0;
    }
    LobbyArray_ctor(&list);
    LobbyArray_Init(&list, 0x20, 0, 0xF0);
    memset(&req1, 0, sizeof(req1));
    sprintf(req1.f0, D_004C0D28, &list);
    String_Copy(req1.f15, s->name);
    req1.f28 = 1;
    req1.f2C = 0x1E;
    s->f2410 = Lobby_GetTime();
    memset(s->f16DC, 0, 0xF0);
    s->f24C = func_00467838(&req1, func_004484B0);
    if (s->f24C == 0) {
        while (s->f17C8 != 1) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0)
                break;
        }
    }
    for (i = 0; i < list.count; i++) {
        int* e = LobbyArray_At(&list, i);
        memset(&req2, 0, sizeof(req2));
        String_Copy(req2.f0, D_004C0D38);
        String_Copy(req2.f15, s->name);
        req2.f28 = e[7];
        s->f2410 = Lobby_GetTime();
        s->f21C = 0;
        s->f24C = func_004673C8(&req2, func_00448470);
        if (s->f24C == 0) {
            while ((s->f21C != 0) ^ 1) {
                SFOLobby_CallUpdateHook(s, 0, 0);
                if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
                    i = 0x3E7;
                    break;
                }
            }
        }
    }
    memset(&req3, 0, sizeof(req3));
    String_Copy(req3.f0, D_004C0D38);
    String_Copy(req3.f15, s->name);
    strncpy(req3.f26, msg, 0xC7);
    s->f220 = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00467278(&req3, func_00448700);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x2BB);
        func_0044F970(&list, -1);
        return 0;
    }
    while ((s->f220 != 0) ^ 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x2C6);
            func_0044F970(&list, -1);
            return 0;
        }
    }
    memset(s->out, 0, 0xC8);
    strncpy(s->out, msg, 0xC7);
    if (func_00452FF0(s, 0)) {
        func_0044F970(&list, -1);
        return 0;
    }
    func_0044F970(&list, -1);
    return 1;
}
#pragma pop
#undef LobbyArray_At /* merge_units */
#undef func_004484B0 /* merge_units */
#undef func_00448470 /* merge_units */
#undef func_00448700 /* merge_units */
#undef func_00452FF0 /* merge_units */
#undef D_004C0D10 /* merge_units */
#undef func_00448470 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A420 */

/* merge_units: begin func_0044A800 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_0044A810(LobbyCell* cell, int value);
#endif /* merge_units */
#define func_0044A810(a0, a1) (func_0044A810((void *)(a0), (a1))) /* merge_units */


int func_0044A800(LobbyCell* cell) {
    return func_0044A810(cell, cell->unk2480);
}
#undef func_0044A810 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A800 */

/* merge_units: begin func_0044A810 */
#pragma push /* merge_units */
#pragma inline_depth(8)

#if 0 /* merge_units */
extern int func_00449A00(S44A810*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449D20(S44A810*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449180(S44A810*);
#endif /* merge_units */
#define func_00449180(a0) (func_00449180((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(S44A810*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00450A90(void*, int, int);
#endif /* merge_units */
#define func_00450A90(a0, a1, a2) (func_00450A90((void *)(a0), (a1), (a2))) /* merge_units */

extern int func_00466E08(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00448E30(); /* gsynth: address taken */
#define func_00448E30 ((char *)func_00448E30) /* merge_units */

static inline void Tick44A810(S44A810* s, int arg1)
{
    int last = s->f258C;
    int dt = Lobby_GetTime() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->f258C = Lobby_GetTime();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->f258C = Lobby_GetTime();
    }
}
static inline unsigned char Known44A810(S44A810* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44A810(s, 1);
    }
    if (func_00450A90(s->f134, key, 0)) return 1;
    return func_00450A90(s->fC4, key, 0) != 0;
}
static inline int Online44A810(S44A810* s)
{
    int last = s->f2588;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265C;
}
int func_0044A810(S44A810* s, int id)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; int f2C; } req;

    func_00451AE0();
    s->f2588 = 0;
    s->f258C = 0;
    func_00449A00(s);
    func_00449D20(s, 1);
    if (id < 0 || !Known44A810(s, id, 1)) {
        SFOLobby_SetError(s, 0x1D, D_004C0D10, 0x1E4);
        return 0;
    }
    if (id != s->f2480 && !Online44A810(s)) {
        SFOLobby_SetError(s, 0x1F, D_004C0D10, 0x1EB);
        return 0;
    }
    if (!Online44A810(s) || id != s->f2480) {
        memset(&req, 0, sizeof(req));
        String_Copy(req.f0, D_004C0D38);
        String_Copy(req.f15, s->name);
        req.f28 = id;
        req.f2C = s->fE84;
        s->f1D4 = 0;
        s->f2410 = Lobby_GetTime();
        s->f24C = func_00466E08(&req, func_00448E30);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x203);
            return 0;
        }
        s->busy = 1;
        while (s->f1D4 == 0) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (s->f24C != 0) {
                SFOLobby_SetError(s, 1, D_004C0D10, 0x20E);
                s->busy = 0;
                return 0;
            }
            if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0D10, 0x216);
                s->busy = 0;
                return 0;
            }
        }
        s->busy = 0;
        if (s->fC24 != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x21F);
            return 0;
        }
        s->f2588 = 0;
        s->f258C = 0;
        func_00449A00(s);
        func_00449D20(s, 0);
    } else if (Online44A810(s) && id == s->f2480 && !func_00449180(s)) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x231);
        return 0;
    }
    return 1;
}
#undef func_00448E30 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_00449180 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef func_00450A90 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044A810 */

/* merge_units: begin func_0044AC10 */
#pragma push /* merge_units */
#pragma inline_depth(8)
typedef struct {
    char p0[0x74]; int f74; char p78[0xC4 - 0x78]; char fC4[0x70]; char f134[0x1D4 - 0x134]; int f1D4;
    int f1D8; char p1DC[0x24C - 0x1DC]; int f24C; char p250[0xC08 - 0x250]; int fC08; char pC0C[0xC24 - 0xC0C]; int fC24;
    char pC28[0xE84 - 0xC28]; int fE84; char pE88[4]; char fE8C[0x2408 - 0xE8C];
    signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x68];
    int f2480; char p2484[0x255C - 0x2484]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C;
} S44AC10;
#if 0 /* merge_units */
extern int func_00449A00(S44AC10*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449D20(S44AC10*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449510(S44AC10*);
#endif /* merge_units */
#define func_00449510(a0) (func_00449510((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern unsigned char func_00452FF0(S44AC10*, int);
#endif /* merge_units */
#define func_00452FF0(a0, a1) (func_00452FF0((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(S44AC10*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00450A90(void*, int, int);
#endif /* merge_units */
#define func_00450A90(a0, a1, a2) (func_00450A90((void *)(a0), (a1), (a2))) /* merge_units */

extern int func_00466EA8(void*, void*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

void func_00448D10(); /* gsynth: address taken */
#define func_00448D10 ((char *)func_00448D10) /* merge_units */

static inline void Tick44AC10(S44AC10* s, int arg1)
{
    int last = s->f258C;
    int dt = Lobby_GetTime() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->f258C = Lobby_GetTime();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->f258C = Lobby_GetTime();
    }
}
static inline unsigned char Known44AC10(S44AC10* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44AC10(s, 1);
    }
    if (func_00450A90(s->f134, key, 0)) return 1;
    return func_00450A90(s->fC4, key, 0) != 0;
}
static inline int Online44AC10(S44AC10* s)
{
    int last = s->f2588;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265C;
}
int func_0044AC10(S44AC10* s, int id)
{
    struct { char f0[0x15]; char f15[0x13]; int f28; char f2C[0xC8]; } req;

    func_00451AE0();
    func_00449A00(s);
    if (id < 0) {
        SFOLobby_SetError(s, 0x1D, D_004C0D10, 0x161);
        return 0;
    }
    if (!Online44AC10(s)) {
        SFOLobby_SetError(s, 0x1F, D_004C0D10, 0x169);
        return 0;
    }
    if (Known44AC10(s, id, 1)) {
        SFOLobby_SetError(s, 0x1E, D_004C0D10, 0x170);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f0, D_004C0D38);
    String_Copy(req.f15, s->name);
    req.f28 = id;
    strncpy(req.f2C, s->fE8C, 0xC8);
    s->f1D8 = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00466EA8(&req, func_00448D10);
    if (s->f24C != 0) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x183);
        return 0;
    }
    while (s->f1D8 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 1, D_004C0D10, 0x18E);
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x196);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->fC08 < 0) {
        if (func_00452FF0(s, 0) == 0x2A) {
            func_00449510(s);
            if (s->f74 != 0) {
                SFOLobby_SetError(s, 0x3F, D_004C0D10, 0x1A6);
            }
            return 0;
        }
        SFOLobby_SetError(s, 1, D_004C0D10, 0x1AB);
        return 0;
    }
    func_00451AE0(s);
    return 1;
}
#undef func_00448D10 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_00449510 /* merge_units */
#undef func_00452FF0 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef func_00450A90 /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044AC10 */

/* merge_units: begin func_0044AF60 */
#pragma push /* merge_units */
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
typedef struct { char p0[0x1CC]; int done; char p1D0[0x7C]; int f24C; char p250[0x21B8]; signed char busy; char p2409[7]; int f2410; char p2414[4]; char name[0x14C]; unsigned char b2564; } S44AF60;
#if 0 /* merge_units */
extern int func_00443100(S44AF60*, char*, int);
#endif /* merge_units */
#define func_00443100(a0, a1, a2) (func_00443100((void *)(a0), (a1), (a2))) /* merge_units */

extern int func_00466A28(void*, void*);
extern int func_00476998(void);
#if 0 /* merge_units */
extern char* func_00449F40(S44AF60*, char*);
#endif /* merge_units */
#define func_00449F40(a0, a1) (func_00449F40((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_0044A420(S44AF60*, char*);
#endif /* merge_units */
#define func_0044A420(a0, a1) (func_0044A420((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449A00(S44AF60*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

#define D_004C0D30 ((char *)D_004C0D30) /* merge_units */
void func_00448EB0(); /* gsynth: address taken */
#define func_00448EB0 ((char *)func_00448EB0) /* merge_units */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
int func_0044AF60(S44AF60* s, char* arg1)
{
    struct { char f30[0x15]; char f45[0x13]; int f58; char f5C[0x20]; } req;

    func_00451AE0();
    if (strlen(arg1) > 0x20) {
        SFOLobby_SetError(s, 0x1B, D_004C0D10, 0xEB);
        return 0;
    }
    if (*(int*)(func_00449F40(s, arg1) + 0x18) == 0) {
        SFOLobby_SetError(s, 0x1A, D_004C0D10, 0xF1);
        return 0;
    }
    if (func_00443100(s, arg1, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0D10, 0xF7);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f30, D_004C0D38);
    String_Copy(req.f45, s->name);
    strncpy(req.f5C, arg1, 0x20);
    req.f58 = func_00476998();
    s->done = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00466A28(&req, func_00448EB0);
    SFOLobby_SetError(s, 0, D_004C0D10, 0x113);
    s->busy = 1;
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0D10, 0x123);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (s->b2564)
        return 0;
    func_0044A420(s, D_004C0D30);
    func_00449A00(s);
    return 1;
}
#pragma pop
#undef func_00448EB0 /* merge_units */
#undef func_00443100 /* merge_units */
#undef func_00449F40 /* merge_units */
#undef func_0044A420 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef D_004C0D10 /* merge_units */
#undef D_004C0D30 /* merge_units */
#undef strlen /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044AF60 */

/* merge_units: begin func_0044B180 */
#pragma push /* merge_units */
#pragma mpwc_relax on

void func_00453FE0(char*);
#if 0 /* merge_units */
int func_00449A00(char*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int func_00449D20(char*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_0044A290(char*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

void func_00451B30(char*);
void func_00453FA0(char*, char*);
void func_0044EBD0(char*, char*);
void func_0044D700(char*, int);
#if 0 /* merge_units */
extern char D_004C0D38;
#endif /* merge_units */
#define D_004C0D38 (*(char*)&D_004C0D38) /* merge_units */

#define func_004482E0 (*(char *)func_004482E0) /* merge_units */

typedef struct { char p0[0xC4]; char c4[0x188]; int f24C; char p250[0x2409-0x250]; unsigned char f2409; char p240A[0x2418-0x240A]; char ip[0x255C-0x2418]; int st; char p2560[0x2584-0x2560]; int t84; int t88; int t8C; } Cell;
void func_0044B180(Cell * c) { char* arg0 = (char*)c;
    struct { char name[0x15]; char ip[0x13]; int f58; int f5C; } sl;
    int temp_a0;
    int temp_s1;

    int st = c->st;
    if (st == 7 && c->f2409 == 0) {
        func_00453FE0(arg0);
        temp_s1 = c->t88;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if ((temp_s1 == 0) || (D_00497800 < temp_a0)) {
            func_00449A00(arg0);
        }
        temp_s1 = c->t8C;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if (c->st == 7) {
            if ((temp_s1 == 0) || (D_00497800 < temp_a0)) {
                func_00449D20(arg0, 0);
                func_0044A290(arg0);
                c->t8C = Lobby_GetTime();
            }
        } else {
            if ((temp_s1 == 0) || (D_00497818 < temp_a0)) {
                func_00449D20(arg0, 0);
                c->t8C = Lobby_GetTime();
            }
        }
        temp_s1 = c->t84;
        temp_a0 = Lobby_GetTime() - temp_s1;
        if ((temp_s1 == 0) || (D_004977E8 < temp_a0)) {
            memset((char*)&sl, 0, 0x30);
            String_Copy(sl.name, &D_004C0D38);
            strncpy(sl.ip, arg0 + 0x2418, 0x11);
            sl.f58 = 1;
            sl.f5C = 0x3E7;
            c->f24C = func_00466F50((char*)&sl, &func_004482E0);
            if (c->f24C != 0) {
                SFOLobby_SetError(arg0, 1, &D_004C0D10, 0x53F);
            }
            c->t84 = Lobby_GetTime();
        }
        func_00451B30(arg0);
        func_00453FA0(arg0, arg0 + 0xC4);
        func_0044EBD0(arg0, arg0 + 0xC4);
        func_0044D700(arg0, 0);
    }
}
#undef func_004482E0 /* merge_units */
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef D_004C0D38 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044B180 */

/* merge_units: begin func_0044B370 */
#pragma push /* merge_units */
typedef struct {
    char p0[0x70]; char f70[0xE84 - 0x70]; int fE84; char pE88[0x1B38 - 0xE88];
    int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80; char p1B84[0x1EA4 - 0x1B84];
    int f1EA4; char p1EA8[0x23E4 - 0x1EA8]; void* f23E4; int p23E8; void* f23EC;
    char p23F0[0x255C - 0x23F0]; int state; char p2560[0x2588 - 0x2560];
    int f2588; int f258C; char p2590[0x265C - 0x2590]; unsigned char f265C; unsigned char f265D;
    char p265E[0x26A8 - 0x265E]; int f26A8;
} SLB;
#if 0 /* merge_units */
extern int func_00449A00(SLB*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449D20(SLB*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(SLB*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

extern void func_00452FC0(SLB*, int);
extern void func_00453FB0(SLB*);
extern void func_0044F810(void*);
extern void LobbyArray_Free(void*);
#if 0 /* merge_units */
extern void LobbyArray_Init(void*, int, int, int);
#endif /* merge_units */
#define LobbyArray_Init(a0, a1, a2, a3) (LobbyArray_Init((void *)(a0), (a1), (a2), (a3))) /* merge_units */

extern int func_00451ED0(SLB*, char*);
extern int func_004524C0(SLB*, char*, char*);
extern int func_00452050(SLB*, int, char*);
extern void func_00454010(char*);
extern void func_00454050(SLB*);
#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */

extern char D_004C0D40[];
static inline void ClearLists(SLB* s)
{
    if (s->f23E4) LobbyArray_Free(s->f23E4);
    s->f23E4 = 0;
    if (s->f23EC) LobbyArray_Free(s->f23EC);
    s->f23EC = 0;
}void func_0044B370(SLB* s)
{
    int st;
    func_00451AE0();
    st = s->state;
    if (st == 9) return;
    if (st == 7 || st == 10) {
        if (st != 10) s->state = 9;
        s->f2588 = 0;
        func_00453FB0(s);
        func_00452FC0(s, 0);
        func_0044F810(s->f70);
        ClearLists(s);
    }
}
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef LobbyArray_Init /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044B370 */

/* merge_units: begin func_0044B420 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_00449A00(SLB*);
#endif /* merge_units */
#define func_00449A00(a0) (func_00449A00((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int func_00449D20(SLB*, int);
#endif /* merge_units */
#define func_00449D20(a0, a1) (func_00449D20((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0044A290(SLB*);
#endif /* merge_units */
#define func_0044A290(a0) ((void)func_0044A290((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void LobbyArray_Init(void*, int, int, int);
#endif /* merge_units */
#define LobbyArray_Init(a0, a1, a2, a3) (LobbyArray_Init((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern char D_004C0D10[];
#endif /* merge_units */
#define D_004C0D10 ((char*)&D_004C0D10) /* merge_units */
static inline int Online2(SLB* s)
{
    int last = s->f2588;
    int elapsed = Lobby_GetTime() - last;
    if (last == 0 || D_00497800 < elapsed) {
        func_00449A00(s);
    }
    return s->f265D;
}
int func_0044B420(SLB* s, int mode, void* a, void* b)
{
    char key[0x60];
    char name[0x100];
    char path[0x40];

    func_00451AE0();
    if (s->state != 9) {
        SFOLobby_SetError(s, 1, D_004C0D10, 0x27);
        return 0;
    }
    func_00452FC0(s, mode);
    s->f23E4 = a;
    s->f23EC = b;
    LobbyArray_Init(s->f23EC, s->f1EA4, 0, 0x68);
    LobbyArray_Init(s->f23E4, 0x40, 0x20, 0x50);
    s->f2588 = 0;
    if (!func_00449A00(s)) {
        ClearLists(s);
        return 0;
    }
    func_00449D20(s, 1);
    func_0044A290(s);
    s->f2588 = 0;
    s->f258C = 0;
    if (Online2(s) && s->f26A8 != 3) {
        s->f26A8 = 0;
        func_00454010(key);
        String_Copy(name, D_004C0D30);
        sprintf(path, D_004C0D40, s->fE84);
        if (!func_00451ED0(s, path)) {
            if (!func_004524C0(s, path, name)) {
                SFOLobby_SetError(s, 0x17, D_004C0D10, 0x59);
                ClearLists(s);
                return 0;
            }
            if (!func_00452050(s, s->f1B38, key)) {
                SFOLobby_SetError(s, 0x16, D_004C0D10, 0x60);
                ClearLists(s);
                return 0;
            }
        } else if (!func_00452050(s, s->f1B80, key)) {
            if (!func_004524C0(s, path, name)) {
                SFOLobby_SetError(s, 0x17, D_004C0D10, 0x6C);
                ClearLists(s);
                return 0;
            }
            if (!func_00452050(s, s->f1B38, key)) {
                SFOLobby_SetError(s, 0x16, D_004C0D10, 0x73);
                ClearLists(s);
                return 0;
            }
        }
        s->f26A8 = 3;
    }
    func_00454050(s);
    s->state = 7;
    return 1;
}
#undef func_00449A00 /* merge_units */
#undef func_00449D20 /* merge_units */
#undef func_0044A290 /* merge_units */
#undef LobbyArray_Init /* merge_units */
#undef D_004C0D10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044B420 */
