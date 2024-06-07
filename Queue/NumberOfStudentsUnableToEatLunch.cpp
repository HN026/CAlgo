#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        deque<int> studentDeque;
        deque<int> sandwichDeque;

        for (auto student : students)
            studentDeque.push_back(student);
        for (auto sandwich : sandwiches)
            sandwichDeque.push_back(sandwich);

        int count = 0;
        while (!studentDeque.empty() && count < studentDeque.size()) {
            if (studentDeque.front() == sandwichDeque.front()) {
                studentDeque.pop_front();
                sandwichDeque.pop_front();
                count = 0;
            } else {
                studentDeque.push_back(studentDeque.front());
                studentDeque.pop_front();
                count++;
            }
        }

        return studentDeque.size();
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    Solution sol = Solution();
    cout << sol.countStudents(students, sandwiches) << endl;
    return 0;
}