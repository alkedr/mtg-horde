NAME := mtg-horde
VERSION := 1.0
DISTFILES := README.md Makefile UNLICENSE *.cpp *.hpp

SHELL := bash
CXX := clang++ -std=c++11
UPX := upx --best --ultra-brute --lzma -qqq

QT_CXXFLAGS := -fPIE $(shell pkg-config --cflags Qt5Gui Qt5Widgets Qt5Multimedia | sed 's/-I\//-isystem\ \//g')
QT_LIBS := $(shell pkg-config --libs Qt5Gui Qt5Widgets)
LIBS_CXXFLAGS := $(QT_CXXFLAGS)
LIBS := $(QT_LIBS)

CXXFLAGS_release := -O2 -s -w
CXXFLAGS_debug := -ggdb3 -Weverything -Wno-padded -Wno-c++98-compat-pedantic -Wno-unused-member-function -Wno-weak-vtables -Wno-sign-conversion -Wno-c99-extensions


.PHONY : all dist clean

$(NAME): main.cpp *.hpp Makefile
	@echo "BUILD $@"
	@$(CXX) $(CXXFLAGS_release) $(LIBS_CXXFLAGS) $(LIBS) $< -o $@
	@echo "UPX $@"
	@$(UPX) $@

precompiled.hpp.pch: precompiled.hpp Makefile
	@echo "PRECOMPILE $@"
	@$(CXX) -x c++-header -ggdb3 $(LIBS_CXXFLAGS) $< -o $@

$(NAME)-dbg: main.cpp *.hpp precompiled.hpp.pch Makefile
	@echo "BUILD $@"
	@$(CXX) -DUSE_PRECOMPILED -include precompiled.hpp $(CXXFLAGS_debug) $(LIBS_CXXFLAGS) $(LIBS) $< -o $@

clean:
	@echo "CLEAN $(NAME) $(NAME)-dbg"
	@rm -f $(NAME) $(NAME)-dbg

full-clean: clean
	@echo "CLEAN precompiled.hpp.pch $(NAME)-$(VERSION).tar.xz"
	@rm -f precompiled.hpp.pch $(NAME)-$(VERSION).tar.xz

