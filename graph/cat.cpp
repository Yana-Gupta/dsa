#include <bits/stdc++.h>

using namespace std;

int dp[1000][64][64][2];

bool dfs(int depth, vector<string> &grid, int pci, int pcj, int pmi, int pmj, int cj, int mj, int turn)
{
    if (pci == pmi && pcj == pmj)
        return false;

    if ( grid[pmi][pmj] == 'F' ) return true;

    cout << pci << pcj << pmi << pmj << endl;

    if (depth >= 1000)
        return false;

    int grid_width = grid[0].size();
    int grid_height = grid.size();
    int mouse_index = (pmi * grid_width) + pmj;
    int cat_index = (pci * grid_width) + pcj;

    if (dp[depth][cat_index][mouse_index][turn] != -1)
        return dp[depth][cat_index][mouse_index][turn];

    bool getwinner;

    if (turn == 0)
    { // Mouse's turn
        getwinner = false;

        for (int j = 1; j <= mj; j++)
        {
            int new_j = pcj + j;
            if (new_j >= grid_width || grid[pmi][new_j] == '#')
                break;
        
            if (grid[pmi][new_j] == 'F')
                return dp[depth][cat_index][mouse_index][turn] = true;
        
            if (dfs(depth, grid, pci, pcj, pmi, new_j, cj, mj, 1))
                return dp[depth][cat_index][mouse_index][turn] = true;
        }
        for (int j = -1; j >= -mj; j--)
        {
            int new_j = pcj + j;
            if (new_j < 0 || grid[pmi][new_j] == '#')
                break;
            if (grid[pmi][new_j] == 'F')
                return dp[depth][cat_index][mouse_index][turn] = true;
            if (dfs(depth, grid, pci, pcj, pmi, new_j, cj, mj, 1))
                return dp[depth][cat_index][mouse_index][turn] = true;
        }
        for (int i = 1; i <= mj; i++)
        {
            int new_i = pmi + i;
            if (new_i >= grid_height || grid[new_i][pcj] == '#')
                break;
            if (grid[new_i][pcj] == 'F')
                return dp[depth][cat_index][mouse_index][turn] = true;
            if (dfs(depth, grid, pci, pcj, new_i, pcj, cj, mj, 1))
                return dp[depth][cat_index][mouse_index][turn] = true;
        }
        for (int i = -1; i >= -mj; i--)
        {
            int new_i = pmi + i;
            if (new_i < 0 || grid[new_i][pcj] == '#')
                break;
            if (grid[new_i][pcj] == 'F')
                return dp[depth][cat_index][mouse_index][turn] = true;
            if (dfs(depth, grid, pci, pcj, new_i, pcj, cj, mj, 1))
                return dp[depth][cat_index][mouse_index][turn] = true;
        }
    }
    else
    { // Cat's turn
        getwinner = true;
        for (int j = 1; j <= cj; j++)
        {
            int new_j = pcj + j;
            if (new_j >= grid_width || grid[pci][new_j] == '#')
                break;
            if (grid[pci][new_j] == 'F' || (pci == pmi && new_j == pmj))
                return dp[depth][cat_index][mouse_index][turn] = false;
            if (!dfs(depth + 1, grid, pci, new_j, pmi, pmj, cj, mj, 0))
                return dp[depth][cat_index][mouse_index][turn] = false;
        }
        for (int j = -1; j >= -cj; j--)
        {
            int new_j = pcj + j;
            if (new_j < 0 || grid[pci][new_j] == '#')
                break;
            if (grid[pci][new_j] == 'F' || (pci == pmi && new_j == pmj))
                return dp[depth][cat_index][mouse_index][turn] = false;
            if (!dfs(depth + 1, grid, pci, new_j, pmi, pmj, cj, mj, 0))
                return dp[depth][cat_index][mouse_index][turn] = false;
        }
        for (int i = 1; i <= cj; i++)
        {
            int new_i = pci + i;
            if (new_i >= grid_height || grid[new_i][pcj] == '#')
                break;
            if (grid[new_i][pcj] == 'F' || (new_i == pmi && pcj == pmj))
                return dp[depth][cat_index][mouse_index][turn] = false;
            if (!dfs(depth + 1, grid, new_i, pcj, pmi, pmj, cj, mj, 0))
                return dp[depth][cat_index][mouse_index][turn] = false;
        }
        for (int i = -1; i >= -cj; i--)
        {
            int new_i = pci + i;
            if (new_i < 0 || grid[new_i][pcj] == '#')
                break;
            if (grid[new_i][pcj] == 'F' || (new_i == pmi && pcj == pmj))
                return dp[depth][cat_index][mouse_index][turn] = false;
            if (!dfs(depth + 1, grid, new_i, pcj, pmi, pmj, cj, mj, 0))
                return dp[depth][cat_index][mouse_index][turn] = false;
        }
    }

    return dp[depth][cat_index][mouse_index][turn] = getwinner;
}

bool canMouseWin(vector<string> &grid, int catJump, int mouseJump)
{
    memset(dp, -1, sizeof(dp)); // Initialize DP table
    int ci, cj, mi, mj;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 'C')
            {
                ci = i;
                cj = j;
            }
            if (grid[i][j] == 'M')
            {
                mi = i;
                mj = j;
            }
        }
    }

    return dfs(0, grid, ci, cj, mi, mj, catJump, mouseJump, 0);
}

int main()
{
    vector<string> graph = {"####F", "#C...", "M...."};

    cout << canMouseWin(graph, 1, 2) << endl;
}