#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1; //아무런 돗자리를 못 깔때

    // 동적 계획법 사용
    int row = park.size(); //park의 행 개수
    int col = park[0].size(); //park의 열 개수

    vector<vector<int>> dp_mat(row, vector<int>(col, 0)); //park랑 크기가 같은 테이블
    int max_size = 0; //정사각형의 최대 크기

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) { dp_mat[i][j] = 1; }
                else {
                    dp_mat[i][j] = min({ dp_mat[i - 1][j],dp_mat[i][j - 1],dp_mat[i - 1][j - 1] }) + 1;
                    //각각 서쪽, 북쪽, 북서쪽. 3개의 값중 가장 작은 거만 더하기.
                }
                max_size = max(max_size, dp_mat[i][j]); //가장 큰 정사각형 크기 비교 후 저장
            }
        }
    }

    //갖고 있는 돗자리 크기 비교
    int mat_size = mats.size(); //돗자리 개수
    sort(mats.rbegin(), mats.rend()); //내림차순으로 정렬, rbegin(),rend()는 역순 반복자, vector에서만 사용가능

    for (int i = 0; i < mat_size; i++) {
        if ((answer == -1) && (mats[i] <= max_size)) { answer = mats[i]; }
        //answer이 여전히 0이고 최대 크기 찾을 때 조건문 실행
        //내림차순 정렬이므로 최대 크기를 찾으면 answer의 값이 바뀌기 때문에 추가적으로 답이 더이상 안 바뀜
    }

    return answer;
}