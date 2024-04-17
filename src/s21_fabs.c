#include "s21_math.h"
long double s21_fabs(double x) {
  if (x != x) return S21_NAN;
  if (x < 0) x = -x;
  return x;
}