#include <bits/stdc++.h>
using namespace std;

static int count_greedy_pairs(const vector<int> &left_positions, const vector<int> &right_positions)
{
  int i = 0, j = 0, formed = 0;
  const int nL = (int)left_positions.size();
  const int nR = (int)right_positions.size();
  while (i < nL && j < nR)
  {
    if (left_positions[i] < right_positions[j])
    {
      ++formed;
      ++i;
      ++j;
    }
    else
    {
      ++j;
    }
  }
  return formed;
}

static long long compute_answer(const vector<long long> &values)
{
  const int n = (int)values.size();
  unordered_map<long long, vector<int>> positions_by_value;
  positions_by_value.reserve(n * 2);
  for (int i = 0; i < n; ++i)
    positions_by_value[values[i]].push_back(i);

  vector<long long> sorted_values;
  sorted_values.reserve(positions_by_value.size());
  for (const auto &kv : positions_by_value)
    sorted_values.push_back(kv.first);
  sort(sorted_values.begin(), sorted_values.end());

  const int m = (int)sorted_values.size();
  vector<int> frequency(m);
  for (int i = 0; i < m; ++i)
    frequency[i] = (int)positions_by_value[sorted_values[i]].size();

  vector<int> pairable_between_neighbors(max(0, m - 1), 0);
  for (int i = 0; i + 1 < m; ++i)
  {
    if (sorted_values[i + 1] == sorted_values[i] + 1)
    {
      const auto &A = positions_by_value[sorted_values[i]];
      const auto &B = positions_by_value[sorted_values[i + 1]];
      pairable_between_neighbors[i] = count_greedy_pairs(A, B);
    }
  }

  long long answer = 0;
  int used_from_previous = 0;
  for (int i = 0; i + 1 < m; ++i)
  {
    if (sorted_values[i + 1] != sorted_values[i] + 1)
    {
      used_from_previous = 0;
      continue;
    }
    int available_left = frequency[i] - used_from_previous;
    if (available_left < 0)
      available_left = 0;
    int choose_here = min({pairable_between_neighbors[i], available_left, frequency[i + 1]});
    answer += choose_here;
    used_from_previous = choose_here;
  }

  return answer;
}

int main()
{
  int test_cases;
  if (!(cin >> test_cases))
    return 0;
  while (test_cases--)
  {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    cout << compute_answer(arr) << '\n';
  }
  return 0;
}
