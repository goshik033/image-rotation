//
// Created by George Salnikov on 18.10.2022.
//

#include "../include/image.h"


void free_img(struct image *image)
{
    free(image->data);
    image->data = NULL;
    image->width = 0;
    image->height = 0;
}
struct image image_create(const size_t width, const size_t height) {
    return ((struct image) {.width = width, .height = height, .data = malloc(width * height * sizeof(struct pixel))});
}




