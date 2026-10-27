#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int std_basic_string_char_char_traits_char_ctor_charP(char *, char *);                 
int String_Dtor(char *, int);                            
int std_basic_string_char_char_traits_char_assign_basicstringR(char * , char *);                       
int cTexMan_RemoveTexture(int, int, int);                       
const unsigned int D_004C0018[2] = { 0x0, 0x0 };
extern int g_TextureMgr;

#pragma push
#pragma opt_common_subs off
void GuiBitmapWidget_ClearBitmap(char * arg0) {
    struct { int f20[4]; } sl;
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        cTexMan_RemoveTexture(g_TextureMgr, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
    F_(arg0, 0x4C, int) = 0;
    std_basic_string_char_char_traits_char_ctor_charP(sl.f20, &(*(char*)D_004C0018));
    std_basic_string_char_char_traits_char_assign_basicstringR(arg0 + 0x50, sl.f20);
    String_Dtor(sl.f20, 0);
}
#pragma pop
