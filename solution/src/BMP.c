//
// Created by George Salnikov on 17.10.2022.
//
#include "../include/BMP.h"
#include "image_rotate.h"

#define TYPE 0x4D42
#include <inttypes.h>

struct bmp_header create_header(struct image const* image){
    struct bmp_header myHeader = {
            .bfType = TYPE,
            .bfileSize = image->height * image->width * sizeof(struct pixel) +
                         image->height * (image->width % 4) + sizeof(struct bmp_header),
            .bfReserved = 0,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,
            .biWidth = image->width,
            .biHeight = image->height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = image->height * image->width * sizeof(struct pixel) + (image->width % 4) * image->height,
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0,
    };
    return myHeader;
}

enum read_status from_bmp(FILE *in, struct image *image)
{
    struct bmp_header bh;
    if (fread(&bh, sizeof(struct bmp_header), 1, in) != 1)
    {

        return READ_INVALID_HEADER;
    }
    image->height = bh.biHeight;
    image->width = bh.biWidth;
    image->data = malloc(sizeof(struct pixel)*image->width*image->height);
    uint64_t pixel_counter = 0;
    const int64_t padding = get_padding(image);
    for (uint64_t i = 0; i < (image->height); i++) {
        uint64_t read_pixels = fread(&((image->data)[i * image->width]), sizeof(struct pixel), image->width, in);
        if (read_pixels != image->width) {
            free_img(image);
            return READ_ERROR;
        }

        pixel_counter += read_pixels;
        if (fseek(in, (long) padding, SEEK_CUR)) {
            free_img(image);
            return READ_ERROR;
        }
    }

    if (pixel_counter !=  image->width*image->height) {
        free_img(image);
        return READ_INVALID_BITS;
    }
    else{
        return READ_OK;

    }




}
enum write_status to_bmp(FILE *out, struct image const *image)
{
    if (out == NULL)
        return WRITE_ERROR;
    struct bmp_header myHeader = create_header(image);

    const int64_t padding = get_padding(image);
    const uint64_t value = 0;
    uint64_t pixel_counter = 0;
    if (fwrite(&myHeader, sizeof(struct bmp_header), 1, out) != 1)
        return WRITE_ERROR;
    for (uint64_t i = 0; i < (image->height ); i++)
    {

        uint64_t write_pixels =fwrite(&((image->data)[i*image->width]), sizeof(struct pixel), image->width, out);
        if (write_pixels!= image->width) {
            return WRITE_ERROR;
        }
        pixel_counter += write_pixels;

        if (fwrite(&value, 1, padding, out) != image->width % 4)
        {
            return WRITE_ERROR;
        }

    }
    if (pixel_counter !=  image->width*image->height) {
        return WRITE_INVALID_BITS;
    }
    else{
        return WRITE_OK;

    }



}
