/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Callback: 1 file, 00446340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00446340 */
#pragma push /* merge_units */
#include "types.h"
int Libc_Strncmp(char*, char*, int);
char* strchr(char*, int);
int strlen(char*);

typedef struct {
    unsigned char id;
    char* name;
} LobbyCmd;

extern LobbyCmd D_004976E0[8];
extern unsigned char D_004978F8;
extern char* D_00584530[4];
extern int D_00584540;

unsigned char ParseSystemMessage(char* str, int len) {
    int sep;
    unsigned int i;
    int n;
    int rem;
    char* p;
    char* base;
    char* q;
    int j;
    char* s;
    int k;

    D_00584540 = 0;
    sep = D_004978F8;
    if (sep > 0 && sep < 0x100) {
        for (i = 0; i < 8; i++) {
            if (Libc_Strncmp(str, D_004976E0[i].name, strlen(D_004976E0[i].name)) == 0) {
                n = strlen(D_004976E0[i].name);
                rem = len - n;
                p = str + n;
                base = p;
                if (0 <= rem) {
                    do {
                        D_00584530[D_00584540++] = p;
                        q = strchr(p, (unsigned char)sep);
                        if (q == 0 || q - base > rem || D_00584540 == 4) {
                            break;
                        }
                        *q = 0;
                        p = q + 1;
                    } while (p - base <= rem);
                }
                for (j = 0; j < D_00584540; j++) {
                    s = D_00584530[j];
                    while (!!*s && (unsigned char)*s <= ' ') {
                        s++;
                    }
                    k = strlen(s) - 1;
                    while (k >= 0 && (unsigned char)s[k] <= ' ') {
                        s[k] = 0;
                        k--;
                    }
                    D_00584530[j] = s;
                }
                return D_004976E0[i].id;
            }
        }
    }
    D_00584530[0] = str;
    D_00584540 = 1;
    return 0;
}
static inline void merge_flush_func_00446340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00446340 */
