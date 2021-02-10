#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define GNUPOT "gnuplot.exe"
#define xrange 15
#define yrange 300

double xfunc (double x, double t){ return x; }
double yfunc (double y, double t){ return (20+y*t + y*y*t - 0.7*y*y*y*t + 0.06*y*y*y*y*t); }

int main (){
  FILE *gnuplot = popen("gnuplot", "w");
  fprintf(gnuplot, "se xrange [0:%d]\n", xrange);
  fprintf(gnuplot, "se yrange [%d:%d]\n", -yrange/2, yrange/2);

  int loop = 40;
  double range = 100;

  for(int t = 1; t < loop; t++){
    fprintf(gnuplot, "plot '-' with lines\n");
    for(int i = 0; i < range; i++){
      fprintf(gnuplot, "%lf, %lf\n"
      , xfunc(i*xrange/range, (double)t), yfunc(i*xrange/range, (double)t));
    }
    fprintf(gnuplot, "e\n");
    fflush(gnuplot);
    Sleep(100);
  }
  return EXIT_SUCCESS;
}
