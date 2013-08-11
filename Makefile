CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x

OBJS =		keyseq.o Sequencer.o KeyMap.o

LIBS =    -lSDL -lasound

TARGET =	keyseq

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
