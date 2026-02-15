#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* input = NULL;
    FILE* output = NULL;
    char buffer[4096];

    if (argc < 3) {
        printf("smp2mp3 utility to decode/encode .smp files\n");
        printf("\n");
        printf("Usage: smp2mp3 [input_file] [output_file]\n");
        printf("\n");
        printf("input_file - .smp file for decoding, .mp3 file for encoding\n");
        printf("output_file - .mp3 file for decoding, .smp file for encoding\n");
        return -1;
    }

    input = fopen(argv[1], "rb");
    if (!input) {
        printf("Cannot open input file %s for reading\n", argv[1]);
        goto exit;
    }

    output = fopen(argv[2], "wb");
    if (!output) {
        printf("Cannot open output file %s for writing\n", argv[2]);
        goto exit;
    }

    while (!feof(input)) {
        size_t size = fread(buffer, 1, sizeof(buffer), input);
        for (size_t i = 0; i < size; ++i) {
            buffer[i] ^= 0x88;
        }
        fwrite(buffer, 1, size, output);
    }

exit:
    if (output)
        fclose(output);
    if (input)
        fclose(input);

    return 0;
}
