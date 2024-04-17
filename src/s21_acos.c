#include "s21_math.h"
long double s21_acos(double x) {
  if (s21_fabs(x) > 1) {
    return S21_NAN;
  }
  if (s21_fabs(x) < S21_EPS) {
    return S21_PI2;
  }
  if (s21_fabs(x - 1) < S21_EPS) {
    return 0;
  }
  if (s21_fabs(x + 1) < S21_EPS) {
    return S21_PI;
  }
  if (x > 0) {
    return s21_atan(s21_sqrt(1 - (x * x)) / x);
  }
  return s21_atan(s21_sqrt(1 - (x * x)) / x) + S21_PI;
}