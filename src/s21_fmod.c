#include "s21_math.h"
long double s21_fmod(double numerator, double denominator) {
  if (s21_fabs(denominator) < S21_EPS || s21_fabs(numerator) == S21_INF)
    return -S21_NAN;
  if (s21_fabs(denominator) == S21_INF) return numerator;

  long double num = numerator, den = denominator, del = num / den, result = 0;
  if (del > 0) {
    result = num - den * s21_floor(del);
  } else {
    result = (long double)num - den * s21_ceil(del);
  }
  return result;
}