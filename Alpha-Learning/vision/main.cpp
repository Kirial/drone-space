#define X1 0.0003
#define C 1

#define WIDTH 1280
#define HEIGHT 720

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//using namespace std;

double array[WIDTH][HEIGHT][2];

int main() {

  int fakeX;
  int fakeY;

  printf("Start!\n");

  for(int i = 0; i < HEIGHT; i++) {



    fakeY = abs(i-HEIGHT/2);

    for(int j = 0; j < WIDTH; j++) {

      printf("X: %i\n", i);

      printf("Y: %i\n", j);

      fakeX = abs(j-WIDTH/2);

      // x
      array[j][i][0] = fakeX*(fakeX*X1+C)*(X1*fakeY+C)/fakeX;

      printf("x: %i - %f.\n", fakeX, array[j][i][0]);

      // y
      array[j][i][1] = fakeY*(fakeY*X1+C)*(X1*fakeX+C)/fakeY;

      printf("y: %i - %f.\n", fakeY, array[j][i][1]);

    }

  }


  printf("Done!\n");

}
