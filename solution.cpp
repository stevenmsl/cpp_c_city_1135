#include "solution.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace sol1135;
using namespace std;

/*takeaways
  - use Kruskal's algorithm to find the MST
    - MST stands for Minimum Spanning tree
    - it is defined as a subset of the edges
      which connect all vertices in the graph
      with the minimal total edge cost

  - Kruskal's algorithm steps
    - sort the edges by ascending edge weight
    - walk through the edges and unify two
      cities at a time
    - terminate when all the vertices
      have been unified

*/

int Solution::minCost(int N, vector<vector<int>> &input)
{
  /*step 1
    - sort the edges by ascending edge weight
  */
  auto compare = [](vector<int> a, vector<int> b)
  {
    /* ascending */
    return a[2] < b[2];
  };
  sort(input.begin(), input.end(), compare);

  int totalCost = 0;
  UnionFind uf = UnionFind(N);

  /*step 2
    - walk through the edges and unify two
      cities at a time
    - the goal is to reduce the
      groups to one so a MST
      tree can be formed if
      possible
  */
  for (auto edge : input)
  {
    if (uf.findGroup(edge[0]) != uf.findGroup(edge[1]))
    {
      /*
        - you need to merge these two groups
        - and pay the minimum cost possible
          to connect these two groups
          - that's why we sort the input vec
            first
      */
      uf.unify(edge[0], edge[1]);
      totalCost += edge[2];
    }

    /* step 3
      - terminate when all the vertices
        have been unified
      - we don't necessarily need to use all the
        edges to form a MST tree
    */
    if (uf.CountGroup() == 1)
    {
      return totalCost;
    }
  }

  return -1;
}

UnionFind::UnionFind(int n)
{
  parents = vector<int>(n + 1);
  sizes = vector<int>(n + 1);
  /*
     - we are not using the position 0
       for the sake of convenience as
       the input of the edges is 1-based
   */
  for (auto i = 0; i <= n; i++)
  {
    /*
       - initially everyone is its own parent
    */
    parents[i] = i;
    sizes[i] = 1;
  }
  groups = n;
}
int UnionFind::findGroup(int city)
{
  if (parents[city] != city)
  {
    city = findGroup(parents[city]);
  }
  return city;
}
void UnionFind::unify(int city1, int city2)
{
  auto group1 = findGroup(city1);
  auto group2 = findGroup(city2);
  if (group1 == group2)
    return;

  /* merge with the group with more cities */
  if (sizes[group1] > sizes[group2])
  {
    parents[group2] = group1;
    sizes[group1] += sizes[group2];
  }
  else
  {
    parents[group1] = group2;
    sizes[group2] += sizes[group1];
  }

  /*
    - one fewer group
    - if a MST tree can be formed
      , it will only have one group
      left
  */
  groups--;
}
int UnionFind::CountGroup()
{
  return groups;
}