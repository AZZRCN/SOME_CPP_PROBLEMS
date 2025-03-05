#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include "lodepng.cpp"
#include <map>
#include <numeric>
#include <math.h>
#include <limits>
using namespace std;
int matchCmdColor(int r, int g, int b) {
    // 定义CMD颜色代码
    std::map<int, std::tuple<int, int, int>> cmdColors = {
        {0, {0, 0, 0}},  // 黑色
        {1, {128, 0, 0}},  // 红色
        {2, {0, 128, 0}},  // 绿色
        {3, {128, 128, 0}},  // 黄色
        {4, {0, 0, 128}},  // 蓝色
        {5, {128, 0, 128}},  // 品红色
        {6, {0, 128, 128}},  // 青色
        {7, {192, 192, 192}},  // 白色
        {8, {128, 128, 128}},  // 灰色
        {9, {255, 0, 0}},  // 亮红色
        {10, {0, 255, 0}},  // 亮绿色
        {11, {255, 255, 0}},  // 亮黄色
        {12, {0, 0, 255}},  // 亮蓝色
        {13, {255, 0, 255}},  // 亮品红色
        {14, {0, 255, 255}},  // 亮青色
        {15, {255, 255, 255}}  // 亮白色
    };

    // 找到最接近的颜色代码
    int closestColor = 0;
    double minDistance = std::numeric_limits<double>::max();
    for (const auto& pair : cmdColors) {
        double distance = std::sqrt(
            std::pow(std::get<0>(pair.second) - r, 2) +
            std::pow(std::get<1>(pair.second) - g, 2) +
            std::pow(std::get<2>(pair.second) - b, 2)
        );
        if (distance < minDistance) {
            minDistance = distance;
            closestColor = pair.first;
        }
    }

    return closestColor;
}
unsigned char * image;//图像
unsigned char* p;//读取
unsigned width, height;
HANDLE STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
void color(int x){
    SetConsoleTextAttribute(STDOUT, x);
}
void read(){
    color(matchCmdColor(*(p++),*(p++),*(p++)));
    putchar('#');
}
int main(){
	const char* filename =  "488.png";
	lodepng_decode24_file(&image, &width, &height, filename);
    p = image;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= width; j++){
            read();
        }
        putchar('\n');
    }
    free(image);

	color(7);
	return 0;
}