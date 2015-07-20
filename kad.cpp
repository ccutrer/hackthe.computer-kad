#include <vector>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

uint64_t request = 0;

int comp(uint64_t l, uint64_t r)
{
  return (l ^ request) < (r ^ request);
}

int main(int argc, char **argv)
{
  size_t request_size = 3;
  std::vector<uint64_t> numbers;
  std::string line;
  while (true)
  {
    getline(cin, line);
    cerr << line << endl;
    if(line.empty()) {
      break;
    }
    numbers.push_back(strtoull(line.c_str(), NULL, 10));
  }

  while (true)
  {
    getline(cin, line);
    cerr << line << endl;
    if(line.empty()) {
      break;
    }

    request = strtoull(line.c_str(), NULL, 10);
    std::sort(numbers.begin(), numbers.end(), comp);

    for (size_t i = 0; i < request_size; ++i) {
      cout << numbers[i] << endl;
    }
  }
}
