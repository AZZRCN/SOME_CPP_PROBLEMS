#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include "lodepng.cpp"
using namespace std;
int main(){
	unsigned error;//错误
	unsigned char * image;//图像
    unsigned width, height;
	const char* filename =  "488.png";
	const char* filename_new =  "out.png";
	error =lodepng_decode32_file(&image, &width, &height, filename);
	//error =lodepng_decode24_file(&image, &width, &height, filename);//image内存的大小是多少
    if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

	printf("error is %d,,width is %d ,height is %d\r\n",error,width,height);
    printf("%d,%d,%d\n",image[0],image[1],image[2]);
	//lodepng_encode24_file(filename_new, image, width, height);



    //写入
    	FILE *fp;
	//fp = fopen("E:\\face\\19_32.raw","w");//生成raw图片是这样生成的吗
	fp = fopen("E:\\face\\2_1211.raw","wb");//生成raw图片是这样生成的吗  //一定要用wb打开二进制
	//fwrite(image, width*height*3 , 1, fp);
	fwrite(image, width*height*4 , 1, fp);
	//fwrite(image, width*height*4 , 1, fp);
	fclose(fp);

   free(image);

	
	return 0;
}