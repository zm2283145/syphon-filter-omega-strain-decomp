/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Games: 4 files, 0044EBD0-0044EFF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044EBD0 */
#pragma push /* merge_units */
#include "types.h"
#define NULL 0
#pragma mpwc_relax on
typedef struct List44 {
    int unk0;
    int count;
} List44;
typedef struct Ent44 {
    int id;
    char pad4[0x20];
    int state;
    int time;
} Ent44;
typedef struct Obj44 {
    char pad0[0x39];
    unsigned char active;
    char pad3A[0x130 - 0x3A];
    int key;
} Obj44;
typedef struct Lobby44 {
    char pad0[0x118];
    List44 list;
    char pad120[0x2418 - 0x120];
    char name[1];
} Lobby44;
void Libc_Strcpy(char *, char *);
int SFOLobby_GetMillisecs(void);
Ent44 *SFOLobbyList_GetSlot(List44 *, int);
Obj44 *SFOLobby_FindAgentData(Lobby44 *, int);
void MediusGetGameInfo(char *, void *);
extern int D_00497860;
extern int D_00497878;
extern char D_004C0EF0;
extern int D_00585E50;
extern void SFOLobby_Callback_RefreshGameInfo(void);

typedef struct {
    char a[0x15];
    char b[0x13];
    int id;
} Msg44EBD0;

