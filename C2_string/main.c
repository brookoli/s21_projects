#include <check.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_string.h"
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char strtest[][20] = {"Hello world\0", "Hello world\n\0",
                      "a\n\0", " \n\0", " \0", "\n\0", "\0"};
char liamstrtest[][20] = {
    "Hello world\0", "Hello world\n\0", "a\n\0", " \n\0", " \0", "\n\0", "\0"};

char specialtest[][20] = {"LiamDona", "Nghdcg\n\0", "dfrghfs\n\0", " \n\0",
                          " \0",      "\n\0",       "\0"};

char specialtest1[][20] = {"LIAMDONA", "NGHDCG\n\0", "DFRGHFS\n\0", " \n\0",
                           " \0",      "\n\0",       "\0"};

char specialtest2[][20] = {"liamdona", "nghdcg\n\0", "dfrghfs\n\0", " \n\0",
                           " \0",      "\n\0",       "\0"};

char specialtest3[][20] = {"LLIAMDONAiamDona",
                           "NNGHDCG\nghdcg\n\0",
                           "dDFRGHFS\nfrghfs\n\0",
                           " \n\0",
                           "ababababababababab",
                           "\n\0",
                           "\0"};

char specialtest4[][20] = {"a", "g", "f", " \n\0", "ab", "\n\0", "\0"};

char specialtest5[][20] = {"LiamDon", "Nghdcg\n\0", "dfrghfs\n\0", " \n\0",
                           "",     "\n\0",       "\0"};

struct fmt {
    char str[30];
    long fmt;
    long fmt2;
    long fmt3;
};

struct fmtS {
    char str[30];
    char fmt[30];
    char fmt2[30];
    char fmt3[30];
};

struct fmt2 {
    char str[30];
    int fmt;
    int fmt2;
};

struct fmtF {
    char str[30];
    float fmt;
    float fmt2;
    float fmt3;
};

struct fmtExp {
    char str[30];
    double fmt;
    double fmt2;
    double fmt3;
};

/*
s21_memcpy
s21_memmove
s21_memset
s21_strcpy
s21_strncpy
 */

// 13b+0, 10b+0, 13b, 14b
char deststrtest[][20] = {"21-school-ru\0", "21-school\0", "21-school-ru!", "21-school-ruuu"};

char nullstrtest[][20] = {""};

// 12b+0, 13b+0, 15b, 9b
char srcstrtest[][20] = {"Hello world\0", "Hello world\n\0", "Not hello world", "Hellworld"};




START_TEST(test_strchr_letter) {
    ck_assert_ptr_eq(s21_strchr(strtest[_i], 'o'), strchr(strtest[_i], 'o'));
}
END_TEST
START_TEST(test_strchr_null) {
    ck_assert_ptr_eq(s21_strchr(strtest[_i], 0), strchr(strtest[_i], 0));
}
END_TEST
START_TEST(test_strchr_carriage) {
    ck_assert_ptr_eq(s21_strchr(strtest[_i], '\n'), strchr(strtest[_i], '\n'));
}
END_TEST
START_TEST(test_memchr_letter) {
    ck_assert_ptr_eq(s21_memchr(strtest[_i], 'o', 15), memchr(strtest[_i], 'o', 15));
}
END_TEST
START_TEST(test_memchr_null) {
    ck_assert_ptr_eq(s21_memchr(strtest[_i], 0, 15), memchr(strtest[_i], 0, 15));
}
END_TEST
START_TEST(test_memchr_carriage) {
    ck_assert_ptr_eq(s21_memchr(strtest[_i], '\n', 15), memchr(strtest[_i], '\n', 15));
}
END_TEST
START_TEST(test_strpbrk_word) {
    ck_assert_ptr_eq(s21_strpbrk(strtest[_i], "Love"), strpbrk(strtest[_i], "Love"));
}
END_TEST
START_TEST(test_strpbrk_null) {
    ck_assert_ptr_eq(s21_strpbrk(strtest[_i], ""), strpbrk(strtest[_i], ""));
}
END_TEST
START_TEST(test_strpbrk_carriage) {
    ck_assert_ptr_eq(s21_strpbrk(strtest[_i], "\n"), strpbrk(strtest[_i], "\n"));
}
END_TEST
START_TEST(test_strrchr_letter) {
        ck_assert_ptr_eq(s21_strrchr(strtest[_i], 'o'), strrchr(strtest[_i], 'o'));
}
END_TEST
START_TEST(test_strrchr_null) {
    ck_assert_ptr_eq(s21_strrchr(strtest[_i], 0), strrchr(strtest[_i], 0));
}
END_TEST
START_TEST(test_strrchr_carriage) {
    ck_assert_ptr_eq(s21_strrchr(strtest[_i], '\n'), strrchr(strtest[_i], '\n'));
}
END_TEST
START_TEST(test_strstr_word) {
    ck_assert_ptr_eq(s21_strstr(strtest[_i], "orld"), strstr(strtest[_i], "orld"));
}
END_TEST
START_TEST(test_strstr_null) {
    ck_assert_ptr_eq(s21_strstr(strtest[_i], ""), strstr(strtest[_i], ""));
}
END_TEST
START_TEST(test_strstr_carriage) {
    ck_assert_ptr_eq(s21_strstr(strtest[_i], "\n"), strstr(strtest[_i], "\n"));
}
END_TEST
START_TEST(test_memcmp_null) {
  ck_assert_int_eq(s21_memcmp(liamstrtest[_i], "\0", 7),
                   memcmp(liamstrtest[_i], "\0", 7));
}
END_TEST

