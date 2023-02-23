//
// Created by George Salnikov on 20.10.2022.
//
#include "../include/image.h"
#include "../include/image_rotate.h"

int32_t get_padding(struct image const* img){
    if((img->width*sizeof(struct pixel))%4 == 0) return 0;
    else{
        return 4 - (int32_t)(img->width*sizeof(struct pixel))%4;
    }

}
struct pixel get_pixel(struct image const *source, int32_t i){
    struct pixel new_px = (source->data[(source->height * source->width - source->width * (i % source->height + 1) + i / source->height)]);
    return new_px;

}
struct image rotate(struct image const *source)
{
    struct image output = image_create(source->height, source->width);
    for (int32_t i = 0; i < output.height * output.width; i++)
    {
        struct pixel new_px =  get_pixel(source,i );
        output.data[i] = new_px;
    }
    return output;
}
