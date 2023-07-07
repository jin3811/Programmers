#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<vector<int>>::iterator commandIter = commands.begin();
    vector<int> copyArray;

    for (; commandIter != commands.end(); ++commandIter) {
        copyArray.assign(array.begin() + commandIter->at(0) - 1, array.begin() + commandIter->at(1));
        sort(copyArray.begin(), copyArray.end());
        answer.push_back(copyArray[commandIter->at(2) - 1]);
    }
    return answer;
}

// second sol
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//     vector<int> answer;
//     vector<int> copyArray;

//     for (const auto& command : commands) {
//         copyArray.assign(array.begin() + command[0] - 1, array.begin() + command[1]);
//         sort(copyArray.begin(), copyArray.end());
//         answer.push_back(copyArray[command[2] - 1]);
//     }
//     return answer;
// }