#pragma once  

#include <string>
#include <vector>

using namespace std;

const int MAX_PROCESSES = 100;
const int NOT_STARTED = -1; // firstRunTime của tiến trình chưa chạy CPU lần nào

// Thông tin của một tiến trình
struct Process {
    // Dữ liệu đầu vào ( Người 1 ) 
    string id;         
    int arrivalTime;        // AT
    int burstTime;          // BT

    // Dữ liệu trong lúc mô phỏng ( Người 2 ) 
    int remainingTime;      // ban đầu bằng burstTime
    int firstRunTime;       // ban đầu là NOT_STARTED

    // Kết quả ( Người 3 ) 
    int completionTime;     // CT   
    int turnaroundTime;     // TAT = CT - AT
    int waitingTime;        // WT = TAT - BT
    int responseTime;       // RT = firstRunTime - AT
};

// Các hàm nhập dữ liệu 
int inputNumberOfProcesses();
Process inputProcess(int index, const vector<Process>& existingProcesses);
vector<Process> inputProcessList();

// Các hàm tiện ích cho nhóm 

Process createProcess(const string& id, int arrivalTime, int burstTime); // tạo không cần bàn phím, dùng khi kiểm thử
void resetProcesses(vector<Process>& processes); // xóa kết quả cũ, giữ id/AT/BT, dùng trước mỗi lần mô phỏng
void sortByArrivalTime(vector<Process>& processes);
void printProcessList(const vector<Process>& processes);