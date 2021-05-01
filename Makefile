CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		 Board.o util.o Position.o GameObject.o MoveableObject.o Player.o Mushroom.o Bomb.o ScoreBoard.o LazySeg.o Segment.o Fleas.o AllVariables.o game.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
