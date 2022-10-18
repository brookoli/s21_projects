#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include "s21_string.h"

struct pattern elemP = {0, 1, 0, 0, 0, ' ', 1, ' ', 0, DEFAULT};

char bufStr[1024];

char ER_MAC_OS[][80] = {"Operation not permitted",
                        "No such file or directory",
                        "No such process",
                        "Interrupted system call",
                        "Input/output error",
                        "Device not configured",
                        "Argument list too long",
                        "Exec format error",
                        "Bad file descriptor",
                        "No child processes",
                        "Resource deadlock avoided",
                        "Cannot allocate memory",
                        "Permission denied",
                        "Bad address",
                        "Block device required",
                        "Resource busy",
                        "File exists",
                        "Cross-device link",
                        "Operation not supported by device",
                        "Not a directory",
                        "Is a directory",
                        "Invalid argument",
                        "Too many open files in system",
                        "Too many open files",
                        "Inappropriate ioctl for device",
                        "Text file busy",
                        "File too large",
                        "No space left on device",
                        "Illegal seek",
                        "Read-only file system",
                        "Too many links",
                        "Broken pipe",
                        "Numerical argument out of domain",
                        "Result too large",
                        "Resource temporarily unavailable",
                        "Operation now in progress",
                        "Operation already in progress",
                        "Socket operation on non-socket",
                        "Destination address required",
                        "Message too long",
                        "Protocol wrong type for socket",
                        "Protocol not available",
                        "Protocol not supported",
                        "Socket type not supported",
                        "Operation not supported",
                        "Protocol family not supported",
                        "Address family not supported by protocol family",
                        "Address already in use",
                        "Can't assign requested address",
                        "Network is down",
                        "Network is unreachable",
                        "Network dropped connection on reset",
                        "Software caused connection abort",
                        "Connection reset by peer",
                        "No buffer space available",
                        "Socket is already connected",
                        "Socket is not connected",
                        "Can't send after socket shutdown",
                        "Too many references: can't splice",
                        "Operation timed out",
                        "Connection refused",
                        "Too many levels of symbolic links",
                        "File name too long",
                        "Host is down",
                        "No route to host",
                        "Directory not empty",
                        "Too many processes",
                        "Too many users",
                        "Disc quota exceeded",
                        "Stale NFS file handle",
                        "Too many levels of remote in path",
                        "RPC struct is bad",
                        "RPC version wrong",
                        "RPC prog. not avail",
                        "Program version wrong",
                        "Bad procedure for program",
                        "No locks available",
                        "Function not implemented",
                        "Inappropriate file type or format",
                        "Authentication error",
                        "Need authenticator",
                        "Device power is off",
                        "Device error",
                        "Value too large to be stored in data type",
                        "Bad executable (or shared library)",
                        "Bad CPU type in executable",
                        "Shared library version mismatch",
                        "Malformed Mach-o file",
                        "Operation canceled",
                        "Identifier removed",
                        "No message of desired type",
                        "Illegal byte sequence",
                        "Attribute not found",
                        "Bad message",
                        "EMULTIHOP (Reserved)",
                        "No message available on STREAM",
                        "ENOLINK (Reserved)",
                        "No STREAM resources",
                        "Not a STREAM",
                        "Protocol error",
                        "STREAM ioctl timeout",
                        "Operation not supported on socket",
                        "Policy not found",
                        "State not recoverable",
                        "Previous owner died",
                        "Interface output queue is full",
                        ""};

char ERR_GNU_LINUX[][80] = {
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error",
    "",
};

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *res = s21_NULL;
    for (const unsigned char *p = (const unsigned char*)str; (n > 0) && (!res); p++, n--) {
        if (*p == c) {
            res = (unsigned char*)p;
        }
    }
    return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *line1 = (unsigned char *)str1;
  unsigned char *line2 = (unsigned char *)str2;
  int flag = 0;
  for (int i = 0; i < (int)n; i++) {
    if (line1[i] != line2[i]) {
      flag = line1[i] - line2[i];
      break;
    }
  }
  return flag;
}

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    for (s21_size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return dest;
}

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
    char* temp = malloc(n);

    s21_memcpy(temp, src, n);
    s21_memcpy(dest, temp, n);

    free(temp);
    return dest;
}

