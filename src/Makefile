##
# Tokenizer
#
# @src/Makefile
# @version 0.1

tokenizer: tokenizer.o
	${CC} -o $@ $^

%.o: %.c
	${CC} -g -c $^ # keep debugging symbols

# end
