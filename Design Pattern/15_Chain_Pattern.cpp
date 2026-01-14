#include <iostream>
using namespace std;

void approveRequest(int days) {
    if (days <= 3) {
        cout << "直属上司批准请假 " << days << " 天" << endl;
    }
    else if (days <= 7) {
        cout << "部门经理批准请假 " << days << " 天" << endl;
    }
    else if (days <= 30) {
        cout << "总经理批准请假 " << days << " 天" << endl;
    }
    else {
        cout << "请假天数太长，无法批准" << endl;
    }
}

int main15() {
    approveRequest(2);
    approveRequest(5);
    approveRequest(15);
    
    return 0;
}
