#include "types.h"
#include "fileman_entry.h"
extern void func_001AFB20(void);
extern int func_0036E140(void* h, const char* name, int arg, int opt);
extern void func_003B5310(void* a, void* e);
extern int func_0022A200(void* v, void* value);
extern char D_004A6340[];
extern char D_004A6360[];
extern char* D_004F77A0;

/* Loads the front-end idle animation and pushes an empty 4-char tag onto the character list. */
void func_0022A140(void)
{
    char tag[4];
    FileManEntry e;
    unsigned char done;
    unsigned int i;
    const char* s;
    func_001AFB20();
    func_0036E5D0(&e);
    func_0036E140(&e, D_004A6340, 0, 0);
    func_003B5310(D_004F77A0, &e);
    done = 0;
    for (i = 0, s = D_004A6360; i < 4; i++) {
        char c = *s;
        if (c == 0)
            done = 1;
        tag[i] = done ? 0 : c;
        s++;
    }
    func_0022A200(D_004F77A0 + 4, tag);
    func_0036E220(&e, -1);
}



