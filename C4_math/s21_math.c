#include "s21_math.h"
//  -----------------abs---------------  //

int s21_abs(int x) { return (x < 0) ? (~x + 1) : x; }
long double s21_fabs(double x) { return ((x < 0) ? (x * (-1)) : x); }

//  --------------trigonometry--------------  //

long double s21_cos(double x) {
  long double this_cos = 0;
  if ((x != x) || (x == S21_INF) || (-x == S21_INF)) {
    this_cos = S21_NAN;
  } else {
    long double rad_arg = castToRadian(x);
    int quadrant = getNotRandomNumberAndDoSmth(&rad_arg);
    if ((quadrant == 1) || (quadrant == 4)) {
      this_cos = s21_baby_cos(rad_arg);
    } else {
      this_cos = s21_baby_cos(rad_arg);
    }
  }
  return this_cos;
}

long double s21_baby_cos(long double min_arg) {
  long double tailor_sum = 1;
  long double last_delta = 1;
  long double new_delta = 1;
  int i = 1;
  while ((s21_fabs(new_delta / tailor_sum) >= S21_LONG_EPS) &&
         (i < S21_MAX_ITER)) {
    new_delta =
        (-1) * (last_delta * ((min_arg * min_arg) / (4 * i * i - 2 * i)));
    tailor_sum += new_delta;
    last_delta = new_delta;
    ++i;
  }
  return tailor_sum;
}

long double s21_sin(double x) {
  long double this_sin = 0;
  if ((x != x) || (x == S21_INF) || (-x == S21_INF)) {
    this_sin = S21_NAN;
  } else {
    long double rad_arg = castToRadian(x);
    this_sin = s21_baby_sin(rad_arg);
  }
  return this_sin;
}

long double s21_baby_sin(long double arg) {
  long double tailor_sum = arg;
  long double last_delta = arg;
  long double new_delta = 1.0;
  int i = 1;
  while ((s21_fabs((new_delta / tailor_sum)) >= S21_LONG_EPS) &&
         (i < S21_MAX_ITER)) {
    new_delta = (-1) * last_delta * (arg * arg / (2 * i * (2 * i + 1)));
    tailor_sum += new_delta;
    last_delta = new_delta;
    ++i;
  }
  return tailor_sum;
}

long double s21_tan(double x) {
  long double this_tan = 0;
  if ((x != x) || (x == S21_INF) || (-x == S21_INF)) {
    this_tan = S21_NAN;
  } else {
    long double rad_arg = castToRadian(x);
    int quadrant = getNotRandomNumberAndDoSmth(&rad_arg);
    if ((quadrant == 1) || (quadrant == 3)) {
      this_tan = -s21_baby_tan(rad_arg);
      this_tan *= ((this_tan >= 0) ? 1 : (-1));
    } else {
      this_tan = -s21_baby_tan(rad_arg);
      this_tan *= ((this_tan < 0) ? 1 : (-1));
    }
  }
  return this_tan;
}

long double s21_baby_tan(long double rad_arg) {
  return (s21_sin(rad_arg) / s21_cos(rad_arg));
}

long double s21_acos(double x) { return ((S21_PI / 2) - s21_asin(x)); }

long double s21_asin(double x) {
  long double anti_sin = 0;
  long double break_point = 0.9999;
  if ((s21_fabs(x) > 1.0) || (x != x) || (s21_fabs(x) == S21_INF)) {
    anti_sin = S21_NAN;
  } else if ((s21_fabs(x) > (1 - S21_LONG_EPS))) {
    anti_sin = S21_PI / 2;
    anti_sin *= ((x > 0) ? 1 : (-1));
  } else if (s21_fabs(x) > break_point) {
    anti_sin = s21_asin_interpol(s21_fabs(x), break_point);
    anti_sin *= ((x > 0) ? 1 : (-1));
  } else {
    anti_sin = s21_alreadyNotABaby_asin(x);
  }
  return anti_sin;
}

long double s21_alreadyNotABaby_asin(long double mini_arg) {
  long double taylor_sum = 0;
  long double next_member = mini_arg;
  int num = 1;
  while ((num < S21_MAX_ITER) && (s21_fabs(next_member) > S21_LONG_EPS)) {
    taylor_sum += next_member;

    next_member *= (mini_arg * mini_arg * (2. * num - 1.) * (2. * num - 1.));
    next_member /= (2. * num * (2. * num + 1.));
    ++num;
  }
  return taylor_sum;
}

