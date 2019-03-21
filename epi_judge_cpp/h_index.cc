#include <vector>
#include <algorithm>

#include "test_framework/generic_test.h"
using std::vector;
using namespace std;

//below is O(logN) soln
int HIndex_logn(vector<int> citations) {
  sort(citations.begin(),citations.end());

  for(int i=0;i<citations.size();i++)
  {
    if(citations[i]>=citations.size()-i)
    {
      return citations.size()-i;
    }
  }

  return 0;
}

//below is O(n) soln
int HIndex(vector<int> citations) {
  int n = citations.size();
  vector<int> s(n+1,0);

  for(int i=0;i<n;i++)
  {
    s[min(n,citations[i])]++;
  }

  int sum =0;
  for(int i=n;i>=0;i--)
  {
    sum += s[i];
    if(sum>=i)
    {
      return i;
    }
  }

  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"citations"};
  return GenericTestMain(args, "h_index.cc", "h_index.tsv", &HIndex,
                         DefaultComparator{}, param_names);
}
