#include <stdio.h>
void removenewline(char str[]){
    for(int i=0;str[i]!='\0';i++)
        if(str[i]=='\n'){
            str[i]='\0';
            break;
        }
}
void patrep(char str[], char pat[], char rep[]){
    char result[500];
    int i =0,j=0,k=0,resindex =0,count=0;
    while(str[i]!='\0'){
        j=0;
        while(pat[j]!='\0' && str[i+j]!='\0' && str[i+j]==pat[j])
            j++;
        if(pat[j]=='\0'){
            k=0;
            while(rep[k]!='\0')
                result[resindex++] = rep[k++];
            i= i+j;
            count++;
        }
        else
            result[resindex++] = str[i++];
    }
    result[resindex]='\0';
    if(count==0)
        printf("Pattern was not found in the String: ");
    else{
        printf("Number of Replacements: %d\n",count);
        printf("Resultant String is: %s",result);
    }
}
int main(){
    char str[200], pat[50], rep[50];
    printf("Enter main string, pattern string, and replacement string: ");
    fgets(str,200,stdin);
    fgets(pat,50,stdin);
    fgets(rep,50,stdin);
    removenewline(str);
    removenewline(pat);
    removenewline(rep);
    patrep(str,pat,rep);
    return 0;
}
