#include <cstdio>
#include <cstring>

using namespace std;

const int AP[7] = { 0, 2, 3, 4, 5, 8, 6 };
const int NEXT_TB[11] = { 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 5 };

int A[7];
int C[11];
int CP[11];
int B;
char buf[20];

int getCPSum() { return CP[1] + CP[2] * 2 + CP[5] * 5 + CP[10] * 10 - B; }
int getASum() { return A[1] + A[2] + A[3] + A[4] + A[5] + A[6]; }

void printA() {
    for (int i = 1; i <= 6; i++) {
        printf("A%d %d %d\n", i, AP[i], A[i]);
    }
}
void printP() {
    printf("1 yuan coin number=%d\n", C[1] + CP[1]);
    printf("2 yuan coin number=%d\n", C[2] + CP[2]);
    printf("5 yuan coin number=%d\n", C[5] + CP[5]);
    printf("10 yuan coin number=%d\n", C[10] + CP[10]);
}

int TB[11], canTB, finalTB[11];
inline int min(const int &a, const int &b) { return a < b ? a : b; }
void printTB() {
    printf("1 yuan coin number=%d\n", finalTB[1]);
    printf("2 yuan coin number=%d\n", finalTB[2]);
    printf("5 yuan coin number=%d\n", finalTB[5]);
    printf("10 yuan coin number=%d\n", finalTB[10]);
}
void dfs(int left, int cur) {
    if (cur == 0) {
        canTB = true;
        memcpy(finalTB, TB, sizeof(TB));
        return;
    }
    if (cur < 1) { return; }
    if (canTB) { return; }
    int curN = C[cur] + CP[cur];
    for (int i = min(curN, left / cur); i >= 0 && !canTB; i--) {
        TB[cur] = i;
        dfs(left - i * cur, NEXT_TB[cur]);
    }
}
void tb() {
    for (int i = getCPSum(); i >= 0; i--) {
        memset(TB, 0, sizeof(TB));
        canTB = false;
        dfs(getCPSum(), 10);
        if (canTB) { break; }
    }
    C[1] = C[1] + CP[1] - finalTB[1];
    C[2] = C[2] + CP[2] - finalTB[2];
    C[5] = C[5] + CP[5] - finalTB[5];
    C[10] = C[10] + CP[10] - finalTB[10];
    memset(CP, 0, sizeof(CP));
    B = 0;
    printTB();
}
bool getS() {
    char ch;
    int p = 0;
    bool hasSpace = false;
    while ((ch = getchar()) == ' ') { hasSpace = true; }
    buf[p++] = ch;
    while ((ch = getchar()) != ';') { buf[p++] = ch; }
    buf[p] = '\0';
    return hasSpace;
}

int main() {
    memset(A, 0, sizeof(A));
    memset(C, 0, sizeof(C));
    char cmd;
    while (scanf("%c", &cmd) == 1) {
        if (cmd == 'r') {
            memset(A, 0, sizeof(A));
            memset(C, 0, sizeof(C));
            scanf(" %d-%d-%d-%d-%d-%d %d-%d-%d-%d;", &A[1], &A[2], &A[3], &A[4], &A[5], &A[6]
                , &C[1], &C[2], &C[5], &C[10]);
            printf("S001:Initialization is successful\n");
        } else if (cmd == 'p') {
            int curP;
            scanf(" %d;", &curP);
            if (curP != 1 && curP != 2 && curP != 5 && curP != 10) {
                printf("E002:Denomination error\n");
            } else if ((curP == 5 || curP == 10) && (curP > C[1] + CP[1] + (C[2] + CP[2]) * 2)) {
                printf("E003:Change is not enough, pay fail\n");
            } else if (getASum() == 0) {
                printf("E005:All the goods sold out\n");
            } else {
                CP[curP]++;
                printf("S002:Pay success,balance=%d\n", getCPSum());
            }
        } else if (cmd == 'b') {
            int curB;
            getS();
            if (strlen(buf) != 2 || buf[0] != 'A' || buf[1] < '1' || buf[1] > '6') {
                printf("E006:Goods does not exist\n");
                continue;
            }
            curB = buf[1] - '0';
            if (A[curB] == 0) {
                printf("E007:The goods sold out\n");
            } else if (getCPSum() < AP[curB]) {
                printf("E008:Lack of balance\n");
            } else {
                B += AP[curB];
                A[curB]--;
                printf("S003:Buy success,balance=%d\n", getCPSum());
            }
        } else if (cmd == 'c') {
            scanf(";");
            if (getCPSum() == 0) {
                printf("E009:Work failure\n");
            } else {
                tb();
            }
        } else if (cmd == 'q') {
            bool hasSpace = getS();
            if (!hasSpace || strlen(buf) != 1 || buf[0] < '0' || buf[0] > '1') {
                printf("E010:Parameter error\n");
            } else if (buf[0] == '0') {
                printA();
            } else {
                printP();
            }
        } else {
            continue;
        }
    }
    return 0;
}
