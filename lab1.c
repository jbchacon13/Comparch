
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int len(char*str){

  int length= 0;
  while(*(str+length))

    length++;

  return length-1;
}



bool delim_character(char c, char delim){
  if(c== delim){
    return true;
  }
  else{
    return false;
}
}


bool non_delim_character(char c, char delim){
  if (c!=delim){
    return true;
  }
  else{
    return false;
  }
}


char *word_start(char* str,char delim){

  char* p = str;
   while(*p!='\0'){
    if(non_delim_character(*p,delim)){
       return p;
    }

    else{
          p++;
  }
  }
  return p;
  }


char *end_word(char* str, char delim){
 char* p = str;
  while(*p!='\0'){
   if(non_delim_character(*p,delim)){
      p++;
   }

   else{
        return p;
}
}
return p;
}




int count_tokens(char* str, char delim){
  int length;
  int count=0;
  int tok=0;

  length=len(str);
  for(int i =0; str[i]!='\0'; i++){
     if(str[i]== delim){
        count++;
     }
  else if (str[i]==' '||str[i]=='\n'){
     tok++;
  }
  }
  count=tok-count;
  return count;

}


char *copy_str(char*inStr,short length,  char delim){

  int i = 0;
  char *copy_str=(char*)malloc(sizeof(char)*(length+1));

  for(i=0;i<length;i++){
     copy_str[i]=inStr[i];
  }

  copy_str[i]='\0';
  return copy_str;
}



char** tokenize(char* str, char delim){
  int length;
  char *start = word_start(str,delim);
  char *end = end_word(start,delim);
  int i;
  int count= 4;
  char** token = (char **)malloc(sizeof(char*) * (count + 1));
  for(i=0; i< count;i++){
       length=end-start;
       token[i]=copy_str(start,length,delim);
       start = word_start(end,delim);
       end = end_word(start,delim);


    }


   //token[count] = NULL;
    return token;
}
void print_all_tokens(char** tokens){

  int count= 0 ;
  while(*tokens != NULL){
    //char* str= *tokens;
    printf("tokens[%i]=\"%s\"\n", count, *tokens);
    tokens++;
    count++;
  }
}
//  int main(){
 // char str[1000];
//  char delim[1000];
 // printf("Please enter the input  string:  \n$ ");
  //fgets(str,1000, stdin);
  //printf("Please enter the delimeter char: \n$ ");
  //fgets(delim,1000,stdin);
  //char a [] = "hello@world";
  //char delim = ',';
 // char *b = str;
 // char *test = end_word(b,delim);
  //int count = count_tokens(b,delim);
  //char** token = tokenize(b,delim) ;
/// printf( print_all_tokens(token));
  //print_all_tokens(token);

//printf("%d\n",len(token[0]));

//printf("%c\n",end_word(*b,delim)) ;
//printf("%i\n",count) ;

//}

