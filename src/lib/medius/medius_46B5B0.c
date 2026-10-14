/* MediusCallbackStatus -> name */
const char* func_0046B5B0(int status)
{
    switch (status) {
    case -1000: return "MediusBeginSessionFailed";
    case -999: return "MediusAccountAlreadyExists";
    case -998: return "MediusAccountNotFound";
    case -997: return "MediusAccountLoggedIn";
    case -996: return "MediusEndSessionFailed";
    case -995: return "MediusLoginFailed";
    case -994: return "MediusRegistrationFailed";
    case -993: return "MediusIncorrectLoginStep";
    case -992: return "MediusAlreadyLeaderOfClan";
    case -991: return "MediusWMError";
    case -990: return "MediusNotClanLeader";
    case -989: return "MediusPlayerNotPrivileged";
    case -988: return "MediusDBError";
    case -987: return "MediusDMEError";
    case -986: return "MediusExceedsMaxWorlds";
    case -985: return "MediusRequestDenied";
    case -984: return "MediusSetGameListFilterFailed";
    case -983: return "MediusClearGameListFilterFailed";
    case -982: return "MediusGetGameListFilterFailed";
    case -981: return "MediusNumFiltersAtMax";
    case -980: return "MediusFilterNotFound";
    case -979: return "MediusInvalidRequestMsg";
    case -978: return "MediusInvalidPassword";
    case -977: return "MediusGameNotFound";
    case -976: return "MediusChannelNotFound";
    case -975: return "MediusGameNameExists";
    case -974: return "MediusChannelNameExists";
    case -973: return "MediusGameNameNotFound";
    case -972: return "MediusPlayerBanned";
    case -971: return "MediusClanNotFound";
    case -970: return "MediusClanNameInUse";
    case -969: return "MediusSessionKeyInvalid";
    case -968: return "MediusTextStringInvalid";
    case -967: return "MediusFilterFailed";
    case -966: return "MediusFail";
    case 0: return "MediusSuccess";
    case 1: return "MediusNoResult";
    case 2: return "MediusRequestAccepted";
    case 3: return "MediusWorldCreatedSizeReduced";
    case 4: return "MediusPass";
    default: return "UNKNOWN MEDIUSCALLBACKSTATUS";
    }
}

