#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <assert.h>

int KR_puts(const char *s) {
    assert(s != nullptr);

    int i = 0;
    for (;       s[i]; i++) {
        if (putc(s[i], stdout) == EOF) return EOF;
    }

    if (putc('\n', stdout) == EOF) return EOF;
    return i;
}

const char * KR_strchr(const char *s, int ch) {
    assert(s != nullptr);

    do {
        if  (*s == ch) return s;
    } while (*s++);
    
    return nullptr;
}

char * KR_strchr(char *s, int ch) {
    assert(s != nullptr);

    do {
        if  (*s == ch) return s;
    } while (*s++);

    return nullptr;
}

unsigned int KR_strlen (char *s) {
    assert(s != nullptr);

    char   *p = s;
    while (*p) p++;

    return p - s;
}

unsigned int KR_strlen (const char *s) {
    assert(s != nullptr);

    const char *p = s;
    while (    *p) p++;

    return p - s;
}

void KR_strcpy(char *s, char *ct) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    while ((*s = *ct)) {
        s++;
        ct++;
    }
}

void KR_strcpy(char *s, const char *ct) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    while ((*s = *ct)) {
        s++;
        ct++;
    }
}

void KR_strncpy(char *s, char *ct, int n) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    for (int i = 0; i < n && (*s = *ct); i++) {
        s++;
        ct++;
    }
    *s = 0;
}

void KR_strncpy(char *s, const char *ct, int n) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    for (int i = 0; i < n && (*s = *ct); i++) {
        s++;
        ct++;
    }
    *s = 0;
}

void KR_strcat(char *s, char *ct) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    KR_strcpy(KR_strchr(s, '\0'), ct);
}

void KR_strcat(char *s, const char *ct) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    KR_strcpy(KR_strchr(s, '\0'), ct);
}

void KR_strncat(char    *s, char  *ct, int n) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    KR_strncpy(KR_strchr(s, '\0'), ct, n);
}

void KR_strncat(char *s, const char *ct, int n) {
    assert(s  != nullptr);
    assert(ct != nullptr);

    KR_strncpy(KR_strchr(s, '\0'), ct, n);
}

char * KR_fgets(char *s, int n, FILE *stream) {
    assert(s      != nullptr);
    assert(stream != nullptr);

    int c    = 0;
    char *cs = nullptr;

    cs = s;
    while (--n > 0 && (c = getc(stream)) != EOF)
        if ((*cs++ = (char)c) == '\n' ) break;

    if (cs != s) {
        *(--cs) = '\0';
    }
    else {
        *cs = '\0';
    }

    return (c == EOF && cs == s) ? nullptr : s;
}

char * KR_strdup(char *s) {
    assert(s != nullptr);

    char *p = nullptr;
    p = (char *) malloc(KR_strlen(s) + 1);

    KR_strcpy(p, s);

    return p;
}

char * KR_strdup(const char *s) {
    assert(s != nullptr);

    char *p = nullptr;
    p = (char *) malloc(KR_strlen(s) + 1);

    KR_strcpy(p, s);

    return p;
}