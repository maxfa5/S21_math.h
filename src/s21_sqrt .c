#include "s21_math.h"
long double s21_sqrt(double x) {
  if (x < 0) return -S21_NAN;
  if (x == S21_INF) return S21_INF;
  if (x != x) return S21_NAN;
  return s21_pow(x, 0.5);
}
