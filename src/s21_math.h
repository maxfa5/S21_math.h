#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#define S21_PI 3.14159265358979323846L
#define S21_PI2 1.57079632679L
#define S21_E 2.7182818284590452354L
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_EPS 1e-07
#define loge05 -0.30102999L

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
