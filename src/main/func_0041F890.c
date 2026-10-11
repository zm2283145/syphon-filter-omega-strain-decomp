#pragma cplusplus on
#include "types.h"
typedef struct { int key; char name[4]; } Data_41F890;
typedef struct Node_41F890 { int pad0; struct Node_41F890* next; Data_41F890* data; } Node_41F890;
typedef struct { Node_41F890* p; } It_41F890;
typedef struct { int w[1]; } Raw_41F890;
extern "C" {
void func_0013B180(Raw_41F890* out, void* list);
void func_0028C0B0(It_41F890* out, Raw_41F890* raw);
void func_0028C0A0(Raw_41F890* out, void* list);
void func_0028C090(It_41F890* out, Raw_41F890* raw);
int String_AssignCStr_1C43A0(void* s, const char* key);
}
extern "C" Data_41F890* func_0041F890(void* o, const char* key)
{
    It_41F890 last;
    It_41F890 first;
    Raw_41F890 rawFirst;
    Raw_41F890 rawEnd;
    Node_41F890* n;
    func_0013B180(&rawFirst, o);
    func_0028C0B0(&first, &rawFirst);
    for (n = first.p; (func_0028C0A0(&rawEnd, o), func_0028C090(&last, &rawEnd), n != last.p); n = n->next) {
        if (!String_AssignCStr_1C43A0(n->data->name, key))
            return n->data;
    }
    return 0;
}