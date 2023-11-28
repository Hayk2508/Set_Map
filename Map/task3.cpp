#include <iostream>
#include <map>
#include <vector>

int main(){

int n;
int k;

std::cin >> n;
std::vector<int> nums(n);

for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
}

std::cin >> k;
bool isfound = false;

std::map<int, int> IndexMap;
for (int i = 0; i < nums.size(); ++i) {
    if (IndexMap.find(nums[i]) != IndexMap.end() && abs(i - IndexMap[nums[i]]) <= k) {
        isfound = true;
        break;
        }
    IndexMap[nums[i]] = i;
}

if(isfound){
    std::cout << "True";
}
else{
    std::cout << "False";
}
}
