#include "Round2Mock.h"

#include <vector>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>

void Round2Mock::Solution1()
{

    int N, k;
    std::cin >> N >> k;

    std::vector<int> numbers;
    std::string input;
    std::getline(std::cin, input); // consume the newline character after reading N and k

    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;

    while (iss >> num)
    {
        numbers.push_back(num);
    }

    // Rest of your code...
    std::vector<int> sumOfThree;

    for (int i = 0; i <= N - 2; i++)
    {
        int sum = numbers[i] + numbers[i + 1] + numbers[i + 2];
        sumOfThree.push_back(sum);
        i = i + 2;
    }

    int count = 0;

    for (int i = 0; i < sumOfThree.size(); i++)
    {
        if (sumOfThree[i] != k)
        {
            count++;
        }
    }

    std::cout << count;
}

void Round2Mock::Solution2()
{

    int N, k;
    std::cin >> N >> k;

    std::vector<int> numbers;
    std::string input;
    std::getline(std::cin, input); // consume the newline character after reading N and k

    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;

    while (iss >> num)
    {
        numbers.push_back(num);
    }

    int sum = 0;

    for (int i = 1; i <= N; i++)
    {

        for (int j = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == i)
            {
            }
        }
    }

    std::cout << sum;
}

void Round2Mock::Solution3()
{

    int N;
    std::cin >> N;

    std::vector<int> difficulties;
    std::string input;
    std::getline(std::cin, input); // consume the newline character after reading N

    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;

    while (iss >> num)
    {
        difficulties.push_back(num);
    }

    // Sort the array in ascending order
    std::sort(difficulties.begin(), difficulties.end(), [](int a, int b)
              { return a > b; });

    // Iterate over the sorted array
    for (int i = 0; i < difficulties.size() - 2; i++)
    {
        // Check if the current problem, the next problem, and the problem after the next one all have different difficulty levels
        if (difficulties[i] < difficulties[i + 1] && difficulties[i + 1] < difficulties[i + 2])
        {
            // If such a set is found, return true
            std::cout << true;
        }
    }

    // If no such set is found, return false
    std::cout << false;
}

void Round2Mock::Solution4()
{
    int N, K;
    std::cin >> N >> K;
    std::cin.ignore(); // ignore the newline character after reading K

    std::vector<int> sequence(N);
    std::vector<int> index(N + 1);
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;
    for (int i = 0; i < N; i++)
    {
        iss >> num;
        sequence[i] = num;
        index[num] = i;
    }

    int maxSeq = 1;
    int currSeq = 1;
    for (int i = 2; i <= N; i++)
    {
        if (index[i] > index[i - 1])
        {
            currSeq++;
        }
        else
        {
            currSeq = 1;
        }
        maxSeq = std::max(maxSeq, currSeq);
    }

    int minNumberOfTimes = std::ceil((double)(N - maxSeq) / K);
    std::cout << minNumberOfTimes;
}

void Round2Mock::Solution5()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        long long N, M;
        std::cin >> N >> M;
        if (N + M < 12)
        {
            std::cout << 0 << std::endl;
        }
        else if (N < 5)
        {
            std::cout << 0 << std::endl;
        }
        else
        {
            std::cout << N / 5 << std::endl;
        }
    }
}

void Round2Mock::Solution6()
{
    const int MOD = 1e9 + 7;
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - i]) % MOD;
            }
        }
    }

    std::cout << dp[N][K] << std::endl;
}

const int INF = 1e9;

struct Edge
{
    int to, cost;
};

std::vector<Edge> adj[10001];
int dist[10001];

void dijkstra(int start)
{
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost)
            continue;
        for (Edge &e : adj[here])
        {
            int nextCost = cost + e.cost;
            if (dist[e.to] > nextCost)
            {
                dist[e.to] = nextCost;
                pq.push({-nextCost, e.to});
            }
        }
    }
}

void Round2Mock::Solution7()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int minCost = INF;
    int minAgency = -1;
    for (int i = 0; i < N; ++i)
    {
        std::fill(dist, dist + N, INF);
        dijkstra(i);
        int totalCost = 0;
        for (int j = 0; j < N; ++j)
        {
            if (i != j)
                totalCost += dist[j];
        }
        if (totalCost < minCost)
        {
            minCost = totalCost;
            minAgency = i;
        }
    }
    std::cout << minCost << std::endl;
}