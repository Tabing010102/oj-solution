#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "443", // ˫�������滻Ϊ A ��Ĵ�
        "LLLV", // ˫�������滻Ϊ B ��Ĵ�
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
