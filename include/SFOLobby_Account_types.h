#ifndef SFOLOBBY_ACCOUNT_TYPES_H
#define SFOLOBBY_ACCOUNT_TYPES_H

/* The two fixed-width fields passed to the account submission helpers. */
typedef struct LobbyAccount {
    char pad0000[0x243D];
    char first[32];                /* 0x243D */
    char second[32];               /* 0x245D */
} LobbyAccount;

#endif
