/*
 * Copyright (c) 2019-2022 Ruda Moura. All rights reserved.
 */

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
fatal(const char *s, int status)
{
	fprintf(stderr, "%s: stdin/stdout isn't a terminal (tty)\n", s);
	perror(s);
	exit(status);
}

void
usage(const char *progname, int status)
{
	fprintf(stderr, "usage: %s [-h | -t]\n", progname);
	exit(status);
}

int
main(int argc, char *argv[])
{
	char *progname = argv[0];
	char *tty = NULL;
	struct winsize ws;
	int status = EXIT_FAILURE;
	int ch;
	while ((ch = getopt(argc, argv, "ht")) != -1) {
		switch (ch) {
		case 'h': /* help */
			usage(progname, EXIT_SUCCESS);
			break;
		case 't': /* test mode: fatal() exits with SUCCESS */
			status = EXIT_SUCCESS;
			break;
		case '?': /* usage */
		default:
			usage(progname, EXIT_FAILURE+1);
		}
	}
	if ((tty = ttyname(STDOUT_FILENO)) == NULL)
		if ((tty = ttyname(STDIN_FILENO)) == NULL)
			fatal(progname, status);
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
		if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
			fatal(progname, status);
	printf("%s: %d columns x %d rows", tty, ws.ws_col, ws.ws_row);
	if (ws.ws_xpixel && ws.ws_ypixel)
		printf(" (%d x %d pixels)\n", ws.ws_xpixel, ws.ws_ypixel);
	else
		printf("\n");
	return EXIT_SUCCESS;
}
