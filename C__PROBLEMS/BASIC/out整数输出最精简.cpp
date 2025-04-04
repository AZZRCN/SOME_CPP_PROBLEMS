template<typename T>void __out(T x){if(x)__out(x/10),putchar(x%10+'0');}
template<typename T>void out(T x){x?__out(x),0:putchar('0');}