#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*string func(string S, string T, int N){
    string out = "Yes";
    for(int i = 0; i < N; i++){
        if(S[i] != T[i]){
            if(((S[i] != 1 && T[i] != 'l') && (S[i] != 'l' && T[i] != 1)) && ((S[i] != 0 && T[i] != 'o') && (S[i] != 'o' && T[i] != 0))){
                out = "No";
                return out;
            }
        }
    }
    return out;
}

int main(){
    int N;
    string S;
    string T;
    cin >> N;
    cin >> S;
    cin >> T;
    string out = func(S, T, N);
    cout << out << endl;
}*/



int main(){
    int N;//col
    int M;//row
    cin >> N >> M;
    int arr[M][N];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    unordered_map <int, vector<int>> dict;
    for(int i = 1; i <= N; i++){
        vector <int> neighbors;
        unordered_map <int, bool> visited;
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(arr[j][k] == i){
                    if(k - 1 >= 0){
                        if(!visited[arr[j][k - 1]]){
                            neighbors.push_back(arr[j][k - 1]);
                            visited[arr[j][k - 1]] = true;
                            
                        }
                    }
                    if(k + 1 < N){
                        if(!visited[arr[j][k + 1]]){
                            neighbors.push_back(arr[j][k + 1]);
                            visited[arr[j][k + 1]] = true;
                            
                        }
                    }
                    break;
                }
            }
        }
        dict[i] = neighbors;  
    }
    int counter = 0;
   
    for(int i = 1; i <= N; i++){
        counter = counter + (N - 1) - dict[i].size();
    }
    cout << counter/2 << endl;
    
}