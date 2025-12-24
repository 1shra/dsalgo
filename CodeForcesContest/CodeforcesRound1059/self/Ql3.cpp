public:
string lexGreaterPermutation(string s, string target)
{
  int n = (int)s.size();
  vector<int> arr(26, 0);
  for (char ch : s)
    arr[ch - 'a']++;
  string ans(n, '?');
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int t = target[i] - 'a';
    if (arr[t] > 0)
    {
      ans[i] = target[i];
      arr[t]--;
      v.push_back(i);
    }
    else
    {
      int ch = -1;
      for (int c = t + 1; c < 26; c++)
        if (arr[c] > 0)
        {
          ch = c;
          break;
        }
      if (ch != -1)
      {
        ans[i] = char('a' + ch);
        arr[ch]--;
        int pos = i + 1;
        for (int c = 0; c < 26; c++)
          while (arr[c]--)
            ans[pos++] = char('a' + c);
        return ans;
      }
      else
      {
        while (!v.empty())
        {
          int p = v.back();
          v.pop_back();
          int tp = target[p] - 'a';
          arr[tp]++;
          int ch2 = -1;
          for (int c = tp + 1; c < 26; c++)
            if (arr[c] > 0)
            {
              ch2 = c;
              break;
            }
          if (ch2 != -1)
          {
            ans[p] = char('a' + ch2);
            arr[ch2]--;
            int pos = p + 1;
            for (int c = 0; c < 26; c++)
              while (arr[c]--)
                ans[pos++] = char('a' + c);
            return ans;
          }
        }
        return "";
      }
    }
  }
  while (!v.empty())
  {
    int p = v.back();
    v.pop_back();
    int tp = target[p] - 'a';
    arr[tp]++;
    int ch = -1;
    for (int c = tp + 1; c < 26; c++)
      if (arr[c] > 0)
      {
        ch = c;
        break;
      }
    if (ch != -1)
    {
      ans[p] = char('a' + ch);
      arr[ch]--;
      int pos = p + 1;
      for (int c = 0; c < 26; c++)
        while (arr[c]--)
          ans[pos++] = char('a' + c);
      return ans;
    }
  }
  return "";
}
}
;