void* s21_memset(void* str, int c, s21_size_t n) {
    char* cstr = (char*)str;

    for (s21_size_t i = 0; i < n; i++) {
        cstr[i] = c;
    }
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    char *result = dest;
    while (*dest) dest++;

    while (*src != 0) {
        *dest++ = *src++;
    }
    *dest = *src;

    return result;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    char *result = dest;
    while (*dest) dest++;
    char *pr = (char *)src;
    while (n-- != 0 && (*pr != 0)) {
        pr++;
    }
    while (src != pr) {
        *dest++ = *src++;
    }
    *dest = 0;
    return result;
}

char *s21_strchr(const char *str, int c) {
    char *res = 0;
    do {
        if (*str == c) {
            res = (char*)str;
        }
    } while ((*str++) && (!res));
    return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  int flag = 0;
  for (; ((*str1 != '\0') && (*str2 != '\0') && (flag == 0)); str1++, str2++) {
    flag = *str1 - *str2;
  }
  if (flag == 0) {
    flag = *str1 - *str2;
  }
  return flag;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;
  int i = 0;
  for (; ((i < (int)n) && (*str1 != '\0') && (*str2 != '\0') && (flag == 0));
       i++, str1++, str2++) {
    flag = *str1 - *str2;
  }
  if ((flag == 0) && (i < (int)n)) {
    flag = *str1 - *str2;
  }
  return flag;
}

char* s21_strcpy(char* dest, const char* src) {
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    s21_size_t i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        cdest[i] = csrc[i];
    }
    cdest[i] = '\0';

    return dest;
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    s21_size_t i = 0;

    while ((i < n) && (src[i] != '\0')) {
        cdest[i] = csrc[i];
        i++;
    }
    cdest[i] = '\0';

    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    const char *sc1 = 0;
     for (sc1 = str1; *sc1 != '\0'; sc1++) {
         if (s21_strchr(str2, *sc1) != s21_NULL) {
           break;
         }
     }
     return (s21_size_t)(sc1 - str1);
}

char *s21_strerror(int errnum) {
    char *descr;
#ifdef __APPLE__
    if (errnum < 1 || errnum > 106) {
        char errMsg[90] = "Unknown error: ";
        s21_strclear(ER_MAC_OS[106]);
        char err[10];
        s21_itoa_base(errnum, err, 10, 1, 0);
        s21_strcpy(ER_MAC_OS[106], errMsg);
        s21_strcat(ER_MAC_OS[106], err);
        descr = ER_MAC_OS[106];
    } else {
        descr = ER_MAC_OS[errnum - 1];
    }
#elif __linux__
    if (errnum < 1 || errnum > 133) {
        char errMsg[90] = "Unknown error ";
        s21_strclear(ER_MAC_OS[106]);
        char err[10];
        s21_itoa_base(errnum, err, 10, 1, 0);
        s21_strcpy(ER_MAC_OS[106], errMsg);
        s21_strcat(ER_MAC_OS[106], err);
        descr = ER_MAC_OS[106];
    } else {
        descr = ERR_GNU_LINUX[errnum - 1];
    }
#endif

    return descr;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    if (str != s21_NULL) {
    while (str[result]) {
        result++;
    }
    }
    return result;
}


char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = s21_NULL;
    for (char *p = (char*)str1; (*p != 0) && (!res); p++) {
        for (char *r = (char*)str2; (*r != 0) && (!res); r++) {
            if (*p == *r) {
                res = p;
            }
        }
    }
    return res;
}