long double s21_asin_interpol(long double arg, long double break_point) {
  long double up_limit = S21_PI / 2;
  long double down_limit = break_point;
  long double current = (up_limit + down_limit) / 2;
  long double this_sin = s21_sin(current);
  while (s21_fabs(this_sin - arg) > S21_LONG_EPS) {
    if (this_sin > arg) {
      up_limit = current;
    } else {
      down_limit = current;
    }
    current = (up_limit + down_limit) / 2;
    this_sin = s21_sin(current);
  }
  return current;
}

long double s21_atan(double x) {
  long double res = 0;
  long double break_point = 0.99999;
  long double prec_near_one = 1e-14;
  if (x != x) {
    res = S21_NAN;
  } else if (s21_fabs(x) == S21_INF) {
    res = S21_PI / (2 * ((x > 0) ? 1 : (-1)));
  } else if (s21_fabs(s21_fabs(x) - 1) < prec_near_one) {
    res = S21_PI / 4;
    res *= ((x > 0) ? 1 : (-1));
  } else if ((s21_fabs(x) > break_point) && (s21_fabs(1.0 / x) > break_point)) {
    long double line_slip = 0.7853931633724482;  //  arctg(break_point)
    long double line_koef = 0.5000025000083333;
    res = line_slip + line_koef * (s21_fabs(x) - break_point);
    res *= ((x > 0) ? 1 : (-1));
  } else if (s21_fabs(x) > 1.0) {
    res = s21_base_atan(s21_fabs(1.0 / ((long double)x)));
    res = ((x > 0) ? (S21_PI / 2 - res) : (res - S21_PI / 2));
  } else {
    res = s21_base_atan(x);
  }
  return res;
}

long double s21_base_atan(long double mini_arg) {
  long double tailor_sum = 0;
  long double this_member = mini_arg;
  int i = 1;
  while ((s21_fabs(this_member) > S21_LONG_EPS) && (i < S21_MAX_ITER)) {
    tailor_sum += this_member;
    this_member *= -((mini_arg * mini_arg) * (2 * i - 1)) / (2 * i + 1);
    ++i;
  }
  return tailor_sum;
}

long double castToRadian(long double wide_number) {
  long double rad_arg =
      ((s21_fabs(wide_number) <= S21_PI) ? wide_number
                                         : s21_fmod(wide_number, (2 * S21_PI)));
  return ((rad_arg <= -S21_PI)
              ? (rad_arg + 2 * S21_PI)
              : ((rad_arg > S21_PI) ? (rad_arg - 2 * S21_PI) : (rad_arg)));
}

int getNotRandomNumberAndDoSmth(long double *rad_arg) {
  int quadrant = 0;
  if (*rad_arg <= (-S21_PI / 2)) {
    quadrant = 3;
  } else if (*rad_arg <= 0) {
    quadrant = 4;
  } else if (*rad_arg <= (S21_PI / 2)) {
    quadrant = 1;
  } else {
    quadrant = 2;
  }
  return quadrant;
}

//  -----------------round----------------  //

long double s21_ceil(double x) {
  long double y = x;
  if (!((y != y) || (y == S21_INF) || (-y == S21_INF))) {
    y = (int)x;
    if (x > 0 && x - y != 0) {
      y += 1;
    }
  }
  return y;
}

