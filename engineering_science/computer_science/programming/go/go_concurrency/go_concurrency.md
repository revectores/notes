# Go Concurrency

##### # Goroutine

Use `go` to create a goroutine, which will create a new thread. `f, x, y, z` are evaluated in the current goroutine, while the execution of `f` is in the new goroutine. As what we know about the thread model, all goroutines run in the same address space. Hence the race condition must be taken care.

```go
func say(s string){
    for i := 0; i < 5; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Println(s)
    }
}
func main(){
    go say("world")
    say("hello")
}
// The output depends on CPU scheduling
```



##### # Channel

Channels are a typed conduit through which you can send and receive values with the channel operator `<-`, created by `make(chan [T], [size])`. Notice the direction is marked by the arrow:

```go
i int
c = make(chan int)
c <- i		// send i to channel c
i = <- c	// receive value from channel c
```

To provide synchronizaiton, sends and receives block until the other side is ready. For example, we compute the sum of two arrays by deviding it into two parts:

```go
func sum(s []int, c chan int){
    sum := 0
    for _, v := range s {
        sum += v
    }
    c <- sum
}

func main(){
    s := []int{7, 2, 8, -9, 4, 0}
    c := make(chan int)
    go sum(s[:len(s)/2], c)
    go sum(s[len(s)/2:], c)
    x, y := <-c, <-c
    
    fmt.Println(x+y)
}
```



















