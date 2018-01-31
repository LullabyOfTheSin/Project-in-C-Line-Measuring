#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include "stb_image.h"

typedef struct ImageData
{
    int width;
    int height;
    int originalBytesPerPixel;
    int finalBytesPerPixel;
    unsigned char *imagePixelRawData;
}ImageData;

typedef struct PixelData
{
    int numberOfComponents;
    unsigned char redOrGray;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
}PixelData;

ImageData *ImageFileRead(char *fileName, int desiredBytesPerPixel);

void ImageDataToFile(char *fileName, ImageData *image);

PixelData *PixelCoordinatesToPixelData (ImageData *image, int xCoordinate, int yCoordinate);
