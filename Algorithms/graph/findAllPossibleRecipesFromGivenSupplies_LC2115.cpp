/*
2115. Find All Possible Recipes from Given Supplies
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& igr, vector<string>& sup) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> inDegree;
        queue<string> q;

        for(int i = 0; i < r.size(); i++){
            string recipe = r[i];
            inDegree[recipe] = igr[i].size();
            for(string ing : igr[i]){
                graph[ing].push_back(recipe);
            }
        }
        
        for(auto ele : sup){
            q.push(ele);
        }


        vector<string> ans;

        while(!q.empty()){
            string current = q.front();
            q.pop();

            for(auto ele : graph[current]){
                inDegree[ele]--;
                if(inDegree[ele] == 0){
                    ans.push_back(ele);
                    q.push(ele);
                }
            }
        }
        return ans;
    }
};

int main(){
	
}
