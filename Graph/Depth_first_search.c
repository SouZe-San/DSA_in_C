// > DEPTH FIRST SEARCH IS FOLLOWING STACK IMPLEMENTATION/ 
#include<stdio.h>

int visited [7] = {0, 0, 0, 0, 0, 0, 0};
// >> Adjacency matrix representation of that graph
int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

// DFS Algorithm -- goes/move randomly to connected any vertex

int dfs(int vertex){
    printf("%d", vertex);
    visited[vertex] = 1; //--> add or marked as visited in visited list
    for(int i=0; i<7; i++){
        if (a[vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}
int main(){
    dfs(4); // order is not unique 
    return 0;
}