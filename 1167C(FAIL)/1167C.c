#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	int user_count, group_count;
	scanf("%d %d",&user_count, &group_count);
	
	int **group_list = malloc(sizeof(int*)*group_count);
	char *user_flag = malloc(sizeof(char)*(user_count+1));
	memset(user_flag,0,sizeof(char)*(user_count+1));
	
	int i,j,v,k;
	
	for(i=0;i<group_count;i++){
		
		int group_size;
		scanf("%i",&group_size);
		group_list[i] = malloc(sizeof(int)*(group_size+1));
		group_list[i][0] = group_size;
		
		for(j=1;j<=group_size;j++){
			scanf("%d",&group_list[i][j]);
		}
		
	}
	
	char *group_mem = malloc(sizeof(char)*(user_count+1));
	memset(group_mem,0,sizeof(char)*(user_count+1));
	
	while(1){
		
		int count = 0;
		int flag = 0;
		for(j=0;j<group_count;j++){
			for(v=1;v<=group_list[j][0];v++){
				if(flag == 0 && group_mem[group_list[j][v]] == 0){
					for(k=1;k<=group_list[j][0];k++){
						group_mem[group_list[j][k]] = 1;
						count++;
					}
					v = 0x7fffffff-1;//break;
					flag = 1;
				}
				else if(flag == 1 && group_mem[group_list[j][v]] == 1){
					for(k=1;k<=group_list[j][0];k++){
						if(group_mem[group_list[j][k]] == 0){
							group_mem[group_list[j][k]] = 1;
							count++;
							
							v = 0x7fffffff-1;//break;
						}
					}
				}
			}
			
			if(v == 0x7fffffff){
				j=-1;
			}

		}
		
		if(flag == 0){break;}
		
		for(j=1;j<user_count+1;j++){
			if(group_mem[j] == 1){
				user_flag[j] = count;
				group_mem[j] = 5;
			}
		}
		
		
		
	}
	
	free(group_mem);
	
	for(i=1;i<user_count+1;i++){
		if(user_flag[i]==0){
			printf("1 ");
		}
		else{
			printf("%d ",user_flag[i]);
		}
	}
	printf("\n");
	
	return 0;
}