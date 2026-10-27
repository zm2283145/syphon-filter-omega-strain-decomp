#ifndef SFOLOBBY_H
#define SFOLOBBY_H

/*
 * SFOLobby: the online lobby layer (SFOLobby_*.cc). It wraps the Medius online
 * SDK: every request starts with a MessageID string and the session key, is sent
 * with a reply callback, and the caller then polls (SFOLobby_GuiCallback/SFOLobby_Poll)
 * until the callback has set the matching gotReply* flag.
 *
 * The single instance is reached through the global D_00585E60 (callbacks) or a
 * self argument (everything else). Field names are descriptive guesses where only
 * the code is evidence; replyXXX / gotReplyXXX keep the offset in the name until
 * the Medius request behind them is identified.
 *
 * String symbols used throughout the lobby code:
 *   D_004C0E78, D_004C0EC0, D_004C0EF0, D_004C0F68, D_004C05C8  "1" (request MessageID)
 *   D_004C0CB0 "SFOLobby_Callback.cc"   D_004C0D70 "SFOLobby_Config.cc"
 *   D_004C0E80 "SFOLobby_Connect.cc"    D_004C0ED0 "SFOLobby_Contact.cc"
 *   D_004C0F00 "SFOLobby_Games.cc"      D_004C0F70 "SFOLobby_Lobby.cc"
 *   D_004C05D0 "SFOLobby_Servers.cc"    D_004C0FB0 "SFOLobby_Main.cc"
 *   D_004C0EE8, D_004C0F98 "%d"         D_004C0CD0 "{SFOLOBBY_SETTINGS}"
 *   D_004C0D58 "Pre DNAS"               D_004C0D88 "Post DNAS"
 *   D_004C0CC8 ""
 */

/* Growable array of fixed-size elements (SFOLobbyList_AllocList init, SFOLobbyList_Append append,
 * SFOLobbyList_GetSlot element at, SFOLobbyList_DeleteSlot remove at, SFOLobbyList_ClearList clear,
 * SFOLobbyList_ClearAndCompactList free). */
typedef struct LobbyArray {
    int capacity;                   /* 0x00 at least 5 */
    int count;                      /* 0x04 */
    int initialCapacity;            /* 0x08 */
    int grow;                       /* 0x0C capacity increment; <= 0 drops the oldest element instead */
    int elemSize;                   /* 0x10 */
    char* data;                     /* 0x14 */
    signed char dirty;              /* 0x18 set when the contents change */
    char refreshing;                /* 0x19 set while a refresh request is outstanding (SFOLobbyList_SetBusy) */
    unsigned char unique;           /* 0x1A append skips elements that compare equal */
} LobbyArray;

/* Medius MediusCallbackStatus values seen in reply StatusCode fields. */
enum MediusCallbackStatus {
    MediusSuccess = 0,
    MediusRequestAccepted = 2,
    MediusInvalidPassword = -978,
    MediusRequestDenied = -985,
    MediusDMEError = -987,
    MediusDBError = -988,
    MediusPlayerNotPrivileged = -989,
    MediusWMError = -991,
    MediusAccountLoggedIn = -997,
    MediusAccountNotFound = -998
};

/* Medius MediusPlayerStatus (buddy list entries). */
enum MediusPlayerStatus {
    MediusPlayerDisconnected = 0,
    MediusPlayerInAuthWorld = 1,
    MediusPlayerInChatWorld = 2,
    MediusPlayerInGameWorld = 3,
    MediusPlayerInOtherUniverse = 4
};

/* SFOLobby::state values. */
enum SFOLobbyState {
    SFOLOBBY_STATE_0 = 0,
    SFOLOBBY_STATE_NETWORK = 1,     /* network configuration (SFOLobby_ConfigScreenStart .. SFOLobby_ConfigScreenExit) */
    SFOLOBBY_STATE_ONLINE = 4,      /* per-frame update runs (SFOLobby_MissionScreenIntel) */
    SFOLOBBY_STATE_5 = 5,
    SFOLOBBY_STATE_CONTACTS = 6,    /* buddy list (SFOLobby_ContactScreenStart .. SFOLobby_ContactScreenExit) */
    SFOLOBBY_STATE_7 = 7,
    SFOLOBBY_STATE_IDLE = 9,        /* no mode active */
    SFOLOBBY_STATE_10 = 10
};

/* Common reply header: MessageID then StatusCode. */
typedef struct LobbyReply {
    char messageId[0x15];           /* 0x00 */
    char pad15[3];
    int statusCode;                 /* 0x18 MediusCallbackStatus */
} LobbyReply;

