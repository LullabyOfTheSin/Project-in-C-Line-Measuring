#define STB_IMAGE_IMPLEMENTATION
#include "Interface.h"
#include "MarchingSquares.h"

int main (int argc, char *argv[])
{
    if(argc>=3)
    {
        int pixelDataPointer;
        LineStorage *lineStoragePointer=malloc(sizeof(LineStorage));
        int isoValue=128;
        if(argc==4)
            isoValue=atoi(argv[3]);

        ImageData *image=ImageFileRead(argv[1], 4);
        printf("Obraz wejsciowy:\nWymiary: %d na %d\nKomponenty na pixel: domyslnie %d, wymuszono %d",image->width, image->height, image->originalBytesPerPixel, image->finalBytesPerPixel);

        image=ImageThresholdApply(image, isoValue, image->finalBytesPerPixel);
        image=MarchingSquaresAlgoritm(image);
        ImageDataToFile(argv[2],image);

        for(int row=0; row<image->height; row++)
        {
            for(int column=0; column<image->width; column++)
            {
                pixelDataPointer=row*image->width*image->finalBytesPerPixel;
                pixelDataPointer+=column*image->finalBytesPerPixel;
                if(image->imagePixelRawData[pixelDataPointer]==50)
                    LineMeasurent(image, lineStoragePointer, column, row);
            }
        }

        InterfaceInit(argc, argv);
    }
    else
        printf("Minimalna ilosc argumentow to dwie nazwy plikow graficznych, z czego drugi koniecznie png!");
    return 0;
}
