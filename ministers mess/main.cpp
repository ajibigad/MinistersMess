#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void minister();
void printArray(string [],int);

  ifstream input("votes.txt");//to read the dile that contains the votes
ofstream output("result.txt"); //to print out the result of the code
int main()
{
    try{
    //cout<<"hello world"<<endl;
    //cout<<(3/2)<<endl;
    //int i=1;
    while(true){
    minister();
    //minister();
    //minister();
    }}
    catch(string error)
{
 cout<<"error occured: "<<error<<endl;
}
catch(...){
cout<<"error detected "<<endl;
}
}


void minister(){
int N,M;// N is the no of bills  M is the number of ministers
        input>>N>>M; //read this values from the file
        //cout<<N<<M<<endl;
        if(N==0&&M==0){ // throws an exception if N and M is == 0 this indicates end of cases
            throw string("END OF CASES");
        }
        if(N==0||M==0){ // throws an exception if N or M is == 0
            throw string("WRONG INPUT");
        }

//if(M!=0){
int N1=N+1;
int M1=M+1;
    string vote[M1][N1]; // string to contain the votes of the ministers
    int a[M]; //array that contains the no of bills each minister votes on
    int n; //the number of bills the minister voted on
    int k; //the bill's number
    //string v;
    for(int i=0,h=1; i<M; i++,h++){ //loops no of ministers time
        input>>n; //stores no of bills voted by this minister
        if(n>4){
            throw string("WRONG INPUT"); //throws an exception if the no of bills is more than 4
            break;
        }
        a[i]=n;// stores the n in the a array
        //cout<<n;
        for(int j=0; j<n; j++){//loop to read and store the ministers vote on each bill.. runs n times
                input>>k; //read and store the bill no
            input>>vote[h][k]; //use this bill no to store the vote in the vote array
        }
        }
    string R[N]; //array to store the results of the voting on each bill.. the length of this array is no of bills size
    int z=0; // counter used to count no of agreements


    /*for(int x=1,y=1,i=0; y<=N; y++,i++){
        if(vote[x][y]==vote[x+1][y]){
            if(vote[x][y]==""&&vote[x+1][y]==""){
            R[i]="?";
            }
            else {
                R[i]=vote[x][y];
                z++;
            }
        }
        else{
            if(vote[x][y]==""||vote[x+1][y]==""){
                if(vote[x][y]==""){
                R[i]=vote[x+1][y];
                z++;}
                else{
                    R[i]=vote[x][y];
                    z++;
                }
                }
            else{
                        if(vote[x][y]!=vote[x+1][y]){
                    R[i]="?";
                        }
                }
            }
        }
        int h1=a[0]/2;
        int h2=a[1]/2;
        //cout<<z<<endl;
        if(z>=h1&&z>=h2){
            cout<<"case 1: ";
            printArray(R,N);
            cout<<endl;
        }
        else{
            cout<< "case 2: IMPOSSIBLE"<<endl;
        }*/
        int satisfy[M][1];
        int tempY[M];
        int tempN[M];
        for(int y=1,i=0;y<=N;i++,y++){// loop used to implement the majority carries the vote algorithm
            int Y=0,N1=0; // the counters for the yes and no votes respectively
            //Y=0; N1=0;
            for(int x=1;x<=M;x++){// loop through ministers votes on a particular bill{y} to count the no of yes and no
                if(vote[x][y]=="y"){
                        tempY[x];
                    Y++; //increases yes counter
                }
                else{
                    if(vote[x][y]=="n"){
                        tempN[x];
                        N1++; //increases no counter
                    }
                }
            }
            if(Y==N1){ //if tie btw yes and no then undecided bill
                R[i]="?";
            }
            else{//means one is more than the other
                    if(Y>N1){
                R[i]="y"; // if yes counter is more than no counter
                z++;
            }
                    else{
                        R[i]="n"; //if no counter is less than yes counter
                        z++;
                    }
                    }
                       }
                       //if(N1>Y){

                //}
                /*else{
                    R[i]="?";
                }*/


        int h[M];
        for(int i=0;i<M;i++){
            h[i]=a[i]/2;
        }
         int c=0;
        while(z>=h[c]&&c<M){
                //cout<<h[c]<<endl;
            c++;
        }

        //cout<<c<<endl;
        if(c==M){
                output<<"case 1: ";
            printArray(R,N);
            output<<endl;
            //cout<<"case 1: POSSIBLE"<<endl;
            //cout<<"case 1: ";
            //printArray(R,N);
            //cout<<endl;
            output<<"case : POSSIBLE"<<endl;
        }
        else{
                output<<"case 2: ";
            printArray(R,N);
            output<<endl;
          output<< "case : IMPOSSIBLE"<<endl;
                //cout<<"case 2: ";
            //printArray(R,N);
            //cout<<endl;
          //cout<< "case 2: IMPOSSIBLE"<<endl;
        }
}
//}

void printArray(string t[],int n){
for(int i=0; i<n; i++){
    output<<t[i];
}
cout<<endl;
}
