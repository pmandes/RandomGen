CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		RandomGen.o

LIBS =

TARGET =	RandomGen

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
