/*
 * main/SFOLobby_Main: 5 files, 004536B0-00453B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004536B0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x255C]; int mode; } S4536B0;
extern unsigned char D_00585FB8;
extern int SFOLobby_Poll(S4536B0*, int, int, int);
extern void SFOLobby_ConfigScreenIntel(S4536B0*);
extern void SFOLobby_ServerScreenIntel(S4536B0*);
extern void SFOLobby_AccountScreenIntel(S4536B0*);
extern void SFOLobby_LobbyScreenIntel(S4536B0*);
extern void SFOLobby_UpdateContacts(S4536B0*);
extern void SFOLobby_CellScreenIntel(S4536B0*);
extern void SFOLobby_MissionScreenIntel(S4536B0*);
extern void SFOLobby_GameIntel(S4536B0*);
void SFOLobby_Update(S4536B0* s) {
    if (D_00585FB8) return;
    D_00585FB8 = 1;
    if (s->mode != 0 && s->mode != 1) {
        if (!SFOLobby_Poll(s, 0, 0, 0)) {
            D_00585FB8 = 0;
            return;
        }
    }
    switch (s->mode) {
    case 1: SFOLobby_ConfigScreenIntel(s); break;
    case 2: SFOLobby_ServerScreenIntel(s); break;
    case 3: SFOLobby_AccountScreenIntel(s); break;
    case 5: SFOLobby_LobbyScreenIntel(s); break;
    case 6: SFOLobby_UpdateContacts(s); break;
    case 7: SFOLobby_CellScreenIntel(s); break;
    case 4: SFOLobby_MissionScreenIntel(s); break;
    case 10: SFOLobby_GameIntel(s); break;
    }
    D_00585FB8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004536B0 */

/* merge_units: begin func_004537D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Main.cc (ends 0x004534A0) and GuiSubTitleDisplay.cc;
 * probably part of SFOLobby_Main.cc.
 */

#include "loose05_types.h"

extern int memset(void* dst, int value, int size); /* memset */

