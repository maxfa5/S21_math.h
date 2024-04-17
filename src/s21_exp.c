#include "s21_math.h"
long double s21_exp(double exp) {
  if (exp != exp) return S21_NAN;
  if (exp == S21_INF) return S21_INF;
  if (exp == -S21_INF) return 0;
  if (s21_fabs(exp) < S21_EPS) return 1;
  if (s21_fabs(exp - 1) < S21_EPS) return S21_E;

  unsigned long long floor_exp = s21_abs(s21_ceil(exp)), tmp = floor_exp;
  long double result = 1.0;
  int binaryNumber[256] = {0}, count_binary_num = 0;

  while (tmp > 0) {  //перевод целой части степени в двоичный вид
    binaryNumber[count_binary_num++] += (tmp % 2);
    tmp /= 2;
  }
  while (--count_binary_num >= 0) {
    (binaryNumber[count_binary_num]) ? result *= S21_E : 0;
    if (count_binary_num != 0) {
      result *= result;
    }
  }
  if (exp == floor_exp) {
    return result;
  }

  int num_terms = 500;  // количество членов ряда Маклорена
  long double znamenatel = 1;
  long double advaced_x = s21_fabs(exp) - floor_exp, chislitel = advaced_x,
              result2 = 1;
  for (int i = 1; i < num_terms; i++) {
    result2 += chislitel / znamenatel;
    chislitel *= advaced_x;
    znamenatel *= (i + 1);
  }
  if (exp < 0) return (1 / (result * result2));
  return result * result2;
}
