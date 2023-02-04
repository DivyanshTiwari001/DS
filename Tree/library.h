int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int abs(int a){
    if(a<0)return -a;
    else return a;
}