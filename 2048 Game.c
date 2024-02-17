#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define SIZE 4
#define BORDER 219
#define LENGTH 220
#define ESC 27


int Box[SIZE][SIZE]={0};
int score=100,hscore=256,h,c;			//Number of tries

void delay(unsigned int );
void starting();
void loading();
void Body();
void Upper_border();
void Action(char);
void Random_creator();
void Random_Places();
void Finisher(char Arrow,char P);
int Game_ender();
void Down();
void Up();
void Left();
void Right();
void h_score(char Arrow);




int main()
{
	FILE *fp2;											//FILING
	fp2=fopen("hscore.txt", "r");
    fscanf(fp2,"%d",&h);
    fclose(fp2);
	FILE *fp;
    fp=fopen("score.txt", "w");
    fprintf(fp,"%d",hscore);
    fclose(fp);
    
    int c=0,var,*ptr;
    char Arrow,P;
    
    system("COLOR E0");  
	printf("\n   GROUP G4\n");
    puts("   Group Members : ");
    puts("     ->  Syed Abdullah Bin Tariq (22k-4253)\n     ->  M.Arham Affan (22k-4136)");  
    char s[] = "\n\t\t\t\t\t     WELCOME TO 2048 GAME";
    for (c = 0; s[c] != '\0'; c++) {    
        printf("%c", s[c]);    
        delay(100);    
    }    
    
    starting();
    loading();
    Random_Places();
    Finisher(Arrow,P);

    h_score(Arrow);
    

    
}

void delay(unsigned int milliseconds) {    
    clock_t start = clock();    
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);    
}    

void starting()
{
    printf("\n\n\t\t\t  ========================2048 GAME===========================");
    printf("\n\n  INSTRUCTIONS:\n\n\n");
    printf(" ->  Enter arrow keys to move\n\n");
    printf(" ->  For wining this game any one box should have value 2048\n\n");
    printf(" ->  You have maximum 2048 tries to win the game\n\n");
    printf(" ->  Press ESC key to exit the game\n\n\n\n");
    printf("\t\t\t\t\t\tPRESS ANY KEY TO PLAY\n");
    while(!kbhit());
    system("cls");
}

void loading()
{
	int i;
	printf("\n\n\t\t\t\t\t\tLOADING....");
	puts("");
	printf("\n\t\t\t\t\t  ");
	for(i=0;i<=20;i++){
		printf("%c",BORDER);
		Sleep(100);
	}
	
}

void Random_creater()
{
    int random,add,i,j;
    
    srand(time(NULL));
    random=rand()%SIZE;  

    if(random%4==0)
        add=2;
    else if(random%4==1)
        add=2;
    else if(random%4==2)
        add=4;
    else 
    	add=8;

    for(i=0;i<2048;i++)
    {
        for(j=random;j<SIZE;j++)
        {
            if(Box[i][j]==0)
            {
                Box[i][j]=add;
                return;
            }
        }
    }
}

void Upper_border()
{
    
    printf("\n\n\n\t\t\t\tAttempt Left: %d              Highest Score: %d\n\n\n",score, h);
    printf("\t\t\t\t\t\t   2048 GAME\n\n\n");
    printf("\t\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,
	BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);

}

void Body()
{

    int i,j;
    system("cls");
    
    Upper_border();
    
    for(i=0;i<SIZE;i++)
    {
        printf("\t\t\t\t\t %c",BORDER);
        for(j=0;j<SIZE;j++)
        {
            if(Box[i][j]==0)
            {
                printf("      ");
            }
            else
                printf(" %4d ",Box[i][j]);
        }
        printf("%c\n\t\t\t\t\t %c                        %c\n",BORDER,BORDER,BORDER);
    }
    printf("\t\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,
	BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);
}

void Action(char Arrow)
{

    switch(Arrow)
    {
        case UP:
            {
                Up();
                break;
            }
        case DOWN:
            {
                Down();
                break;
            }
        case LEFT:
            {
                Left();
                break;
            }
        case RIGHT:
            {
                Right();
                break;
            }
        default:
            {
                return;
            }
    }
    score--;
    Random_creater();
    Body();
}

