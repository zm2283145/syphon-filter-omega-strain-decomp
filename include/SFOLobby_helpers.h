#ifndef SFOLOBBY_HELPERS_H
#define SFOLOBBY_HELPERS_H

/*
 * Functions shared by the SFOLobby_*.cc translation units (online lobby; the
 * types are in SFOLobby.h).
 * Declared once with C linkage, whatever the including block's language mode.
 * Object parameters are `void *`: each unit has its own (partial) view of the
 * lobby structures, and pointer parameters compile the same either way.
 */

#pragma push
#pragma cplusplus off

/* 0x00129360: strcpy-style copy; callers ignore the result. */
char *String_Copy(void *dst, const void *src);

/* 0x00451B00: record an error code with the source file and line.  The
   definition takes the code as `unsigned char`; callers pass an int. */
void SFOLobby_SetError(void *self, int err, const char *file, int line);

/* 0x004505C0: nonzero when no lobby instance exists.  Defined `(void)`, but
   the network callbacks call it with their own arguments still in a0..a3, so
   it is declared without a prototype. */
int SFOLobby_NoInstance();

/* 0x00451AE0: clear the lobby's error state (byte 0x2564) unless it is 5.
   Takes the lobby; some callers still have it in a0 and pass nothing, so no
   prototype. */
void func_00451AE0();

/* 0x00452FC0: set a lobby mode value (`(LobbyMain *self, int value)`); one
   caller passes only the lobby, so no prototype. */
void func_00452FC0();

/* 0x00443E70: the current time (Time_GetMilliseconds's result).  Defined returning
   `long long`; every caller declares and uses it as int. */
int Lobby_GetTime(void);

/* 0x00452F70: run the update hook while waiting for a request. */
void SFOLobby_CallUpdateHook(void *self, int a, int b);

/* 0x004534A0: poll a pending request; 0 on timeout. */
int SFOLobby_Poll(void *self, int start, int timeout, int flag);

/* LobbyArray: growable array of records. */
void LobbyArray_Clear(void *array);
void LobbyArray_SetRefreshing(void *array, int on);

/* 0x0044F290: the address of record `index` of a LobbyArray.  Blocks view the
   result as their own record type (a casting macro per block); one caller
   passes only the array, so no prototype. */
void *LobbyArray_At();

#pragma pop

#endif /* SFOLOBBY_HELPERS_H */