char *s21_strrchr(const char *str, int c) {
    char *res = 0;
    do {
        if (*str == c) {
            res = (char*)str;
        }
    } while (*str++);
    return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    const char *sc1;
     for (sc1 = str1; *sc1 != '\0'; sc1++) {
         if (s21_strchr(str2, *sc1) == NULL) {
           break;
         }
     }
     return (s21_size_t)(sc1 - str1);
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (*needle == 0) {
        return (char*)haystack;
    }
    char *res = s21_NULL;
    char *comp = (char*)needle;
    for (char *p = (char*)haystack; (*p) && (*comp); p++) {
        if (*p == *comp) {
            if (!res) {
                res = p;
            }
            comp++;
        } else {
            res = s21_NULL;
            comp = (char*)needle;
        }
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static char* pr_end_strtok;
    char *p;
    if (str != s21_NULL) {
        pr_end_strtok = str;
        while ((s21_strchr(delim, *pr_end_strtok)) && (*pr_end_strtok)) {
            *pr_end_strtok = 0;
            pr_end_strtok++;
        }
    }
    if (*pr_end_strtok != 0) {
        p = pr_end_strtok;
        while ((!s21_strchr(delim, *pr_end_strtok)) && (*pr_end_strtok)) {
            pr_end_strtok++;
        }
        while (*pr_end_strtok && (s21_strchr(delim, *pr_end_strtok))) {
            *pr_end_strtok = 0;
            pr_end_strtok++;
        }
    } else {
        p = s21_NULL;
    }
    return p;
}

void *to_upper(const char *str) {
  int i = 0;
  char *str_copy = NULL;
  if (str != NULL) {
    str_copy = malloc(s21_strlen(str) + 1);
    for (; str[i]; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        str_copy[i] = str[i] - 32;
      } else {
        str_copy[i] = str[i];
      }
    }
    str_copy[i] = 0;
  }
  return str_copy;
}

void *to_lower(const char *str) {
  int i = 0;
  char *str_copy = NULL;
  if (str != NULL) {
    str_copy = malloc(s21_strlen(str) + 1);
    for (; str[i]; i++) {
      if (str[i] >= 65 && str[i] <= 90) {
        str_copy[i] = str[i] + 32;
      } else {
        str_copy[i] = str[i];
      }
    }
    str_copy[i] = 0;
  }
  return str_copy;
}

void *insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = (char *)src;
    int len = s21_strlen(src);
    int shift = s21_strlen(str);
    for (int i = len; i > (int)start_index - 1; i--) {
        res[i + shift] = res[i];
    }
    for (int i = 0; i < shift; i++) {
        res[i + start_index] = str[i];
    }
    return res;
}

void *trim(const char *src, const char *trim_chars) {
    char *res;
    if ((src == NULL) || (trim_chars == NULL)) {
        res = (char*) src;
    } else {
        int place = s21_strcspn(src, trim_chars);
        int amount = s21_strspn(src + place, trim_chars);
        res = malloc(s21_strlen(src) + 1);
        s21_strcpy(res, src);
        s21_strcpy(res + place, res + place + amount);
        size_t len = s21_strlen(res);
        place = s21_strcspn_back(res + len - 1, trim_chars, len - place - amount + 1);
        amount = s21_strspn_back(res + len - place - 1, trim_chars, len - place);
        s21_strcpy(res + len - place - amount, res + len - place);
    }
    return res;
}

s21_size_t s21_strcspn_back(const char *str1, const char *str2, s21_size_t len) {
  const char *sc1 = 0;
  s21_size_t i;
  for (i = len, sc1 = str1; i > 0; sc1--, i--) {
    if (s21_strchr(str2, *sc1) != NULL) {
      break;
    }
  }
  return (s21_size_t)(str1 - sc1);
}

