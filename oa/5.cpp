#include<bits/stdc++.h>
#include<vector>


using namespace std;

int main () {
    int n;
    int m;

    cout << "Server" <<endl;

    cin >> n;

    cout << "Request" << endl;
    cin >> m;

    vector<int> v(m);
    for ( auto i = 0; i < m; i++ ) cin >> v[i];

    int totaltime = 0;


    vector<int> services(m, 0);

    for ( auto c: v ) {
        int j = 0;

        if ( services[j] == 0 ) {
            if ( !totaltime ) totaltime++;
        } else {

            int minele = *min_element(services.begin(), services.end());

            totaltime = max(minele + 2, totaltime);

        }
        services[j]++;
    } 

    cout << totaltime << endl;

}