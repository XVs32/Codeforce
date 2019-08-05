#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
		
	char name_list[100005][35];
	int name_count[100005];
	
	int testcase;
	
	memset(name_list,'\0',sizeof(char)*100005*35);
	memset(name_count,0,sizeof(int)*100005);
	
	scanf("%d",&testcase);
	
	while(testcase--){
		
		char name[35];
		
		scanf("%s",name);
		
		int i;
		for(i=0;;i++){
			
			if(strlen(name_list[i])==0){
				strcpy(name_list[i],name);
				name_count[i] ++;
				printf("OK\n");
				break;
			}
			else if(strcmp(name_list[i],name)==0){
				printf("%s%d\n",name,name_count[i]);
				name_count[i]++;
				break;
			}
		}
		
	}
	
	return 0;
}