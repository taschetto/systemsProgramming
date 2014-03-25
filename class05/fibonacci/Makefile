compiler = g++
cflags   = -Wall
ldflags  = -c -Wall -pg
sources	 = main.c
objects  = $(sources:.c=.o)
folder   = $(shell basename '$(CURDIR)')
target	 = $(folder)

all: $(sources) $(target)
	
$(target): $(objects) 
	$(compiler) $(objects) -o $@

.c.o:
	$(compiler) $(ldflags) $<

clean:
	rm -fr *.o $(target)
