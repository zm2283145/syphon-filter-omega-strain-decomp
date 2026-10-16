#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Reserve(char *, int);                           
int FileMan_LoadMemberSync(char *, int *, int);                     
char * func_0036DD80(char *);                           
int func_0036DEC0(char *);                               
int FileMan_FindMember(char *);                             
int FileMan_Release(char *, int);                            
int func_0036E4B0(char *, int, int, int);                    
extern int D_00543658;
extern int D_00543660;
extern unsigned char D_00543668;
extern char D_00543680;
extern char D_005436A0;

int func_003CBE90(int arg0) {
    int sp10[40];

    if (D_00543668 == 0) {
        func_0036E4B0(sp10, arg0, 0, 0);
        if (!(FileMan_FindMember(sp10) & 0xFF)) {
            D_00543660 = F_(func_0036DD80(sp10), 0x2C, int);
            D_00543658 = 0;
            FileMan_LoadMemberSync(sp10, &D_00543658, 0);
            func_0036DEC0(sp10);
            D_00543668 = 1;
            String_Reserve(&D_00543680, 0x40);
            String_Reserve(&D_005436A0, 0x40);
            FileMan_Release(sp10, -1);
            return 1;
        }
        FileMan_Release(sp10, -1);
        goto block_5;
    }
block_5:
    return 0;
}
