#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct VC_EE70 { virtual int v0(int); };
struct Raw_EE70 { int p; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter(int*, char*, int*);
Raw_EE70 std_list_deleter_voidPtr_begin_void(void*);
Raw_EE70 std_list_cInterfaceElementPtr_end(void*);
void std_list_cInterfaceElementPtr_generic_iterator_ctor(char**, const Raw_EE70&);
void cLListIterator_cInterfaceElementPtr_ctor(char**, const Raw_EE70&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
}
extern "C" void cInterfaceModel_DestroyInstance(char* self, VC_EE70* obj) {
    char* end;
    {
        VC_EE70* e;
        char* n;
        char* cur;
        char* it;
        std_list_cInterfaceElementPtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(self + 0x8C));
        n = it;
        while ((cLListIterator_cInterfaceElementPtr_ctor(&end, std_list_cInterfaceElementPtr_end(self + 0x8C)), n != end)) {
            e = F_(n, 0x8, VC_EE70*);
            if (e == obj) {
                cur = n;
                n = F_(n, 0x4, char*);
                {
                    AllocGuard g;
                    e->v0(-1);
                    cMemMan_Deallocate(0, e, "interface_model.cc", 0x218);
                }
                {
                    char* c;
                    int res;
                    int pos;
                    c = cur;
                    std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                    std_list_deleter_voidPtr_erase_listdeleter(&res, self + 0x8C, &pos);
                }
            } else {
                n = F_(n, 0x4, char*);
            }
        }
    }
    if (F_(self, 0x8C, int) == 0) F_(self, 0x60, unsigned char) = 0;
}