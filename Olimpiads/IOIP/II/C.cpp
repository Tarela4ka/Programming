#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const int MAX_LOG = 20;
const long long P = 911382629;
const long long MOD = 1e18 + 3;

vector<long long> p_pows;

void init_p_pows(int max_len) {
    p_pows.resize(max_len + 1);
    p_pows[0] = 1;
    for (int i = 1; i <= max_len; ++i) {
        p_pows[i] = (p_pows[i-1] * P) % MOD;
    }
}

struct Node {
    char c;
    int parent;
    vector<int> children;
    vector<int> up;
    vector<long long> hash;
};

vector<Node> nodes;
unordered_map<char, vector<int>> char_map;

void build_binary_lifting(int n) {
    for (int u = 1; u <= n; ++u) {
        nodes[u].up.resize(MAX_LOG);
        nodes[u].hash.resize(MAX_LOG);
        nodes[u].up[0] = nodes[u].children.empty() ? -1 : nodes[u].children[0];
        nodes[u].hash[0] = nodes[u].children.empty() ? 0 : (nodes[nodes[u].children[0]].c * p_pows[0]) % MOD;
    }

    for (int j = 1; j < MAX_LOG; ++j) {
        for (int u = 1; u <= n; ++u) {
            if (nodes[u].up[j-1] != -1) {
                nodes[u].up[j] = nodes[nodes[u].up[j-1]].up[j-1];
                nodes[u].hash[j] = (nodes[u].hash[j-1] * p_pows[1 << (j-1)] + nodes[nodes[u].up[j-1]].hash[j-1]) % MOD;
            } else {
                nodes[u].up[j] = -1;
                nodes[u].hash[j] = 0;
            }
        }
    }
}

long long compute_hash(const string &s) {
    long long h = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        h = (h * P + s[i]) % MOD;
    }
    return h;
}

int count_occurrences(const string &s, long long target_hash) {
    int k = s.size();
    if (k == 0) return 0;
    int count = 0;

    if (char_map.find(s[0]) == char_map.end()) return 0;

    for (int u : char_map.at(s[0])) {
        int current = u;
        long long current_hash = 0;
        int remaining = k;
        int len = 0;

        for (int j = MAX_LOG - 1; j >= 0; --j) {
            if (remaining >= (1 << j) && nodes[current].up[j] != -1) {
                current_hash = (current_hash * p_pows[1 << j] + nodes[current].hash[j]) % MOD;
                current = nodes[current].up[j];
                remaining -= (1 << j);
                len += (1 << j);
            }
        }

        if (len == k-1 && remaining == 1) {
            current_hash = (current_hash * P + nodes[current].c) % MOD;
            if (current_hash == target_hash) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    nodes.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        nodes[p].children.push_back(i);
        nodes[i].parent = p;
    }

    string a;
    cin >> a;
    for (int i = 1; i <= n; ++i) {
        nodes[i].c = a[i-1];
        char_map[nodes[i].c].push_back(i);
    }

    int max_len = n;
    init_p_pows(max_len);

    build_binary_lifting(n);

    while (m--) {
        string s;
        cin >> s;
        long long h = compute_hash(s);
        cout << count_occurrences(s, h) << '\n';
    }

    return 0;
}