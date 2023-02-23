
#include "../include/image.h"
#include "../include/image_rotate.h"
int main(int argc, char **argv){
    (void)argc;
    (void)argv; // supress 'unused parameters' warning
    const char *in = argv[1];
    const char *out = argv[2];

    struct image img;
    if (in==NULL || out==NULL)
        return OPEN_ERROR;
    else {
        FILE *f1 = fopen(in, "rb");
        FILE *f2 = fopen(out, "wb");

        if (from_bmp(f1, &img) == READ_ERROR) {
            return READ_ERROR;
        } else {
            struct image rot = rotate(&img);

            free_img(&img);

            if (to_bmp(f2, &rot) == WRITE_ERROR)
                return WRITE_ERROR;
            else {
                free_img(&rot);
                return 0;
            }
        }
    }

}



