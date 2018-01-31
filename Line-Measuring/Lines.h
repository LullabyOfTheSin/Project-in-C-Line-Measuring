#include "ImageRead.h"

typedef struct LineStorage
{
    int xStartingCoordinate;
    int yStartingCoordinate;
    int pixelLength;
    struct LineStorage *nextLine;
}LineStorage;

LineStorage *LineMeasurent(ImageData *image, LineStorage *pointer, int xStartingCoordinate, int YStartingCoordinate);