s21_size_t s21_strspn_back(const char *str1, const char *str2, s21_size_t len) {
  const char *sc1;
  s21_size_t i;
  int count = 0;
  for (i = len, sc1 = str1; i > 0; sc1--, i--) {
    for (char *p = (char*)str2; *p != 0; p++) {
      if (*sc1 == *p) {
        break;
      }
      count++;
    }
    if (count == (int)s21_strlen(str2)) {
      break;
    }
    count = 0;
  }
  return (s21_size_t)(str1 - sc1);
}

void s21_itoa_base(long long n, char *container, int base, int precsn, int prefix) {
    long long nShadow = n;
    int i = 0, check = 0, oneMore = 0;
    if (base < 0) {
        base = -base;
        oneMore = 1;
    }
    if (n < 0) {
        n = -n;
        check = 1;
    }
    do {
        int remndr = (n % base);
        if (oneMore) {
            container[i++] = "0123456789ABCDEF"[remndr];
        } else {
            container[i++] = "0123456789abcdef"[remndr];
        }
    } while ((n /= base) > 0);

    if (prefix == 1 && base == 8 && nShadow != 0) container[i++] = '0';

    container[i] = '\0';
    int k = s21_strlen(container);

    while (k < precsn) {
        container[i++] = '0';
        precsn--;
    }

    if (prefix == 1 && base == 16 && nShadow != 0 && oneMore == 0) {
        container[i++] = 'x';
        container[i++] = '0';
    }
    if (prefix == 1 && base == 16 && nShadow != 0 && oneMore == 1) {
        container[i++] = 'X';
        container[i++] = '0';
    }

    if ((check) && (elemP.paddingChar == ' ')) {
        container[i++] = '-';
    } else if ((elemP.filling == TRUE)  && (elemP.paddingChar != '0')) {
        container[i++] = elemP.signFiller;
    }

    container[i] = '\0';
    reverse(container);
}

void s21_itoa_baseUnsigned(unsigned long n, char *container, int base, int precsn, int prefix) {
    unsigned nShadow = n;
    int i = 0, oneMore = 0;
    if (base < 0) {
        base = -base;
        oneMore = 1;
    }
    do {
        int remndr = (n % base);
        if (oneMore) {
            container[i++] = "0123456789ABCDEF"[remndr];
        } else {
            container[i++] = "0123456789abcdef"[remndr];
        }
    } while ((n /= base) > 0);

    if (prefix == 1 && base == 8 && nShadow != 0) container[i++] = '0';

    container[i] = '\0';
    int k = s21_strlen(container);
    while (k < precsn) {
        container[i++] = '0';
        precsn--;
    }

    if (prefix == 1 && base == 16 && nShadow != 0 && oneMore == 0) {
        container[i++] = 'x';
        container[i++] = '0';
    }
    if (prefix == 1 && base == 16 && nShadow != 0 && oneMore == 1) {
        container[i++] = 'X';
        container[i++] = '0';
    }

    if ((elemP.filling) == TRUE) {
        container[i++] = elemP.signFiller;
    }

    container[i] = '\0';
    reverse(container);
}

void s21_ftoa(double n, char *container, int prec) {
    int i = 0, check = 0;
    if (n < 0) {
        n = -n;
        check = 1;
    }
    long intPart = (long)n;
    n = n - intPart;
    if (n == 0.5 && elemP.precsn == 0) {
        if (intPart % 2 == 1) intPart += 1;
    }
    do {
        container[i++] = (intPart % 10 + '0');
    } while ((intPart /= 10) > 0);

    if (check) {
        container[i++] = '-';
    } else if ((elemP.filling) == TRUE) {
        container[i++] = elemP.signFiller;
    }
    reverse(container);
    if (elemP.precsnIndr == TRUE) container[i++] = '.';
    while (prec--) {
        n *= 10;
        int k = (int)n;
        container[i++] = k + '0';
        n = n - k;
    }
    container[i] = '\0';

    if (n > 0.5) {
        i--;
        while (container[i] == '9') {
            container[i--] = '0';
            if (container[i] == '.') i--;
        }
        if (container[i] == '.') i--;
        container[i] += 1;
    } else if (n == 0.5) {
    }
}

