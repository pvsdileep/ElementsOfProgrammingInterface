#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
int HIndex(vector<int> citations) {
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

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"citations"};
  return GenericTestMain(args, "h_index.cc", "h_index.tsv", &HIndex,
                         DefaultComparator{}, param_names);
}
