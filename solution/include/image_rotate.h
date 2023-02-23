//
// Created by George Salnikov on 17.10.2022.
//

#ifndef ASSIGNMENT_IMAGE_ROTATION_IMAGE_ROTATE_H
#define ASSIGNMENT_IMAGE_ROTATION_IMAGE_ROTATE_H
#include "BMP.h"
#include "image.h"
#include <stdio.h>

struct image rotate(struct image const *source);
int32_t get_padding(const struct image * img);
struct pixel get_pixel(struct image const *source, int32_t i);
#endif // ASSIGNMENT_IMAGE_ROTATION_IMAGE_ROTATE_H