/* Reply carrying an id after the status (reply314). */
typedef struct LobbyIdReply {
    char messageId[0x15];           /* 0x00 */
    char pad15[3];
    int statusCode;                 /* 0x18 */
    int id;                         /* 0x1C -1 = none */
} LobbyIdReply;

/* One buddy-list reply record (callback SFOLobby_Callback_GetBuddyList). */
typedef struct LobbyBuddyReply {
    char messageId[0x15];           /* 0x00 */
    char pad15[3];
    int statusCode;                 /* 0x18 */
    int accountId;                  /* 0x1C */
    char accountName[0x20];         /* 0x20 */
    int playerStatus;               /* 0x40 MediusPlayerStatus */
    int unk44;                      /* 0x44 */
    int gameWorldId;                /* 0x48 */
    int rest[0x20];                 /* 0x4C */
    signed char endOfList;          /* 0xCC */
} LobbyBuddyReply;



/* buddyList element (0x50 bytes), built by the buddy-list reply callback SFOLobby_Callback_GetBuddyList. */
typedef struct LobbyBuddyEntry {
    int accountId;                  /* 0x00 */
    char name[0x20];                /* 0x04 */
    int location;                   /* 0x24 1 = in a game world, 2 = in a chat world, 3 = elsewhere/offline */
    int f28;                        /* 0x28 */
    char* f2C;                      /* 0x2C */
    int f30;                        /* 0x30 copied from the buddy's game (SFOLobby_FindGameData) */
    int f34;                        /* 0x34 */
    int f38;                        /* 0x38 */
    int f3C;                        /* 0x3C */
    int f40;                        /* 0x40 */
    int f44;                        /* 0x44 */
    int gameWorldId;                /* 0x48 */
    int f4C;                        /* 0x4C */
} LobbyBuddyEntry;

/* Account id lookup by name (SFOLobby_GetAgentID, callback SFOLobby_Callback_AccountGetID). */
typedef struct LobbyAccountIdReply {
    char messageId[0x15];           /* 0x00 */
    char pad15[3];
    int accountId;                  /* 0x18 */
    int statusCode;                 /* 0x1C */
} LobbyAccountIdReply;

typedef struct LobbyStatPair {
    signed char a;
    signed char b;
} LobbyStatPair;

/* 0xFC-byte per-player info block (cached per account in accountCache). */
typedef struct LobbyPlayerInfo {
    unsigned char b0, b1, b2, b3;   /* 0x00 */
    unsigned short h4, h6, h8, hA, hC, hE; /* 0x04 */
    int w10, w14, w18, w1C, w20, w24; /* 0x10 */
    LobbyStatPair pairs[0x60];      /* 0x28 */
    int wE8;                        /* 0xE8 */
    int wEC;                        /* 0xEC */
    int wF0;                        /* 0xF0 */
    int ip;                         /* 0xF4 IPv4 address (SFOLobby_PackIPAddress) */
    unsigned char bF8, bF9;         /* 0xF8 */
} LobbyPlayerInfo;

/* Account info by id (SFOLobby_GetAgentDetails, callback SFOLobby_Callback_GetPlayerInfo). */
typedef struct LobbyAccountInfoReply {
    char head[0x1C];                /* 0x00 */
    char accountName[0x2C];         /* 0x1C */
    LobbyPlayerInfo info;           /* 0x48 */
    char pad144[4];
} LobbyAccountInfoReply;

/* accountCache element (0x140 bytes; SFOLobby_RefreshAgentData adds/updates, SFOLobby_FindAgentData finds). */
typedef struct LobbyAccountEntry {
    int accountId;                  /* 0x00 */
    char name[0x20];                /* 0x04 */
    int ip;                         /* 0x24 the counters below reset when it changes */
    int f28;                        /* 0x28 */
    int f2C;                        /* 0x2C */
    int f30;                        /* 0x30 */
    int f34;                        /* 0x34 */
    char f38;                       /* 0x38 */
    unsigned char hasInfo;          /* 0x39 info is valid */
    char pad3A[2];
    int infoTime;                   /* 0x3C time info was stored */
    LobbyPlayerInfo info;           /* 0x40 */
    int f13C;                       /* 0x13C */
} LobbyAccountEntry;

/* 0x40-byte Medius RSA server key. */
typedef struct LobbyBlock40 {
    int w[16];
} LobbyBlock40;

