#ifndef SFOLOBBY_CALLBACK_TYPES_H
#define SFOLOBBY_CALLBACK_TYPES_H

/* Lobby state object reached through the global pointer D_00585E60 (partial). */
typedef struct LobbyState {
    char pad000[0x180];
    int unk180;             /* 0x180 value reported by the callback (only set when > 0) */
    int unk184;             /* 0x184 set to 1 when that callback fires */
    char pad188[0x204 - 0x188];
    int unk204;             /* 0x204 set to 1 when the info callback fires */
    char pad208[0x2429 - 0x208];
    char name[1];           /* 0x2429 string copied from the callback info */
} LobbyState;

/* Info record passed as the fourth callback argument (partial). */
typedef struct LobbyCallbackInfo {
    char pad00[0x15];
    char name[0x2C - 0x15]; /* 0x15 */
    int unk2C;              /* 0x2C name is copied only when this is 0 */
} LobbyCallbackInfo;

/* Status result supplied as the fourth argument to lobby callbacks. */
typedef struct LobbyStatusResult {
    char pad00[0x15];
    signed char status;            /* 0x15 zero indicates success */
    char pad16[2];
    int value;                     /* 0x18 */
} LobbyStatusResult;

typedef struct LobbyPayloadResult {
    char pad00[0x15];
    signed char status;
    char pad16[2];
    char payload[0x9C];
} LobbyPayloadResult;

typedef struct LobbyPoolResult {
    char pad00[0x18];
    int status;                    /* 0x18 zero indicates success */
    char pad1C[0x110 - 0x1C];
    signed char complete;          /* 0x110 */
} LobbyPoolResult;

#endif
