/* K&R2 exercise 5-14, page 121 */
/*
 * WIP - -r works only on -n
 */

#include <stdio.h>
#include <string.h> /* strcmp() */
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void _qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
int numcmp(char *, char *, int rev);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverse sort */
    int c;
    
    while (--argc && (*++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch (c) {
	    case 'n':
		numeric = 1;
		break;
	    case 'r':
		reverse = 1;
		break;
	    default:
		printf("illegal option %c\n", c);
		argc = 0;
		break;
	    }
	}
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
	if (reverse) {
	    _qsort((void **) lineptr, 0, nlines - 1,
		   (int (*)(void *, void *))(numeric ? numcmp : strcmp));
	}
	else {
	    _qsort((void **) lineptr, 0, nlines - 1,
		   (int (*)(void *, void *))(numeric ? numcmp : strcmp));
	}
	writelines(lineptr, nlines);
	return 0;
    }
    else {
	printf("input too big to sort \n");
	return -1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    
    /*if ((rev && left <= right) || (!rev && left >= right))*/
    if (left >= right)
	return; /* do nothing if array contains fewer than two elements */
    
    swap(v, left, (left + right) / 2);
    last = left;
    
    for (i = left + 1; i <= right; i++)
	if ((*comp)(v[i], v[left]) < 0)
	    swap(v, ++last, i);
    swap(v, left, last);
    
    _qsort(v, left, last - 1, comp);
    _qsort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2, int rev)
{
    double v1, v2;

    if (!rev) {
	v1 = atof(s1);
	v2 = atof(s2);
    }
    else {
	v1 = atof(s2);
	v2 = atof(s1);
    }
    if (v1 < v2)
	return -1;
    else if (v1 > v2)
	return 1;
    else
	return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
            
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
	if (nlines >= maxlines || (p = alloc(len)) == NULL) {
	    return -1;
	}
	else {
	    line[len-1] = '\0';
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
	printf("%s\n", *lineptr++);
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
	return 0;
}