/* Medius NetAddress / NetAddressList (two entries). */
typedef struct LobbyNetAddress {
    int type;                       /* 0x00 */
    char address[0x14];             /* 0x04 */
} LobbyNetAddress;

typedef struct LobbyNetAddressList {
    LobbyNetAddress addr[2];
} LobbyNetAddressList;

typedef struct LobbyKey11 {
    char s[0x11];
} LobbyKey11;

/* Medius NetConnectionInfo layout. */
typedef struct LobbyConnectInfo {
    int type;                       /* 0x00 */
    LobbyNetAddressList addrs;      /* 0x04 */
    int worldId;                    /* 0x34 */
    LobbyBlock40 serverKey;         /* 0x38 */
    LobbyKey11 sessionKey;          /* 0x78 */
    LobbyKey11 accessKey;           /* 0x89 */
} LobbyConnectInfo;

/* Connect parameters passed to MediusConnect (0x100 bytes). */
typedef struct LobbyConnectParams {
    LobbyConnectInfo info;          /* 0x00 */
    char pad9C[0xF0 - 0x9C];
    int timeout;                    /* 0xF0 */
    void* onConnect;                /* 0xF4 SFOLobby_Callback_MediusConnect */
    void* unkF8;                    /* 0xF8 */
    void* unkFC;                    /* 0xFC */
} LobbyConnectParams;

/* Login reply (callback SFOLobby_Callback_AccountLogin), Medius AccountLoginResponse layout. */
typedef struct LobbyLoginReply {
    char messageId[0x15];           /* 0x00 */
    char pad15[3];
    int statusCode;                 /* 0x18 */
    int accountId;                  /* 0x1C */
    int accountType;                /* 0x20 */
    int worldId;                    /* 0x24 */
    LobbyConnectInfo connectInfo;   /* 0x28 lobby server to connect to */
} LobbyLoginReply;

/* Universe list entry (0x210 bytes), built from a MediusUniverseVariableInformationResponse
 * by SFOLobby_Callback_UniverseStatusList or as a single dummy entry by SFOLobby_StartNetwork. */
typedef struct LobbyUniverseEntry {
    char name[0x80];                /* 0x000 */
    char hostName[0x80];            /* 0x080 */
    int port;                       /* 0x100 */
    char description[0x100];        /* 0x104 */
    int status;                     /* 0x204 */
    int userCount;                  /* 0x208 */
    int maxUsers;                   /* 0x20C */
} LobbyUniverseEntry;

