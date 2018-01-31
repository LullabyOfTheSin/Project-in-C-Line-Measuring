#define STB_IMAGE_IMPLEMENTATION
#include "Interface.h"
#include "MarchingSquares.h"

int main (int argc, char *argv[])
{

    ImageData *image=ImageFileRead(argv[1], 3);

   ImageData *test=ImageThresholdApply(image, 100, 3);
   ImageData *moarTest=MarchingSquaresAlgoritm(test);
    ImageDataToFile(argv[2],moarTest);
    InterfaceInit(argc, argv);
    return 0;
}
