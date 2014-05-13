CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x

OBJS =		keyseq.o Sequencer.o KeyMap.o visualkeyboard.o

LIBS =    -lSDL -lasound -lGL

TARGET =	keyseq

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
