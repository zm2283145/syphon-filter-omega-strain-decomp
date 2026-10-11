#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Math_FModImpl();                                  

void Math_FMod(void) {
    Math_FModImpl();
}
