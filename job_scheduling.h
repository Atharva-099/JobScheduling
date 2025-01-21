#ifndef JOB_SCHEDULING_H
#define JOB_SCHEDULING_H

#include <vector>
#include <string>

struct Job {
    std::string id;
    int deadline;
    int profit;
};

std::pair<int, std::vector<Job>> jobScheduling(std::vector<Job> &jobs);

#endif
