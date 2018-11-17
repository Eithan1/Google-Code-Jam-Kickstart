#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int Triplets(vector<long long int> data)
{
    //有0的情况拿出来单独判断
    int num0 = 0;
    sort(data.begin(), data.end());
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] == 0)
        {
            num0++;
        }
    }

    int num = 0;

    //不存在0的情况
    for (int i = data.size() - 1; i >= num0 + 2; i--) {
        for (int j = i - 1; j >= num0 + 1; j--) {
            for (int k = j - 1; k >= num0; k--) {
                if (data[i] == data[k] * data[j]) {
                    num++;
                }
            }
        }
    }

    return num + num0 * (num0 - 1) * (data.size() - num0) / 2 + num0 * (num0 - 1) * (num0 - 2) / 6;
}

int main()
{
    ifstream input("A-small-practice.in");
    ofstream output("A-practice.txt");

    int casenum;
    input >> casenum;
    //cin >> casenum;
    int n;
    int Result;


//----------------按题目要求实现标准化输入-------------//
    for(int i = 1; i < casenum + 1; i++)
    {
        input >> n;
        //cin >> n;
        vector<long long int> data(n);

        for (int j = 0; j < n; j++)
        {
            input >> data[j];
            //cin >> data[j];
        }

        //开始处理数据。。。。。。。。。。
        Result = Triplets(data);
        output << "case #" << i << ": " << Result << endl;
        //cout << "case #" << i << ": " << Result << endl;
    }
    return 0;
}