long double s21_floor(double x) {
  long double res = 0;
  if (x != x) {
    res = S21_NAN;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else if (-x == S21_INF) {
    res = -S21_INF;
  } else {
    res = (long double)((long long int)x);
    if (res > x) --res;
  }
  return res;
}

//  ---------------exponent---------------  //

long double s21_exp(double x) {
  long double res = 0.0;
  if (x != x) {
    res = S21_NAN;
  } else if (-x == S21_INF) {
    res = 0;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    long double my_arg = s21_fabs(x);
    if (my_arg < (1.0 - S21_LONG_EPS)) {
      res = s21_mini_exp(my_arg);
    } else if (s21_fabs(my_arg - 1) <= S21_LONG_EPS) {
      res = S21_EXP;
    } else {
      long double int_arg = s21_floor(my_arg);
      res = s21_int_exp(int_arg) * s21_mini_exp(my_arg - int_arg);
    }
    if (x < 0) res = (1.0 / res);
  }
  return res;
}

long double s21_int_exp(long double deg) {
  long double res = 1;
  long long count = 0;
  while (deg > count) {
    res *= S21_EXP;
    ++count;
  }
  return res;
}

long double s21_mini_exp(long double arg) {
  long double sum = 1.0;
  long double this_member = 1.0;
  int i = 1;
  while ((i < S21_MAX_ITER) && (s21_fabs(this_member / sum) > 1e-16)) {
    this_member *= (arg / (i));
    sum += this_member;
    ++i;
  }
  return sum;
}

long double s21_log(double x) {
  long double ans;
  if ((x > 0) && (x < S21_INF)) {
    // Enough iterations to pass the test
    int max_iterations = 200;
    // Bring x to the range with fast convergence
    int power_counter = 0;
    while (x > 1.0) {
      x /= S21_EXP;
      power_counter++;
    }
    while (x < .25) {
      x *= S21_EXP;
      power_counter--;
    }

    // Sum Taylor series for log(x)
    x -= 1.0;
    double sum_tay = 0.0, sign = 1.0, order = x;
    for (int i = 1; i <= max_iterations; i++) {
      sum_tay += order * sign / i;
      order *= x;
      sign = -sign;
    }
    ans = sum_tay + power_counter;
  } else if ((x < S21_LONG_EPS) && (x >= 0)) {
    ans = (-1) * S21_INF;
  } else if (x >= S21_INF) {
    ans = S21_INF;
  } else {
    ans = S21_NAN;
  }

  return ans;
}

//  ----------------power----------------  //

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  int base_is_nan = s21_nan(base);
  int base_is_fin = s21_finite(base);
  int exp_is_nan = s21_nan(exp);
  int exp_is_fin = s21_finite(exp);
  int exp_ok = (s21_fabs(exp - s21_floor(exp)) <= S21_EPS);

  // pow(+0, exp), where exp is a negative odd integer, returns +inf
  if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS && exp_ok &&
      ((int)exp) < 0 && ((int)exp) % 2) {
    res = S21_INF;
    // pow(-0, exp), where exp is a negative odd integer, returns -inf
  } else if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS &&
             exp_ok && ((int)exp < 0) && (int)exp % 2) {
    res = -S21_INF;
    // pow(±0, exp), where exp is negative, finite, and is an even integer or a
    // non-integer, returns +inf
  } else if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS &&
             exp_is_fin && ((exp_ok && !(((int)exp) % 2)) || !exp_ok)) {
    res = S21_INF;
    // pow(±0, -inf) returns +inf
  } else if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS &&
             !exp_is_nan && !exp_is_fin && exp < 0) {
    res = S21_INF;
  } else if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS &&
             exp_ok && ((int)exp) % 2) {
    // pow(+0, exp), where exp is a positive odd integer, returns +0
    res = +0;
  } else if (base_is_fin && !base_is_nan && base < 0 && base >= -S21_EPS &&
             exp_ok && ((int)exp) % 2) {
    // pow(-0, exp) returns -0 == exp is a positive odd integer
    res = -0;
  } else if (base_is_fin && !base_is_nan && base < 0 && base >= -S21_EPS &&
             exp_ok && ((int)exp) % 2) {
    // pow(-0, exp), where exp is a +odd integer, returns -0
    res = -0;
  } else if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS &&
             ((!exp_ok && s21_fabs(exp) > S21_EPS) ||
              (exp_ok && !((int)exp % 2)))) {
    // pow(+-0, exp), where exp is +non-integer or a +even integer, returns +0
    res = +0;
  } else if (base_is_fin && !base_is_nan && s21_fabs(base + 1) < S21_EPS &&
             !exp_is_fin && !exp_is_nan) {
    // pow(-1, +-inf) returns 1
    res = 1;
  } else if (base_is_fin && !base_is_nan && s21_fabs(base - 1) < S21_EPS) {
    // pow(+1, exp) returns 1 for any exp even when exp is nan
    res = 1;
  } else if (s21_fabs(exp) < S21_EPS) {
    // pow(base, +-0) returns 1 for any base even when base is nan
    res = 1;
  } else if (base_is_fin && base < -S21_EPS && exp_is_fin && !exp_ok) {
    // pow(base, exp) returns nan
    res = S21_NAN;
  } else if (s21_fabs(base) - 1 < S21_EPS && !exp_is_nan && !exp_is_fin &&
             exp < 0) {
    // pow(base, neg inf) returns pos inf for any |base|<1
    res = S21_INF;
  } else if (s21_fabs(base) - 1 > S21_EPS && !exp_is_nan && !exp_is_fin &&
             exp < 0) {
    // pow(base, neg inf) returns +0 for any |base|>1
    res = +0;
  } else if (s21_fabs(base) - 1 < S21_EPS && !exp_is_nan && !exp_is_fin &&
             exp > 0) {
    // pow(base, pos inf) returns +0 for any |base|<1
    res = +0;
  } else if (s21_fabs(base) - 1 > S21_EPS && !exp_is_nan && !exp_is_fin &&
             exp > 0) {
    // pow(base, pos inf) returns +infinity for any |base|>1
    res = S21_INF;
  } else if (!base_is_nan && !base_is_fin && base < 0 && exp_ok && exp < 0 &&
             ((int)exp) % 2) {
    // pow(neg inf, exp) returns -0 if exp is a -odd integer
    res = -0;
  } else if (!base_is_nan && !base_is_fin && base < 0 &&
             ((!exp_ok && exp < 0) ||
              (exp_ok && exp < 0 && !(((int)exp) % 2)))) {
    // pow(neg inf, exp) returns +0 if exp is a -non-integer or -even integer
    res = +0;
  } else if (!base_is_nan && !base_is_fin && base < 0 &&
             (exp_ok && exp > 0 && ((int)exp) & 1)) {
    // pow(neg inf, exp) returns neg inf
    res = -S21_INF;
  } else if (!base_is_nan && !base_is_fin && base < 0 &&
             ((!exp_ok && exp > 0) ||
              (exp_ok && exp > 0 && !(((int)exp) % 2)))) {
    // pow(neg inf, exp) == pos inf
    res = +S21_INF;
  } else if (!base_is_nan && !base_is_fin && base > 0 && exp < -S21_EPS) {
    res = +0;
  } else if (!base_is_nan && !base_is_fin && base > 0 && exp > S21_EPS) {
    res = +S21_INF;
  } else if (base_is_nan || exp_is_nan) {
    res = S21_NAN;
  } else if (exp > S21_EPS) {
    if (exp_ok) {
      res = s21_simple_pow(base, exp);
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  } else {
    if (exp_ok) {
      res = s21_simple_pow(base, exp);
    } else {
      res = (long double)1 / s21_exp(-exp * s21_log(base));
    }
  }

  return res;
}

