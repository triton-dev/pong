#include <ncurses.h>
#include <unistd.h>

class Ball {
  public:
  int x, y, dx, dy;
  char shape;
  
  void move(int w, int h) {
    //mvprintw(y,x,"%c",' ');
    x += dx;
    y += dy;
    mvprintw(y,x,"%c",shape);
    if(x >= w - 1 || x < 1 ) {
      dx = -dx;
    }
    if(y >= h - 1 || y < 1) {
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
  Ball b[10] = {
    Ball(15,17,1,-1,'O'),
    Ball(15,12,-1,-1,'O'),
    Ball(12,10,1,1,'O'),
    Ball(18,16,-1,1,'O'),
    Ball(13,19,1,1,'O'),
    Ball(13,19,-1,-1,'O'),
    Ball(3,7,1,-1,'O'),
    Ball(5,7,-1,1,'O'),
    Ball(11,7,-1,-1,'O'),
    Ball(1,5,1,1,'O')
  };
  
  initscr();
  curs_set(0);
  raw();
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  char key;
  int bsize = 10;
  printw("%d",bsize);
  
  while((key = getch()) != 27) {
      for(int i=0; i<bsize; i++) {
      getmaxyx(stdscr,mag,szel);
      b[i].move(szel, mag);
      refresh();
      usleep(2500);
    }
  }
  getch();
  endwin();
  return 0;

}

