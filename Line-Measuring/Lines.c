#include "Lines.h"

LineStorage *LineMeasurent(ImageData *image, LineStorage *pointer, int xStartingCoordinate, int yStartingCoordinate)
{
    int xCoordinate=xStartingCoordinate+1, yCoordinate=yStartingCoordinate, direction=1, pixelDataPointer;
    PixelData *pixelUL, *pixelUR, *pixelBR, *pixelBL;
    pixelUL=malloc(sizeof(PixelData));
    pixelUR=malloc(sizeof(PixelData));
    pixelBR=malloc(sizeof(PixelData));
    pixelBL=malloc(sizeof(PixelData));

    while(1)
    {
        if(xCoordinate==xStartingCoordinate && yCoordinate==yStartingCoordinate)
        {
            pointer->pixelLength++;
            return pointer;
        }
        else
        {
            pointer->pixelLength++;
            pixelUL=PixelCoordinatesToPixelData(image,xCoordinate-1,yCoordinate-1);
            pixelUR=PixelCoordinatesToPixelData(image,xCoordinate,yCoordinate-1);
            pixelBR=PixelCoordinatesToPixelData(image,xCoordinate,yCoordinate);
            pixelBL=PixelCoordinatesToPixelData(image,xCoordinate-1,yCoordinate);

            pixelDataPointer=yCoordinate*image->width*image->finalBytesPerPixel;
            pixelDataPointer+=xCoordinate*image->finalBytesPerPixel;
            image->imagePixelRawData[pixelDataPointer]=150;

            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray==0 && pixelBR->redOrGray==0 && pixelBL->redOrGray==0)
            {
                xCoordinate--;
                direction=3;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray==0 && pixelBL->redOrGray==0)
            {
                yCoordinate--;
                direction=4;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray==0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray==0)
            {
                xCoordinate++;
                direction=1;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray==0 && pixelBR->redOrGray==0 && pixelBL->redOrGray!=0)
            {
                yCoordinate++;
                direction=2;
            }




            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray==0 && pixelBL->redOrGray==0)
            {
                xCoordinate--;
                direction=3;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray==0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray!=0)
            {
                xCoordinate++;
                direction=1;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray==0)
            {
                yCoordinate--;
                direction=4;
            }
            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray==0 && pixelBR->redOrGray==0 && pixelBL->redOrGray!=0)
            {
                yCoordinate++;
                direction=2;
            }




            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray==0)
            {
                yCoordinate++;
                direction=2;
            }
            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray==0 && pixelBL->redOrGray!=0)
            {
                xCoordinate++;
                direction=1;
            }
            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray==0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray!=0)
            {
                yCoordinate--;
                direction=4;
            }
            if(pixelUL->redOrGray==0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray!=0)
            {
                xCoordinate--;
                direction=3;
            }




            if(pixelUL->redOrGray==0 && pixelUR->redOrGray!=0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray==0)
            {
                if(direction==1)
                {
                    yCoordinate--;
                    direction=4;
                }
                else
                if(direction==2)
                {
                    xCoordinate--;
                    direction=3;
                }
                else
                if(direction==3)
                {
                    yCoordinate++;
                    direction=2;
                }
                else
                if(direction==4)
                {
                    xCoordinate++;
                    direction=1;
                }

            }
            if(pixelUL->redOrGray!=0 && pixelUR->redOrGray==0 && pixelBR->redOrGray!=0 && pixelBL->redOrGray==0)
            {
                if(direction==3)
                {
                    yCoordinate--;
                    direction=4;
                }
                else
                if(direction==4)
                {
                    xCoordinate--;
                    direction=3;
                }
                else
                if(direction==1)
                {
                    yCoordinate++;
                    direction=2;
                }
                else
                if(direction==2)
                {
                    xCoordinate++;
                    direction=1;
                }
            }
        }
    }
}
