// #include "job_scheduling.h"
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

// Topological sort for job dependencies
void topologicalSort(std::vector<Job> &jobs, std::unordered_map<std::string, std::vector<Job>> &dependencyGraph, std::vector<Job> &sortedJobs) {
    std::unordered_map<std::string, int> inDegree;
    
    // Calculate in-degree for each job (number of dependencies)
    for (auto &job : jobs) {
        inDegree[job.id] = 0;  // Initialize in-degree for each job
    }
    for (auto &entry : dependencyGraph) {
        for (auto &depJob : entry.second) {
            inDegree[depJob.id]++;
        }
    }

    // Use a queue to store jobs with zero in-degree (no dependencies)
    std::queue<Job> zeroInDegreeQueue;
    for (auto &job : jobs) {
        if (inDegree[job.id] == 0) {
            zeroInDegreeQueue.push(job);
        }
    }

    // Perform topological sort (Kahn's algorithm)
    while (!zeroInDegreeQueue.empty()) {
        Job currentJob = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        sortedJobs.push_back(currentJob);

        for (auto &depJob : dependencyGraph[currentJob.id]) {
            inDegree[depJob.id]--;
            if (inDegree[depJob.id] == 0) {
                zeroInDegreeQueue.push(depJob);
            }
        }
    }
}

std::pair<int, std::vector<Job>> jobScheduling(std::vector<Job> &jobs) {
    // Build the dependency graph
    std::unordered_map<std::string, std::vector<Job>> dependencyGraph;
    
    // Example of adding dependencies manually (replace this with your own logic)
    // job2 depends on job1, job3 depends on job2
    dependencyGraph["Job1"] = {};  // Job1 has no dependencies
    dependencyGraph["Job2"] = {jobs[0]};  // Job2 depends on Job1
    dependencyGraph["Job3"] = {jobs[1]};  // Job3 depends on Job2
    
    // Perform topological sort to respect dependencies
    std::vector<Job> sortedJobs;
    topologicalSort(jobs, dependencyGraph, sortedJobs);

    // Sort jobs by profit in descending order
    std::sort(sortedJobs.begin(), sortedJobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxProfit = 0;
    std::vector<Job> scheduledJobs;
    std::vector<bool> timeSlots(jobs.size(), false);

    // Schedule jobs while respecting the dependencies and deadlines
    for (auto &job : sortedJobs) {
        for (int t = std::min((int)jobs.size(), job.deadline) - 1; t >= 0; --t) {
            if (!timeSlots[t]) {
                timeSlots[t] = true;
                maxProfit += job.profit;
                scheduledJobs.push_back(job);
                break;
            }
        }
    }

    return {maxProfit, scheduledJobs};
}
