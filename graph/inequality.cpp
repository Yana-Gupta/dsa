#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

bool checkStatements(vector<tuple<string, string, string>> statements)
{
    UnionFind uf;
    vector<pair<string, string>> inequalities;

    for (auto &statement : statements) {
        string x, op, y;
        tie(x, op, y) = statement;

        if (op == "==") {
            uf.unionSets(x, y);
        }
        else if (op == "!=") {
            inequalities.push_back(make_pair(x, y));
        }
    }

    for (auto &ineq : inequalities) {
        string x = ineq.first;
        string y = ineq.second;
        if (uf.find(x) == uf.find(y)) {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<tuple<string, string, string>> statements = {
        make_tuple("a", "==", "b"),
        make_tuple("b", "==", "c"),
        make_tuple("c", "==", "a"),
        make_tuple("a", "==", "c"),
        make_tuple("a", "==", "c"),
        make_tuple("c", "==", "f"),
        make_tuple("f", "!=", "g"),
        make_tuple("s", "==", "r"),
        make_tuple("f", "==", "h"),
        make_tuple("f", "!=", "r"),
        make_tuple("r", "==", "g"),
    };

    if (checkStatements(statements)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
