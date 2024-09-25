#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    //today는 전체 날짜, terms는 유효기간, privacies는 수집된 개인정보
    vector<int> answer;
    string comma = "."; //. 변수 선언
    string spacebar = " "; //띄어쓰기를 구분하기 위해 만든 변수
    string today_year, today_month, today_day; //각각 기준 날짜의 연도, 월, 일을 받을 변수

    //오늘 날짜의 연도,월,일 분리
    today_year = today.substr(0, 4); //0번째 인덱스를 포함해서 4의 길이를 자름
    today_month = today.substr(5, 2); //6번째 인덱스를 포함해서 2의 길이를 자름
    today_day = today.substr(8, 2); //9번째 인덱스를 포함해서 2의 길이를 자름

    //terms에서 약관의 종류와 유효기간 정리
    int index_terms = terms.size(); //index_terms는 terms의 벡터 길이
    vector<string> terms_type(index_terms); //기존 벡터 길이만큼 약관 종류를 담을 새로운 벡터 생성
    vector<string> terms_month(index_terms); //기존 벡터 길이만큼 개인정보 보관 기간을 담을 새로운 벡터 생성

    for (int i = 0; i < index_terms; i++) {
        int sb_index = terms[i].find(spacebar, 0); //뛰어쓰기 위치 찾기
        int size = terms[i].size(); //입력받은 문자열의 길이
        terms_type[i] = terms[i].substr(0, sb_index); //약관 종류 입력 받기
        terms_month[i] = terms[i].substr(sb_index + 1);//약관 기간 입력 받기
    }

    //privacies의 원소 정리
    int index_pri = privacies.size(); //privacies의 길이 저장
    //각각 개인정보가 수집되었던 날짜의 연도, 월, 일을 받을 변수
    vector<string> date_y(index_pri);
    vector<string> date_m(index_pri);
    vector<string> date_d(index_pri);
    vector<string> ptype(index_pri); //privacies 에 있는 약관 종류 저장

    for (int j = 0; j < index_pri; j++) {
        int d_size = privacies[j].size(); //privacies에 확인해야하는 약관 종류 개수
        int sb_pindex = privacies[j].find(spacebar, 0); //띄어쓰기 확인용
        ptype[j] = privacies[j].substr(sb_pindex + 1); //약관 종류 저장
        date_y[j] = privacies[j].substr(0, 4);
        date_m[j] = privacies[j].substr(5, 2);
        date_d[j] = privacies[j].substr(8, 2);
    }

    //만료기간 계산
    for (int i = 0; i < index_terms; i++) {
        for (int j = 0; j < index_pri; j++) {
            if (terms_type[i] == ptype[j]) { //약관 종류가 동일한 경우
                //만료 기간 일 계산
                if (date_d[j] == "01") { date_d[j] = "28"; } //약관 날짜가 1인 경우
                else { //그외의 경우
                    int ddate = stoi(date_d[j]);
                    ddate--;
                    date_d[j] = to_string(ddate);
                    if (date_d[j].size() == 1) { date_d[j] = "0" + date_d[j]; }
                }

                //만료 기간 월 계산
                int mdata = (stoi(terms_month[i])) % 12;
                if ((stoi(date_m[j]) + mdata) > 12) { //만약 12를 넘어갈 경우
                    int date = stoi(date_m[j]);
                    date = date + mdata - 12;
                    date_m[j] = to_string(date);
                    if (date_m[j].size() == 1) { date_m[j] = "0" + date_m[j]; }
                    int yydate = stoi(date_y[j]);
                    yydate++;
                    date_y[j] = to_string(yydate);
                }
                else {
                    int date = stoi(date_m[j]);
                    date = date + mdata;
                    date_m[j] = to_string(date);
                    if (date_m[j].size() == 1) { date_m[j] = "0" + date_m[j]; }
                }
                //만료 기간 연도 계산
                int ydata = (stoi(terms_month[i])) / 12;
                int date = stoi(date_y[j]);
                date = date + ydata;
                date_y[j] = to_string(date);
            }
            //cout<<date_y[j]<<date_m[j]<<date_d[j]<<endl;
        }
    }


    //대망의 만료날짜와 드디어얻어어아ㅓ아어어어어 비교
    for (int i = 0; i < index_pri; i++) {
        if (stoi(date_y[i]) < stoi(today_year) ||
            (stoi(date_y[i]) == stoi(today_year) && stoi(date_m[i]) < stoi(today_month)) ||
            (stoi(date_y[i]) == stoi(today_year) && stoi(date_m[i]) == stoi(today_month) && stoi(date_d[i]) < stoi(today_day))) {
            answer.push_back(i + 1);  // 만료된 경우
        }
    }

    return answer;
}