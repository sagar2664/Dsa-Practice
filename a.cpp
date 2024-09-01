#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> profits, vector<vector<bool>> skillsForJobs, vector<vector<bool>> skillsOfCandidates) {
    int numJobs = profits.size();
    int numCandidates = skillsOfCandidates.size();
    vector<int> dp(1 << numJobs, 0);

    // Iterate over each candidate
    for (int c = 0; c < numCandidates; ++c) {
        vector<int> new_dp = dp;
        
        // Iterate over each job
        for (int j = 0; j < numJobs; ++j) {
            // Check if this candidate can be assigned to job j
            bool canDoJob = true;
            for (int k = 0; k < skillsForJobs[j].size(); ++k) {
                if (skillsForJobs[j][k] && !skillsOfCandidates[c][k]) {
                    canDoJob = false;
                    break;
                }
            }
            
            if (canDoJob) {
                // Try to assign candidate c to job j
                for (int mask = 0; mask < (1 << numJobs); ++mask) {
                    if (!(mask & (1 << j))) { // if job j is not yet assigned
                        new_dp[mask | (1 << j)] = max(new_dp[mask | (1 << j)], dp[mask] + profits[j]);
                    }
                }
            }
        }
        
        dp = new_dp;
    }
    
    return dp[(1 << numJobs) - 1];
}