START_TEST(test_memcmp_ten) {
  ck_assert_int_eq(s21_memcmp(liamstrtest[_i], "NULL", 7),
                   memcmp(liamstrtest[_i], "NULL", 7));
}
END_TEST

START_TEST(test_memcmp_carriage) {
  ck_assert_int_eq(s21_memcmp(liamstrtest[_i], "liamdona", 7),
                   memcmp(liamstrtest[_i], "liamdona", 7));
}
END_TEST

START_TEST(test_strcmp_null) {
  ck_assert_int_eq(s21_strcmp(liamstrtest[_i], "\0"), strcmp(liamstrtest[_i], "\0"));
}
END_TEST

START_TEST(test_strcmp_ten) {
  ck_assert_int_eq(s21_strcmp(liamstrtest[_i], "NULL"),
                   strcmp(liamstrtest[_i], "NULL"));
}
END_TEST

START_TEST(test_strcmp_carriage) {
  ck_assert_int_eq(s21_strcmp(liamstrtest[_i], "liamdona"),
                   strcmp(liamstrtest[_i], "liamdona"));
}
END_TEST

START_TEST(test_strncmp_null) {
  ck_assert_int_eq(s21_strncmp(liamstrtest[_i], "\0", 10),
                   strncmp(liamstrtest[_i], "\0", 10));
}
END_TEST

START_TEST(test_strncmp_ten) {
  ck_assert_int_eq(s21_strncmp(liamstrtest[_i], "NULL", 7),
                   strncmp(liamstrtest[_i], "NULL", 7));
}
END_TEST

START_TEST(test_strncmp_carriage) {
  ck_assert_int_eq(s21_strncmp(liamstrtest[_i], "liamdona", 10),
                   strncmp(liamstrtest[_i], "liamdona", 10));
}
END_TEST

START_TEST(test_to_upper) {
    char *a = to_upper(specialtest[_i]);
    ck_assert_str_eq(a, specialtest1[_i]);
    free(a);
}
END_TEST

START_TEST(test_to_lower) {
    char *b = to_lower(specialtest[_i]);
    ck_assert_str_eq(b, specialtest2[_i]);
    free(b);
}
END_TEST

START_TEST(test_insert) {
  ck_assert_str_eq(insert(specialtest[_i], specialtest1[_i], 1),
                   specialtest3[_i]);
}
END_TEST

START_TEST(test_trim) {
    ck_assert_str_eq(trim("123mmm456", "123456"), "mmm");
}
END_TEST

START_TEST(test_trim_NULL_2nd) {
    ck_assert_str_eq(trim("123mmm456", NULL), "123mmm456");
}
END_TEST

START_TEST(test_trim_NULL_1st) {
    ck_assert_ptr_eq(trim(NULL, "NULL"), NULL);
}
END_TEST

