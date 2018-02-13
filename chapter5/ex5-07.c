/* K&R2 exercise 5-7, page 110 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN];

int readlines(char *lineptr[], int nlines);
int readlines2(char lines[][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
	qsort(lineptr, 0, nlines-1);
	writelines(lineptr, nlines);
	return 0;
    }
    else
    {
	printf("error: input too big to sort\n");
	return 1;
    }
}

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
	if (nlines >= maxlines || (p = alloc(len)) == NULL)
	{
	    return -1;
	}
	else
	{
	    line[len-1] = '\0';
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    }
    return nlines;
}

int readlines2(char lines[][MAXLEN], int maxlines)
{
    int len, nlines;

    nlines = 0;
    while ((len = getline(lines[nlines], MAXLEN)) > 0)
    {
	if (nlines >= maxlines)
	    return -1;
	else
	    lines[nlines++][len-1] = '\0';
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
    if (c == '\n')
    {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]..v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
	return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
	if (strcmp(v[i], v[left]) < 0)
	    swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
	return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
