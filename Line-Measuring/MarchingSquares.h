#include "Lines.h"
#include "ImageRead.h"

ImageData *ImageThresholdApply(ImageData *originalImage, int isoValue, int tresholdingMode);

ImageData *MarchingSquaresAlgoritm(ImageData *tresholdedImage);
