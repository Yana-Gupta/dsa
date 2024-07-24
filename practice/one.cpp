class Solution {
public:
    vector<int> segtree;

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            if ( nums.size() == 1 ) {
                segtree[node] = 0;
            } else  {
                if ( l == 0 || l == nums.size() - 1) segtree[node] = 0;
                else {
                    if ( nums[l] > nums[l+1] && nums[l] > nums[l-1] ) {
                        segtree[node] = 1;
                    } else {
                        segtree[node] = 0;
                    }
                }
            }
            return;   
        }

        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return segtree[node];
        int mid = (l + r) >> 1;

        int left =  query(2 * node + 1, l, mid, ql, qr);
        
        int right = query(2 * node + 2, mid + 1, r, ql, qr);

        return left + right;
    }

    void update(int node, int l, int r, int idx, int key, vector<int>& nums) {
        if (l == r) {
            nums[idx] = key;
            if ( nums.size() == 1 ) {
                segtree[node] = 0;
            } else  {
                if ( l == 0 || l == nums.size() - 1) segtree[node] = 0;
                else {
                    if ( nums[l] > nums[l+1] && nums[l] > nums[l-1] ) {
                        segtree[node] = 1;
                    } else {
                        segtree[node] = 0;
                    }
                }
            }
            return;   
        }

        int mid = (l + r) / 2;
        if (idx <= mid) 
            update(2 * node + 1, l, mid, idx, key, nums);
        else 
            update(2 * node + 2, mid + 1, r, idx, key, nums);
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        segtree.resize(4 * n);
        build(0, 0, n - 1, nums);

        vector<int> ans;
        for (auto q : queries) {
            if (q[0] == 1) { 
                if ( q[1] == q[2] ) ans.push_back(0);
                else {
                    int t = query(0, 0, n - 1, q[1], q[2]);
                    t -= query(0, 0, n-1, q[1], q[1]);
                    t -= query(0, 0, n-1, q[2], q[2]);
                    ans.push_back(t);
                }
            } else {
                update(0, 0, n - 1, q[1], q[2], nums);
            }
        }

        return ans;
    }
};