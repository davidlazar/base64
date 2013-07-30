#include "base64encode.h"
#include <sym-api.h>

#define STR(x) #x
#define XSTR(x) STR(x)
#define OUTLEN 4 * ((INLEN + 2) / 3)

int main() {
    uint8_t *data = lss_fresh_array_uint8(INLEN, 0, NULL);
    char result[OUTLEN];
    base64_encode(data, INLEN, result);
    lss_write_aiger_array_uint8((uint8_t *) result, OUTLEN, XSTR(AIGFILE));

    return 0;
}
