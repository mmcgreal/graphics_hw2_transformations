#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"


int main() {

  screen s;
  clear_screen(s);
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  struct matrix *edges;
  edges = new_matrix(4, 4);
  struct matrix *transform;
  transform = new_matrix(4, 4);
  
  //Make a square
  add_edge(edges, 50, 50, 0, 50 , YRES-400, 0);
  add_edge(edges, 50, YRES-400, 0, XRES-400, YRES-400, 0);
  add_edge(edges, XRES-400, YRES-400, 0, XRES-400, 50, 0);
  add_edge(edges, XRES-400, 50, 0, 50, 50, 0);

 
  int i;
  for (i = 0; i < 360; i ++){
    c. blue= (c.blue + 50) % MAX_COLOR;
    //c.green = i % MAX_COLOR;    
    transform = make_rotZ(-i);
    matrix_mult(transform, edges);
    scalar_mult(1, edges);
    transform = make_translate(250, 250, 250);
    matrix_mult(transform, edges);
    draw_lines(edges, s, c);
    transform = make_translate(-250, -250, -250);
    matrix_mult(transform, edges);
  }

  display(s);
  save_extension(s, "matrix.png");

  free_matrix( transform );
  free_matrix( edges );
}  