void s21_ftoa_exp(long double n, char *container, int prec, int registr) {
    int power = 0;
    int i = 0, check = 0;
    if (n < 0) {
        n = -n;
        check = 1;
    }
    if (n > 10) {
        while (n > 10) {
            n /= 10;
            power++;
        }
    } else if (n < 1 && n != 0) {
        while (n < 1) {
            n *= 10;
            power--;
        }
    } else {
        power = 0;
    }
    long intPart = (long)n;
    n = n - intPart;
    if (check) {
        container[i++] = '-';
    } else if (elemP.filling == TRUE) {
        container[i++] = elemP.signFiller;
    }
    container[i++] = intPart + '0';

    container[i++] = '.';
    while (prec--) {
        n *= 10;
        int k = (int)n;
        container[i++] = "0123456789"[k];
        n = n - k;
    }
    if (registr) {
        container[i++] = 'e';
    } else {
        container[i++] = 'E';
    }
    if (power < 0) {
        power *= -1;
        container[i++] = '-';
    } else {
        container[i++] = '+';
    }
    if (power < 10) container[i++] = '0';

    char buff[4];
    char *pr = buff;
    s21_itoa_base(power, buff, 10, 1, 0);
    while (*pr < 48 || *pr > 57) {
        pr++;
    }
    while (*pr) {
        container[i++] = *pr++;
    }
    container[i] = '\0';
    n *= 10;

    if (n >= 5) {
        while (container[i + 1] != 'e' && container[i + 1] != 'E') {
            i--;
        }
        while (container[i] == '9') {
            container[i--] = '0';
            if (container[i] == '.') i--;
        }
        container[i] += 1;
    }
}

void reverse(char *string) {
    for (int i = 0, j = s21_strlen(string) - 1; i <= j; i++, j--) {
    char swap;
        swap = string[i];
        string[i] = string[j];
        string[j] = swap;
    }
}

void s21_strclear(char *str) {
    while (*str) {
        *str = 0;
        str++;
    }
}

const char *numParse(const char *str, int *res) {
    int multiplicator = 10;
    char *num = malloc(50 * sizeof(char));
    char *pr = num;

    while (*str >= 48 && *str <= 57) {
        *num = *str;
        num++;
        str++;
    }
    *num = '\0';
    num = pr;
    reverse(num);

    if (*num != 0) {
    int result = 0;
        result += (*pr - 48);
        pr++;
        while (*pr) {
            result += (*pr - 48) * multiplicator;
            multiplicator *= 10;
            pr++;
        }
        *res = result;
    } else {
        *res = 0;
    }
    free(num);
    return str;
}

