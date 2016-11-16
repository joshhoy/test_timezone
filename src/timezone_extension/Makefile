include /home/y/share/yahoo_cfg/yphp.defs
PLATFORMS = $(shell build_platforms -r6_64)

YAPACHES = 2.4
YPHPS = 5.6

CXXSRC =  test_timezone.cpp
CXXFLAGS += -Wno-write-strings
LIB_NAME = test_timezone
SHLIB_VERSION = handler
LDEF = -DCOMPILE_DL_TEST_TIMEZONE=1
LDEF += -DMBRRHEL6
LINC = -I/home/y/include/yicu
LLDLIBS = -lyapphparraydata -lyaperrlist 
ROOT = /home/y

ifeq (1,$(shell expr $(OSMAJOR) \>= 6))
	    LINC += -I/usr/include/libxml2
else
	    LINC += -I$(ROOT)/include/libxml2
endif

include /home/y/share/yahoo_cfg/yphp.rules
