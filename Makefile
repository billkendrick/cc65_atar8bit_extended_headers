# Makefile for cc65_atar8bit_extended_headers
# Bill Kendrick <bill@newbreedsoftware.com>
# 2015-07-17 - 2015-07-17

PREFIX=/usr/local/share/cc65/include/atari

all:
	@echo
	@echo "Use e.g. 'sudo make install' to install .h files"
	@echo "to an 'extended_headers' subdirectory of '${PREFIX}'."
	@echo
	@echo "Specify '... make install PREFIX=/path/to/dest'"
	@echo "to override default destination."
	@echo

install:
	mkdir -p ${PREFIX}/extended_headers
	cp extended_headers/* ${PREFIX}/extended_headers/
