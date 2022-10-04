BINDIR=/usr/local/bin

all: termsize

install: termsize
	install -m 755 termsize $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(BINDIR)/termsize

test: termsize
	@test -t 1 || echo "stdout is not a tty"
	@test -t 0 || echo "stdin is not a tty"
	@tty       || echo "tty has failed"
	@stty size || echo "stty has failed"
	./termsize -h
	./termsize -t
	./termsize -t < /dev/null
	./termsize -t > /dev/null
	./termsize -t < /dev/null > /dev/null

clean:
	rm -f *~ termsize
