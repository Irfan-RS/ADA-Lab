
#include<stdio.h>
int a[10][10],n,t[10],indegree[10];
int stack[10],top=-1;
void computeIndegree(int,int [][10]);
void tps_SourceRemoval(int,int [][10]);
int main(){
printf("Enter the no. of nodes: ");
scanf("%d",&n);
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
computeIndegree(n,a);
tps_SourceRemoval(n,a);
printf("Solution:");
for(i=0;i<n;i++){
printf("%d ",t[i]);
}
return 0;
}
void computeIndegree(int n,int a[][10]){
int i,j,sum=0;
for(i=0;i<n;i++){
sum=0;
for(j=0;j<n;j++){
sum=sum+a[j][i];
}
indegree[i]=sum;
}
}
void tps_SourceRemoval(int n,int a[][10]){
int i,j,v;
for(i=0;i<n;i++){
if(indegree[i]==0){
stack[++top]=i;
}
}

int k=0;
while(top!=-1){
v=stack[top--];
t[k++]=v;
for(i=0;i<n;i++){
if(a[v][i]!=0){
indegree[i]=indegree[i]-1;
if(indegree[i]==0){
stack[++top]=i;
}
}
}
}
}
