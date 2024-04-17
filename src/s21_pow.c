#include "s21_math.h"
long double s21_pow(double base, double exp) {
  if (base == 1 || s21_fabs(exp) < S21_EPS) return 1.0;
  if (base != base || exp != exp) return S21_NAN;
  if (exp == -S21_INF || s21_fabs(base) < S21_EPS) return 0.0;
  if (base == -S21_INF) {
    if (((long long)(s21_floor(exp))) % 2 == 0)
      return S21_INF;
    else
      return -S21_INF;
  }
  if (base == S21_INF || exp == S21_INF) {
    if (exp < 0)
      return 0.0;
    else
      return S21_INF;
  }
  if (exp == 1) return base;
  if (exp == -1) return (1.0 / base);

  long long floor_exp = s21_abs(s21_ceil(exp)), tmp = floor_exp;
  long double result = 1.0;
  int binaryNumber[256] = {0}, count_binary_num = 0;

  while (tmp > 0) {  //перевод целой части степени в двоичный вид
    binaryNumber[count_binary_num++] += (tmp % 2);
    tmp /= 2;
  }
  while (--count_binary_num >= 0) {
    (binaryNumber[count_binary_num]) ? result *= base : 0;
    if (count_binary_num != 0) {
      result *= result;
    }
  }
  if (exp == floor_exp) {
    return result;
  }

  long double advaced_x = s21_fabs(exp) - floor_exp,
              result2 = s21_exp(advaced_x * s21_log(base));

  if (exp < 0) return (1 / (result * result2));
  return result * result2;
}
