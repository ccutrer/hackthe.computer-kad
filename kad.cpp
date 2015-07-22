#include <vector>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

uint64_t request = 0;

int comp(uint64_t l, uint64_t r)
{
  return (l ^ request) < (r ^ request);
}

int main(int argc, char **argv)
{
  std::string line = argv[1];
  size_t request_size;
  size_t equal = line.find('=');
  request_size = atoi(argv[1] + equal + 1);
  std::vector<uint64_t> numbers;
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
    if (cin.eof()) {
      break;
    }
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
