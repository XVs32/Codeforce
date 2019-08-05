    #include <stdio.h>
    #include <stdlib.h>
     
     
     
    int main(){
    	
    	int number_of_chocolate;
    	int chocolate[100005];
    	
    	scanf("%d",&number_of_chocolate);
    	
    	int i;
    	for(i = 0; i < number_of_chocolate ; i++){
    		
    		scanf("%d",&chocolate[i]);
    		
    	}
    	
    	int alice_index = 0;
    	int alice_time = 0;
    	int bob_index = number_of_chocolate-1;
    	int bob_time = 0;
    	
    	while(bob_index >= alice_index){
    		
    		if(bob_time<alice_time){
    			bob_time += chocolate[bob_index];
    			bob_index--;
    		}
    		else{
    			alice_time += chocolate[alice_index];
    			alice_index ++;
    		}
    		
    	}
    	
    	printf("%d %d\n",alice_index,number_of_chocolate-1-bob_index);
    	
    	return 0;
    }