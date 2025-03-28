#include<vector>
using namespace std;

int cal_1(vector<vector<int>> maps) //우선순위 : 아래->오른쪽->위->왼쪽
{
    int n = maps.size(); //세로
    int m = maps[0].size(); //가로
    int x = 0;
    int y = 0;
    int answer = 1;
    while (true) {
        if ((x == n - 1) && (y == m - 1)) {
            break;
        }
        else {
            if ((maps[x + 1][y] == 1) && (x + 1 < n)) { //아래
                maps[x][y] = 0;
                x++;
                answer++;
            }
            else if ((maps[x][y + 1] == 1) && (y + 1 < m)) { //오른쪽
                maps[x][y] = 0;
                y++;
                answer++;
            }
            else if ((maps[x - 1][y] == 1) && (x - 1 >= 0)) { //위로
                maps[x][y] = 0;
                x--;
                answer++;
            }
            else if ((maps[x][y - 1] == 1) && (y - 1 >= 0)) { //왼쪽으로
                maps[x][y] = 0;
                y--;
                answer++;
            }
            else
                return -1;
        }
    }
    return answer;
}

int cal_2(vector<vector<int>> maps) //우선순위 : 아래->오른쪽->왼쪽->위
{
    int n = maps.size(); //세로
    int m = maps[0].size(); //가로
    int x = 0;
    int y = 0;
    int answer = 1;
    while (true) {
        if ((x == n - 1) && (y == m - 1)) {
            break;
        }
        else {
            if ((maps[x + 1][y] == 1) && (x + 1 < n)) { //아래
                maps[x][y] = 0;
                x++;
                answer++;
            }
            else if ((maps[x][y + 1] == 1) && (y + 1 < m)) { //오른쪽
                maps[x][y] = 0;
                y++;
                answer++;
            }
            else if ((maps[x][y - 1] == 1) && (y - 1 >= 0)) { //왼쪽으로
                maps[x][y] = 0;
                y--;
                answer++;
            }
            else if ((maps[x - 1][y] == 1) && (x - 1 >= 0)) { //위로
                maps[x][y] = 0;
                x--;
                answer++;
            }
            else
                return -1;
        }
    }
    return answer;
}

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    int n = maps.size(); //세로
    int m = maps[0].size(); //가로
    int result[5];

    result[0] = cal_1(maps);
    result[1] = cal_2(maps);
    //result[2] = cal_3(maps);
    //result[3] = cal_4(maps);

    if (result[0] > result[1])
        answer = result[1];
    else
        answer = result[0];

    return answer;
}