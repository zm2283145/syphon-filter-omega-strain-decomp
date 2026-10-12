#include "types.h"
typedef struct { char pad[0x2564]; signed char code; char pad2[3]; char* file; int line; } E452;
extern int sprintf(char*, const char*, ...);
extern char D_004C0FB0[];
signed char func_00452FF0(E452* e, char* buf) {
    signed char r = e->code;
    if (buf) {
        char* s;
        unsigned char c = *(volatile unsigned char*)&e->code;
        switch (c) {
    case 0: s = "ERROR_NONE"; break;
    case 1: s = "ERROR_GENERAL"; break;
    case 2: s = "ERROR_TIMEOUT"; break;
    case 3: s = "ERROR_VULGARITY"; break;
    case 4: s = "ERROR_CONFIGSELECT"; break;
    case 5: s = "ERROR_CATASTROPHIC"; break;
    case 6: s = "ERROR_DNAS_FAILED"; break;
    case 7: s = "ERROR_HARDWARE_NOT_SUPPORTED"; break;
    case 8: s = "ERROR_UPDATE_PASSWORD_FAILED"; break;
    case 9: s = "ERROR_LOGOUT_FAILED"; break;
    case 10: s = "ERROR_LOGIN_FAILED"; break;
    case 11: s = "ERROR_ACCOUNT_CREATE_FAILED"; break;
    case 12: s = "ERROR_CONNECTION_FAILED"; break;
    case 13: s = "ERROR_UPDATECLIENTSTATE_FAILED"; break;
    case 14: s = "ERROR_MODULE_LOAD_FAILED"; break;
    case 15: s = "ERROR_MEDIUS_NOT_INITIALIZED"; break;
    case 16: s = "ERROR_MEDIUS_INITIALIZATION_FAILED"; break;
    case 17: s = "ERROR_BEGIN_SESSION_FAILED"; break;
    case 18: s = "ERROR_END_SESSION_FAILED"; break;
    case 19: s = "ERROR_GET_SESSION_KEY_FAILED"; break;
    case 20: s = "ERROR_AUTHENTICATION_FAILED"; break;
    case 21: s = "ERROR_GET_POLICY_FAILED"; break;
    case 22: s = "ERROR_JOIN_CHANNEL_FAILED"; break;
    case 23: s = "ERROR_CREATE_CHANNEL_FAILED"; break;
    case 24: s = "ERROR_FIND_CHANNEL_FAILED"; break;
    case 25: s = "ERROR_FILTER_FAILED"; break;
    case 26: s = "ERROR_NAME_TAKEN"; break;
    case 27: s = "ERROR_NAME_TOO_LONG"; break;
    case 28: s = "ERROR_ALREADY_LEADER"; break;
    case 29: s = "ERROR_AGENT_NONEXISTENT"; break;
    case 30: s = "ERROR_AGENT_ALREADY_BELONGS"; break;
    case 31: s = "ERROR_NOT_LEADER"; break;
    case 32: s = "ERROR_INTERFACE_NOT_STARTED"; break;
    case 33: s = "ERROR_INTERFACE_CONNECTION_FAILED"; break;
    case 34: s = "ERROR_INVALID_NAME"; break;
    case 35: s = "ERROR_SCREEN_NOT_ALLOWED"; break;
    case 36: s = "ERROR_NO_CHAT_LINES"; break;
    case 38: s = "ERROR_CONTACTINVITE_OFFLINE"; break;
    case 39: s = "ERROR_CONTACTINVITE_NONLOBBY"; break;
    case 40: s = "ERROR_CONTACTINVITE_DECLINED"; break;
    case 37: s = "ERROR_CANTINVITESELF"; break;
    case 41: s = "ERROR_GENERAL_IGNORABLE"; break;
    case 42: s = "ERROR_AGENTLIST_FULL"; break;
    case 43: s = "ERROR_MLSDISCONNECTFAILED"; break;
    case 44: s = "ERROR_MASDISCONNECTFAILED"; break;
    case 45: s = "ERROR_DNSLOOKUP_FAILED"; break;
    case 46: s = "ERROR_REQUESTEZNET_FAILED"; break;
    case 47: s = "ERROR_CONFIGGETLIST_FAILED"; break;
    case 48: s = "ERROR_CONFIGGETLIST_INVALID_MEMCARD"; break;
    case 49: s = "ERROR_SFOMGCL_STARTUP_FAILED"; break;
    case 50: s = "ERROR_CREATE_GAME_FAILED"; break;
    case 51: s = "ERROR_GAME_NOTFOUND"; break;
    case 52: s = "ERROR_EMPTY_LIST_SLOT"; break;
    case 53: s = "ERROR_JOINGAME_FILTER_PING"; break;
    case 54: s = "ERROR_JOINGAME_FILTER_CELL"; break;
    case 55: s = "ERROR_JOINGAME_FILTER_CONTACT"; break;
    case 56: s = "ERROR_JOINGAME_GENERAL"; break;
    case 57: s = "ERROR_JOINGAME_CLOSED"; break;
    case 58: s = "ERROR_INCORRECTPASSWORD"; break;
    case 59: s = "ERROR_ACCOUNT_NOT_FOUND"; break;
    case 60: s = "ERROR_ACCOUNT_LOGGEDIN"; break;
    case 61: s = "ERROR_ACCOUNT_ALREADY_EXISTS"; break;
    case 62: s = "ERROR_USER_CANCEL"; break;
    case 63: s = "ERROR_CELL_FULL_BUT_REVOKABLE"; break;
        default: s = "ERROR_UNKNOWN"; break;
        }
        sprintf(buf, "Error: %d - %s, File: %s, Line: %d", c, s, e->file, e->line);
    }
    if ((unsigned char)e->code != 5) {
        e->code = 0;
        e->file = D_004C0FB0;
        e->line = 0x2EA;
    }
    return r;
}
