#ifndef SOL_HEADER
#define SOL_HEADER

struct solution {
    int part_one;
    int part_two;
};

struct solution solve(const char *filename);
void swap(int *x, int *y, int *z, int temp_sum);

#endif