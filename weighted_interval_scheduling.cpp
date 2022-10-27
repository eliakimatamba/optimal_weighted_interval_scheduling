
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
struct Job
{
    int start;
    int end;
    int weight;
};
bool cmp(Job a, Job b)
{
    return a.end < b.end;
}

vector<int> dp;
vector<Job> jobs;
int n;

void solve()
{
    sort(jobs.begin(), jobs.end(), cmp);
    dp[0] = jobs[0].weight;
    int ans = dp[0];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = jobs[i].weight;
        for (int j = 0; j < i; ++j)
        {
            if (jobs[i].start >= jobs[j].end)
            {
                dp[i] = max(dp[i], dp[j] + jobs[i].weight);
            }
        }
        ans = max(dp[i], ans);
    }
    printf("%d\n", ans);
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &n);
        jobs.resize(n);
        dp.resize(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d %d", &jobs[i].start, &jobs[i].end, &jobs[i].weight);
        }
        solve();
    }
    return 0;
}
