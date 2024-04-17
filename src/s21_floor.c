#include "s21_math.h"
long double s21_floor(double x) {
  if (x != x) {
    return x;
  }
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x == -S21_INF) {
    return -S21_INF;
  }

  char arr[100];
  sprintf(arr, "%0.lf", x);
  long double res = 0;
  sscanf(arr, "%Lf", &res);
  if (x < res) {
    res--;
  }
  return res;
}
