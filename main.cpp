#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1135;

tuple<vector<vector<int>>, int, int> testFixture1()
{
  vector<vector<int>> input{{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
  return make_tuple(input, 3, 6);
}

tuple<vector<vector<int>>, int, int> testFixture2()
{
  vector<vector<int>> input{{1, 2, 3}, {3, 4, 4}};
  return make_tuple(input, 4, -1);
}

void test1()
{
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minCost(get<1>(fixture), get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto fixture = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minCost(get<1>(fixture), get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}