typedef struct SFOLobby {
    LobbyArray array00;                     /* 0x0 freed on shutdown; contents not identified */
    LobbyArray inbox;                       /* 0x1C pending invites/messages (LobbyInboxEntry); answered by SFOLobby_MessageAck */
    LobbyArray array38;                     /* 0x38 */
    LobbyArray array54;                     /* 0x54 */
    LobbyArray pool70;                      /* 0x70 elem 0x114 bytes */
    LobbyArray list8C;                      /* 0x8C refreshed every few seconds while mode == 0 (SFOLobby_LobbyScreenIntel) */
    LobbyArray listA8;                      /* 0xA8 refreshed while mode == 1 (func_00450B30) */
    LobbyArray poolC4;                      /* 0xC4 elem 0x50 bytes */
    LobbyArray buddyList;                   /* 0xE0 LobbyBuddyEntry (0x50), filled by the buddy-list reply callback SFOLobby_Callback_GetBuddyList */
    LobbyArray accountCache;                /* 0xFC LobbyAccountEntry (0x140) keyed by account id (SFOLobby_RefreshAgentData) */
    LobbyArray pool118;                     /* 0x118 elem 0x2C bytes */
    LobbyArray pool134;                     /* 0x134 elem 0x50 bytes */
    LobbyArray pool150;                     /* 0x150 elem 0x50 bytes; copy of buddyList */
    char sessionBlock[1];                   /* 0x16C start of the 0x950-byte block cleared by the reset (SFOLobby_ResetConnectionFlags) */
    char pad016D[0x174 - 0x16D];
    int rangeStart;                         /* 0x174 nonnegative lower bound */
    int rangeEnd;                           /* 0x178 at least rangeStart */
    unsigned char unk17C;                   /* 0x17C while clear (and D_00585FA8 set) list refreshes are skipped (func_0044FA40) */
    char pad017D[0x180 - 0x17D];
    int connHandle;                         /* 0x180 connection handle from the connect callback SFOLobby_Callback_MediusConnect; -1 = none */
    int gotConnect;                         /* 0x184 set when SFOLobby_Callback_MediusConnect fires */
    int gotReply188;                        /* 0x188 func_00445F40 */
    int gotLogin;                           /* 0x18C login reply SFOLobby_Callback_AccountLogin */
    int gotReply190;                        /* 0x190 SFOLobby_Callback_AccountLogout */
    int gotReply194;                        /* 0x194 */
    int gotReply198;                        /* 0x198 SFOLobby_Callback_AccountRegistration (reply314) */
    int gotReply19C;                        /* 0x19C SFOLobby_Callback_UniverseNews (reply17CC) */
    int gotReply1A0;                        /* 0x1A0 SFOLobby_Callback_UniverseStatusList (reply18EC) */
    int gotReply1A4;                        /* 0x1A4 SFOLobby_Callback_SessionBegin (reply350) */
    int gotReply1A8;                        /* 0x1A8 SFOLobby_Callback_SessionEnd (reply380) */
    int gotReply1AC;                        /* 0x1AC SFOLobby_Callback_GetLocations (reply39C) */
    int gotReply1B0;                        /* 0x1B0 SFOLobby_Callback_PickLocation (reply400) */
    int gotReply1B4;                        /* 0x1B4 */
    int gotReply1B8;                        /* 0x1B8 SFOLobby_Callback_GetPolicy (reply484) */
    int gotReply1BC;                        /* 0x1BC SFOLobby_OnSettings (reply5A4) */
    int gotReply1C0;                        /* 0x1C0 SFOLobby_Callback_JoinChannel (reply9B0) */
    int gotAccountId;                       /* 0x1C4 SFOLobby_Callback_AccountGetID (accountIdReply) */
    int gotAccountInfo;                     /* 0x1C8 SFOLobby_Callback_GetPlayerInfo (accountInfoReply) */
    char pad01CC[0x1D0 - 0x1CC];
    int gotReply1D0;                        /* 0x1D0 SFOLobby_Callback_TextFilter (replyFD8) */
    char pad01D4[0x1F4 - 0x1D4];
    int gotReply1F4;                        /* 0x1F4 */
    int gotReply1F8;                        /* 0x1F8 SFOLobby_Callback_CreateChannel (reply1B1C) */
    int gotReply1FC;                        /* 0x1FC SFOLobby_Callback_FindChannel (reply1B3C) */
    int gotReply200;                        /* 0x200 SFOLobby_Callback_ChannelInfo (reply1BCC) */
    int gotMyIp;                            /* 0x204 SFOLobby_Callback_GetMyIP */
    int gotReply208;                        /* 0x208 SFOLobby_Callback_UpdateStats */
    int gotReply20C;                        /* 0x20C func_00446B40 (reply1D08) */
    int gotReply210;                        /* 0x210 */
    char pad0214[0x21C - 0x214];
    int gotReply21C;                        /* 0x21C */
    char pad0220[0x22C - 0x220];
    int gotReply22C;                        /* 0x22C SFOLobby_Callback_GetBuddyInvitations */
    int gotReply230;                        /* 0x230 func_004466B0 */
    char pad0234[0x238 - 0x234];
    int gotReply238;                        /* 0x238 SFOLobby_Callback_RemoveFromBuddyList */
    char pad023C[0x240 - 0x23C];
    int reply238Ok;                         /* 0x240 SFOLobby_Callback_RemoveFromBuddyList: reply status was MediusSuccess */
    char pad0244[0x24C - 0x244];
    int requestResult;                      /* 0x24C return code of the last Medius request call; nonzero = failed to send */
    LobbyLoginReply loginReply;             /* 0x250 */
    LobbyIdReply reply314;                  /* 0x314 */
    char pad0334[0x34C - 0x334];
    int reply188Status;                     /* 0x34C checked by func_0044D3D0 */
    LobbyReply reply350;                    /* 0x350 0x30-byte reply */
    char pad036C[0x380 - 0x36C];
    LobbyReply reply380;                    /* 0x380 */
    char reply39C[0x5C];                    /* 0x39C lobby list record (SFOLobby_Callback_GetLocations); memset as 0x64 bytes */
    int reply39CStatus;                     /* 0x3F8 */
    signed char reply39CEnd;                /* 0x3FC end-of-list byte */
    char pad03FD[0x400 - 0x3FD];
    char reply400[0x1C];                    /* 0x400 */
    char pad041C[0x484 - 0x41C];
    char reply484[0x120];                   /* 0x484 */
    char reply5A4[0x40C];                   /* 0x5A4 */
    char reply9B0[0xB8];                    /* 0x9B0 */
    LobbyAccountIdReply accountIdReply;     /* 0xA68 */
    LobbyAccountInfoReply accountInfoReply; /* 0xA88 */
    char pad0BD0[0xBEC - 0xBD0];
    int unkBEC;                             /* 0xBEC -1 = none */
    char pad0BF0[0xC28 - 0xBF0];
    LobbyBuddyReply buddyListReply;         /* 0xC28 last buddy-list reply record */
    char pad0CF8[0xD14 - 0xCF8];
    int unkD14;                             /* 0xD14 -1 = none */
    char pad0D18[0xD3C - 0xD18];
    int unkD3C;                             /* 0xD3C -1 = none */
    char pad0D40[0xE84 - 0xD40];
    int unkE84;                             /* 0xE84 -1 = none */
    char pad0E88[0xEAC - 0xE88];
    int unkEAC;                             /* 0xEAC -1 = none */
    char pad0EB0[0xFD8 - 0xEB0];
    char replyFD8[0x5C];                    /* 0xFD8 */
    char pad1034[0x126C - 0x1034];
    int unk126C;                            /* 0x126C -1 = none */
    char pad1270[0x13B0 - 0x1270];
    int unk13B0;                            /* 0x13B0 -1 = none */
    int unk13B4;                            /* 0x13B4 -1 = none */
    char pad13B8[0x14F8 - 0x13B8];
    int unk14F8;                            /* 0x14F8 -1 = none */
    char pad14FC[0x17CC - 0x14FC];
    char reply17CC[0x11C];                  /* 0x17CC */
    signed char reply17CCEnd;               /* 0x18E8 end-of-list byte of reply17CC */
    char pad18E9[0x18EC - 0x18E9];
    char reply18EC[0x22C];                  /* 0x18EC */
    signed char reply18ECEnd;               /* 0x1B18 end-of-list byte of reply18EC */
    char pad1B19[0x1B1C - 0x1B19];
    char reply1B1C[0x20];                   /* 0x1B1C */
    char reply1B3C[0x90];                   /* 0x1B3C */
    char reply1BCC[0x64];                   /* 0x1BCC */
    char reply1C30[0xBC];                   /* 0x1C30 copied by SFOLobby_Callback_JoinGame */
    char pad1CEC[0x1D08 - 0x1CEC];
    char reply1D08[0x18C];                  /* 0x1D08 */
    char pad1E94[0x1E98 - 0x1E94];
    int list8CTime;                         /* 0x1E98 time of the last list8C refresh */
    int listA8Time;                         /* 0x1E9C time of the last listA8 refresh */
    int mode;                               /* 0x1EA0 selects which list is refreshed (SFOLobby_LobbyScreenIntel) */
    int unk1EA4;                            /* 0x1EA4 initial capacity of outList23EC (SFOLobby_ContactScreenStart) */
    int unk1EA8;                            /* 0x1EA8 > 0: network already started (SFOLobby_ConfigScreenStart) */
    int list8CId;                           /* 0x1EAC id sent with the list8C refresh request */
    char pad1EB0[0x1F38 - 0x1EB0];
    int lobbyWorldId;                       /* 0x1F38 id of the joined lobby (SFOLobby_RegionSelect) */
    LobbyBlock40 serverKey;                 /* 0x1F3C connect params serverKey for auth/lobby connects (SFOLobby_MediusConnectMUIS/SFOLobby_MediusConnectMAS) */
    char authHostName[0x80];                /* 0x1F7C resolved into authServer by SFOLobby_DNSLookup */
    char authServer[0x80];                  /* 0x1FFC auth server IP string, connected with authPort by SFOLobby_MediusConnectMAS */
    int authPort;                           /* 0x207C */
    char dirHostName[0x80];                 /* 0x2080 directory (universe list) server host name; resolved into dirServer */
    char dirServer[0x80];                   /* 0x2100 directory server IP string, connected with dirPort by SFOLobby_MediusConnectMUIS */
    int dirPort;                            /* 0x2180 */
    unsigned char directAuth;               /* 0x2184 set: use authHostName directly (one dummy universe); clear: fetch the universe list (SFOLobby_StartNetwork) */
    char pad2185[0x2188 - 0x2185];
    int dnasArg;                            /* 0x2188 first DNAS auth argument (SFOLobby_ConfigVerifyDNAS) */
    char dnasData[0x200];                   /* 0x218C DNAS auth data */
    unsigned short dnasDataLen;             /* 0x238C */
    char password[0x22];                    /* 0x238E from DNAS (SFOLobby_ConfigVerifyDNAS); filled with '*' when empty (SFOLobby_Authenticate) */
    int passwordLen;                        /* 0x23B0 */
    unsigned char useDnas;                  /* 0x23B4 password comes from DNAS (SFOLobby_ConfigVerifyDNAS) rather than the default */
    char pad23B5[0x23D5 - 0x23B5];
    unsigned char unk23D5;                  /* 0x23D5 */
    char pad23D6[0x23D8 - 0x23D6];
    LobbyArray* netConfigList;              /* 0x23D8 network configurations (0x13C0-byte entries, SFOLobby_ConfigGetList); this and the following lists are caller-supplied */
    LobbyArray* universeList;               /* 0x23DC 0x210-byte entries: name, host name +0x80, port +0x100, description +0x104 (SFOLobby_Callback_UniverseStatusList) */
    LobbyArray* lobbyList;                  /* 0x23E0 entries: world id, name +4 (SFOLobby_Callback_GetLocations) */
    char pad23E4[0x23E8 - 0x23E4];
    LobbyArray* outBuddyList;               /* 0x23E8 receives a copy of buddyList */
    LobbyArray* outList23EC;                /* 0x23EC */
    LobbyArray* outList23F0;                /* 0x23F0 */
    LobbyArray* outList23F4;                /* 0x23F4 */
    LobbyArray* outUsageList;               /* 0x23F8 "USAGE" entries (SFOLobby_Callback_GetPolicy) */
    LobbyArray* outList23FC;                /* 0x23FC other entries (SFOLobby_Callback_GetPolicy) */
    LobbyArray* outList2400;                /* 0x2400 SFOLobby_OnSettings */
    LobbyArray* outList2404;                /* 0x2404 SFOLobby_Callback_UniverseNews */
    char busy;                              /* 0x2408 */
    unsigned char inUpdateHook;             /* 0x2409 set while the update hook runs (SFOLobby_GuiCallback) */
    char pad240A[0x2410 - 0x240A];
    int waitStart;                          /* 0x2410 start time of the current wait loop */
    int unk2414;                            /* 0x2414 */
    char sessionKey[0x11];                  /* 0x2418 Medius session key copied into every request */
    char myIp[0x14];                        /* 0x2429 own IP address string (SFOLobby_Callback_GetMyIP) */
    char accountName[0x43];                 /* 0x243D */
    int accountId;                          /* 0x2480 own account id (login reply); -1 = none */
    int unk2484;                            /* 0x2484 -1 = none */
    char pad2488[0x248C - 0x2488];
    char wantedUniverse[0x80];              /* 0x248C universe to join, matched against universeList names (SFOLobby_ServerSelect) */
    char wantedLobby[0x40];                 /* 0x250C lobby to join, matched against lobbyList names */
    char pad254C[0x2550 - 0x254C];
    void* updateHook;                       /* 0x2550 called by SFOLobby_GuiCallback */
    char pad2554[0x255C - 0x2554];
    int state;                              /* 0x255C SFOLOBBY_STATE_* */
    char pad2560[0x2564 - 0x2560];
    unsigned char error;                    /* 0x2564 last error code (SFOLobby_SetError) */
    char pad2565[0x2568 - 0x2565];
    const char* errorFile;                  /* 0x2568 */
    int errorLine;                          /* 0x256C */
    int dnasResult;                         /* 0x2570 DNAS auth return code */
    char pad2574[0x2578 - 0x2574];
    int unk2578;                            /* 0x2578 */
    int buddyListTime;                      /* 0x257C time of the last buddy list request (SFOLobby_RequestBuddyList) */
    int buddyInfoTime;                      /* 0x2580 time of the last buddy info refresh (SFOLobby_ContactScreenIntel) */
    char pad2584[0x2590 - 0x2584];
    int unk2590;                            /* 0x2590 */
    char pad2594[0x2660 - 0x2594];
    int unk2660;                            /* 0x2660 */
    char libnetCtx[0x40];                   /* 0x2664 sceLibnet context for host name lookups (SFOLobby_DNSLookup) */
    int unk26A4;                            /* 0x26A4 */
    char pad26A8[0x26A8 - 0x26A8];
} SFOLobby;

#endif
