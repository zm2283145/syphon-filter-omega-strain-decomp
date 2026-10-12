#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00107718(char * , int);                         
int func_00107748(char * );                            
int func_00107ED8();                       
int func_0010BD90(char * , char *);                       

void func_00108790(char * arg0) {
    int temp_v0;
    int temp_v0_2;

    temp_v0 = func_00107ED8(arg0, 1);
    F_(arg0, 0x858, int) = temp_v0;
    if (temp_v0 != 0) {
        func_00107748(arg0);
        func_00107718(arg0, 0x50000000);
        func_00107748(arg0);
    }
    temp_v0_2 = func_00107ED8(arg0, 1);
    F_(arg0, 0x85C, int) = temp_v0_2;
    if (temp_v0_2 != 0) {
        func_00107748(arg0);
        func_00107718(arg0, 0x58000000);
        func_00107748(arg0);
    }
    if (func_00107ED8(arg0, 1) != 0) {
        func_0010BD90(arg0, "load_chroma_intra_quantizer_matrix == 1");
    }
    if (func_00107ED8(arg0, 1) != 0) {
        func_0010BD90(arg0, "load_chroma_non_intra_quantizer_matrix == 1");
    }
}
