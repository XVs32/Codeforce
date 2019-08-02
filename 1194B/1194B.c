#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[400005];

int map_scan(int x,int y){
	
	int x_record[50005];
	int y_record[50005];
	
	memset(x_record,0,sizeof(int)*y);
	memset(y_record,0,sizeof(int)*x);
	
	int min_x = 0x7fffffff;
	int min_y = 0x7fffffff;
	
	int i, j;
	
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			if(map[i*x+j] == '.'){
				x_record[i] += 1;
				y_record[j] += 1;
			}
		}
		if(min_x>x_record[i]){min_x=x_record[i];}
		
	}
	
	for(j=0;j<x;j++){
		if(min_y>y_record[j]){min_y=y_record[j];}
	}
	

	char flag = 0;
	for(i=0;i<y;i++){
		if(x_record[i]>min_x){
			continue;
		}
		
		for(j=0;j<x;j++){
			if(y_record[j]>min_y){
				continue;
			}
			
			if(map[i*x+j] == '.'){
				flag = 1;
				return min_x+min_y-1;
			}
		}
	}
	
	return min_x+min_y;
}

	
int main(){
	
	int testcase;
	scanf("%d",&testcase);
	
	char eol_cleaner;
	int i;
	
	for(i=0;i<testcase;i++){
		
		int x ,y;
		
		scanf("%d %d",&y,&x);
		
		int j, v;
		
		for(j=0;j<y;j++){
			
			scanf("%s",&map[j*x+0]);
			
		}
		
		printf("%d\n",map_scan(x,y));
		
	}
	
	return 0;
	
}






