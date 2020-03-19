# Practices For Data Structure

##### 1.1

```c++
int A[m];
int B[n];

int min(int a, int b){
  return a < b ? a : b;
}

int sign(int n){
  return (n > 0) - (n < 0);
}

int compare(){
  int i;
	for(i=0; i<min(m,n); i++){
    sign_of = sign(A[i] - B[i]);
    if(sign_of != 0) return sign_of;
  }
  if(i == min(m, n)) return sign(m - n);
}
```

##### 1.9

```c
# define MAXN 26
char q[MAXN];
int head = 0, tail = 0;

int en_queue(char x){
  if(tail == MAXN - 1) return 1;
  q[++tail] = x;
  return 0;
}

int de_queue(char *p_y){
  if(head == tail) return 1;
  *p_y = q[++head];
  return 0;
}
```





