#include "s21_math.h"
long double s21_cos(double x) {
  if (x == S21_INF) return -S21_NAN;
  if (x != x) return x;

  long double advanced_x = x, result = 1;
  long double znamenatel = 2, chislitel = 0;
  advanced_x = x - 2 * S21_PI * s21_floor(x / (2 * S21_PI));
  chislitel = advanced_x * advanced_x;
  int accuracy = 100;

  for (int i = 4; i < accuracy; i += 4) {
    result += (-1) * chislitel / znamenatel;
    znamenatel *= i * (i - 1);
    chislitel *= advanced_x * advanced_x;
    result += chislitel / znamenatel;
    chislitel *= advanced_x * advanced_x;
    znamenatel *= (i + 2) * (i + 1);
  }

  return result;
}