void Random_Places()
{   
    int x=0,pos1,pos2,temp,q=-1,r=-1;
	while(x!=2){
		srand(time(NULL));
    	pos1=rand()%SIZE;
    	if(q==pos1)
    	  continue;
    	q=pos1;
    
    	srand(time(NULL));
    	pos2=rand()%SIZE;
    	if(r==pos2)
    	  continue;
    	r=pos2;
    
    	srand(time(NULL));
    	temp=rand()%2;
    	if(temp==1)
    	   Box[pos1][pos2]=2;
    	else
    	   Box[pos1][pos2]=4;
    	x++;
    	
}


    Body();
}

void Finisher(char Arrow, char P){
 
 	int var,*ptr,x=0;
    while(Arrow!=ESC)
    {
        Arrow=getch();
        Action(Arrow);
        var = Game_ender();
        ptr=&var;
        if(*ptr==1)
        { 
            printf("\n\t\t\t\t                **YOU WON**");
            x=1;
            printf("\n\n");
            break;
        }
        if(*ptr==0 || score==0)
        {
            printf("\n\t\t\t                     SORRY !  GAME OVER");
            x=1;
            printf("\n\n");
            break;
        }
        
    }
    
    
    	
	
}

int Game_ender()
{
     //IT SHOULD FIND MAX VALUE FROM WHOLE BOX
    int value=0,i,j;
    int *flag=&value;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(Box[i][j]==256) 				//GAME ENDER
                return(1);
            else if(Box[i][j]==0)
                *flag=1;
        }
    }
    if(*flag==1)
    {
        
        return(99);
    }
    else
    {

        return(0);
    }
}

void Down()
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=2;
        while(1)
        {
            while(Box[i][j]==0)
            {
                if(i==-1)
                    break;
                i--;
            }
            if(i==-1)
                break;
            while(i<SIZE-1 && (Box[i+1][j]==0 || Box[i][j]==Box[i+1][j]))
            {
                Box[i+1][j]+=Box[i][j];
                Box[i][j]=0;
                i++;
            }
            i--;
        }
    }
    FILE *fp;
        fp=fopen("score.txt", "w");
        hscore-=2;
        fprintf(fp,"%d",hscore);
        fclose(fp);
    
    
}
void Up()
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=1;
        while(1)
        {
            while(Box[i][j]==0)
            {
                if(i==SIZE)
                    break;
                i++;
            }
            if(i==SIZE)
                break;
            while(i>0 && (Box[i-1][j]==0 || Box[i][j]==Box[i-1][j]))
            {
                Box[i-1][j]+=Box[i][j];
                Box[i][j]=0;
                i--;
            }
            i++;
        }
    }
    FILE *fp;
        fp=fopen("score.txt", "w");
        hscore-=2;
        fprintf(fp,"%d",hscore);
        fclose(fp);
}
void Right()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=2;
        while(1)
        {
            while(Box[i][j]==0)
            {
                if(j==-1)
                    break;
                j--;
            }
            if(j==-1)
                break;
            while(j<SIZE-1 && (Box[i][j+1]==0 || Box[i][j]==Box[i][j+1]))
            {
                Box[i][j+1]+=Box[i][j];
                Box[i][j]=0;
                j++;
            }
            j--;
        }
    }
    FILE *fp;
        fp=fopen("score.txt", "w");
        hscore-=2;
        fprintf(fp,"%d",hscore);
        fclose(fp);
}
void Left()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=1;
        while(1)
        {
            while(Box[i][j]==0)
            {
                if(j==SIZE)
                    break;
                j++;
            }
            if(j==SIZE)
                break;
            while(j>0 && (Box[i][j-1]==0 || Box[i][j]==Box[i][j-1]))
            {
                Box[i][j-1]+=Box[i][j];
                Box[i][j]=0;
                j--;
            }
            j++;
        }
    }
    FILE *fp;
        fp=fopen("score.txt", "w");
        hscore-=2;
        fprintf(fp,"%d",hscore);
        fclose(fp);
}

void h_score(char Arrow)
{
	if(Arrow!=ESC){
		if(Game_ender()==1){
	        FILE *fp;
	        fp=fopen("score.txt", "r");
            fscanf(fp,"%d",&c);
            fclose(fp);
	        if(c>h){
		        h=c;
	            FILE *fp2;
                fp2=fopen("hscore.txt", "w");
                fprintf(fp2,"%d",h);
                fclose(fp2);
                printf("\n                           CONGRATULATION ON ACHIEVING THE NEW HIGHEST SCORE %d\n\n", h);
    
	       }
        }
    }
}



