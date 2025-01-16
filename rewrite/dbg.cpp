#ifndef AZZR_DBG
#define AZZR_DBG
class str_err {
public:
    const char* message;
    str_err(const char* msg) : message(msg) {}
    const char* what() const {
        return message;
    }
};
#endif