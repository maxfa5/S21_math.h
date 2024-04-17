#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_test) {
  ck_assert_int_eq(s21_abs(-123), abs(-123));
  ck_assert_int_eq(s21_abs(123), abs(123));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-123456789), abs(-123456789));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabsl(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabsl(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_fabs(-123.0), fabsl(-123.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(123.0), fabsl(123.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabsl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-123456789.3), fabsl(-123456789.3),
                           S21_EPS);
  for (long double i = -100; i <= 100; i += 1.257) {
    ck_assert_ldouble_eq_tol(s21_fabs(i), fabsl(i), S21_EPS);
  }
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(-123.0));
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acosl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acosl(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acosl(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(0.1535), acosl(0.1535), S21_EPS);
  for (long double i = -1; i <= 1; i += 0.001) {
    ck_assert_ldouble_eq_tol(acosl(i), acosl(i), S21_EPS);
  }
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(-123.));
  ck_assert_ldouble_nan(s21_asin(123.));
  ck_assert_ldouble_eq_tol(s21_asin(-1.), asinl(-1.), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(1.), asinl(1.), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.), asinl(0.), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.1535), asinl(0.1535), S21_EPS);
  for (long double i = -1; i < 1; i += 0.001) {
    ck_assert_ldouble_eq_tol(asinl(i), asinl(i), S21_EPS);
  }
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atanl(INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atanl(-INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atanl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(0.9999), atanl(0.9999), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-0.9999), atanl(-0.9999), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(123.), atanl(123.), S21_EPS);
  for (long double i = -1; i <= 1; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atanl(i), S21_EPS * 10);
  }
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceill(INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceill(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceill(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(0.1535), ceill(0.1535), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(1234567890123456.7890),
                           ceill(1234567890123456.7890), S21_EPS);
  for (double i = -100; i <= 100; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceill(i), S21_EPS);
  }
}
END_TEST

START_TEST(exp_test) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_eq(s21_exp(INFINITY), expl(INFINITY));
  ck_assert_ldouble_eq(s21_exp(-INFINITY), expl(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_exp(0.0), expl(0.0), S21_EPS);
  for (long double i = 0; i <= 20; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_exp(i), expl(i), S21_EPS * 10);
  }
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floorl(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floorl(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_floor(0.1535), floorl(0.1535), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(1234567890123456.7890),
                           floorl(1234567890123456.7890), S21_EPS);
  for (long double i = -100; i <= 100; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floorl(i), S21_EPS);
  }
}
END_TEST

START_TEST(fmod_test) {
  ck_assert_ldouble_nan(s21_fmod(NAN, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(NAN, 5));
  ck_assert_ldouble_nan(s21_fmod(5, NAN));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 2));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, 2));
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
  ck_assert_ldouble_eq_tol(s21_fmod(3, INFINITY), fmodl(3, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(3, -INFINITY), fmodl(3, -INFINITY),
                           S21_EPS);

  ck_assert_ldouble_eq_tol(s21_fmod(123.0, 5.1), fmodl(123.0, 5.1), S21_EPS);
  for (double i = -100; i <= 100; i += 0.21) {
    ck_assert_ldouble_eq_tol(s21_fmod(i, 2), fmodl(i, 2), S21_EPS);
  }
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_infinite(s21_log(0.0));
  ck_assert_ldouble_nan(s21_log(-10.0));
  ck_assert_ldouble_eq_tol(s21_log(0.1535), logl(0.1535), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(S21_E), logl(S21_E), S21_EPS);
  for (double i = 0.1; i <= 400; i += 2.0123) {
    ck_assert_ldouble_eq_tol(s21_log(i), logl(i), S21_EPS);
  }
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cosl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(0.1535), cosl(0.1535), S21_EPS);
  for (long double i = -100; i <= 100; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cosl(i), S21_EPS);
  }
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-INFINITY, 0), powl(-INFINITY, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0, INFINITY), powl(0, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, INFINITY), powl(1, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, INFINITY), powl(1, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(INFINITY, -1), powl(INFINITY, -1), S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(2, INFINITY));
  ck_assert_ldouble_nan(s21_pow(NAN, INFINITY));
  ck_assert_ldouble_nan(s21_pow(NAN, 1));
  ck_assert_ldouble_eq_tol(s21_pow(NAN, 0), powl(NAN, 0), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(0, NAN));
  ck_assert_ldouble_eq_tol(s21_pow(1, NAN), powl(1, NAN), S21_EPS);
  ck_assert(s21_pow(-INFINITY, 2) > 0);
  ck_assert(s21_pow(-INFINITY, 3) < 0);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -1), powl(-2, -1), S21_EPS);
  for (long double i = -25; i <= 25; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_pow(i, 2), powl(i, 2), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_pow(2, i), powl(2, i), S21_EPS);
  }
}
END_TEST

START_TEST(sin_test) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sinl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(0.1535), sinl(0.1535), S21_EPS);
  for (long double i = -100; i <= 100; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sinl(i), S21_EPS);
  }
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
  ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrtl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.1535), sqrtl(0.1535), S21_EPS);
  for (long double i = 0.1; i <= 1e15; i *= 2.5) {
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrtl(i), S21_EPS);
  }
}
END_TEST

START_TEST(tan_test) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_tan(0.0), tanl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(0.1535), tanl(0.1535), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(0.99999), tanl(0.99999), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(-0.99999), tanl(-0.99999), S21_EPS);
  for (long double i = -100; i <= 100; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tanl(i), S21_EPS * 10);
  }
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite = suite_create("s21_math");
  TCase *tcase = tcase_create("s21_math");
  tcase_add_test(tcase, abs_test);
  tcase_add_test(tcase, acos_test);
  tcase_add_test(tcase, asin_test);
  tcase_add_test(tcase, atan_test);
  tcase_add_test(tcase, ceil_test);
  tcase_add_test(tcase, cos_test);
  tcase_add_test(tcase, exp_test);
  tcase_add_test(tcase, fabs_test);
  tcase_add_test(tcase, floor_test);
  tcase_add_test(tcase, fmod_test);
  tcase_add_test(tcase, log_test);
  tcase_add_test(tcase, pow_test);
  tcase_add_test(tcase, sin_test);
  tcase_add_test(tcase, sqrt_test);
  tcase_add_test(tcase, tan_test);
  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  Suite *s = s21_math_suite();
  SRunner *suite_runner = srunner_create(s);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return failed ? 1 : 0;
}
