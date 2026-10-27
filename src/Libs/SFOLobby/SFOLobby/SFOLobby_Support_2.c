/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Support: 3 files, 00443260-00443BF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00443260 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Libc_Strcpy(char * , int);
int atoi(int);
int String_CompareNoCase(int, char *);

void SFOLobby_ParseConfigValue(char * arg0, int arg1, int arg2) {
    signed char temp_s1;
    int var_v0;

    if (arg2 != 0) {
        var_v0 = atoi(arg2);
    } else {
        var_v0 = 0;
    }
    temp_s1 = var_v0 != 0;
    if (String_CompareNoCase(arg1, "MAS_IP") == 0) {
        Libc_Strcpy(arg0 + 0x1FFC, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MAS_PORT") == 0) {
        F_(arg0, 0x207C, int) = var_v0;
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_IP") == 0) {
        Libc_Strcpy(arg0 + 0x2100, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MUIS_DNS") == 0) {
        Libc_Strcpy(arg0 + 0x2080, arg2);
        return;
    }
    if (String_CompareNoCase(arg1, "MAS_DNS") == 0) {
        Libc_Strcpy(arg0 + 0x1F7C, arg2);
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
            Libc_Strcpy(arg0 + 0x23B5, arg2);
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
static inline void merge_flush_func_00443260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00443260 */

/* merge_units: begin func_004434A0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
extern int atoi(char*);
#endif /* merge_units */
#define atoi(a0) (atoi((int)(a0))) /* merge_units */

extern int strcmp(const char*, const char*);
extern char D_004C0720[];
extern char D_004C0740[];
extern char D_004C0760[];
extern char D_004C0780[];
extern char D_004C07B0[];
extern char D_004C07E0[];
extern char D_004C0810[];
extern char D_004C0830[];
extern char D_004C0860[];
extern char D_004C0890[];
extern char D_004C08B0[];
extern char D_004C08E0[];
extern char D_004C0910[];
extern char D_004C0930[];
extern char D_004C0960[];
extern char D_004C0990[];
extern char D_004C09B0[];
extern char D_004C09D0[];
extern char D_004C0A00[];
extern char D_004C0A30[];
extern char D_004C0A60[];
extern char D_004C0A90[];
extern char D_004C0AB0[];
extern char D_004C0AD0[];
extern char D_004C0AF0[];
extern int D_00497728;
extern int D_00497730;
extern int D_00497738;
extern int D_00497740;
extern int D_00497748;
extern int D_00497750;
extern int D_00497758;
extern int D_00497760;
extern int D_00497768;
extern int D_00497770;
extern int D_00497778;
extern int D_00497780;
extern int D_00497788;
extern int D_00497790;
extern int D_00497798;
extern int D_004977A0;
extern int D_004977A8;
extern int D_004977B0;
extern int D_004977B8;
extern int D_004977C0;
extern int D_004977C8;
extern int D_004977D0;
extern int D_004977D8;
extern int D_004977E0;
extern int D_004977E8;
extern int D_004977F0;
extern int D_004977F8;
extern int D_00497800;
extern int D_00497808;
extern int D_00497810;
extern int D_00497818;
extern int D_00497820;
extern int D_00497828;
extern int D_00497830;
extern int D_00497838;
extern int D_00497840;
extern int D_00497848;
extern int D_00497850;
extern int D_00497858;
extern int D_00497860;
extern int D_00497868;
extern int D_00497870;
extern int D_00497878;
extern int D_00497880;
extern int D_00497888;
extern int D_00497890;
extern int D_00497898;
extern int D_004978A0;
extern int D_004978A8;
extern int D_004978B0;
extern int D_004978B8;
extern int D_004978C0;
extern int D_004978C8;
extern int D_004978D0;
extern int D_004978D8;
extern int D_004978E0;
extern int D_004978E8;
extern int D_004978F0;
extern int D_004978F8;
extern int D_00497900;
extern int D_00497908;
extern int D_00497910;
extern int D_00497918;
extern int D_00497920;
extern int D_00497928;
extern int D_00497930;
extern int D_00497938;
extern int D_00497940;
extern int D_00497948;
extern int D_00497950;
extern int D_00585F90;
extern int D_00585F98;
extern int D_00585FA0;
extern int D_00585FA8;
extern int D_00585FB0;

/* Applies one "{SFOLOBBY_SETTINGS}" key/value pair: the value is parsed with
 * atoi and stored only if it lies within the setting's [min, max]. */
void SFOLobby_ParseIntSetting(void* self, char* key, char* value) {
    int n;

    if (value != 0) {
        n = atoi(value);
    } else {
        n = 0;
    }
    if (strcmp(key, D_004C0720) == 0) {
        if (n >= D_00497730 && n <= D_00497738) {
            D_00497728 = n;
        }
    } else if (strcmp(key, D_004C0740) == 0) {
        if (n >= D_00497748 && n <= D_00497750) {
            D_00497740 = n;
        }
    } else if (strcmp(key, D_004C0760) == 0) {
        if (n >= D_00497760 && n <= D_00497768) {
            D_00497758 = n;
        }
    } else if (strcmp(key, D_004C0780) == 0) {
        if (n >= D_00497778 && n <= D_00497780) {
            D_00497770 = n;
        }
    } else if (strcmp(key, D_004C07B0) == 0) {
        if (n >= D_00497790 && n <= D_00497798) {
            D_00497788 = n;
        }
    } else if (strcmp(key, D_004C07E0) == 0) {
        if (n >= D_004977A8 && n <= D_004977B0) {
            D_004977A0 = n;
        }
    } else if (strcmp(key, D_004C0810) == 0) {
        if (n >= D_004977C0 && n <= D_004977C8) {
            D_004977B8 = n;
        }
    } else if (strcmp(key, D_004C0830) == 0) {
        if (n >= D_004977D8 && n <= D_004977E0) {
            D_004977D0 = n;
        }
    } else if (strcmp(key, D_004C0860) == 0) {
        if (n >= D_004977F0 && n <= D_004977F8) {
            D_004977E8 = n;
        }
    } else if (strcmp(key, D_004C0890) == 0) {
        if (n >= D_00497808 && n <= D_00497810) {
            D_00497800 = n;
        }
    } else if (strcmp(key, D_004C08B0) == 0) {
        if (n >= D_00497820 && n <= D_00497828) {
            D_00497818 = n;
        }
    } else if (strcmp(key, D_004C08E0) == 0) {
        if (n >= D_00497838 && n <= D_00497840) {
            D_00497830 = n;
        }
    } else if (strcmp(key, D_004C0910) == 0) {
        if (n >= D_00497850 && n <= D_00497858) {
            D_00497848 = n;
        }
    } else if (strcmp(key, D_004C0930) == 0) {
        if (n >= D_00497868 && n <= D_00497870) {
            D_00497860 = n;
        }
    } else if (strcmp(key, D_004C0960) == 0) {
        if (n >= D_00497880 && n <= D_00497888) {
            D_00497878 = n;
        }
    } else if (strcmp(key, D_004C0990) == 0) {
        if (n >= D_00497898 && n <= D_004978A0) {
            D_00497890 = n;
        }
    } else if (strcmp(key, D_004C09B0) == 0) {
        if (n >= D_00497940 && n <= D_00497948) {
            D_00497938 = n;
        }
    } else if (strcmp(key, D_004C09D0) == 0) {
        if (n >= D_004978B0 && n <= D_004978B8) {
            D_004978A8 = n;
        }
    } else if (strcmp(key, D_004C0A00) == 0) {
        if (n >= D_004978C8 && n <= D_004978D0) {
            D_004978C0 = n;
        }
    } else if (strcmp(key, D_004C0A30) == 0) {
        if (n >= D_004978E0 && n <= D_004978E8) {
            D_004978D8 = n;
        }
    } else if (strcmp(key, D_004C0A60) == 0) {
        if (n >= D_00585FB0 && n <= D_00497950) {
            D_00585FA8 = n;
        }
    } else if (strcmp(key, D_004C0A90) == 0) {
        if (n >= D_00585F98 && n <= D_004978F0) {
            D_00585F90 = n;
        }
    } else if (strcmp(key, D_004C0AB0) == 0) {
        if (n >= D_00497900 && n <= D_00497908) {
            D_004978F8 = n;
        }
    } else if (strcmp(key, D_004C0AD0) == 0) {
        if (n >= D_00497918 && n <= D_00497920) {
            D_00497910 = n;
        }
    } else if (strcmp(key, D_004C0AF0) == 0) {
        if (n >= D_00585FA0 && n <= D_00497930) {
            D_00497928 = n;
        }
    }
}
#undef atoi /* merge_units */
static inline void merge_flush_func_004434A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004434A0 */

/* merge_units: begin func_00443BF0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);
char* strstr(const char*, const char*);
char* strchr(const char*, int);
int strlen(const char*);
#if 0 /* merge_units */
void SFOLobby_ParseIntSetting(void*, char*, char*);
#endif /* merge_units */
#define SFOLobby_ParseIntSetting(a0, a1, a2) (SFOLobby_ParseIntSetting((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void SFOLobby_ParseConfigValue(void*, char*, char*);
#endif /* merge_units */
#define SFOLobby_ParseConfigValue(a0, a1, a2) (SFOLobby_ParseConfigValue((char *)(a0), (int)(a1), (int)(a2))) /* merge_units */

extern char D_004C0B10[];
}

extern "C" void SFOLobby_ParseConfigFile(void* self, char* text, int len, int mode)
{
    int start;
    int end;
    if (text == 0 || len <= 0) return;
    for (start = 0; start < len; start = end + 1) {
        int n;
        char line[0x100];
        char* key;
        char* val;
        char* c;
        int i;
        for (end = start; (text[end] >= ' ' || text[end] == '\t') && end < len; end++);
        n = end - start + 1;
        if (n < 0 || (unsigned)n >= 0x100) return;
        memset(line, 0, sizeof(line));
        memcpy(line, text + start, n);
        c = strstr(line, D_004C0B10);
        if (c) *c = 0;
        key = line;
        while ((bool)*key && *key <= ' ') key++;
        if (!*key) continue;
        val = strchr(key, '=');
        *val = 0;
        val++;
        while ((bool)*val && *val <= ' ') val++;
        for (i = strlen(val) - 1; val[i] <= ' ' && i >= 0; i--) val[i] = 0;
        for (i = strlen(key) - 1; key[i] <= ' ' && i >= 0; i--) key[i] = 0;
        if (mode) SFOLobby_ParseIntSetting(self, key, val);
        else SFOLobby_ParseConfigValue(self, key, val);
    }
}
#undef SFOLobby_ParseIntSetting /* merge_units */
#undef SFOLobby_ParseConfigValue /* merge_units */
static inline void merge_flush_func_00443BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00443BF0 */
