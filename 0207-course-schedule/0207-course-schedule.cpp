class Solution {
private:
    bool solution1Helper(int i, vector<bool> &visited, vector<bool> &inStack, vector<vector<int>> &adjMatrix) {
        if(inStack[i]) return false;
        if(visited[i]) return true;
        inStack[i] = true;
        visited[i] = true;
        for(int ch: adjMatrix[i]) {
            if(solution1Helper(ch, visited, inStack, adjMatrix)) continue;
            return false;
        }
        inStack[i] = false;
        return true;
    }
    bool solution1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMatrix(numCourses);
        for(vector<int> &edge: prerequisites) {
            adjMatrix[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(numCourses), inStack(numCourses);
        for(int i{0};i<numCourses;++i) {
            if(visited[i]) continue;
            if(solution1Helper(i, visited, inStack, adjMatrix)) continue;
            return false;
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return solution1(numCourses, prerequisites);
    }
};