//
// Created by George Salnikov on 17.10.2022.
//

#ifndef ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
#define ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"


struct pixel
{
    uint8_t r, g, b;
};

struct image
{
    uint64_t width, height;
    struct pixel *data;
};
void free_img(struct image *image);
struct image image_create(size_t width, size_t height);

#endif // ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
