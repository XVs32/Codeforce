#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char cur;
	
	int max = 0;
	int max_count = 1;
	
	int stack[1000000];
	int stack_ptr=-1;

	int length[1000000]={0};
	
	int count=0;
	
	while(1){
		
		scanf("%c",&cur);
		if(cur=='('){
			stack_ptr++;
			stack[stack_ptr] = count;
		}
		else if(cur==')'){
			if(stack_ptr>-1){
				int len = count - stack[stack_ptr]+1;
				length[stack[stack_ptr]]=len;
				stack_ptr--;
			}
		}
		else{
			break;
		}
		count++;
		
	}

	
	int i;
	int len=0;
	for(i=0;i<count;){
		
		if(length[i]>0){
			len+=length[i];
			i+=length[i];			
			continue;
		}
		else{
			if(len>max){
				max = len;
				max_count = 1;
			}
			else if(len == max){
				max_count++;
			}
			len=0;
			i++;
		}
		
	}

	if(len>max){
		max = len;
		max_count = 1;
	}
	else if(len == max){
		max_count++;
	}
	
	if(max==0){
		printf("0 1\n");
	}
	else{
		printf("%d %d\n",max,max_count);
	}
	
	return 0;
}