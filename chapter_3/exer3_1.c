#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000
#define MAX_VALUE 200

int binarysearch(int x, int v[], int n)
{
  int low, mid, high;
  
  low = 0;
  high = n - 1;


  while (low <= high) {
    mid = (low + high) / 2;
    if (x > v[mid])
      low = mid + 1;
    else if (x > v[mid])
      high = mid - 1;
    else
      return mid;
  }

  return -1;
}

int binarysearch2(int x, int v[], int n)
{
  int low, mid, high;
  
  low = 0;
  high = n - 1;

  mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    mid = (low + high) / 2;
    if (x > v[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return v[mid] == x ? mid : -1;
}

void populate(int *arr, unsigned sz, unsigned max)
{
  srand(time(NULL));

  for (int i = 0; i < sz; arr[i++] = (rand() % max))
    ;

  return;
}

int main()
{
  int *arr = (int*) malloc(SIZE * (sizeof(int)));

  populate(arr, SIZE, MAX_VALUE);

  srand(time(NULL));
  int rand_n = rand() % MAX_VALUE;
  
  int search_for = rand_n;
  printf("searching for the number %d...\n", search_for);

  struct timespec start, end, start2, end2;
  long seconds, nanoseconds, seconds2, nanoseconds2;
  double elapsed, elapsed2;
  
  // Record start time
  clock_gettime(CLOCK_MONOTONIC, &start);

  int res =  binarysearch(search_for, arr, SIZE);

  // Record end time
  clock_gettime(CLOCK_MONOTONIC, &end);

  // Calculate elapsed time
  seconds = end.tv_sec - start.tv_sec;
  nanoseconds = end.tv_nsec - start.tv_nsec;
  elapsed = seconds + nanoseconds*1e-9;

  // Record start time
  clock_gettime(CLOCK_MONOTONIC, &start2);

  int res2 =  binarysearch2(search_for, arr, SIZE);

  // Record end time
  clock_gettime(CLOCK_MONOTONIC, &end2);

  // Calculate elapsed time
  seconds2 = end2.tv_sec - start2.tv_sec;
  nanoseconds2 = end2.tv_nsec - start2.tv_nsec;
  elapsed2 = seconds2 + nanoseconds2*1e-9;

  printf("Elapsed time for binarsearch: %.9f seconds\n", elapsed);
  printf("Elapsed time for binarysearch2: %.9f seconds\n", elapsed2);
  return 0;
  
}
