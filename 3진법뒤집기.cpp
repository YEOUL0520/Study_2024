#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string num;

    while (n >= 3) {
        num.push_back((n % 3) + '0'); //아스키코드로 '0'은 48
        n = n / 3;
    }
    num.push_back(n + '0');
    answer = stoi(num, 0, 3); //stoi(변환할 정수형,인덱스위치,n진법 해석)

    return answer;
}