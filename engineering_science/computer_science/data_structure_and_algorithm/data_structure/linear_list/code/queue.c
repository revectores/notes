# define MAXN 26
char q[MAXN];
int head = -1, tail = -1;


int en_queue(char x){
	if(tail == MAXN - 1) return 1;
    
    // Move the pointer first, the put the value into the new address.
    q[++tail] = x;
	return 0;
}


int de_queue(char *p_y){
	if(head == tail) return 1;

    // There's no need to actually 'erase' the value.
    *p_y = q[++head];
	return 0;
}


int main(){
    r = en_queue(x);
    if(r) printf("full queue");
    
    return 0;
}
