#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SignalSema(int);
extern int D_00492CC8;

void unblock(void) {
    if (D_00492CC8 > 0) {
        SignalSema(D_00492CC8);
    }
}
