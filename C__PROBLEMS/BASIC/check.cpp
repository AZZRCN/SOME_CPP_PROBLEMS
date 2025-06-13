inline bool is_digit(char c){return (c>='0')&&(c<='9');}
inline bool is_char(char c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z');}
inline constexpr bool is_c(const unsigned char& c){return (unsigned)((c&0xDFU)-0x41U)<26U;}
inline constexpr bool is_d(const unsigned char& c){return (unsigned)(c^0x30U)<10U;}