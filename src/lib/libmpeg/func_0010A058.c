#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int _sysbitNext(int, int);                               
int _sysbitFlush(int, int);                            

int _sysbitMarker(int arg0) {
    int temp_s1;

    temp_s1 = _sysbitNext(arg0, 1);
    _sysbitFlush(arg0, 1);
    return temp_s1;
}
