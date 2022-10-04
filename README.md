termsize
========

Print the terminal/teletype (TTY) name, the number of columns and rows, the number of pixels (width and height).

Build & Install
---------------

With a C compiler (GCC/LLVM) installed, do the `make` command:

```shell
$ make
$ sudo make install
```

Usage
-----

```shell
$ termsize
/dev/ttys000: 80 columns x 24 rows (640 x 408 pixels)
```

The terminal (TTY) name is `ttys000` and has 80 columns by 24 rows inside a window with 640×408 pixels.

License
-------

See the LICENSE file.
