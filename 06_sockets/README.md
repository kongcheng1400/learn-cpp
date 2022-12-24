#sockets


stream sockets(TCP,保持连接, 按顺序到达),  http, telnet, ftp
datagram sockets:UDP: tftp, sftp, game, 

## byte order

big ending: 先存储大的一边: big end.  网络字节序.
little endian: 先存储小的一边。host byte order: 
htons(): host to network short.