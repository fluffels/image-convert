#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using std::cout;
using std::endl;

struct Header {
    uint32_t width;
    uint32_t height;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    char* path = argv[1];
    char outPath[1024];
    sprintf_s(outPath, "%s.dat", path);

    int x, y, n;
    unsigned char *data = stbi_load(path, &x, &y, &n, 4);
    int size = x * y * 4;

    Header header = { uint32_t(x), uint32_t(y) };

    FILE* outFile;
    fopen_s(&outFile, outPath, "wb");

    fwrite(&header, sizeof(header), 1, outFile);
    fwrite(data, size, 1, outFile);

    return 0;
}
