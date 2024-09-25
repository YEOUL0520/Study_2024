#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>  // sort

using namespace std;

int solution(vector<int> d, int budget) {
    int n = 0;

    // ������������ ����
    sort(d.begin(), d.end());

    // ���� ������� �μ� ����
    for (int i = 0; i < d.size(); i++)
    {
        if (budget < d[i])
            break;

        budget -= d[i];
        n++;  // ������ �μ� �� ++
    }

    return n;
}