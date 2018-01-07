#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;
#pragma warning (disable : 4996)

union RGB {
	unsigned char r;
	unsigned char g;
	unsigned char b;
}pixel[3] = {25,117,126 };




int main()
{


	unsigned int width =252 , height = 252;
	unsigned int bpp = 24;
	unsigned int rowsize = ((bpp*width + 31) / 32) * 4;
	unsigned int area = width*height;
	unsigned int sizeOfArr = rowsize *height;
	unsigned int fileSize = 54 + sizeOfArr;

	unsigned int resolution = 2835;//see wiki. 72dpi* 39.3701 in/meter

	unsigned char bmpfileheader[14] = { 'B','M',   0,0,0,0 ,   0,0,0,0 ,   54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0,  width,0,0,0,   height,0,0,0 ,   1,0,24,0 };

	
	bmpinfoheader[25] = (unsigned char)(resolution);      //horizontal resolutions
	
	bmpinfoheader[29] = (unsigned char)(resolution);      //vertical resolutions
	

	FILE *pfile = fopen("image.bmp", "wb");
	fwrite(bmpfileheader, 1, 14, pfile);
	fwrite(bmpinfoheader, 1, 40, pfile);

				

	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			fwrite(pixel, sizeof(unsigned char), 3, pfile);
		}

	}

	
	fclose(pfile);

	

	
	
	return 0;






