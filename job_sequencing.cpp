#include<iostream>
#include<vector>
#include<algorithm>

struct Job{
    char id;
    int deadline;
    int profit;
};

bool compareJobs(Job a, Job b){
    return a.profit > b.profit;
}

void JobSequencing(std::vector<Job>& jobs){
    std::sort(jobs.begin(), jobs.end(), compareJobs);
    int n = jobs.size();

    int maxDeadline = 0;
    for(const auto& job : jobs){
            if(job.deadline > maxDeadline)
                maxDeadline = job.deadline;
    }

    std::vector<char> timeline(maxDeadline + 1, '0');
    int totalProfit = 0;
    std::cout << "Scheduled Jobs: ";

    for(int i = 0; i < n; i++){
        for(int j = std::min(maxDeadline, jobs[i].deadline); j > 0; j--){
            if(timeline[j] == '0'){
                timeline[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                std::cout << jobs[i].id << " ";
                break;
            }
        }
    }
    std::cout << "\nTotal Profit: " << totalProfit << "\n";
}

int main(){
    std::vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    JobSequencing(jobs);
    return 0;
}