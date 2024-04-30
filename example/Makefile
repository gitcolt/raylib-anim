INCLUDES = -I../raylib-5.0/src
LIBRAYLIB = ../raylib-5.0/src/libraylib.a
LIBS = -lm

example: example.c $(LIBRAYLIB) ../anim.c ../animator.c
	$(CC) $(LIBS) $(INCLUDES) -O0 -g -L. -o $@ $^

.PHONY: raylib
raylib: $(LIBRAYLIB)
$(LIBRAYLIB):
	make PLATFORM=PLATFORM_DESKTOP RAYLIB_BUILD_MODE=DEBUG -C ../raylib-5.0/src

.PHONY: clean
clean:
	rm -f example
	make clean -C ../raylib-5.0/src
