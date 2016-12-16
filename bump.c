#include <ncurses.h>
#include <unistd.h>

class Ball {
  public:
  int x, y, dx, dy;
  char shape;
  
  void move(int w, int h) {
    mvprintw(y,x,"%c",' ');
    x += dx;
    y += dy;
    mvprintw(y,x,"%c",shape);
    if(x >= w - 1 || x <= 1 ) {
      dx = -dx;
    }
    if(y >= h - 1 || y <= 1) {
      dy = -dy;
    }
  }
  
  
  
  Ball (int x, int y, int dx, int dy, char shape) {
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->shape = shape;
  }
  
  ~Ball() {};
};


int main() {
  
  int mag, szel;
  Ball b[5] = {
    Ball(15,17,1,-1,255),
    Ball(15,12,-1,-1,'#'),
    Ball(12,10,1,1,'o'),
    Ball(18,16,1,-1,'*'),
    Ball(13,19,-1,-1,'+')
  };
  
  initscr();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);
  noecho();
  char key;
  
  while((key = getch()) != 27) {
      for(int i=0; i<5; i++) {
      getmaxyx(stdscr,mag,szel);
      //mvprintw(0,0,"%d, y=%d, dx=%d, dy=%d, shape=%c", b.x, b.y, b.dx, b.dy, b.shape);
      b[i].move(szel, mag);
      refresh();
      usleep(5000);
    }
  }
  getch();
  endwin();
  return 0;

}

