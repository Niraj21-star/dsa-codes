#include <stdio.h>
#include<string.h>
# define max 10
int cost[max][max],n,visited[max];
char cities[max][max];

//dfs function checks the 
void dfs(int v){
	visited[v]=1;
	for(int i=0;i<n;i++){
	if(cost[v][i]!=0 && visited[i]==0)
	dfs(i);
	}
	
}


int main(){
	printf("enter numbeR of cities");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
	
		printf("enter the name of city");
		scanf("%s",cities[i]);
}
	printf("Enter the flight cost details\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		if(i==j)
		{
		cost[i][j]=0;
		continue;
		}
		printf("enter the distance between %s -> %s",cities[i],cities[j]);
		scanf("%d",&cost[i][j]);}
}
	for(int i=0;i<n;i++){
	
		printf("\n");
		for(int j=0;j<n;j++){
			
		printf("%d	 ",cost[i][j]);
}
}
	// checking the connected path
	for(int i=0;i<n;i++)
		 visited[i]=0;
		 dfs(0);{
		 int connected=1;
		 for(int i=0;i<n;i++)
		 {
		 	if(visited[i]==0)
		 	connected=0;
		 	
		 }
		 
		 
		if(connected){
		
		printf("\nThe flight network is connected");
		
		}
		else{
		
		printf("\nThe flight network is not  connected");
	}}
}
