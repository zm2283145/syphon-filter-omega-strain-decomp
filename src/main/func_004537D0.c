/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between SFOLobby_Main.cc (ends 0x004534A0) and GuiSubTitleDisplay.cc;
 * probably part of SFOLobby_Main.cc.
 */

#include "loose05_types.h"

extern int memset(void* dst, int value, int size); /* memset */

/* Resets the lobby object: clears the session block and the handles. */
int func_004537D0(SFOLobby* self) {
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
