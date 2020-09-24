# Network Address Translation

**网络地址转换(Network Address Translation, NAT)**是一种在链接局域网和广域网的路由器上应用的技术, 它将局域网中使用的私有IP地址在路由器上转换为公网IP, 使数据报得以进入Internet, 在接受数据时则将公网IP转换回私有IP到达局域网主机, 从而实现局域网主机与Internet的通信. NAT避免了所有终端都必须具备一个独立公网IP的局面, 从而节省了IP资源, 使得在这个IPv4严重缺乏的环境中Internet仍然能够健壮地运转.

除了IP地址以外, NAT还需要对TCP端口进行一些调整, 以保证链路的独立. 

> Example for network address translation.
>
> ```mermaid
> stateDiagram-v2
> 
> 
> state LOCAL {
> 	A(10.1.1.2)
> 	B(10.1.1.3)
> 	C(10.1.1.4)
> }
> 
> LOCAL --> GATEWAY(1.1.1.1)
> GATEWAY(1.1.1.1) --> LOCAL
> 
> GATEWAY(1.1.1.1) --> INTERNET 
> INTERNET --> GATEWAY(1.1.1.1)
> INTERNET --> SERVER(2.2.2.2)
> SERVER(2.2.2.2) --> INTERNET
> 
> ```
>
> A使用1025端口访问Server 80端口; B使用1025端口访问Server 80端口; C使用2000端口访问Server 443端口.
>
> 在GateWay上的**网络地址转换表**(**NAT table**):
>
> | Machine IP/PORT Locally | Machine IP/PORT OUTSIDE GATEWAY |
> | :---------------------: | :-----------------------------: |
> |     `10.1.1.2/1025`     |         `1.1.1.1/1025`          |
> |     `10.1.1.3/1025`     |         `1.1.1.1/1026`          |
> |     `10.1.1.4/2000`     |         `1.1.1.1/1027`          |

通过单射, NAT确保了链路的独立性.

NAT的缺陷: 

1. 通常不转换应用层内嵌的私有IP地址. 这时必须使用**应用层网关(Application Layer Gateway, ALG)**和NAT协同作用, ALG负责将应用层中嵌入的私有IP转化为公网IP.
2. 需要局域网主机主动发起并保持连接. 在局域网主机没有主动发起连接的情况下, NAT table是空的, 外网的计算机无法主动访问私有IP. 另外NAT table有超时机制, 一旦超过规定时间NAT table将删掉对应的映射, 则外网也将无法访问, 因此主机必须周期性地给路由器发送`keep-alive`消息.






