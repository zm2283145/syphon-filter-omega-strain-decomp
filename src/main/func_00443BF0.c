#pragma cplusplus on
#include "types.h"

extern "C" {
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);
char* func_00129C80(const char*, const char*);
char* strchr(const char*, int);
int strlen(const char*);
void func_004434A0(void*, char*, char*);
void func_00443260(void*, char*, char*);
extern char D_004C0B10[];
}

extern "C" void func_00443BF0(void* self, char* text, int len, int mode)
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
        c = func_00129C80(line, D_004C0B10);
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
        if (mode) func_004434A0(self, key, val);
        else func_00443260(self, key, val);
    }
}



