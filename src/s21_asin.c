#include "s21_math.h"
long double s21_asin(double x) {
  if (s21_fabs(x) > 1) {
    return S21_NAN;
  }
  if (s21_fabs(s21_fabs(x) - 1) < S21_EPS) {
    if (x > 0) {
      return S21_PI2;
    } else {
      return -S21_PI2;
    }
  }
  return s21_atan(x / s21_sqrt(1 - (x * x)));
}