int s21_sprintf(char *stream, const char *format, ...) {
    char *zone51 = stream;
    char *digStr = bufStr;
    char *startDigStr = digStr;
    char ch;          /*for char*/
    double fNum;      /*for float*/
    long digit;
    int *digPr;
    unsigned long unInt; /*for 'u' */

    struct pattern *elem = &elemP;
    resetPattern(elem);

    int insertedLength = 0; /*for width*/

    va_list paramList;
    va_start(paramList, format);
    while (*format) {
        s21_strclear(digStr);
        if (*format != '%' && (elem->pattern) == FALSE) {
            *stream++ = *format++;
        } else {
            elem->pattern = TRUE;
            if (*format == '%') format++;

            if (*format == '-') {
                elem->justify = 0;
                format++;
            }

            if (*format == '+' || *format == ' ') {
                if (*format == '+') elem->signFiller = '+';
                if (*format == ' ') {
                    elem->signFiller = ' ';
                }
                elem->filling = TRUE;

                format++;
            }
            if (*format > 48 && *format <= 57) format = numParse(format, &(elem->width));

            if (*format == '*') {
                format++;
                elem->width = va_arg(paramList, int);
            }

            if (*format == '#') {
                format++;
                elem->prefix = TRUE;
            }

            if (*format == '0') {
                elem->paddingChar = '0';
                format++;
            }

            if (*format == '.') {
                if (*(format + 1) == '*') {
                    format += 2;
                    elem->precsn = va_arg(paramList, int);
                } else {
                    format++;
                    format = numParse(format, &(elem->precsn));
                }
                elem->precsnIndr = TRUE;
            }
            if (*format == 'h') {
                format++;
                elem->type = SHORT;
            }
            if (*format == 'l') {
                elem->type = LONG;
                format++;
            }
            if (*format == 'L') {
                elem->type = LONGFLOAT;
                format++;
            }
            switch (*format) {
                case 'd':
                case 'i':
                    digit = va_arg(paramList, long);
                    if (elem->type == SHORT) digit = (short)digit;
                    // if (elem->type == LONG) digit = (long)digit;
                    if (elem->type == DEFAULT) digit = (int)digit;
                    if (elem->precsnIndr == TRUE) elem->paddingChar = ' ';
                    s21_itoa_base(digit, digStr, 10, elem->precsn, 0);
                    elem->prefix = TRUE;
                    stream = signFilling(stream, digit);
                    insertedLength = elem->width - s21_strlen(digStr);
                    stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'd');
                    format++;
                    resetPattern(elem);
                    break;
                case 'u':
                    unInt = va_arg(paramList, unsigned long);
                    if (elem->type == SHORT) unInt = (unsigned short)unInt;
                    if (elem->type == DEFAULT) unInt = (unsigned int)unInt;
                    elem->filling = FALSE;
                    s21_itoa_baseUnsigned(unInt, digStr, 10, elem->precsn, 0);
                    insertedLength = elem->width - s21_strlen(digStr);
                    if (elem->precsnIndr == TRUE) elem->paddingChar = ' ';
                    stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'u');
                    format++;
                    resetPattern(elem);
                    break;
                case 's': {
                };
                    #ifdef __linux__
                    elem -> paddingChar = ' ';
                    #endif
                    char *pr = va_arg(paramList, char *);
                    insertedLength = elem->width - s21_strlen(pr);
                    if (elem->precsnIndr == TRUE)
                        if (elem->justify == 0)
                        elem->paddingChar = ' ';
                    stream = fillingBefore(stream, insertedLength);
                    if (elem->precsnIndr == FALSE) {
                        while (*pr) {
                            *stream++ = *pr++;
                        }
                    } else {
                        while ((elem->precsn)-- != 0 && *pr) {
                            *stream++ = *pr++;
                        }
                    }
                    stream = fillingAfter(stream, insertedLength, 's');
                    format++;
                    resetPattern(elem);
                    break;
                case 'c':
                    #ifdef __linux__
                    elem -> paddingChar = ' ';
                    #endif
                    ch = va_arg(paramList, int);
                    insertedLength = elem->width - 1;
                    if (elem->justify == 0)
                        elem->paddingChar = ' ';
                    stream = fillingBefore(stream, insertedLength);
                    *stream++ = ch;
                    stream = fillingAfter(stream, insertedLength, 'c');
                    format++;
                    resetPattern(elem);
                    break;
                case 'f': {
                };
                    fNum = va_arg(paramList, double);
                    if (elem->type == LONGFLOAT) fNum = (long double)fNum;
                    if (elem->precsnIndr == FALSE) {
                        elem->precsn = 6;
                        elem->precsnIndr = TRUE;
                    } else if (elem->precsnIndr == TRUE && elem->precsn == 0) {
                        elem->precsnIndr = FALSE;
                    }
                    if (elem->prefix == TRUE) {
                        elem->precsnIndr = TRUE;
                    }

                    s21_ftoa(fNum, digStr, elem->precsn);
                    insertedLength = elem->width - s21_strlen(digStr);
                    stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'f');
                    format++;
                    resetPattern(elem);
                    break;
                case 'o':
                case 'x':
                case 'X':
                    if (elem->prefix == TRUE) elem->paddingChar = ' ';
                    // if (elem->filling == TRUE && elem->signFiller == '+') {
                    //     if (unsignedFiller == TRUE) elem->signFiller = ' ';
                    // }
                    elem->filling = FALSE;
                    unInt = va_arg(paramList, unsigned int);
                    if (elem->type == SHORT) unInt = (unsigned short)unInt;
                    if (elem->type == LONG) unInt = (unsigned long)unInt;
                    if (elem->type == DEFAULT) unInt = (unsigned int)unInt;

                    if (*format == 'x') s21_itoa_baseUnsigned(unInt, digStr, 16, elem->precsn, elem->prefix);
                    if (*format == 'X') s21_itoa_baseUnsigned(unInt, digStr, -16, elem->precsn, elem->prefix);
                    if (*format == 'o') s21_itoa_baseUnsigned(unInt, digStr, 8, elem->precsn, elem->prefix);

                    insertedLength = elem->width - s21_strlen(digStr);
                    stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'o');
                    format++;
                    resetPattern(elem);
                    break;
                case 'e':
                case 'E':
                    if (elem->precsnIndr == FALSE) {
                        elem->precsn = 6;
                    }
                    fNum = va_arg(paramList, double);
                    if (*format == 'e') s21_ftoa_exp(fNum, digStr, elem->precsn, 1);
                    if (*format == 'E') s21_ftoa_exp(fNum, digStr, elem->precsn, 0);
                    insertedLength = elem->width - s21_strlen(digStr);
                    if (elem->justify) stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'e');
                    format++;
                    resetPattern(elem);
                    break;
                case 'p':
                    digit = va_arg(paramList, unsigned long);
                    if (digit == 0) {
                    #ifdef __APPLE__
                        digStr = "0x0";
                    #elif __linux__
                        digStr = "(nil)";
                    #endif
                    } else {
                        s21_itoa_base(digit, digStr, 16, 0, 1);
                    }
                    insertedLength = elem->width - s21_strlen(digStr);
                    if (elem->justify) stream = fillingBefore(stream, insertedLength);
                    while (*digStr) {
                        *stream++ = *digStr++;
                    }
                    stream = fillingAfter(stream, insertedLength, 'e');
                    format++;
                    resetPattern(elem);
                    break;
                case 'n':
                    digPr = va_arg(paramList, int *);
                    *stream = 0;
                    *digPr = s21_strlen(zone51);
                    format++;
                    resetPattern(elem);
            }
        }
        digStr = startDigStr;
    }
    *stream = 0;
    va_end(paramList);
    return s21_strlen(zone51);
}

