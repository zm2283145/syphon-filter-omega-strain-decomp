#pragma opt_strength_reduction off
enum OnOff { ON0, ON1 };
typedef struct Item { unsigned char flag; char name[0x20]; } Item;
typedef struct List { int pad0; int count; Item* items; } List;
typedef struct Box { char pad[0x94]; unsigned int size; } Box;
typedef struct Self { char pad[0x48]; Box* box; } Self;
extern List* D_004FFC2C;
extern void func_00424410(Box*, int*, unsigned int*);
extern void func_00421070(Box*);
extern void func_00421290(Box*, char*, int, int);
extern void func_00424430(Box*, int, unsigned int);
extern char* Loc_LookupText(char*);
void func_00454280(Self* self)
{
    int a;
    unsigned int b;
    List* l;
    int i;
    if (self->box == 0) return;
    func_00424410(self->box, &a, &b);
    l = D_004FFC2C;
    if (l == 0) return;
    func_00421070(self->box);
    for (i = 0; i < l->count; i++) {
        char* t = Loc_LookupText(l->items[i].name);
        func_00421290(self->box, t ? t : l->items[i].name, 0, l->items[i].flag ? ON1 : ON0);
    }
    if (b < self->box->size) func_00424430(self->box, 0, b);
}



