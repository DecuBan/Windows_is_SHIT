#include <raylib.h>

int main(int argc, char *argv[])
{
    const char *fileName = argv[1];
    int dataSize = 0;
    unsigned char *data = LoadFileData(fileName, &dataSize);

    const char *outFileName = argv[2];
    if (!ExportDataAsCode(data, dataSize, outFileName))
        return 1;

    UnloadFileData(data);

    return 0;
}
