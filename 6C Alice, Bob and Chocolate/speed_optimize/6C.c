#include <stdio.h>
#include <stdlib.h>



int main(){
	
	int number_of_chocolate;
	int alice_chocolate[100005] = {0};
	int bob_chocolate[100005] = {0};
	
	scanf("%d",&number_of_chocolate);
	
	int i;
	
	for(i = 0; i < number_of_chocolate ; i++){
		
		scanf("%d",&alice_chocolate[i]);
		bob_chocolate[number_of_chocolate - 1 - i] = alice_chocolate[i];
		
	}
	
	int alice_index = 0;
	int alice_time = 0;
	int bob_index = 0;
	int bob_time = 0;
	
	while(number_of_chocolate--){
		
		if(bob_time<alice_time){
			bob_time += bob_chocolate[bob_index];
			bob_index++;
		}
		else{
			alice_time += alice_chocolate[alice_index];
			alice_index++;
		}
	}
	
	printf("%d %d\n",alice_index, bob_index);
	
	return 0;
}