char *fillingBefore(char *str, int length) {
    if (elemP.justify) {
        while (length-- > 0) {
            *str++ = elemP.paddingChar;
        }
    }
    return str;
}

char *signFilling(char *str, long digit) {
    if (elemP.paddingChar != ' ') {
        if (digit < 0) {
            *str++ = '-';
            elemP.width -= 1;
        }
        if (elemP.filling == TRUE && digit >= 0) {
            *str++ = elemP.signFiller;
            elemP.width -= 1;
        }
    }
    return str;
}

char *fillingAfter(char *str, int length, char formatChar) {
    if ((elemP.justify == 0)) {
        if (elemP.paddingChar == '0') elemP.paddingChar = ' ';
        if ((formatChar == 'u' || formatChar == 'd') && elemP.paddingChar == '0') elemP.paddingChar = ' ';
        while (length-- > 0) {
            *str++ = elemP.paddingChar;
        }
    }
    return str;
}

void resetPattern(struct pattern *a) {
    a->pattern = FALSE;
    a->precsn = 1;
    a->precsnIndr = FALSE;
    a->prefix = FALSE;
    a->width = 0;
    a->paddingChar = ' ';
    a->justify = 1;
    a->signFiller = ' ';
    a->filling = FALSE;
    a->type = DEFAULT;
}
