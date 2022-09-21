#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{     /*ορισμος δομης*/
	int code;
	char* name[32];
	int npieces;
	int needed;
	int usage;
	int nuses; 
}list;

int main()
{
int numberofproduct,j,i,c,h,k,flag,count,count2,number,counter,p,answer;
int los[500];
char answer2,userch[15];
list* deikths;

FILE *fp;    
FILE *arxeio;
fp=fopen("datain.txt", "r"); /*ανοιγμα αρχειου*/

if (fp){                       /* ελεγχος αν υπαρχει αρχειο*/
fscanf(fp, "%d\n",&numberofproduct);

list list[numberofproduct];
struct lists *poulos;
flag=0;
number=1;
los[number]=0;
counter=1;

for(i=0; i<numberofproduct; i++){     /*εισαγωγη του περιεχομενου στην δομη*/
	fscanf(fp, "%d %s %d %d\n", &list[i].code,list[i].name,&list[i].needed,&list[i].npieces);
	list[i].nuses=0;
    list[i].usage=0;
	if(list[i].npieces==0){
		list[i].nuses='\0';
		list[i].usage=0;
	    
	}else if(list[i].npieces!=0){       

		
		counter=counter+list[i].npieces*2+2;
		los[number]=list[i].code;
		number++;
		for(j=0; j<(2*list[i].npieces); j++){  /*εισαγωγη των απαραιτητων στοιχειων (δευτερευων)*/
			fscanf(fp, "%d",&c);
			if(answer2=='y'){
		    }
			los[number]=c;
			number=number+1;
		}
		los[number]=0;
		number++;
	}
}

fscanf(fp, "%d",&c);/*poses paragelies*/

for(j=numberofproduct; j<(numberofproduct+c); j++){ /*οι παραγγελιες*/
	fscanf(fp, "%d %d\n",&k, &i);
    for(h=0; h<numberofproduct; h++){
    	if(list[h].code==k){
    		list[h].nuses=i;
    	}
    }
}
count=counter-1;
do{
	do{
	  count=count-1;	
	}while(los[count]!=0);
	count2=count+2;
    do{
      list[los[count2]].nuses=list[los[count2]].nuses+los[count2+1] * list[count+1].nuses;
      count2=count2+2;
	}while(los[count2]!=0);
}while((count-1)>0);

do{
	printf("          <<<<<<<MENU>>>>>>\n");            /*προσδιορισμος επιλογων του <<menu>>*/
	printf("do you want to see all the materials?(1)\n");
	printf("do you want to see a special material?(2)\n");
	printf("do you want to exit?(3)\n");
	printf("Your answer:");
	scanf("%d",&answer);        /*ειγαγη επιλογης*/
	while(answer!=1&&answer!=2&&answer!=3){
		printf("please a correct number\n");
	}
	if(answer==1){
		for(i=0; i<numberofproduct; i++){  /*εμφανηση ολων των υλικων*/
			printf(" the code :%d <> the name :%s <>  the stock :%d\n",list[i].code,list[i].name,list[i].needed);
		}
	}else if(answer==2){
		fseek(stdin,0,SEEK_END);
		printf("Give me a name:\n");
		gets(userch);                 /*εισαγωγη υλικου*/
		flag=1;
		for(i=0; i<numberofproduct; i++){   /*εμφανηση συγκεκριμενου υλικου*/
			flag = strcmp(userch,list[i].name);
			if(flag==0){
				printf(" the code :%d  <>  the name :%s  <>  the stock :%d\n",list[i].code,list[i].name,list[i].needed);
			}
		}
	}
}while(answer!=3);
arxeio=fopen("dataout.txt","w");
for(i=0; i<numberofproduct; i++){ /*εισαγωγη των απαραιτητων στοιχειων στον πινακα*/
	fprintf(arxeio,"%d/name: %s || stock:%d || needed %d\n",list[i].code,list[i].name,list[i].needed,list[i].nuses);
}
fclose(arxeio); /*κλεισιμο αρχειου*/
}else {
printf("File not found! The program will exit");
}
fclose(fp);
system("pause");
return 0;
}


