#include "s21_math.h"
long double s21_ceil(double x) {
  if (x != x) {
    return S21_NAN;
  }
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x == -S21_INF) {
    return -S21_INF;
  }

  char arr[100];
  long double res = 0, x2 = x;
  sprintf(arr, "%0.Lf", x2);
  sscanf(arr, "%Lf", &res);
  if (res < x2) {
    res += 1;
  }
  return res;
}
