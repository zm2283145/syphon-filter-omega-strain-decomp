#include "SFOLobby.h"
extern char D_004C0D58[]; /* DNAS start message */
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern char D_004C0D88[]; /* DNAS done message */
extern unsigned char D_00585E68;
void func_00443E60(char*);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int func_003A6670(int);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
int func_0010D050(void);
int func_0010CFF0(int, int);
void* memset(void*, int, unsigned int);
int func_1E68080(int, char*, unsigned short, int, unsigned char, char*, int*);
void DecodeKey_XorB3(char*, int);

/* DNAS authentication: switches the network mode (func_003A6670(2)), runs the DNAS
 * check with dnasArg/dnasData at a raised thread priority, and on success decodes
 * the returned password. On failure asks the update hook (event 3) whether to
 * continue anyway. */
int SFOLobby_DnasAuth(SFOLobby* self)
{
    int old;
    int r;

    self->dnasResult = 0;
    func_00443E60(D_004C0D58);
    SFOLobby_CallUpdateHook(self, 2, 2);
    if (func_003A6670(2) == 0) {
        SFOLobby_SetError(self, 5, D_004C0D70, 0x27A);
        return 0;
    }
    old = func_0010CFF0(func_0010D050(), 0x7F);
    if (old < 0)
        old = 2;
    memset(self->password, 0, 0x20);
    self->passwordLen = 0;
    self->dnasResult = func_1E68080(self->dnasArg, self->dnasData, self->dnasDataLen, 0, D_00585E68, self->password, &self->passwordLen);
    if (self->dnasResult != 0) {
        SFOLobby_SetError(self, 6, D_004C0D70, 0x289);
        func_0010CFF0(func_0010D050(), old);
        if (func_003A6670(1) == 0) {
            SFOLobby_SetError(self, 5, D_004C0D70, 0x28E);
            return 0;
        }
        r = 0;
        SFOLobby_CallUpdateHook(self, 3, (int)&r);
        return r == 1;
    }
    func_0010CFF0(func_0010D050(), old);
    if (func_003A6670(1) == 0) {
        SFOLobby_SetError(self, 5, D_004C0D70, 0x29B);
        return 0;
    }
    func_00443E60(D_004C0D88);
    DecodeKey_XorB3(self->password, 0);
    return 1;
}