long double s21_simple_pow(long double base, long long int exp) {
  long double res = 1;
  if (exp >= 0) {
    while (exp) {
      if (exp & 1) {
        res *= base;
      }
      base *= base;
      exp >>= 1;
    }
  } else {
    res = 1 / s21_simple_pow(base, -exp);
  }

  return res;
}

long double s21_sqrt(double x) {
  long double initial = x;
  if (!((initial != initial) || (initial == S21_INF) ||
        (-initial == S21_INF))) {
    if ((x > 0) && (x < S21_INF)) {
      // Enough iterations to pass the test
      int max_iterations = 40;
      // Initial guess value
      initial = x / 2;

      // The sequence given by Newton's method
      for (int i = 0; i <= max_iterations; i++) {
        initial -= (initial * initial - x) / (2 * initial);
      }
    } else if (x < 0) {
      initial = S21_NAN;
    }
  }
  return initial;
}

//  ----------------else-----------------  //

long double s21_fmod(double x, double y) {
  bool res_is_nan =
      (s21_nan(x) || s21_nan(y) || s21_infinite(x) || s21_fabs(y) < S21_EPS ||
       (s21_infinite(x) && s21_infinite(y)));

  long double res = S21_NAN;

  if (!res_is_nan) {
    if (s21_fabs(x) < S21_EPS) {
      res = 0;
    } else if (s21_infinite(y)) {
      res = x;
    } else {
      long long int div = x / y;
      long double ld_x = x, ld_y = y;
      res = ld_x - div * ld_y;
    }
  }

  return res;
}

long long unsigned int s21_factorial(int x) {
  long long unsigned int factorial = 1;
  while (x > 1) {
    factorial *= x;
    --x;
  }
  return factorial;
}
