/*You are a participant of an adventure game and there are different rooms where one flag is
hidden in each room. You have to collect flags from these rooms, and you may choose or skip any
room. You cannot go back once you move forward. Each flag is associated with points. Find the
flags in a way so that you can achieve maximum points in the game. Consider that, Color array is
c which can be any integer and there are flags of 4 colours and six rooms so any two flags will have
the same-coloured flag.
• You can define the colour array as per your choice, array size = 8
• Point array for the flags: {2, 8, 3, 5, 11, 9, 1, 4}
• m & n are two integers that can be positive or negative
Where,
a) m will be taken into calculation if you take a same-coloured flag that you already have, and it
   will be multiplied with the corresponding points.
b) n will be taken into consideration if you take a different-coloured flag from the ones you already
   have, and it will be multiplied with the corresponding points.
*/
#include<bits/stdc++.h>
#define umap unordered_map
using namespace std;

enum Colors{
    Red=0,
    Blue,
    Green,
    Yellow
};


int main (){
    printf("\n\t\t\t --- --- --- Welcome to this adventure game--- --- ---");
    printf("\n\nThere are flags of 4 colours and 8 rooms\n\n");


    umap <Colors,string> ColorMap;
    ColorMap[Red]="Red";
    ColorMap[Blue]="Blue";
    ColorMap[Green]="Green";
    ColorMap[Yellow]="Yellow";

    for(auto it=ColorMap.begin(); it!=ColorMap.end();it++){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }

    bool selectedIndexs[8]={false};
    int selectedIndexsPointsMulti[8]={0};

    Colors c[8]= {Red,Blue,Green,Red,Yellow,Blue,Yellow,Green};
    int points[8]= {2,8,   3,    5,  11,    9,   1,     4};

    int colorGroup[4][2]={0};
    int colorIndex[4][2]={0};


    cout<<"\nThe point array for 8 room is: [";
    for(int i=0; i<8; i++){
        cout<<points[i]<<" ";

        if( colorGroup[(c[i]-Red)][0] == 0){
            colorGroup[(c[i]-Red)][0] = points[i];
            colorIndex[(c[i]-Red)][0] = i;
        }
        else{
            colorGroup[(c[i]-Red)][1] = points[i];
            colorIndex[(c[i]-Red)][1] = i;
        }
    }
    cout<<"]\n";
    cout<<"\nprint matrix"<<endl;
    for(int i=0 ; i<4 ; i++)
    {
        cout<<ColorMap[(Colors)(i+Red)]<<" "<< colorGroup[i][0]<<" "<<colorGroup[i][1]<<endl;

    }

    cout<<"\nFind the flags in a way so that you can achieve maximum points in the game."<<endl;
    cout<<"\n     --- --- --- --- --- --- --- --- --- --- --- ---  \n"<<endl;

    int m,n;
    printf("\nEnter Value of m: ");
    scanf("%d",&m);
    printf("\nEnter Value of n: ");
    scanf("%d",&n);


    int max_score=0;

    for(int i=0;i<4;i++){
        int temporaryPick;
        int temporaryPickIndex;
        if(colorGroup[i][0]*n > colorGroup[i][1]*n){
            temporaryPick=colorGroup[i][0]*n;
            temporaryPickIndex=colorIndex[i][0];
        }
        else{
            temporaryPick = colorGroup[i][1]*n;
            temporaryPickIndex=colorIndex[i][1];
        }


        if(((colorGroup[i][0]+colorGroup[i][1])*m) > temporaryPick){
            if((max_score+(colorGroup[i][0]+colorGroup[i][1])*m) >= max_score){
                max_score=max_score+(colorGroup[i][0]+colorGroup[i][1])*m;

                selectedIndexs[colorIndex[i][0]]=true;
                selectedIndexsPointsMulti[colorIndex[i][0]]=m;

                selectedIndexs[colorIndex[i][1]]=true;
                selectedIndexsPointsMulti[colorIndex[i][1]]=m;
            }
        }
        else{
            if(max_score+temporaryPick>max_score){
                max_score=max_score+temporaryPick;
                selectedIndexs[temporaryPickIndex]=true;
                selectedIndexsPointsMulti[temporaryPickIndex]=n;
            }
        }
    }
    cout<<"Assumed Max Score: "<<max_score<<endl;

    int calcMax=0;
    for(int i =0;i<8;i++){
        int temp = 0;
        if(selectedIndexs[i]){
            temp=points[i]*selectedIndexsPointsMulti[i];
            cout<<"\n  Room no: "<<i+1<< " where colour of the flag is "<<ColorMap[c[i]]<<" corresponding point is: ("<<points[i]<<" X "<<selectedIndexsPointsMulti[i]<<")="<<temp<<endl;
        }
        else{
            cout<<"\n  Room no: "<<i+1<< " where colour of the flag is "<<ColorMap[c[i]]<<" is not selected"<<endl;
        }
        calcMax+=temp;
    }
    cout<<"Maximum Score is "<<calcMax<<endl;
    return 0;
}
