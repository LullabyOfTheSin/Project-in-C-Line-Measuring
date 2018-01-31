#include "MarchingSquares.h"

ImageData *ImageThresholdApply(ImageData *originalImage, int isoValue, int tresholdingMode)
{
    int pixelDataPointer=0;
    ImageData *thresholdedImage=originalImage;
    thresholdedImage->width=originalImage->width;
    thresholdedImage->height=originalImage->height;
    thresholdedImage->originalBytesPerPixel=originalImage->originalBytesPerPixel;
    thresholdedImage->finalBytesPerPixel=originalImage->finalBytesPerPixel;
    thresholdedImage->imagePixelRawData=originalImage->imagePixelRawData;

    switch(tresholdingMode)
    {
    case 1:
        for(int row=0; row<originalImage->height; row++)
        {
            for(int column=0; column<originalImage->width; column++)
            {
                pixelDataPointer=row*thresholdedImage->width;
                pixelDataPointer+=column;
                if(thresholdedImage->imagePixelRawData[pixelDataPointer]>=isoValue)
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=255;
                else
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=0;
            }
        }
        break;
    case 2:
        for(int row=0; row<originalImage->height; row++)
        {
            for(int column=0; column<originalImage->width; column++)
            {
                pixelDataPointer=row*thresholdedImage->width*2;
                pixelDataPointer+=column*2;
                if((thresholdedImage->imagePixelRawData[pixelDataPointer]+thresholdedImage->imagePixelRawData[pixelDataPointer+1])/2>=isoValue)
                    {
                        thresholdedImage->imagePixelRawData[pixelDataPointer]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+1]=255;
                    }
                else
                {
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+1]=255;
                }
            }
        }
        break;
    case 3:
        for(int row=0; row<originalImage->height; row++)
        {
            for(int column=0; column<originalImage->width; column++)
            {
                pixelDataPointer=row*thresholdedImage->width*3;
                pixelDataPointer+=column*3;
                if((thresholdedImage->imagePixelRawData[pixelDataPointer]+thresholdedImage->imagePixelRawData[pixelDataPointer+1]+thresholdedImage->imagePixelRawData[pixelDataPointer+2])/3>=isoValue)
                    {
                        thresholdedImage->imagePixelRawData[pixelDataPointer]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+1]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+2]=255;
                    }
                else
                {
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+1]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+2]=0;
                }
            }
        }
        break;
    case 4:
        for(int row=0; row<originalImage->height; row++)
        {
            for(int column=0; column<originalImage->width; column++)
            {
                pixelDataPointer=row*thresholdedImage->width*4;
                pixelDataPointer+=column*4;
                if((thresholdedImage->imagePixelRawData[pixelDataPointer]+thresholdedImage->imagePixelRawData[pixelDataPointer+1]+thresholdedImage->imagePixelRawData[pixelDataPointer+2]+thresholdedImage->imagePixelRawData[pixelDataPointer+3])/4>=isoValue)
                    {
                        thresholdedImage->imagePixelRawData[pixelDataPointer]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+1]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+2]=255;
                        thresholdedImage->imagePixelRawData[pixelDataPointer+3]=255;
                    }
                else
                {
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+1]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+2]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+3]=255;
                }
            }
        }
        break;
    }
    return thresholdedImage;
}



ImageData *MarchingSquaresAlgoritm(ImageData *thresholdedImage)
{
    int pixelDataPointer=0;

    PixelData *pixelUL, *pixelUR, *pixelBR, *pixelBL;
    pixelUL=malloc(sizeof(PixelData));
    pixelUR=malloc(sizeof(PixelData));
    pixelBR=malloc(sizeof(PixelData));
    pixelBL=malloc(sizeof(PixelData));
    for(int row=1; row<thresholdedImage->height; row++)
    {
        for(int column=1; column<thresholdedImage->width; column++)
        {
            pixelUL=PixelCoordinatesToPixelData(thresholdedImage,column-1,row-1);
            pixelUR=PixelCoordinatesToPixelData(thresholdedImage,column,row-1);
            pixelBR=PixelCoordinatesToPixelData(thresholdedImage,column,row);
            pixelBL=PixelCoordinatesToPixelData(thresholdedImage,column-1,row);
            if(pixelUL->redOrGray==0 || pixelUR->redOrGray==0 || pixelBR->redOrGray==0 || pixelBL->redOrGray==0)
            {

                if(pixelUL->redOrGray==255)
                {
                    pixelDataPointer=(row-1)*thresholdedImage->width*thresholdedImage->finalBytesPerPixel;
                    pixelDataPointer+=(column-1)*thresholdedImage->finalBytesPerPixel;
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=50;
                }
                if(pixelUR->redOrGray==255)
                {
                    pixelDataPointer=(row-1)*thresholdedImage->width*thresholdedImage->finalBytesPerPixel;
                    pixelDataPointer+=(column)*thresholdedImage->finalBytesPerPixel;
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=50;
                }
                if(pixelBR->redOrGray==255)
                {
                    pixelDataPointer=(row)*thresholdedImage->width*thresholdedImage->finalBytesPerPixel;
                    pixelDataPointer+=(column)*thresholdedImage->finalBytesPerPixel;
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=50;
                }
                if(pixelBL->redOrGray==255)
                {
                    pixelDataPointer=(row)*thresholdedImage->width*thresholdedImage->finalBytesPerPixel;
                    pixelDataPointer+=(column-1)*thresholdedImage->finalBytesPerPixel;
                    thresholdedImage->imagePixelRawData[pixelDataPointer]=50;
                }
            }

        }
    }

    for(int row=0; row<thresholdedImage->height; row++)
    {
        for(int column=0; column<thresholdedImage->width; column++)
        {

            pixelDataPointer=row*thresholdedImage->width*thresholdedImage->finalBytesPerPixel;
            pixelDataPointer+=column*thresholdedImage->finalBytesPerPixel;
            if(thresholdedImage->imagePixelRawData[pixelDataPointer]!=50)
            {
                thresholdedImage->imagePixelRawData[pixelDataPointer]=0;
                if(thresholdedImage->finalBytesPerPixel>=3)
                {
                    thresholdedImage->imagePixelRawData[pixelDataPointer+1]=0;
                    thresholdedImage->imagePixelRawData[pixelDataPointer+2]=0;
                }
            }

        }
    }

    return thresholdedImage;
}

