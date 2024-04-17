#include "s21_math.h"
long double s21_sin(double x) {
  if (x == S21_INF) return -S21_NAN;
  if (x != x) return x;

  long double advanced_x = x;
  long double znamenatel = 6, chislitel = 0;
  advanced_x = x - 2 * S21_PI * s21_floor(x / (2 * S21_PI));
  chislitel = advanced_x * advanced_x * advanced_x;
  long double result = advanced_x;
  int accuracy = 100;

  for (int i = 5; i < accuracy; i += 4) {
    result += (-1) * chislitel / znamenatel;
    znamenatel *= i * (i - 1);
    chislitel *= advanced_x * advanced_x;
    result += chislitel / znamenatel;
    znamenatel *= (i + 2) * (i + 1);
    chislitel *= advanced_x * advanced_x;
  }

  return result;
}