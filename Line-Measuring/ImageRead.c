#include "ImageRead.h"

ImageData *ImageFileRead(char *fileName, int desiredBytesPerPixel)
{
    ImageData *image=malloc(sizeof(ImageData));
    int width, height, originalBytesPerPixel;
    unsigned char *imagePixelRawData=stbi_load(fileName, &width, &height, &originalBytesPerPixel, desiredBytesPerPixel);
    image->width=width;
    image->height=height;
    image->originalBytesPerPixel=originalBytesPerPixel;
    if(desiredBytesPerPixel!=0)
        image->finalBytesPerPixel=desiredBytesPerPixel;
    else
        image->finalBytesPerPixel=originalBytesPerPixel;
    image->imagePixelRawData=imagePixelRawData;
    return image;
}

void ImageDataToFile(char *fileName, ImageData *image)
{
    unsigned returnValue = lodepng_encode32_file(fileName, image->imagePixelRawData, image->width, image->height);
    if(returnValue) printf("Nastapil blad przy zapisywaniu obrazu do pliku %u: %s\n", returnValue, lodepng_error_text(returnValue));
}

PixelData *PixelCoordinatesToPixelData (ImageData *image, int xCoordinate, int yCoordinate)
{
    PixelData *desiredPixel=malloc(sizeof(PixelData));
    int pixelDataPointer=0;
    pixelDataPointer=yCoordinate*image->width*image->finalBytesPerPixel;
    pixelDataPointer+=xCoordinate*image->finalBytesPerPixel;

    desiredPixel->numberOfComponents=image->finalBytesPerPixel;
    if(desiredPixel->numberOfComponents==1)
    {
        desiredPixel->redOrGray=image->imagePixelRawData[pixelDataPointer];
    }
    if(desiredPixel->numberOfComponents==2)
    {
        desiredPixel->redOrGray=image->imagePixelRawData[pixelDataPointer];
        desiredPixel->alpha=image->imagePixelRawData[pixelDataPointer+1];
    }
    if(desiredPixel->numberOfComponents==3)
    {
        desiredPixel->redOrGray=image->imagePixelRawData[pixelDataPointer];
        desiredPixel->green=image->imagePixelRawData[pixelDataPointer+1];
        desiredPixel->blue=image->imagePixelRawData[pixelDataPointer+2];
    }
    if(desiredPixel->numberOfComponents==4)
    {
        desiredPixel->redOrGray=image->imagePixelRawData[pixelDataPointer];
        desiredPixel->green=image->imagePixelRawData[pixelDataPointer+1];
        desiredPixel->blue=image->imagePixelRawData[pixelDataPointer+2];
        desiredPixel->alpha=image->imagePixelRawData[pixelDataPointer+3];
    }
    return desiredPixel;
}
