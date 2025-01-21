// #include <iostream>
// #include "job_scheduling.h"
// #include "utils.h"

// int main() {
//     int numJobs;
//     std::cout << "Enter the number of jobs: ";
//     std::cin >> numJobs;

//     std::vector<Job> jobs(numJobs);

    
//     for (int i = 0; i < numJobs; ++i) {
//         std::cout << "Enter job " << i + 1 << " details:\n";
//         std::cout << "ID: ";
//         std::cin >> jobs[i].id;
//         std::cout << "Deadline: ";
//         std::cin >> jobs[i].deadline;
//         std::cout << "Profit: ";
//         std::cin >> jobs[i].profit;
//     }


//     auto result = jobScheduling(jobs);
//     int maxProfit = result.first;
//     auto scheduledJobs = result.second;

    
//     std::cout << "Maximum Profit: " << maxProfit << "\n";
//     std::cout << "Scheduled Jobs: ";
//     for (const auto &job : scheduledJobs) {
//         std::cout << job.id << " ";
//     }
//     std::cout << "\n";

    
//     std::cout << "Gantt Chart:\n";
//     for (int i = 0; i < scheduledJobs.size(); ++i) {
//         std::cout << "| " << scheduledJobs[i].id << " ";
//     }
//     std::cout << "|\n";

//     return 0;
// }

#include <iostream>
#include "job_scheduling.h"
#include "utils.h"

int main() {
    int numJobs;
    std::cout << "Enter the number of jobs: ";
    std::cin >> numJobs;

    std::vector<Job> jobs(numJobs);

    // Taking input for job details
    for (int i = 0; i < numJobs; ++i) {
        std::cout << "Enter job " << i + 1 << " details:\n";
        std::cout << "ID: ";
        std::cin >> jobs[i].id;
        std::cout << "Deadline: ";
        std::cin >> jobs[i].deadline;
        std::cout << "Profit: ";
        std::cin >> jobs[i].profit;
    }

    // Calling the jobScheduling function
    auto result = jobScheduling(jobs);
    int maxProfit = result.first;
    auto scheduledJobs = result.second;

    // Output the maximum profit and scheduled jobs
    std::cout << "Maximum Profit: " << maxProfit << "\n";
    std::cout << "Scheduled Jobs: ";
    for (const auto &job : scheduledJobs) {
        std::cout << job.id << " ";
    }
    std::cout << "\n";

    // Displaying the Gantt chart
    std::cout << "Gantt Chart:\n";
    for (int i = 0; i < scheduledJobs.size(); ++i) {
        std::cout << "| " << scheduledJobs[i].id << " ";
    }
    std::cout << "|\n";

    return 0;
}
