#include <stdio.h>
#include <malloc.h>
#define INT unsigned long long int

void seive(INT *listptr, INT listsize)
{
  INT i;
  INT j;
  
  listptr[0] = 0;
  for(i=0; i<listsize; i++){
    if(listptr[i] != 0){
      j=2*listptr[i];
      while(j<listsize){
	listptr[j-1] = 0;
	j += listptr[i];
      }
    }
  }
  return;
}
  
int main()
{
  INT listsize = 41;
  INT *list;
  INT i;
  
  list = malloc(sizeof(INT) * listsize);
  
  if(list == NULL){
    printf("Unable to allocate memory.\n");
    return 1;
  }
  
  for(i=0; i<listsize; i++){
    list[i] = i+1;
  }
  
  seive(list, listsize);
  
  for(i=0; i<listsize; i++){
    if(list[i] != 0){
      printf("%llu\n", list[i]);
      }
  }
  free(list);
  return 0;
}
