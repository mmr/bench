#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <sys/time.h>
#include <sys/resource.h>

int t1(long n) {
  if (n >= 0 && n < 10) return 1;
  if (n >= 10 && n < 100) return 2;
  if (n >= 100 && n < 1000) return 3;
  if (n >= 1000 && n < 10000) return 4;
  if (n >= 10000 && n < 100000) return 5;
  if (n >= 100000 && n < 1000000) return 6;
  if (n >= 1000000 && n < 10000000) return 7;
  if (n >= 10000000 && n < 100000000) return 8;
  if (n >= 100000000 && n < 1000000000) return 9;
  if (n >= 1000000000 && n < 10000000000) return 10;
  if (n >= 10000000000 && n < 100000000000) return 11;
  if (n >= 100000000000 && n < 1000000000000) return 12;
  if (n >= 1000000000000 && n < 10000000000000) return 13;
  if (n >= 10000000000000 && n < 100000000000000) return 14;
  if (n >= 100000000000000 && n < 1000000000000000) return 15;
  if (n >= 1000000000000000 && n < 10000000000000000) return 16;
  if (n >= 10000000000000000 && n < 100000000000000000) return 17;
  if (n >= 100000000000000000 && n < 1000000000000000000) return 18;
  return 0;
}

int t2(long n) {
  //return floor(log10(n)) + 1;
  return log10(n) + 1;
}

#define NUMS 100000000
long nums[NUMS];
void load_nums() {
  int cx = 0;
  size_t len = 0;
  char *line = NULL;
  char *foo = NULL;
  ssize_t read;
  FILE *fp = fopen("num.txt", "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }
  while ((read = getline(&line, &len, fp)) != -1) {
    nums[cx] = strtol(line, &foo, 10);
    cx++;
  }
  fclose(fp);
}

double get_time() {
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec * 1e-6;
}

int main(int argc, char **argv) {
  printf("loading...\n");
  load_nums();
  printf("finished loading...\n");
  if (argc > 1) {
    printf("%d\n", t1(atol(argv[1])));
    return 0;
  }
  int i = 0;
  long n = 0;
  double ini, end;

  ini = get_time();
  for (i = 0; i < NUMS; i++) {
    n = nums[i]; 
    t1(n);
  }
  end = get_time();
  printf("t1 = %f / %f = %f\n", ini, end, end - ini);

  ini = get_time();
  for (i = 0; i < NUMS; i++) {
    n = nums[i]; 
    t2(n);
  }
  end = get_time();
  printf("t2 = %f / %f = %f\n", ini, end, end - ini);

  return 0;
}
