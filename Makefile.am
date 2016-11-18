NULL =

AM_CFLAGS = $(WARN_CFLAGS)
CLEANFILES =
EXTRA_DIST =

GITIGNOREFILES = build-aux/ config.h.in aclocal.m4

noinst_PROGRAMS = test-goci

test_goci_SOURCES = \
	test-goci.c \
	$(NULL)
test_goci_LDADD = libgoci.la $(JSON_LIBS)
test_goci_CFLAGS = $(JSON_CFLAGS)

noinst_LTLIBRARIES = libgoci.la

include Makefile-goci.am

-include $(top_srcdir)/git.mk
