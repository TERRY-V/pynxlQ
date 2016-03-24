#****************************************************************************
#
# Copyright (C) 2010-2014 Terry Niu (Beijing, China)
#
# Author:	TERRY-V
# Email:	cnbj8607@163.com
# Support:	http://blog.sina.com.cn/terrynotes
#
# This is a GNU make (gmake) makefile
#
#****************************************************************************

CC		:= gcc
CXX		:= g++
LD		:= g++
AR		:= ar rc
RANLIB		:= ranlib

VPATH		:= ./:../common:../src:../lib

DEBUG_CFLAGS	:= -Wall -Wno-format -Wno-strict-aliasing -Wno-unused-function -g -DDEBUG -D__multi_thread
RELEASE_CFLAGS	:= -Wall -Wno-format -Wno-strict-aliasing -Wno-unused-function -O3 -D__multi_thread

DEBUG_CXXFLAGS	:= ${DEBUG_CFLAGS} -fexceptions -fPIC
RELEASE_CXXFLAGS:= ${RELEASE_CFLAGS} -fexceptions -fPIC

DEBUG_LDFLAGS	:= -g
RELEASE_LDFLAGS	:=
SHARE_FLAGS 	:= -shared

ifeq (YES, ${DEBUG})
	CFLAGS	:= ${DEBUG_CFLAGS}
	CXXFLAGS:= ${DEBUG_CXXFLAGS}
	LDFLAGS	:= ${DEBUG_LDFLAGS}
else
	CFLAGS	:= ${RELEASE_CFLAGS}
	CXXFLAGS:= ${RELEASE_CXXFLAGS}
	LDFLAGS	:= ${RELEASE_LDFLAGS}
endif

#****************************************************************************
# Include paths
#****************************************************************************

INCS		:= 

#****************************************************************************
# Include libs
#****************************************************************************

LIBS		:= -lpthread
LIBS		+= -lcurl
LIBS		+= -lmysqlcppconn

#****************************************************************************
# Targets of the build
#****************************************************************************

OUTPUT		:= ./QMainTest

all: ${OUTPUT}

#****************************************************************************
# Source files
#****************************************************************************

SRCS		:= qadlist.cc
SRCS		+= qallocator.cc
SRCS		+= qbitmap.cc
SRCS		+= qdictcreator.cc
SRCS		+= qdir.cc
SRCS		+= qfile.cc
SRCS		+= qgramparser.cc
SRCS		+= qgramtree.cc
SRCS		+= qlbscheduler.cc
SRCS		+= qlogger.cc
SRCS		+= qlogicalparser.cc
SRCS		+= qmysqlclient.cc
SRCS		+= qnetworkaccessmanager.cc
SRCS		+= qremotemonitor.cc
SRCS		+= qservice.cc
SRCS		+= qsimhasher.cc
SRCS		+= qsocketpool.cc
SRCS		+= qtcpsocket.cc
SRCS		+= qtrietree.cc
SRCS		+= qwordtokenizer.cc
SRCS		+= QMainTest.cc

OBJS		:= $(addsuffix .o, $(basename ${SRCS}))

#****************************************************************************
# Output
#****************************************************************************

${OUTPUT}: $(OBJS)
	@echo Linking ...
	${LD} -o $@ ${OBJS} ${INCS} ${LIBS} ${LDFLAGS}
	@echo ^_^ Congratulations! ^_^

#****************************************************************************
# Common rules
#****************************************************************************

# Rules for compiling source files to object files
%.o: %.c
	@echo Compiling $< ...
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

%.o: %.cc
	@echo Compiling $< ...
	${CXX} ${CXXFLAGS} ${INCS} -o $@ -c $<

%.o: %.cpp
	@echo Compiling $< ...
	${CXX} ${CXXFLAGS} ${INCS} -o $@ -c $<

clean:
	-rm -f common *.o ${OUTPUT}

