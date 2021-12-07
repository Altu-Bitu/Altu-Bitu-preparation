#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> indegree;
unordered_map<string, vector<string>> graph;
set<string> node;

/**
 * 단순 위상정렬 문제, 문자열이여서 새로운듯!
 * 맵을 써야해서 좋다
 * 출력 순서가 조금 까다롭다
 * 시간 관리 까다로움..
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; //n: 알고있는 선후관계수
    string a, b;

    //입력
    cin >> n;
    while (n--) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
        node.insert(a);
        node.insert(b);
    }
    vector<string> result;
    priority_queue<string, vector<string>, greater<>> q, q2;
    set<string>::iterator iter;
    for (iter = node.begin(); iter != node.end(); iter++) {
        if (indegree.find(*iter) == indegree.end()) {
            result.push_back(*iter);
            string cur = *iter;
            for (int i = 0; i < graph[cur].size(); i++) {
                indegree[graph[cur][i]]--;
                if (indegree[graph[cur][i]] == 0)
                    q.push(graph[cur][i]);
            }
        }
    }
    while (!q.empty()) {
        string cur = q.top();
        q.pop();

        result.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            indegree[graph[cur][i]]--;
            if (indegree[graph[cur][i]] == 0)
                q2.push(graph[cur][i]);
        }
        if (q.empty() && !q2.empty()) {
            swap(q, q2);
        }
    }
    if (result.size() != node.size()) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}