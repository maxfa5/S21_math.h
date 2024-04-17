#include "s21_math.h"
long double s21_log(double x) {
  if (x == S21_INF) return S21_INF;
  if (x == -S21_INF) return S21_NAN;
  if (s21_fabs(x) < S21_EPS) return -S21_INF;
  if (x < S21_EPS) return -S21_NAN;

  unsigned long long int ex_pow = 0;
  long double result = 0;
  long double term = 0;

  for (; x >= S21_E; x /= S21_E, ex_pow++) continue;
  int i = 0;
  do {
    term = result;
    result += 2 * (x - s21_exp(term)) / (x + s21_exp(term));
    i++;
  } while (s21_fabs(result) > S21_EPS && i < 100);
  return (result + ex_pow);
}