struct test_pack_strtok_struct {
    char str1[20];
    char str2[20];
    char str3[20];
};
struct test_pack_strtok_struct test_pack_strtok[] = {
    { "Hello World",       "Hello World",       " ,." },
    { "H/el.lo\0 Wo/r,ld", "H/el.lo\0 Wo/r,ld", " \\,./0" },
    { "",                  "",                  " \\,./0" },
    { "H/el.lo\0 Wo/r,ld", "H/el.lo\0 Wo/r,ld", "x" },
    { "\0",                "\0",                "\n" },
    { "Hello World", "Hello World", "Wor\0ld!" },
    { "",       "",       "World!" },
    { "Hello ", "Hello ", "\0" },
    { "Hello ", "Hello ", "\n" },
    { "Hello ", "Hello ", "" },
    { "",       "",       "" },
    { "\n",     "\n",     "\0" },
    { "\0",     "\0",     "\0" },
};

START_TEST(test_strtok) {
    char* actual = s21_strtok(test_pack_strtok[_i].str1, test_pack_strtok[_i].str3);
    char* expected = strtok(test_pack_strtok[_i].str2, test_pack_strtok[_i].str3);

    while (actual != NULL || expected != NULL) {
        ck_assert_pstr_eq(actual, expected);
        expected = strtok(NULL, test_pack_strtok[_i].str3);
        actual = s21_strtok(NULL, test_pack_strtok[_i].str3);
    }
    ck_assert_str_eq(test_pack_strtok[_i].str1, test_pack_strtok[_i].str2);
}
END_TEST


START_TEST(test_strerror) {
    char *act = s21_strerror(_i);
    char *actS = strerror(_i);
    ck_assert_str_eq(act, actS);
}
END_TEST

START_TEST(test_strncat) {
    struct str {
        char str[100];
        char str2[50];
        size_t n;
    };

    struct str strngs[] =  {
        {"abc", "abcd", 5},
        {"abck", "abcd", 2},
        {"", "abcd", 2},
    };

    char *act = s21_strncat(strngs[_i].str, strngs[_i].str2, strngs[_i].n);
    char *actS = strncat(strngs[_i].str, strngs[_i].str2, strngs[_i].n);
    ck_assert_str_eq(act, actS);
}
END_TEST

START_TEST(test_strcat) {
    struct str {
        char str[100];
        char str2[50];
    };

    struct str strngs[] =  {
        {"abc", "abcd"},
        {"abck", "abcd"},
        {"", "abcd"},
    };

    char *act = s21_strcat(strngs[_i].str, strngs[_i].str2);
    char *actS = strcat(strngs[_i].str, strngs[_i].str2);
    ck_assert_str_eq(act, actS);
}
END_TEST

