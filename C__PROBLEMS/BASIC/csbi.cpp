#include <windows.h>

//!IMPORTANT!
//!重要!
//THE HEIGHT IS ALWAYS 0 IN VSCODE
//height在vscode一直是0
//AND THAT'S NORMAL
//这是正常的
class csbi {
public:
    short width = 0;
    short height = 0;

    csbi() { update(); }
    void update() {
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) {
            width  = info.srWindow.Right  - info.srWindow.Left + 1;
            height = info.srWindow.Bottom - info.srWindow.Top + 1;
        }
    }
};

#include <iostream>

int main() {
    csbi console;
    std::cout << "Width: " << console.width << ", Height: " << console.height << "\n";

    // 等待用户按键后更新尺寸
    std::cin.get();
    console.update();
    std::cout << "New Width: " << console.width << ", New Height: " << console.height << "\n";

    return 0;
}