inline Ent44 *Find44(Lobby44 *l, int id) {
    int n = l->list.count;
    int j;
    Ent44 *e;
    for (j = 0; j < n; j++) {
        e = SFOLobbyList_GetSlot(&l->list, j);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}

void SFOLobby_CollectGameInfo(Lobby44 *arg0, List44 *arg1) {
    Msg44EBD0 msg;
    int now;
    int i;
    Ent44 *e;
    Obj44 *obj;
    int st;
    int eid;
    Ent44 *found;
    int id;
    int n;
    int j;
    int age;

    if (arg1 == NULL || arg1->count == 0) {
        return;
    }
    now = SFOLobby_GetMillisecs();
    if (now - D_00585E50 < D_00497860) {
        return;
    }
    D_00585E50 = now;
    for (i = 0; i < arg1->count; i++) {
        e = SFOLobbyList_GetSlot(arg1, i);
        st = e->state;
        eid = e->id;
        if (st == 3) {
            continue;
        }
        if (st == 2) {
            continue;
        }
        obj = SFOLobby_FindAgentData(arg0, eid);
        if (obj == NULL || obj->active == 0) {
            continue;
        }
        id = obj->key;
        if (id == 0) {
            found = NULL;
        } else {
            found = Find44(arg0, id);
        }
        age = 0x270F;
        if (found != NULL) {
            age = now - found->time;
        }
        if (found == NULL || D_00497878 < age) {
            id = obj->key;
            if (id != 0) {
                Libc_Strcpy(msg.a, &D_004C0EF0);
                Libc_Strcpy(msg.b, arg0->name);
                msg.id = id;
                MediusGetGameInfo(msg.a, SFOLobby_Callback_RefreshGameInfo);
            }
        }
    }
}
static inline void merge_flush_func_0044EBD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044EBD0 */

/* merge_units: begin func_0044EDC0 */
#pragma push /* merge_units */
typedef struct { int id; int f4; int f8; char name[0x18]; int f24; int f28; } E44EDC0;
typedef struct { int pad0; int count; } L44EDC0;
typedef struct {
    char p0[0x8C]; char l8C[0x1C]; char lA8[0x1C]; char lC4[0x1C]; char lE0[0x38];
    L44EDC0 list; char p120[0x22C4]; void* l23E4; void* l23E8; char p23EC[4]; void* l23F0; void* l23F4;
} S44EDC0;
extern int Libc_Memcmp(void*, void*, int);
extern int SFOLobby_GetMillisecs(void);
#if 0 /* merge_units */
extern void SFOLobby_RefreshGameInfo(S44EDC0*, void*, E44EDC0*);
#endif /* merge_units */
void SFOLobby_RefreshGameInfo(); /* merge_units */

#if 0 /* merge_units */
extern E44EDC0* SFOLobbyList_GetSlot(L44EDC0*, int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((E44EDC0 *)SFOLobbyList_GetSlot((List44 *)(a0), (a1))) /* merge_units */


extern void SFOLobbyList_Append(L44EDC0*, E44EDC0*);
extern void* memcpy(void*, const void*, int);
extern void* memset(void*, int, int);

static inline E44EDC0* Find44EDC0(L44EDC0* list, int id)
{
    int n;
    int i;
    E44EDC0* e;
    if (id == 0)
        return 0;
    n = list->count;
    for (i = 0; i < n; i++) {
        e = SFOLobbyList_GetSlot(list, i);
        if (id == e->id)
            return e;
    }
    return 0;
}

void SFOLobby_RefreshGameData(S44EDC0* s, int id, int a2, int a3, int a4, void* name)
{
    E44EDC0* e;
    unsigned char changed;
    E44EDC0 tmp;

    if (name && id) {
    e = Find44EDC0(&s->list, id);
    changed = 0;
    if (e) {
        if (e->f4 != a2 || e->f8 != a3 || e->f24 != a4 || Libc_Memcmp(e->name, name, 0x18) != 0) {
            e->f24 = a4;
            e->f4 = a2;
            changed = 1;
            e->f8 = a3;
            e->f28 = SFOLobby_GetMillisecs();
            memcpy(e->name, name, 0x18);
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.f24 = a4;
        tmp.id = id;
        tmp.f4 = a2;
        tmp.f8 = a3;
        tmp.f28 = SFOLobby_GetMillisecs();
        memcpy(tmp.name, name, 0x18);
        SFOLobbyList_Append(&s->list, &tmp);
        e = &tmp;
        changed = 1;
    }
    if (changed) {
        SFOLobby_RefreshGameInfo(s, s->lC4, e);
        SFOLobby_RefreshGameInfo(s, s->l8C, e);
        SFOLobby_RefreshGameInfo(s, s->lA8, e);
        SFOLobby_RefreshGameInfo(s, s->lC4, e);
        SFOLobby_RefreshGameInfo(s, s->lE0, e);
        SFOLobby_RefreshGameInfo(s, s->l23F0, e);
        SFOLobby_RefreshGameInfo(s, s->l23F4, e);
        SFOLobby_RefreshGameInfo(s, s->l23E4, e);
        SFOLobby_RefreshGameInfo(s, s->l23E8, e);
    }
    }
}
#undef SFOLobbyList_GetSlot /* merge_units */
static inline void merge_flush_func_0044EDC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044EDC0 */

/* merge_units: begin func_0044EFF0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int SFOLobbyList_SetUpdateFlag(char * , int);                         
#if 0 /* merge_units */
char * SFOLobbyList_GetSlot(char * , int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((char *)SFOLobbyList_GetSlot((List44 *)(a0), (a1))) /* merge_units */
                   

typedef struct { int f0; int f4; int f8; char pC[4]; int f10; char p14[4]; int f18; int f1C; char p20[4]; int f24; } PS0_0044EFF0;
void SFOLobby_RefreshGameInfo(int d0, char * arg1, PS0_0044EFF0 *arg2) {
    int temp_s1;
    int var_s0;
    char * temp_v0;

    if ((arg1 == NULL) || (temp_s1 = F_(arg1, 0x4, int), (temp_s1 == 0))) {
        return;
    }
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
            temp_v0 = SFOLobbyList_GetSlot(arg1, var_s0);
            if (F_(temp_v0, 0x48, int) == arg2->f0) {
                F_(temp_v0, 0x30, int) = arg2->f24;
                F_(temp_v0, 0x34, int) = arg2->f4;
                F_(temp_v0, 0x38, int) = arg2->f8;
                F_(temp_v0, 0x3C, int) = arg2->f1C;
                F_(temp_v0, 0x40, int) = arg2->f10;
                F_(temp_v0, 0x44, int) = arg2->f18;
                SFOLobbyList_SetUpdateFlag(arg1, 1);
            }
    }
}
#undef SFOLobbyList_GetSlot /* merge_units */
static inline void merge_flush_func_0044EFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044EFF0 */

/* merge_units: begin func_0044F0C0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int *SFOLobbyList_GetSlot(char * , int);
#endif /* merge_units */
#define SFOLobbyList_GetSlot(a0, a1) ((int *)SFOLobbyList_GetSlot((List44 *)(a0), (a1))) /* merge_units */

                    

int *SFOLobby_FindGameData(char * arg0, int arg1) {
    int *temp_v0;
    int temp_s1;
    int var_s0;

    if (arg1 == 0) {
        return NULL;
    }
    temp_s1 = F_(arg0, 0x11C, int);
    for (var_s0 = 0; var_s0 < temp_s1; var_s0++) {
        temp_v0 = SFOLobbyList_GetSlot(arg0 + 0x118, var_s0);
        if (arg1 == *temp_v0) {
            return temp_v0;
        }
    }
    return NULL;
}
#undef SFOLobbyList_GetSlot /* merge_units */
static inline void merge_flush_func_0044F0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044F0C0 */
