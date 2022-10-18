#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long
#define s21_NULL ((void *)0)
#include <stddef.h>

enum BOOLEAN { FALSE = 0, TRUE = 1 };
enum TYPECONVERTER { DEFAULT, SHORT, LONG, LONGFLOAT };

struct pattern {
    int pattern;
    int precsn;
    int precsnIndr;
    int prefix;
    int width;
    char paddingChar;
    int justify;
    char signFiller;
    int filling;
    int type;
};


/**
 * @brief Searches for the first occurence of a character
 * in the first n bytes of a string
 *
 * @param str string
 * @param c character to search for
 * @param n amount of first bytes
 * @return position of the first occurence or NULL
 */
void *s21_memchr(const void *str, int c, s21_size_t n);
/**
 * @brief Compares the first n bytes of 2 strings
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @param n amount of bytes to compare
 * @return difference between 1st and 2nd strings
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
/**
 * @brief Copies n bytes from string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @param n amount of bytes to copy
 * @return string 2
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
/**
 * @brief Copies n bytes from string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @param n amount of bytes to copy
 * @return string 2
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n);
/**
 * @brief Copies a byte to the first n bytes of the string
 *
 * @param str string
 * @param c byte
 * @param n amount of bytes to replace
 * @return string
 */
void *s21_memset(void *str, int c, s21_size_t n);
/**
 * @brief Appends string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @return string 2
 */
char *s21_strcat(char *dest, const char *src);
/**
 * @brief Appends first n characters of string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @param n amount of characters to append
 * @return string 2
 */
char *s21_strncat(char *dest, const char *src, s21_size_t n);
/**
 * @brief Searches for the first occurence of a character in a string
 *
 * @param str string
 * @param c character
 * @return pointer to the character in a string or NULL
 */
char *s21_strchr(const char *str, int c);
/**
 * @brief Char-by-char comparison of 2 strings
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @return difference between 1st and 2nd strings
 */
int s21_strcmp(const char *str1, const char *str2);
/**
 * @brief Char-by-char comparison of the first n characters of 2 strings
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @param n amount of characters to compare
 * @return difference between first n characters of 1st and 2nd strings
 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
/**
 * @brief Copies string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @return string 2
 */
char *s21_strcpy(char *dest, const char *src);
/**
 * @brief Copies up to n characters from string 1 to string 2
 *
 * @param dest string 2
 * @param src string 1
 * @param n amount of characters to copy
 * @return string 2
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
/**
 * @brief Calculates the length of the initial segment of the 1st string
 * which consists entirely of characters NOT in the 2nd string
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @return calculated length
 */
s21_size_t s21_strcspn(const char *str1, const char *str2);
/**
 * @brief Searches an internal array for the error number
 *
 * @param errnum error number
 * @return pointer to the error message string
 */
char *s21_strerror(int errnum);
/**
 * @brief Computes string length (not including the 0 symbol)
 *
 * @param str string
 * @return string length
 */
s21_size_t s21_strlen(const char *str);
/**
 * @brief Finds first character in the first string
 * that matches any character in the second string
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @return pointer to the found character in the first string
 */
char *s21_strpbrk(const char *str1, const char *str2);
/**
 * @brief Finds last occurence of the character in the string
 *
 * @param str string
 * @param c character
 * @return pointer to the found character in the string or NULL
 */
char *s21_strrchr(const char *str, int c);
/**
 * @brief Calculates the length of the initial segment of the first string
 * which consists entirely of characters in the second string
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @return length of the found segment of the first string
 */
s21_size_t s21_strspn(const char *str1, const char *str2);
/**
 * @brief Finds the first occurence of the entire needle string
 * inside a haystack string
 *
 * @param haystack haystack string
 * @param needle needle string
 * @return pointer to the first occurence of the haystack string or NULL
 */
char *s21_strstr(const char *haystack, const char *needle);
/**
 * @brief Breaks the string into a series of tokens separated
 * by a delimeter
 *
 * @param str string
 * @param delim delimeter
 * @return token
 */
char *s21_strtok(char *str, const char *delim);
/**
 * @brief Writes string contents to a formatted output
 *
 * @param str string to read from
 * @param format output format
 * @param ... outputs to write to
 * @return amount of successfully written outputs
 */
int s21_sscanf(const char *str, const char *format, ...);
/**
 * @brief Writes formatted input to a string
 *
 * @param str string to write to
 * @param format input format
 * @param ... inputs to read from
 * @return amount of successfully read inputs
 */
int s21_sprintf(char *str, const char *format, ...);

void *to_upper(const char *str);

void *to_lower(const char *str);

void *insert(const char *src, const char *str, size_t start_index);

void *trim(const char *src, const char *trim_chars);

size_t s21_strcspn_back(const char *str1, const char *str2, size_t len);

size_t s21_strspn_back(const char *str1, const char *str2, size_t len);

int s21_sscanf(const char *str, const char *format, ...);
/**
 * @brief Writes string contents to a formatted output
 *
 * @param str string to read from
 * @param format output format
 * @param ... outputs to write to
 * @return amount of successfully written outputs
 */
int s21_sprintf(char *stream, const char *format, ...);

/**
 * @brief reverses string presented
 * @param string string to be reversed
 */
void reverse(char *string);
/**
 * @brief convert int number into char sequence
 * @param container string - destination
 * @param n integer to be converted
 * @param base system base (hex, oct, dec, bin)
 * @param prefix determines whether prefix should be inserted
 */
void s21_itoa_base(long long n, char *container, int base, int precsn, int prefix);
/**
 * @brief convert float number into char sequence with given precision
 * @param container string - destination
 * @param n float to be converted
 * @param precsn precision of convertation
 * @param prefix indicator of prefix to be inserted in case of # for oct, hex
 */
void s21_ftoa(double n, char *container, int prec);
/**
 * @brief fill the whole string with '\0'
 * @param str string to be filled
 */
void s21_strclear(char *str);
/**
 * @brief convert float number into exp representation with given precision
 * @param n given float number
 * @param container string to be filled in with an exp representation
 * @param prec precision of converting
 * @param registr indicator for E/e choosing
 * @param prefix
 */
void s21_ftoa_exp(long double n, char *container, int prec, int registr);
/**
 * @brief parses given string untill digits are presented
 * @param str pointer to the place of string to be parsed
 * @param res pointer to the int container for integer result
 */
const char *numParse(const char *str, int *res);
/**
 * @brief reset specifier indicators and values for next argument
 * @param elem struct where inds and vals are stored
 */
void resetPattern(struct pattern *elem);
/**
 * @brief fill in destination string with necessary signs before value insertion
 * @param length the count of signs to be inserted
 * @param formatChar sign-filler
 */
char *fillingAfter(char *str, int length, char formatChar);
/**
 * @brief fill in destination string with necessary signs after value insertion
 * @param length the count of signs to be inserted
 * @param formatChar sign-filler
 */
char *fillingBefore(char *str, int length);

void s21_itoa_baseUnsigned(unsigned long n, char *container, int base, int precsn, int prefix);

/**
 * @brief Checks if size of array is greater than N
 *
 * @param arr array
 * @param n size in bytes
 * @return 0 or 1
 */
int checksize(void* arr, s21_size_t n);
char *signFilling(char *str, long digit);
#endif  //  SRC_S21_STRING_H_