/* tests sprintf */
START_TEST(test_sprintf_int) {
    struct fmt fmts[] = {
        {"\n!!%i!!!%i!!!%i", -10, 0, 10},
        {"\n!!%5i!!!%-5i!!!%05i", -10, 0, 10},
        {"\n!!%#5i!!!%-#5hi!!!%-#05hi", -300, 300, 400},
        {"\n!!%5.5i!!!%-5.5i!!!%#05.5i", -10, 0, 10},
        {"\n!!%+i!!!% 010.5i!!!%- 07.3i", -10, 0, 10},
        {"\n!!% #i!!!%-# 6i!!!%0# 11i", -10, 0, 10},

        {"\n!%hi!%hi!%i", SHRT_MIN, SHRT_MAX, INT_MIN},
        {"\n!%5hi!%-5hi!%5hi", (INT_MIN + 1), 0, INT_MAX},
        {"\n!%#5li!%-#5li!%-#05li", INT_MIN, INT_MAX, (LONG_MIN + 1)},
        {"\n!%5.5li!%-5.5li!%#05.5li", LONG_MAX, (LONG_MIN + 1), SHRT_MAX},
        {"\n%+hi!% 010.5hi!%- 07.3hi", LONG_MIN, INT_MAX, LONG_MAX},
        {"\n!!% #i!!!%-# 6i!!!%0# 11.4i", -10, 0, 10},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_uint) {
    struct fmt fmts[] = {
        {"\n!!%u!!!%u!!!%u", -10, 0, 10},
        {"\n!!%5u!!!%-5u!!!%05u", -10, 0, 10},
        {"\n!!%#5u!!!%-#5hu!!!%-#05hu", -300, 300, 400},
        {"\n!!%5.5u!!!%-5.5u!!!%#05.5u", -10, 0, 10},
        {"\n!!%+u!!!% 010.5u!!!%- 07.3u", -10, 0, 10},
        {"\n!!% #u!!!%-# 6u!!!%0# 11.4u", -10, 0, 10},

        {"\n!%hu!%hu!%i", SHRT_MIN, SHRT_MAX, INT_MIN},
        {"\n!%5hu!%-5hu!%5hu", (INT_MIN + 1), 0, INT_MAX},
        {"\n!%#5lu!%-#5lu!%-#05lu", INT_MIN, INT_MAX, (LONG_MIN + 1)},
        {"\n!%5.5lu!%-5.5lu!%#05.5lu", LONG_MAX, (LONG_MIN + 1), SHRT_MAX},
        {"\n%+hu!% 010.5hu!%- 07.3hu", LONG_MIN, INT_MAX, LONG_MAX},
        {"\n!!% #u!!!%-# 6u!!!%0# 11.4u", -10, 0, 10},
    };
    char act[100];
    char actS[100];
    int a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    int a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_float) {
    struct fmtF fmtsFloat[] = {
        {"!!!%5.0f!!!%5.2f!!!%5.2f", 13.5, 13.255, -13.255},
        {"!!!%5.0f!!!%5.2f!!!%5.2f", 12.5, 12.255, -12.255},
        {"!!!%5f!!!%5f!!!%5.f", 0.88888456, 1.7, -0.888888456},
        {"!!!%05.5f!!!%05.0f!!!%05.12f", 14.5, 2.8, -101.8},
        {"!%#7.3f!%#05.f!%#05.12f", 20856.12345, 3.2, -20856.12345},
        {"!!!%5.5f!!!%5.0f!!!%5.12f", 12, 2.4, -12.},
        {"!!!%5f!!!%5f!!!%5.f", 0.88888456, 1.7, -0.888888456},
        {"!!!%05.5f!!!%05.0f!!!%05.12f", 101.8, 2.8, -101.8},
        {"!%#05.5f!%#05.f!%#05.12f", 20856.12345, 3.2, -20856.12345},
        {"!%-05.5f!%-05.f!%-05.12f", 7777777777.123456, 1.5, -7777777777.123456},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmtsFloat[_i].str, fmtsFloat[_i].fmt, fmtsFloat[_i].fmt2, fmtsFloat[_i].fmt3);
    a2 = sprintf(actS, fmtsFloat[_i].str, fmtsFloat[_i].fmt, fmtsFloat[_i].fmt2, fmtsFloat[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_float2) {
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, "%*.*f", 13, 4, 345.567484);
    a2 = sprintf(actS, "%*.*f", 13, 4, 345.567484);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_string) {
    struct fmtS fmtsS[] = {
        {"!!!%5s!!!%5s!!!%5s", "", " ", "AAA"},
        {"!!!%10.5s!!!%10.5s!!!%10.5s", "", " ", "AAA"},
        {"!!!%-10.5s!!!%-7.4s!!!%-3.5s", "", " ", "AAA"},
        {"!!!%-10.5s!!!%-7.4s!!!%-3.5s", "", " ", "AAA"},
        {"!!!%010.5s!!!%-07.4s!!!%-08.5s", "ZZZ", "SSS", "AAA"},
        {"!%#10.5s!%-07.4s!%-#03.5s", "", " ", "AAA"},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmtsS[_i].str, fmtsS[_i].fmt, fmtsS[_i].fmt2, fmtsS[_i].fmt3);
    a2 = sprintf(actS, fmtsS[_i].str, fmtsS[_i].fmt, fmtsS[_i].fmt2, fmtsS[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_char) {
    struct fmt fmts[] = {
        {"!!!%c!!!%c!!!%c", 50, 52, 100},
        {"!!!%5c!!!%-5c!!!%05c", 20, 100, 50},
        {"!!!%#5c!!!%-#5c!!!%-#05c", 20, 100, 50},
        {"!!!%5.5c!!!%-5.5c!!!%#05.5c", 20, 100, 50},
        {"!!!%+c!!!% 010.5c!!!%- 07.3c", 20, 100, 50},
        {"!!!% #c!!!%-# 6c!!!%0# 11.4c", 20, 100, 50},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST


START_TEST(test_sprintf_octal) {
    struct fmt fmts[] = {
        {"!!!%6ho!!!%-6o!!!% 6lo", USHRT_MAX, USHRT_MAX, USHRT_MAX},
        {"!!!%6.2ho!!!%-6.2o!!!% 6.2lo", INT_MAX, INT_MAX, INT_MAX},
        {"!!!%#6.2o!!!%# 6.2o!!!%#- 6.2o", 348, -348, 0},
        {"!%#06.2o!%# 06.2o!%#- 06.2o", 348, -348, 0},
        {"!%#+6.2o!%# +06.2o!%#- +06.2o", 348, -348, 0},
        {"!!!%#o!!!%# -o!!!%#- o", 888888, -99999, 0},
        {"!!!%#.8o!!!%# 3.8o!!!%#- 04.8o", 888888, -99999, 0},
        {"!!!%#.o!!!%# .8o!!!%#- 0.7o", 888888, -99999, 0},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_hex) {
    struct fmt fmts[] = {
        {"!!!%6hx!!!%-6x!!!% 6lx", USHRT_MAX, USHRT_MAX, USHRT_MAX},
        {"!!!%6.2hx!!!%-6.2x!!!% 6.2lx", INT_MAX, INT_MAX, INT_MAX},
        {"!!!%#6.2x!!!%# 6.2x!!!%#- 6.2x", 348, -348, 0},
        {"!%#06.2x!%# 06.2x!%#- 06.2x", 348, -348, 0},
        {"!%#+6.2x!%# +06.2x!%#- +06.2x", 348, -348, 0},
        {"!!!%#x!!!%# -x!!!%#- x", 888888, -99999, 0},
        {"!%#-2.8x!!!%# 3.8x!%#- 04.8x", 888888, -99999, 0},
        {"!!!%#.x!!!%# .8x!!!%#- 0.7x", 888888, -99999, 0},
    };
    char act[1024];
    char actS[1024];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_heX) {
    struct fmt fmts[] = {
        {"!!!%6hX!!!%-6X!!!% 6lX", USHRT_MAX, USHRT_MAX, USHRT_MAX},
        {"!!!%6.2hX!!!%-6.2X!!!% 6.2lX", INT_MAX, INT_MAX, INT_MAX},
        {"!!!%#6.2X!!!%# 6.2X!!!%#- 6.2X", 348, -348, 0},
        {"!%#06.2X!%# 06.2X!%#- 06.2X", 348, -348, 0},
        {"!%#+6.2X!%# +06.2X!%#- +06.2X", 348, -348, 0},
        {"!!!%#X!!!%# -X!!!%#- X", 888888, -99999, 0},
        {"!%#-2.8X!!!%# 3.8X!%#- 04.8X", 888888, -99999, 0},
        {"!!!%#.X!!!%# .8X!!!%#- 0.7X", 888888, -99999, 0},
    };
    char act[1024];
    char actS[1024];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_exp) {
    struct fmtExp fmts[] = {
        {"%6.5e--%3.5e--%e", -1000000.80000, 10000000.80000, 0},
        {"%#6.5e--%#3.5e--%3.2e", -34.80000, 34.80000, 0},
        {"%+6.5e--%+3.5e--%+3.2e", -34.80000, 34.80000, 0},
        {"% 6.5e--% 3.5e--% 3.2e", -2.580000, 2.580000, 0},
        {"%-6.5e--%-3.5e--%-3.2e", -34.80000, 34.80000, 0},
        {"%- 6.5e--%- 3.5e--%- 3.2e", -34.80000, 34.80000, 0},
        {"% 6.5E--% 3.5E--% 3.2E", -0.80000, 0.80000, 0},
        {"%-6.5E--%-3.5E--%-3.2E", -0.080000, 0.080000, 0},
        {"%- 6.5E--%- 3.5E--%- 3.2E", -34.80000, 34.80000, 0},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt2, fmts[_i].fmt3);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_sprintf_p) {
    struct fmtP {
        char str[30];
        void *fmt;
    };

    char *fmtP1[10];
    int k;
    float p;

    struct fmtP fmts[] = {
        {"%6p-", &p},
        {"%6p-", &k},
        {"%6p-", fmtP1},
    };
    char act[100];
    char actS[100];
    int a1, a2;
    a1 = s21_sprintf(act, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt);
    a2 = sprintf(actS, fmts[_i].str, fmts[_i].fmt, fmts[_i].fmt);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
}
END_TEST



START_TEST(test_sprintf_n) {
    float p;
    int int1, int2, a1, a2;
    char act[100];
    char actS[100];
    a1 = s21_sprintf(act, "%6p-%n-%p", &p, &int1, NULL);
    a2 = sprintf(actS, "%6p-%n-%p", &p, &int2, NULL);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(int2, int1);

    a1 = s21_sprintf(act, "%6p-%p - %n", &p, NULL, &int1);
    a2 = sprintf(actS, "%6p-%p - %n", &p, NULL, &int2);
    ck_assert_str_eq(act, actS);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(int2, int1);
}
END_TEST

START_TEST(test_memcpy_nooverlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_memcpy(deststrtest[_i], srcstrtest[_i], n),
                                memcpy(deststrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_memcpy_overlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_memcpy(srcstrtest[_i]+3, srcstrtest[_i], n),
                                memcpy(srcstrtest[_i]+3, srcstrtest[_i], n));
}
END_TEST
START_TEST(test_memcpy_nnull) {
    s21_size_t n = 0;
    ck_assert_ptr_eq(s21_memcpy(nullstrtest[_i], srcstrtest[_i], n),
                                memcpy(nullstrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_memmove_nooverlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_memmove(deststrtest[_i], srcstrtest[_i], n),
                                memmove(deststrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_memmove_overlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_memmove(srcstrtest[_i]+3, srcstrtest[_i], n),
                                memmove(srcstrtest[_i]+3, srcstrtest[_i], n));
}
END_TEST
START_TEST(test_memmove_nnull) {
    s21_size_t n = 0;
    ck_assert_ptr_eq(s21_memmove(nullstrtest[_i], srcstrtest[_i], n),
                                memmove(nullstrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_strncpy_nooverlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_strncpy(deststrtest[_i], srcstrtest[_i], n),
                                strncpy(deststrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_strcpy_nooverlap) {
    ck_assert_ptr_eq(s21_strcpy(deststrtest[_i], srcstrtest[_i]),
                                strcpy(deststrtest[_i], srcstrtest[_i]));
}
END_TEST
START_TEST(test_strncpy_overlap) {
    s21_size_t n = 20;
    ck_assert_ptr_eq(s21_strncpy(deststrtest[_i]+3, srcstrtest[_i], n),
                                strncpy(deststrtest[_i]+3, srcstrtest[_i], n));
}
END_TEST
START_TEST(test_strcpy_overlap) {
    ck_assert_ptr_eq(s21_strcpy(deststrtest[_i]+3, srcstrtest[_i]),
                                strcpy(deststrtest[_i]+3, srcstrtest[_i]));
}
END_TEST
START_TEST(test_memset_part) {
    ck_assert_ptr_eq(s21_memset(deststrtest[_i], '*', 3), memset(deststrtest[_i], '*', 3));
}
END_TEST
START_TEST(test_memset_full) {
    ck_assert_ptr_eq(s21_memset(deststrtest[_i], 'b', 30), memset(deststrtest[_i], 'b', 30));
}
END_TEST
START_TEST(test_strncpy_nnull) {
    s21_size_t n = 0;
    ck_assert_ptr_eq(s21_strncpy(nullstrtest[_i], srcstrtest[_i], n),
                                strncpy(nullstrtest[_i], srcstrtest[_i], n));
}
END_TEST
START_TEST(test_strlen) {  // код теста
    ck_assert_int_eq(s21_strlen(strtest[_i]), strlen(strtest[_i]));
}
END_TEST

START_TEST(test_strcspn_word) {
    ck_assert_int_eq(s21_strcspn(strtest[_i], "hello"), strcspn(strtest[_i], "hello"));
}
END_TEST

START_TEST(test_strcspn_carriage) {
    ck_assert_int_eq(s21_strcspn(strtest[_i], "\n"), strcspn(strtest[_i], "\n"));
}
END_TEST

START_TEST(test_strspn_word) {
    ck_assert_int_eq(s21_strspn(strtest[_i], "hello"), strspn(strtest[_i], "hello"));
}
END_TEST

START_TEST(test_strspn_carriage) {
    ck_assert_int_eq(s21_strspn(strtest[_i], "\n"), strspn(strtest[_i], "\n"));
}
END_TEST

Suite *string_test_suite(void) {
    Suite *s;
    TCase *tc_string;

    s = suite_create("Testing in progress");

    tc_string = tcase_create("Test Functions");

    tcase_add_loop_test(tc_string, test_strchr_letter, 0, 7);
    tcase_add_loop_test(tc_string, test_strchr_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strchr_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_memchr_letter, 0, 7);
    tcase_add_loop_test(tc_string, test_memchr_null, 0, 7);
    tcase_add_loop_test(tc_string, test_memchr_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strpbrk_word, 0, 7);
    tcase_add_loop_test(tc_string, test_strpbrk_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strpbrk_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strrchr_letter, 0, 7);
    tcase_add_loop_test(tc_string, test_strrchr_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strrchr_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strstr_word, 0, 7);
    tcase_add_loop_test(tc_string, test_strstr_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strstr_carriage, 0, 7);

    tcase_add_loop_test(tc_string, test_memcmp_null, 0, 7);
    tcase_add_loop_test(tc_string, test_memcmp_ten, 0, 7);
    tcase_add_loop_test(tc_string, test_memcmp_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strcmp_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strcmp_ten, 0, 7);
    tcase_add_loop_test(tc_string, test_strcmp_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strncmp_null, 0, 7);
    tcase_add_loop_test(tc_string, test_strncmp_ten, 0, 7);
    tcase_add_loop_test(tc_string, test_strncmp_carriage, 0, 7);

    tcase_add_loop_test(tc_string, test_to_upper, 0, 7);
    tcase_add_loop_test(tc_string, test_to_lower, 0, 7);
    tcase_add_loop_test(tc_string, test_insert, 0, 3);
    tcase_add_test(tc_string, test_trim);
    tcase_add_test(tc_string, test_trim_NULL_1st);
    tcase_add_test(tc_string, test_trim_NULL_2nd);


    tcase_add_loop_test(tc_string, test_memcpy_nooverlap, 0, 4);
    tcase_add_loop_test(tc_string, test_memcpy_overlap, 0, 4);
    tcase_add_loop_test(tc_string, test_memcpy_nnull, 0, 4);
    tcase_add_loop_test(tc_string, test_memmove_nooverlap, 0, 4);
    tcase_add_loop_test(tc_string, test_memmove_overlap, 0, 4);
    tcase_add_loop_test(tc_string, test_memmove_nnull, 0, 4);
    tcase_add_loop_test(tc_string, test_strncpy_nooverlap, 0, 4);
    tcase_add_loop_test(tc_string, test_strcpy_nooverlap, 0, 4);
    tcase_add_loop_test(tc_string, test_memset_part, 0, 4);
    tcase_add_loop_test(tc_string, test_memset_full, 0, 4);
    tcase_add_loop_test(tc_string, test_strncpy_overlap, 0, 4);
    tcase_add_loop_test(tc_string, test_strcpy_overlap, 0, 4);
    tcase_add_loop_test(tc_string, test_strncpy_nnull, 0, 4);

    tcase_add_test(tc_string, test_strtok);
    tcase_add_loop_test(tc_string, test_strerror, 1, 136);
    tcase_add_loop_test(tc_string, test_strncat, 0, 3);
    tcase_add_loop_test(tc_string, test_strcat, 0, 3);

    tcase_add_loop_test(tc_string, test_sprintf_int, 0, 12);
    tcase_add_loop_test(tc_string, test_sprintf_uint, 0, 10);
    tcase_add_loop_test(tc_string, test_sprintf_string, 0, 6);
    tcase_add_loop_test(tc_string, test_sprintf_char, 0, 6);
    tcase_add_loop_test(tc_string, test_sprintf_float, 0, 9);
    tcase_add_loop_test(tc_string, test_sprintf_octal, 0, 7);
    tcase_add_loop_test(tc_string, test_sprintf_hex, 0, 8);
    tcase_add_loop_test(tc_string, test_sprintf_heX, 0, 8);
    tcase_add_loop_test(tc_string, test_sprintf_exp, 0, 9);
    tcase_add_loop_test(tc_string, test_sprintf_p, 0, 3);
    tcase_add_test(tc_string, test_sprintf_n);
    tcase_add_test(tc_string, test_sprintf_float2);

    tcase_add_loop_test(tc_string, test_strlen, 0, 7);
    tcase_add_loop_test(tc_string, test_strcspn_word, 0, 7);
    tcase_add_loop_test(tc_string, test_strspn_word, 0, 7);
    tcase_add_loop_test(tc_string, test_strcspn_carriage, 0, 7);
    tcase_add_loop_test(tc_string, test_strspn_carriage, 0, 7);
    suite_add_tcase(s, tc_string);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = string_test_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
