#include<stdio.h>
#include<stdbool.h>

bool hasEpsilonTransition[10][10],visited[10];

int no_of_states,no_of_transition,state1,state2;
char symbol;

//Closure
void closure(int i)
{
    visited[i]=true;
    for(int j=0;j<no_of_states;j++)
    {
        if(hasEpsilonTransition[i][j] && !visited[j])
        {
            printf(", %d",j);
            closure(j);
        }
    }
}


//Main Function
int main()
{
    int i,j;
    printf("\nNumber Of states : ");
    scanf("%d",&no_of_states);

    printf("\nNumber Of Transitions : ");
    scanf("%d",&no_of_transition);

    printf("\nEnter Transition Table :\nState\tSymbol\tState\n");
    for(i=0;i<no_of_transition;i++)
    {
        scanf("%d %c %d",&state1,&symbol,&state2);
        if(symbol=='e')
        {
            hasEpsilonTransition[state1][state2]=true;
        }

    }

    printf("\nEpsilon Closure :\n");
    for(i=1;i<=no_of_states;i++)
    {
        printf("\nState%d : { %d",i,i);
        for(j=0;j<no_of_states;j++)
        {
            visited[j]=false;
        }
        closure(i);
        printf("}");
    }
      
    printf("\n\n");
    return 0;
}