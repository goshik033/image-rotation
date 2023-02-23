//
// Created by George Salnikov on 17.10.2022.
//

#ifndef ASSIGNMENT_IMAGE_ROTATION_BMP_H
#define ASSIGNMENT_IMAGE_ROTATION_BMP_H
#include "BMP_structure.h"
#include "image.h"

enum read_status
{
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_ERROR

};
enum open_status
{
    OPEN_OK = 0,
    OPEN_ERROR

};
enum read_status from_bmp(FILE *in, struct image *image);
enum write_status
{
    WRITE_OK = 0,
    WRITE_ERROR,
    WRITE_INVALID_BITS

};
enum write_status to_bmp(FILE *out, struct image const *image);
#endif // ASSIGNMENT_IMAGE_ROTATION_BMP_H
