#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                         
int std_list_deleter_voidPtr_begin_void(...);                          
int std_vector_deleter_cSkaSliderValue_dtor(...);                            
int std_vector_deleter_cSkaSwitchValue_dtor(...);                            
int std_list_cSkaTransPlaybackPtr_dtor(...);                            
int cLListIterator_cSkaTransPlaybackPtr_ctor(...);                        
int std_list_cSkaTransPlaybackPtr_end(...);                          
int std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(...);                      
int std_vector_deleter_cSkaAnimAnchorListEntry_dtor(...);                            
int std_deque_deleter_cSkaSystem_Request_dtor(...);                            
int operator_delete(...);                             
extern unsigned char g_ProfileLockEnabled;
}
#pragma inline_depth(10)
static inline void itb_(char **o, char *l) { int r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(o, &r); }
static inline void ite_(char **o, char *l) { int r; std_list_cSkaTransPlaybackPtr_end(&r, l); cLListIterator_cSkaTransPlaybackPtr_ctor(o, &r); }
extern "C" int cSkaParams_dtor(char *arg0, long long arg1) {
    int temp_a0_4;
    int temp_a0_6;
    int temp_a0_2;
    int sp6C;
    int temp_s3;
    int temp_a0_3;
    char * sp68;
    char * var_s0;
    int sp5C;
    int temp_a0_5;
    int sp60;
    int temp_a0;

    if (arg0 != 0) {
        itb_((char **)&sp68, (char *)(arg0 + 0x6C));
        var_s0 = sp68;
        while (ite_((char **)&sp6C, (char *)(arg0 + 0x6C)), (int)var_s0 != (int)sp6C) {
                temp_s3 = F_(var_s0, 0x8, int);
                {
                    AllocGuard g;
                cMemMan_Deallocate(0, temp_s3, "ska.icc", 0x423);
                }
                var_s0 = (char *)(F_(var_s0, 0x4, int));
        }
        temp_a0 = (int)(arg0 + 0xA0);
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            std_vector_deleter_cSkaAnimAnchorListEntry_dtor(temp_a0, 0);
        }
        temp_a0_2 = (int)(arg0 + 0x88);
        if ((temp_a0_2 != 0) && (temp_a0_2 != 0) && (temp_a0_2 != 0)) {
            std_vector_deleter_cSkaSwitchValue_dtor(temp_a0_2, 0);
        }
        temp_a0_3 = (int)(arg0 + 0x78);
        if ((temp_a0_3 != 0) && (temp_a0_3 != 0) && (temp_a0_3 != 0) && (temp_a0_3 != 0)) {
            std_vector_deleter_cSkaSliderValue_dtor(temp_a0_3, 0);
        }
        temp_a0_4 = (int)(arg0 + 0x6C);
        if (temp_a0_4 != 0) {
            std_list_cSkaTransPlaybackPtr_dtor(temp_a0_4, 0);
        }
        temp_a0_5 = (int)(arg0 + 0x54);
        if ((arg0 + 0x24) != 0) {
            if ((temp_a0_5 != 0) && (temp_a0_5 != 0) && (temp_a0_5 != 0)) {
                std_deque_deleter_cSkaSystem_Request_dtor(temp_a0_5, 0);
            }
            temp_a0_6 = (int)(arg0 + 0x3C);
            if ((temp_a0_6 != 0) && (temp_a0_6 != 0) && (temp_a0_6 != 0)) {
                std_deque_deleter_cSkaSystem_Request_dtor(temp_a0_6, 0);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (int)(arg0);
}
