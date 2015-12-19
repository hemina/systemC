
#sous Ubuntu de Matthieu:
#TARGET_ARCH = linux
#sous Debian de PHH:
TARGET_ARCH = linux64

SRC = $(wildcard *.cpp)
INC =  $(wildcard *.h)
OBJ = $(SRC:.cpp=.o)

srcdir = .
#sous Ubuntu de Matthieu:
#prefix = /usr/local/systemc231
#sous Debian de PHH:
#prefix = /opt/SystemC/2.3.1/
prefix = /opt/systemc-2.3.1/

CXX = g++
DEFAULT_INCLUDES =  -I. -I$(srcdir)
INCLUDES = -I$(prefix)/include
CPPFLAGS = 
CXXFLAGS = -g -DDEBUG_SYSTEMC 

all: sim

myLDADD = -L$(prefix)/lib-$(TARGET_ARCH) -lsystemc -lm -Wl,-rpath=$(prefix)/lib-$(TARGET_ARCH)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(CXXFLAGS) -o $@

sim: $(OBJ) 
	@rm -f sim
	$(CXXLINK) $(myLDFLAGS) $(OBJ) $(myLDADD)


CXXCOMPILE = $(CXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(CPPFLAGS) $(CXXFLAGS)

.cpp.o:
	$(CXXCOMPILE) -c -o $@ `test -f '$<' || echo '$(srcdir)/'`$<


clean: 
	rm -f *.o sim waves.vcd 

