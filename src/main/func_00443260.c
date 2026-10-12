#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char * , int);
int func_00121BC8(int);
int String_CompareNoCase(int, char *);

void func_00443260(char * arg0, int arg1, int arg2) {
    signed char temp_s1;
    int var_v0;

    if (arg2 != 0) {
        var_v0 = func_00121BC8(arg2);
    } else {
        var_v0 = 0;
    }
    temp_s1 = var_v0 != 0;
    if (String_CompareNoCase(arg1, "MAS_IP") == 0) {
        String_Copy(arg0 + 0x1FFC, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MAS_PORT") == 0) {
        F_(arg0, 0x207C, int) = var_v0;
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_IP") == 0) {
        String_Copy(arg0 + 0x2100, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_DNS") == 0) {
        String_Copy(arg0 + 0x2080, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MAS_DNS") == 0) {
        String_Copy(arg0 + 0x1F7C, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_PORT") == 0) {
        F_(arg0, 0x2180, int) = var_v0;
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_SKIP") == 0) {
        F_(arg0, 0x2184, signed char) = temp_s1;
        return;
    }
    if (String_CompareNoCase(arg1, "MAX_CHAT") == 0) {
        if (var_v0 > 1) {
            F_(arg0, 0x1EA4, int) = var_v0;
        }
    } else {
        if (String_CompareNoCase(arg1, "FORCE_LOBBY_REFRESH") == 0) {
            F_(arg0, 0x1E98, int) = 0;
            F_(arg0, 0x1E9C, int) = 0;
            return;
        }
        if (String_CompareNoCase(arg1, "DEFAULT_LOBBY_NAME") == 0) {
            String_Copy(arg0 + 0x23B5, arg2);
            return;
        }
        if (String_CompareNoCase(arg1, "LOBBY_DISABLE_HEADSETS") == 0) {
            F_(arg0, 0x23D5, signed char) = temp_s1;
            return;
        }
        if (String_CompareNoCase(arg1, "DISABLE_SECURITY") == 0) {
            F_(arg0, 0x23D6, signed char) = temp_s1;
            return;
        }
        if (String_CompareNoCase(arg1, "DISABLE_PAGED_GAMELISTS") == 0) {
            F_(arg0, 0x17C, signed char) = temp_s1;
        }
    }
}
