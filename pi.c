#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct point{ 
// Struct for every point in the triangle

	int value; // value of the point 
	int total; // value of the max sum for the way to that point 
	int totalLeft; // legacy of total value from upper point 

	struct point * next;

};

void readList(struct point * head){ 
// Reads all the list and prints the variable that we want.

	struct point * tmp = head;

	while(tmp->next!=NULL){

		printf("-%d-",tmp->totalLeft);
		tmp=tmp->next;
	}

}

bool isItPrime(int number){ 
// Checks if the number is prime or not.

	int i;

	if(number==2){
		return true;
	}
	else if(number<=1 || number%2==0){
		return false;
	}

	for(i=3;i<sqrt(number)+1;i+=2){

		if(number%i==0){

			return false;
		}
	}
	
	return true;

}


void findMax(struct point * head){ 
// Finds the biggest 'total' variable in the list.

	struct point * tmp = head;

	int max= tmp->totalLeft;

	while(tmp!=NULL){
		
		if(tmp->totalLeft > max){
			max = tmp->totalLeft;
		}

		tmp=tmp->next;
	}

	printf("\n\n \t \t Max one is : # %d #",max);
}


void addValues(struct point * head){ 
// Checks for all the points in the list to see
// that which legacy of total variable(totalLeft) is bigger. 

	struct point * tmp=head;

  	while(tmp->next!=NULL){

  		if(tmp->next->totalLeft < tmp -> totalLeft){ // For upper 'total' legacies(totalLeft), if left one is bigger, take that.
  			
  			tmp->next->total=tmp->totalLeft+tmp->next->value;
  		}

  		if(tmp->total==0 && tmp->totalLeft!=0){ // If point is not prime(total=0 totalLeft=0), assing the total value to
  			//totalLeft(legacy from upper point)+ value of point. 

  			tmp->total=tmp->totalLeft+tmp->value;
  		}

  		tmp=tmp->next;
  	}

  	if(tmp->total==0 && tmp->totalLeft!=0){ // Checking last point for same conditions.

  		tmp->total=tmp->totalLeft+tmp->value;
  	}

}


void checkValues(struct point *tmp){
// Every time we pass a line, we have 1 additional point, so we are using the same positions in 
// linkedlist and add a new one. 
// If we are at 5th line, we have like 1 2 3 4 5 numbers, after we pass the line
// we are using the same list positions for new values, in short, for 6 7 8 9 10 11 for 6th line, we are using 
// same box for 1 -> 6 , 2 -> 5 ... and assiging the 'total' variable to 'totalLeft'.

	if(tmp->value==2){ // If value is prime, assign totalLeft to 0.
		tmp->totalLeft=0;
			

	}
	else if(tmp->value%2!=0 && isItPrime(tmp->value)){ // If value is prime, assign totalLeft to 0.
	
	 	tmp->totalLeft=0;	
	  		
	}
	else{
		tmp->totalLeft=tmp->total; // If value is not prime, take 'total' variable from upper point as 'totalLeft'
	}
		
		
	tmp->total=0; // Change all points total variable as 0.
}


void changeList(struct point * head){ 
// Travels in the list to assign 'totalLeft' variables using 
// checkValues function to check if the values prime or not to assign the 'totalLeft'.
// Finally adds the new point end of the list.

	struct point * tmp=head;

	while(tmp->next!=NULL){

		checkValues(tmp);
		tmp=tmp->next;

  	}

  	checkValues(tmp);

  	tmp->next=(struct point*)malloc(sizeof(struct point));
  	tmp->next->totalLeft=tmp->totalLeft;
  	tmp->next->total=0;
  	tmp->next->next=NULL;


}

void getValues(struct point* head){ 
// Pulls the triangle values from file and checks for the conditions to use functions that 
// we need to. In this way, It runs the functions at every beginnig of the lines.

	char ch[6];

	struct point * tmp = head;

	int lines=1;
	int dots=0;

	FILE * file;
	file= fopen("dots.txt","r");

	while(!(feof(file))){

		fscanf(file,"%s",ch); // Take values
   		tmp->value= atoi(ch); // Assign to list 'value' variable
		
   		if(lines==1 && dots==0){ // Checks if it is the first point or not. Gives the value of itself as 'total' and 'totalLeft'.
   			head->total=head->value;
  			head->totalLeft=head->value;
   		}

   		dots++; // Increase the number of dots after reading a dot from file  
		
  		if(dots%lines==0){ // If the line ends
				
  			printf("\n");

  			lines++;
  			dots=0;

  			if(lines!=2){
  				addValues(head); // Call addValues and transfer 'total' variables except first dot of the triangle.
  			}

  			changeList(head); // Call changeList function to refresh the list 'total' values for new line.
  			readList(head);	// Print the list 'totalLeft' variables.
			
  			tmp = head;

  		}
  		else{

  			tmp=tmp->next;

  		}
	  
   	}
	
}


int main(){


	struct point * head=NULL;

	head = (struct point*)malloc(sizeof(struct point));
	head->next=NULL;


  	getValues(head); // Call getValues function to take values from file and to make operations.
  	
  	findMax(head); // After we read all the values from file, we are looking for the max value in the list that
  	// includes max sum for each point in last line from the first. Takes the biggest one among them.

	return 0;

}