CFLAGS = -O3 -Wall -Wextra -pedantic -std=c99

b64enc: b64enc.c base64encode.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	rm -f b64enc
