# define MAXN 26
char q[MAXN];
int head = 0, tail = 0;
bool is_full = false;


int en_queue(char x){
	if (tail == head && is_full) return 1;
	
	tail = (tail + 1) % MAXN;
	q[tail] = x;

	// Full state can only caused by en_queue operation,
	// and is stroke when the tail pointer move cross all 
	// the memeory block and finally reaches the head.
	if (tail == head) is_full = true;
	
	return 0;
}


int de_queue(char *p_y){
    if (head == tail && !is_full) return 1;
    
    head = (head + 1) % MAXN;
    *p_y = q[head];
    
    // Empty state can only caused by de_queues.
    if (head == tail) is_full = false;
    return 0;
}
