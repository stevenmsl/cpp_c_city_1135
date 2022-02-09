

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;
namespace sol1135
{
    class Solution
    {
    public:
        int minCost(int N, vector<vector<int>> &input);
    };

    class UnionFind
    {
    private:
        vector<int> parents;
        vector<int> sizes;
        int groups;

    public:
        UnionFind(int n);
        int findGroup(int city);
        void unify(int city1, int city2);
        int CountGroup();
    };

}
#endif