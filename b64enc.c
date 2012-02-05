/*
base64 encoder by David Lazar

Based off of blakesum.c
*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "base64encode.h"

#define BUFSIZE 32 * 1024

int main(int argc, char **argv) {
    uint8_t buf[BUFSIZE];
    char enc[2 * BUFSIZE];
    size_t c, i;
    char *file;
    FILE *fp;


    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    } else {
        file = argv[1];
    }

    if (strcmp(file, "-") == 0) {
        fp = stdin;
        freopen(NULL, "rb", stdin);
    } else if ((fp = fopen(file, "rb")) == NULL) {
        printf("cannot open %s\n", file);
        return 1;
    }

    base64_encodestate S;
    base64_encode_init(&S);

    while ((c = fread(buf, 1, BUFSIZE, fp)) > 0) {
        i = base64_encode_update(&S, buf, c, enc);
        fwrite(enc, 1, i, stdout);

        if (feof(fp))
            break;
    }
    if (ferror(fp)) {
        printf("%s: read error\n", file);
        if (fp != stdin)
            fclose(fp);
        return 1;
    }
    if (fp != stdin)
        fclose(fp);

    i = base64_encode_final(&S, enc);
    fwrite(enc, 1, i, stdout);
    fprintf(stdout, "\n");

    return 0;
}
