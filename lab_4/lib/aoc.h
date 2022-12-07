#ifndef AOC_HEADER
#define AOC_HEADER

/**
 * @brief: Structure holding integer
 * values of solutions for
 * part one and two.
 */
struct solution {
    int part_one;
    int part_two;
};

struct solution solve(const char *filename);
void hotswap(int *x, int *y, int *z, int sum);

#endif