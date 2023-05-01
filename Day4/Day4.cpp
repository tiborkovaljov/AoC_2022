#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    /* PART 1 */

    ifstream file(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day4\day4.in)");
    vector<string> data;
    string line;
    while (getline(file, line)) {
        data.push_back(line);
    }

//    cout << "Data: " << endl;
//    for (string& s : data) {
//        cout << s << endl;
//    }

    int ans = 0;
    int ans2 = 0;

    for (string& elves : data) {
        string one, two;
        size_t position = elves.find(',');
        one = elves.substr(0, position);
        two = elves.substr(position + 1);
        // cout << one << " " << two << endl;
        int a1, b1, a2, b2;
        position = one.find('-');
        a1 = stoi(one.substr(0, position));
        a2 = stoi(one.substr(position + 1));
        position = two.find('-');
        b1 = stoi(two.substr(0, position));
        b2 = stoi(two.substr(position + 1));
        if ((a1 <= b1 && b2 <= a2) || (b1 <= a1 && a2 <= b2)) {
            ans += 1;
        }

        /* PART 2 */

        if(!(a2 < b1 || a1 > b2)) {
            ans2 += 1;
        }

    }

    cout << ans << '\n';
    cout << ans2 << '\n';

    return 0;
}
