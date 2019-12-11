#include "Eigen/Dense"
#include "blaze/Math.h"
#include "macro.hpp"

template <typename U, typename V> auto f(const U& u, const V& v) {
  return u * v;
}
template <typename U, typename V> auto g(const U& u, const V& v) {
  return u * v;
}

template <int n> static void row_major_eigen(benchmark::State& state) {
  using namespace Eigen;
  constexpr int padded =
      blaze::StaticVector<double, static_cast<unsigned int>(n)>::capacity();

  Vector<double, -1> a_buf(padded * padded);
  Vector<double, padded> b_buf;
  Vector<double, padded> c_buf;

  Map<Matrix<double, n, n, RowMajor>, AlignedMax> a(a_buf.data());
  Map<Vector<double, n>, AlignedMax> b(b_buf.data());
  Map<Vector<double, n>, AlignedMax> c(c_buf.data());

  a.setRandom();
  b.setRandom();

  benchmark::DoNotOptimize(a.data());
  benchmark::DoNotOptimize(b.data());

  for (auto _ : state) {
    c = f(a, b);
    benchmark::DoNotOptimize(c.data());
    benchmark::ClobberMemory();
  }
}

template <int n> static void row_major_eigen_strided(benchmark::State& state) {
  using namespace Eigen;
  constexpr int padded =
      blaze::StaticVector<double, static_cast<unsigned int>(n)>::capacity();

  Vector<double, -1> a_buf(padded * padded);
  Vector<double, padded> b_buf;
  Vector<double, padded> c_buf;

  Map<Matrix<double, n, n, RowMajor>, AlignedMax, OuterStride<padded>> a(
      a_buf.data());
  Map<Vector<double, n>, AlignedMax> b(b_buf.data());
  Map<Vector<double, n>, AlignedMax> c(c_buf.data());

  a.setRandom();
  b.setRandom();

  benchmark::DoNotOptimize(a.data());
  benchmark::DoNotOptimize(b.data());

  for (auto _ : state) {
    c = f(a, b);
    benchmark::DoNotOptimize(c.data());
    benchmark::ClobberMemory();
  }
}

template <unsigned int n> static void row_major_blaze(benchmark::State& state) {
  using namespace blaze;
  StaticMatrix<double, n, n, rowMajor> a;
  StaticVector<double, n> b;
  StaticVector<double, n> c;
  randomize(a);
  randomize(b);

  benchmark::DoNotOptimize(a.data());
  benchmark::DoNotOptimize(b.data());

  for (auto _ : state) {
    c = g(a, b);
    benchmark::DoNotOptimize(c.data());
    benchmark::ClobberMemory();
  }
}

BENCH_3_33(row_major_eigen, row_major_eigen_strided, row_major_blaze)
