# We cannot use stlport on the simulator because it conficts with the host stl
# library. Android's port also relies on bionic which is not built for the
# simulator either.
ifneq ($(TARGET_SIMULATOR),true)
LOCAL_PATH := $(call my-dir)

#####################################################
# kalen.lee@lge.com create it based on libstlport.mk 
#####################################################
libgnu_a_SOURCES := \
	prepargs.c\
	rtapelib.c\
	paxerror.c\
	paxexit.c\
	paxnames.c\
	stdopen.c\
	allocsa.c\
	argp-ba.c\
	argp-eexst.c\
	argp-fmtstream.c\
	argp-fs-xinl.c\
	argp-help.c\
	argp-parse.c\
	argp-pin.c\
	argp-pv.c\
	argp-pvh.c\
	argp-xinl.c\
	full-write.c\
	localcharset.c\
	strnlen1.c\
	version-etc.c\
	version-etc-fsf.c\
	xalloc-die.c\
	xstrndup.c\
	xstrtoumax.c

EXTRA_libgnu_a_SOURCES := \
	argmatch.c\
	asnprintf.c\
	backupfile.c\
	basename.c\
	chdir-long.c\
	chown.c\
	close-stream.c\
	closeout.c\
	creat-safer.c\
	dirname.c\
	dup-safer.c\
	error.c\
	exclude.c\
	exitfail.c\
	fchmodat.c\
	fchown-stub.c\
	fd-safer.c\
	fileblocks.c\
	fnmatch.c\
	ftruncate.c\
	getcwd.c\
	getdate.c\
	getdelim.c\
	getline.c\
	getopt.c\
	getopt1.c\
	gettime.c\
	gettimeofday.c\
	hash.c\
	human.c\
	imaxtostr.c\
	lchown.c\
	lstat.c\
	malloc.c\
	mbchar.c\
	memchr.c\
	mempcpy.c\
	memrchr.c\
	memset.c\
	mkdirat.c\
	mkdtemp.c\
	modechange.c\
	obstack.c\
	offtostr.c\
	open-safer.c\
	openat-die.c\
	pipe-safer.c\
	printf-args.c\
	printf-parse.c\
	quote.c\
	quotearg.c\
	regex.c\
	rmdir.c\
	rpmatch.c\
	safe-read.c\
	safe-write.c\
	save-cwd.c\
	savedir.c\
	setenv.c\
	stpcpy.c\
	strcasecmp.c\
	strchrnul.c\
	strdup.c\
	stripslash.c\
	strndup.c\
	strnlen.c\
	strtoimax.c\
	strtol.c\
	strtoll.c\
	strtoul.c\
	strtoull.c\
	strtoumax.c\
	time_r.c\
	umaxtostr.c\
	unlinkdir.c\
	unsetenv.c\
	utime.c\
	utimens.c\
	vasnprintf.c\
	vsnprintf.c\
	xgetcwd.c\
	xmalloc.c\
	xstrtol.c\
	xstrtoul.c\
	__fpending.c

# kalen.lee@lge.com 2011.10.14 remove openat.c,waitpid.c,strncasecmp.c,mktime.c as they are supported.  

libgnu_src_files := $(EXTRA_libgnu_a_SOURCES) $(libgnu_a_SOURCES)

libgnu_cflags := -D_GNU_SOURCE -DHAVE_CONFIG_H 

##########################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(libgnu_src_files)

LOCAL_CFLAGS := $(libgnu_cflags)

#LOCAL_NDK_VERSION := 4
LOCAL_SDK_VERSION := 8

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libgnu
include $(LOCAL_PATH)/libgnu.mk
include $(BUILD_SHARED_LIBRARY)

##########################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(libgnu_src_files)

LOCAL_CFLAGS := $(libgun_cflags)

LOCAL_PRELINK_MODULE := false

#LOCAL_NDK_VERSION := 4
LOCAL_SDK_VERSION := 8

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libgnu
include $(LOCAL_PATH)/libgnu.mk
include $(BUILD_STATIC_LIBRARY)

endif
