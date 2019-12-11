#include "benchmark/benchmark.h"

static void dummy(benchmark::State&) {
}

#define BENCH_TP(func, n)                                                      \
  static void func##n(benchmark::State& state) {                               \
    func<n>(state);                                                            \
  }                                                                            \
  BENCHMARK(func##n);

#define BENCH_3(f1, f2, f3, n)                                                 \
  BENCH_TP(f1, n)                                                              \
  BENCH_TP(f2, n)                                                              \
  BENCH_TP(f3, n)                                                              \
  BENCHMARK(dummy);

#define BENCH_3_33(f1, f2, f3)                                                 \
  BENCH_3(f1, f2, f3, 1)                                                       \
  BENCH_3(f1, f2, f3, 2)                                                       \
  BENCH_3(f1, f2, f3, 3)                                                       \
  BENCH_3(f1, f2, f3, 4)                                                       \
  BENCH_3(f1, f2, f3, 5)                                                       \
  BENCH_3(f1, f2, f3, 6)                                                       \
  BENCH_3(f1, f2, f3, 7)                                                       \
  BENCH_3(f1, f2, f3, 8)                                                       \
  BENCH_3(f1, f2, f3, 9)                                                       \
  BENCH_3(f1, f2, f3, 10)                                                      \
  BENCH_3(f1, f2, f3, 11)                                                      \
  BENCH_3(f1, f2, f3, 12)                                                      \
  BENCH_3(f1, f2, f3, 13)                                                      \
  BENCH_3(f1, f2, f3, 14)                                                      \
  BENCH_3(f1, f2, f3, 15)                                                      \
  BENCH_3(f1, f2, f3, 16)                                                      \
  BENCH_3(f1, f2, f3, 17)                                                      \
  BENCH_3(f1, f2, f3, 18)                                                      \
  BENCH_3(f1, f2, f3, 19)                                                      \
  BENCH_3(f1, f2, f3, 20)                                                      \
  BENCH_3(f1, f2, f3, 21)                                                      \
  BENCH_3(f1, f2, f3, 22)                                                      \
  BENCH_3(f1, f2, f3, 23)                                                      \
  BENCH_3(f1, f2, f3, 24)                                                      \
  BENCH_3(f1, f2, f3, 25)                                                      \
  BENCH_3(f1, f2, f3, 26)                                                      \
  BENCH_3(f1, f2, f3, 27)                                                      \
  BENCH_3(f1, f2, f3, 28)                                                      \
  BENCH_3(f1, f2, f3, 29)                                                      \
  BENCH_3(f1, f2, f3, 30)                                                      \
  BENCH_3(f1, f2, f3, 31)                                                      \
  BENCH_3(f1, f2, f3, 32)                                                      \
  BENCH_3(f1, f2, f3, 33)
