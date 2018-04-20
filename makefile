CXX = g++
CXXFLAGS = -Wall
DBGCXXFLAGS = -g -O0

EXE = hw06

SRCDIR = src
SRCS = main.cpp ant.cpp critter.cpp doodlebug.cpp game.cpp
OBJS = $(SRCS:%.cpp=%.o)
#//turns the .cpp files into .o files		#//puts the src in front of the .o files with a '/'
DBGDIR = dbg
#declaration of debug
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))
RELDIR = rel
#declaration of release
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))
#start of release
all : release debug
$(RELDIR)/$(EXE) : $(RELOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	# $^ is for all dependcies
$(RELDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(RELDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
release : $(RELDIR)/$(EXE)
$(DBGDIR)/$(EXE) : $(DBGOBJS)
#start of debugging
	$(CXX) $(CXXFLAGS) $(DBGCXXFLAGS) -o $@ $^
$(DBGDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(DBGDIR)
	$(CXX) $(CXXFLAGS) $(DBGCXXFLAGS) -c -o $@ $<
debug : $(DBGDIR)/$(EXE)

.PHONY : all clean release debug

clean :
	rm -rf $(DBGDIR) $(RELDIR)

	#tar tvf hw06.tar -- to check whats in .tar file
	#tar cvf hw06.tar src makefile -- to make tar file
