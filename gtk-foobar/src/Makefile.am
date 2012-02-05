## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(GTK_FOOBAR_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gtk_foobar

gtk_foobar_SOURCES = \
	main.c

gtk_foobar_LDFLAGS = \
	-Wl,--export-dynamic

gtk_foobar_LDADD = $(GTK_FOOBAR_LIBS)

