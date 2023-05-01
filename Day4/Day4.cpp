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

    for (string& line : data) {
        string one, two;
        size_t comma_pos = line.find(',');
        one = line.substr(0, comma_pos);
        two = line.substr(comma_pos + 1);
//        cout << one << " " << two << endl;
        int s1, e1, s2, e2;
        comma_pos = one.find('-');
        s1 = stoi(one.substr(0, comma_pos));
        e1 = stoi(one.substr(comma_pos + 1));
        comma_pos = two.find('-');
        s2 = stoi(two.substr(0, comma_pos));
        e2 = stoi(two.substr(comma_pos + 1));
        if ((s1 <= s2 && e2 <= e1) || (s2 <= s1 && e1 <= e2)) {
            ans += 1;
        }

        /* PART 2 */

        if(!(e1 < s2 || s1 > e2)) {
            ans2 += 1;
        }

    }

    cout << ans << '\n';
    cout << ans2 << '\n';

    return 0;
}
