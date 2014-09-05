/*
 * Findings: binsearch finds numbers far from the middle of the set very quickly,
 * fergsearch is faster at finding a value near the middle, as it works it's way out from the center.
 * fergsearch is more efficient at finding a value not in the list because it checks beforehand.
 * 
 */

/*binsearch: find x in v[0] <= v[1] <= v[n-1] */
#include <stdio.h>
#include <time.h>

struct timespec difftimes(struct timespec start, struct timespec end)
{
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

int binsearch(long long x, long long v[], long long n)
{
  long long low, high, mid;
  
  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid -1;
    else if (x > v[mid])
      low = mid + 1;
    else 
      return mid; //match found
  }
  return -1; //no match
}

int fergsearch(long long x, long long v[],long long n)
{
  long long mid;
  if (x<v[n-1] && x>=v[0]) {
    mid= (n-v[0])/2;
    while (mid != x) {
      if(v[mid] < x)
	mid++;
      else
	mid--;
    }
  }
  return mid == x ? mid : -1;
}



int main(int argc,char *argv[])
{
  struct timespec start; // time keeping
  struct timespec end; // time keeping
  struct timespec resb;
  struct timespec resf;
  struct timespec resa;
  
  if (argc == 3) {
    long long x = strtol(argv[1],(char **)NULL,10);
    long long n = strtol(argv[2],(char **)NULL,10);
    long long a[n], i, f,b; 
    //sizeof array, array to build built, iterator.
    for (i=0;i <= n-1; i++){
      a[i] = i;
    }
    clock_gettime(CLOCK_REALTIME,&start);
    b = binsearch(x,a,n);
    clock_gettime(CLOCK_REALTIME,&end);
    resb = difftimes(start,end);
    printf("binsearch ran for %lld.%.9ld seconds ", (long long)resb.tv_sec, resb.tv_nsec);
    (b == -1) ? printf("and failed!\n") : printf("and Succeeded at %i!\n",b);
    clock_gettime(CLOCK_REALTIME,&start);
    f = fergsearch(x,a,n);
    clock_gettime(CLOCK_REALTIME,&end);
    resf = difftimes(start,end);
    printf("fergsearch ran for %lld.%.9ld seconds ", (long long)resf.tv_sec, resf.tv_nsec);
    (f == -1) ? printf("and failed!\n") : printf("and Succeeded at %i!\n",f);
    //printf("%i %i %i : %i %i\n",f,start.tv_sec, start.tv_nsec, end.tv_sec, end.tv_nsec);
    resa = difftimes(resb,resf);
    printf("difference was: %lld.%.9ld seconds.\n", (long long)resa.tv_sec, resa.tv_nsec);
    
  }
  else
    printf("I need a number to search for and a size of the array.\n");
}



