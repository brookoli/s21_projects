#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#ifndef STDBOOL_H_
typedef char bool;
#define true 1
#define false 0
#endif

#define S21_NAN (0.0 / 0.0)
#define S21_INF (1.0 / 0.0)
#define s21_finite(x) __builtin_finite(x)
#define s21_infinite(x) __builtin_isinf(x)
#define s21_nan(x) __builtin_isnan(x)

#define S21_PI 3.141592653589793238
#define S21_EXP 2.71828182845904524
#define S21_EPS 1e-7
#define S21_LONG_EPS 1e-16

#define S21_MAX_ITER 10000

//  -----------------abs---------------  //

int s21_abs(int x);
long double s21_fabs(double x);

//  --------------trigonometry--------------  //

long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);

long double s21_baby_cos(long double min_arg);
long double s21_baby_sin(long double min_arg);
long double s21_baby_tan(long double rad_arg);

long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

long double s21_alreadyNotABaby_asin(long double mini_arg);
long double s21_asin_interpol(long double arg, long double break_point);
long double s21_base_atan(long double mini_arg);

long double castToRadian(long double wide_number);
int getNotRandomNumberAndDoSmth(long double *rad_arg);

//  -----------------round----------------  //

long double s21_ceil(double x);
long double s21_floor(double x);

//  ---------------exponent---------------//

long double s21_exp(double x);  //
long double s21_log(double x);  //

long double s21_int_exp(long double deg);
long double s21_mini_exp(long double arg);

//  ----------------power----------------  //

long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

long double s21_simple_pow(long double base, long long int exp);

//  ----------------else-----------------  //

long double s21_fmod(double x, double y);
long long unsigned int s21_factorial(int x);

#endif  //  SRC_S21_MATH_H_
