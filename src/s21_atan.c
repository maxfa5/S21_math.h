#include "s21_math.h"
long double s21_atan(double x) {
  long double advanced_x = x;
  if (advanced_x > 1) {
    return S21_PI2 - s21_atan(1 / advanced_x);
  }
  if (advanced_x < -1) {
    return (-S21_PI2) - s21_atan(1 / advanced_x);
  }
  int accuracy = 50;
  if (s21_fabs(advanced_x) > 0.999999)
    return advanced_x > 0 ? S21_PI / 4 : -S21_PI / 4;
  if (s21_fabs(advanced_x) > 0.999) {
    accuracy = 500000;
  } else if (s21_fabs(advanced_x) > 0.9799) {
    accuracy = 10000;
  } else if (s21_fabs(advanced_x) > 0.91) {
    accuracy = 1000;
  } else if (s21_fabs(advanced_x) > 0.8) {
    accuracy = 100;
  }
  long double chislitel = advanced_x * advanced_x * advanced_x,
              result = advanced_x;

  for (int i = 3; i < accuracy; i += 4) {
    result += -1 * chislitel / i;
    chislitel *= advanced_x * advanced_x;
    result += chislitel / (i + 2);
    chislitel *= advanced_x * advanced_x;
  }
  return result;
}
