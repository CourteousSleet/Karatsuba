#include <iostream>
#include <fstream>
#include <iterator>
#include <cmath>

using namespace std;

int Karatsuba(int, int, int);

int main() {
  ifstream is("../kek_vector");
  istream_iterator<int> it(is);

  pair<int, int> two_numbers;

  two_numbers.first = *it++;

  two_numbers.second = *it;

  int n = std::to_string(two_numbers.first).length();

  cout << endl;

  cout << "(!) It does not work in C++ correctly. On Python, everything works fine with the same algorithm." << endl << endl;

  cout << two_numbers.first << ' ' << two_numbers.second << endl;

  cout << "Length = " << n << endl;

  if (n % 2 == 0)
    cout << "Calculating..." << endl;
  else
    return 1;

  int result = Karatsuba(n, two_numbers.first, two_numbers.second);

  cout << "Result: " << two_numbers.first << endl <<  'x' << endl << two_numbers.second << " = " << endl << result << endl;

  return 0;
}

int Karatsuba(int length, int x, int y) {

  if (length == 1) {
    int result = y;

    for (int i = 0; i < x - 1; ++i) {
      result += y;
    }

    return result;
  } else {
    int a = x / static_cast<int>(pow(10, static_cast<int>(length) / 2));
    int b = x % static_cast<int>(pow(10, static_cast<int>(length) / 2));

    int c = y / static_cast<int>(pow(10, static_cast<int>(length) / 2));
    int d = y % static_cast<int>(pow(10, static_cast<int>(length) / 2));

    int p = a + b;
    int q = c + d;

    int ac = Karatsuba(length / 2, a, c);

    int bd = Karatsuba(length / 2, b, d);

    int pq = Karatsuba(length / 2, p , q);

    int adbc = pq - ac - bd;

    auto first_coeff = static_cast<int>(pow(10, length));

    for (int i = 0; i < ac - 1; ++i) {
      first_coeff += static_cast<int>(pow(10, length));
    }

    auto second_coeff = static_cast<int>(pow(10, length / 2));

    for (int i = 0; i < adbc - 1; ++i) {
      second_coeff += static_cast<int>(pow(10, length / 2));
    }

    int result = first_coeff + second_coeff + bd;

    return result;
  }
}