#include <iostream>
#include <cstdio> 
#include <cstring>  

using namespace std;




int main(){
    FILE* file1;
    FILE* file2;
    file1=fopen("/Users/utereskovygmail.com/Documents/С++/final/task1_example.txt","r");
    file2=fopen("/Users/utereskovygmail.com/Documents/С++/final/task1_result.txt","w");

    //1.1
    // char str[30];
    // char lastline[30]="";

    // while(fgets(str,sizeof(str),file1)!=NULL){
    //     if(lastline[0]!='\0'){
    //         fputs(lastline,file2);
    //     }
    //     strcpy(lastline,str);
        
    // }




    //1.2
    // char str[30];
    // int count=0,a=0;
    // while(fgets(str,sizeof(str),file1)!=NULL){
    //     count++;
    // }
    // rewind(file1);
    // while(fgets(str,sizeof(str),file1)!=NULL){
    //     a++;
    //     if(a<count){
    //         fputs(str,file2);
    //     }
    // }



    //2
    // int max_size=0;
    // int index;
    // int count=1;
    // char str[30];

    // while(fgets(str,sizeof(str),file1)!=NULL){
    //     if(strlen(str)>max_size){
    //         max_size=strlen(str);
    //         index=count;
    //     }
    //     count++;   
    // }
    // cout<<"Max length - "<<max_size<<". Number of the row - "<<index;



    //3
    // const char *delimiters="., !?";
    // char word[]="hello";
    // char str[50];
    // char *words[100];
    // int count=0;
    // char *token;

    // while(fgets(str,sizeof(str),file1)){
    //     token=strtok(str,delimiters);

    //     while(token!=nullptr){
    //         words[count]=new char[strlen(token)+1];
    //         strcpy(words[count],token);
    //         token=strtok(nullptr,delimiters);
    //         count++;
    //     }

    // }
    // int word_count=0;
    // for(int i=0; i<count; i++){
    //     if(strcmp(words[i],word)==0){
    //         word_count++;
    //     }
    //     delete words[i];
    // }
    // cout<<word_count;



    //4
    char find[10];
    char replace[10];
    cout<<"Which word you would like to replace? - ";
    cin>>find;
    cout<<"Replacement - ";
    cin>>replace;
    bool a;
    char str[100];
    int i;

    while(fgets(str,sizeof(str),file1)!=NULL){
        for(int i=0; i<strlen(str); i++){
            a=true;

            for(int j=0; j<strlen(find); j++){
                if(str[i+j]!=find[j]){
                    a=false;
                    break;
                }
            }
            if(a){
                fprintf(file2,"%s",replace);
                i+=strlen(find)-1;
                a=true;
            }
            else{
                fprintf(file2,"%c",str[i]);
            }
        
        }
        
    }

    fclose(file1);
    fclose(file2);
    return 0;
}