/* Resets the lobby object: clears the session block and the handles. */
int SFOLobby_ResetConnectionFlags(SFOLobby* self) {
    int ret;

    ret = memset(self->sessionBlock, 0, 0x950);
    self->state = 0;
    self->connHandle = -1;
    self->gotConnect = 0;
    self->gotLogin = 0;
    self->gotReply194 = 0;
    self->gotReply198 = 0;
    self->gotReply19C = 0;
    self->gotReply1A0 = 0;
    self->gotReply1A4 = 0;
    self->gotReply1A8 = 0;
    self->gotReply1AC = 0;
    self->gotReply1B0 = 0;
    self->gotReply1B4 = 0;
    self->gotReply1B8 = 0;
    self->gotReply1BC = 0;
    self->gotReply1C0 = 0;
    self->gotAccountId = 0;
    self->gotAccountInfo = 0;
    self->gotReply1D0 = 0;
    self->gotReply1F8 = 0;
    self->gotReply1FC = 0;
    self->gotReply200 = 0;
    self->gotMyIp = 0;
    self->gotReply208 = 0;
    self->gotReply210 = 0;
    self->unk2660 = 0;
    self->list8CTime = 0;
    self->listA8Time = 0;
    self->accountName[0] = 0;
    self->accountId = -1;
    self->unk2484 = -1;
    self->busy = 0;
    self->unk2578 = 0;
    self->dnasArg = 0;
    self->dnasData[0] = 0;
    self->dnasDataLen = 0;
    self->loginReply.accountId = -1;
    self->reply314.id = -1;
    self->accountIdReply.accountId = -1;
    self->unkBEC = -1;
    self->buddyListReply.accountId = -1;
    self->unkD14 = -1;
    self->unkD3C = -1;
    self->unkE84 = -1;
    self->unkEAC = -1;
    self->unk126C = -1;
    self->unk13B0 = -1;
    self->unk13B4 = -1;
    self->unk14F8 = -1;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_004537D0 */

/* merge_units: begin func_004538D0 */
#pragma push /* merge_units */
typedef struct { char p0[0x23D8]; int h[11]; } S4538D0;
extern void LobbyArray_Free(int h);
extern void SFOLobbyList_FreeList(void* p);
static inline void Release4538D0(int* h) { int t = *h; if (t != 0) LobbyArray_Free(t); *h = 0; }
#pragma push
#pragma opt_common_subs off
void SFOLobby_FreeLists(S4538D0* s)
{
    char* b = (char*)s;
    Release4538D0(&s->h[0]); Release4538D0(&s->h[1]); Release4538D0(&s->h[2]); Release4538D0(&s->h[3]);
    Release4538D0(&s->h[4]); Release4538D0(&s->h[5]); Release4538D0(&s->h[6]); Release4538D0(&s->h[7]);
    Release4538D0(&s->h[8]); Release4538D0(&s->h[9]); Release4538D0(&s->h[10]);
    SFOLobbyList_FreeList(b + 0x70);
    SFOLobbyList_FreeList(b + 0xFC);
    SFOLobbyList_FreeList(b + 0x118);
    SFOLobbyList_FreeList(b + 0x8C);
    SFOLobbyList_FreeList(b + 0xA8);
    SFOLobbyList_FreeList(b + 0xC4);
    SFOLobbyList_FreeList(b + 0xE0);
    SFOLobbyList_FreeList(b + 0x134);
    SFOLobbyList_FreeList(b + 0x150);
    SFOLobbyList_FreeList(b);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_004538D0 */

/* merge_units: begin func_00453A50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after SFOLobby_Main.cc (ends 0x004534A0); probably part of it.
 */


extern int LobbyArray_Init(LobbyRecord1C* pool, int count, int grow, int elemSize);

/* Sets up the lobby's record pools (count, growth, element size). */
int SFOLobby_InitLists(SFOLobby* self) {
    LobbyArray_Init(&self->pool70, 32, 32, 276);
    LobbyArray_Init(&self->accountCache, 512, 0, 320);
    LobbyArray_Init(&self->pool118, 1024, 512, 44);
    LobbyArray_Init(&self->poolC4, 64, 32, 80);
    LobbyArray_Init(&self->buddyList, 64, 32, 80);
    LobbyArray_Init(&self->pool134, 64, 32, 80);
    return LobbyArray_Init(&self->pool150, 64, 32, 80);
}
#pragma pop /* merge_units */
/* merge_units: end func_00453A50 */

/* merge_units: begin func_00453B00 */
#pragma push /* merge_units */
typedef struct {
    char p0[0x1C]; char f1C[0x1C]; char f38[0x1C]; char f54[0x1C];
    char p70[0x180 - 0x70]; int f180;
    char p184[0x1EA8 - 0x184]; int f1EA8;
    char p1EAC[0x23DC - 0x1EAC]; void* f23DC;
    char p23E0[0x2404 - 0x23E0]; void* f2404;
    char p2408[0x255C - 0x2408]; int f255C;
    char p2560[4];
    unsigned char err;
} S453B00;
extern void SFOMGCL_Shutdown(int);
extern void SFOLobby_DisconnectAuthServer(S453B00*);
extern void MediusCloseBare(void);
extern void NetClose(void);
extern void SFOMGCL_Close_API(void);
#if 0 /* merge_units */
extern void LobbyArray_Free(void*);
#endif /* merge_units */
#define LobbyArray_Free(a0) (LobbyArray_Free((int)(a0))) /* merge_units */

extern void SFOLobby_NetDown(S453B00*);
extern void Iop_LoadEzNetModules(int);
#if 0 /* merge_units */
extern void SFOLobby_FreeLists(S453B00*);
#endif /* merge_units */
#define SFOLobby_FreeLists(a0) (SFOLobby_FreeLists((S4538D0 *)(a0))) /* merge_units */

extern void LobbyArray_Clear(void*);

void SFOLobby_Reset(S453B00* s, int full)
{
    if (s->f1EA8 > 0) {
        SFOMGCL_Shutdown(0);
        if (s->f180 > 0)
            SFOLobby_DisconnectAuthServer(s);
        if (s->f180 > 0)
            SFOLobby_DisconnectAuthServer(s);
        if (full) {
            MediusCloseBare();
            NetClose();
        }
        s->f1EA8 = 0;
        if (full)
            SFOMGCL_Close_API();
        if (s->f2404)
            LobbyArray_Free(s->f2404);
        s->f2404 = 0;
        if (s->f23DC)
            LobbyArray_Free(s->f23DC);
        s->f23DC = 0;
        s->f1EA8 = full ? 1 : -1;
    }
    if (full) {
        if (s->f1EA8) {
            if (s->f1EA8 == -1) {
                MediusCloseBare();
                SFOMGCL_Close_API();
                NetClose();
            }
            SFOLobby_NetDown(s);
            s->f1EA8 = 0;
        }
        Iop_LoadEzNetModules(0);
    }
    s->f180 = -1;
    SFOLobby_FreeLists(s);
    if (full) {
        LobbyArray_Clear(s->f1C);
        LobbyArray_Clear(s->f38);
        LobbyArray_Clear(s->f54);
    }
    s->f255C = 0;
    s->err = 0;
}
#undef LobbyArray_Free /* merge_units */
#undef SFOLobby_FreeLists /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00453B00 */
