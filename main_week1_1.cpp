#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int fsize = friends.size();

    vector<string> give;
    vector<string> receive;

    // give와 receive 분리하기
    for (const auto& gift : gifts) {
        istringstream divide(gift);
        string first, second;
        divide >> first >> second;
        give.push_back(first);
        receive.push_back(second);
    }

    // 선물지수 계산
    vector<int> give_count(fsize, 0);
    vector<int> receive_count(fsize, 0);
    vector<int> Ggift(fsize, 0);

    for (int i = 0; i < gifts.size(); i++) {
        for (int j = 0; j < fsize; j++) {
            if (friends[j] == give[i]) {
                give_count[j]++;
            }
            if (friends[j] == receive[i]) {
                receive_count[j]++;
            }
        }
    }

    for (int i = 0; i < fsize; i++) {
        Ggift[i] = give_count[i] - receive_count[i];
    }

    // 주고받은 선물 체크
    vector<vector<int>> givereceive(fsize, vector<int>(fsize, 0));

    for (int i = 0; i < fsize; i++) {
        for (int j = 0; j < fsize; j++) {
            for (int k = 0; k < gifts.size(); k++) {
                if (give[k] == friends[i] && receive[k] == friends[j]) {
                    givereceive[i][j]++;
                }
            }
        }
    }

    vector<int> next_count(fsize, 0);

    // 양수 값 갯수 카운트, 제일 많은거 반환
    for (int i = 0; i < fsize; i++) {
        for (int j = 0; j < fsize; j++) {
            if (givereceive[i][j] > givereceive[j][i]) {
                next_count[i]++;
            }
            else if (givereceive[i][j] == givereceive[j][i]) {
                if (Ggift[i] > Ggift[j]) {
                    next_count[i]++;
                }
            }
            else
                continue;
        }
    }

    int max = 0;

    for (int i = 0; i < next_count.size(); i++) {
        if (max < next_count[i])
            max = next_count[i];
        else
            continue;
    }

    return max;
}
