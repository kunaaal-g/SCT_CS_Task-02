#include <stdio.h>
#include <stdlib.h>
int main() 
{
    FILE *out = fopen("/data/data/ru.iiec.cxxdroid/files/output.ppm", "w");
    if (out == NULL) 
    {
        printf("❌ Cannot create output.ppm\n");
        return 1;
    }
    fprintf(out, "P3\n2 2\n255\n");
    int pixels[4][3] = {
        {255, 0, 0}, {0, 255, 0},
        {0, 0, 255}, {255, 255, 0}
    };
    for (int i = 0; i < 4; i++) 
    {
        int r = 255 - pixels[i][0];
        int g = 255 - pixels[i][1];
        int b = 255 - pixels[i][2];
        fprintf(out, "%d %d %d\n", r, g, b);
    }
    fclose(out);
    system("cp /data/data/ru.iiec.cxxdroid/files/output.ppm /sdcard/Download/output.ppm");
    printf("✅ Done! File copied to /sdcard/Download/output.ppm\n");
    return 0;
}