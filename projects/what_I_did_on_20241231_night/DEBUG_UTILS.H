// DebugUtils.h
#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <iostream>
#include <stdexcept>

// 调试宏
#define DEBUG_TRY try {
#define DEBUG_CATCH } catch (const std::exception& e) { \
    std::cerr << "异常捕获： " << e.what() << std::endl; \
}

// 调试类
class Debugger {
public:
    template <typename Func>
    static auto debugRun(Func func) -> decltype(func()) {
        try {
            return func();
        } catch (const std::exception& e) {
            std::cerr << "异常捕获： " << e.what() << std::endl;
            throw;
        }
    }
};

#endif // DEBUG_UTILS_H