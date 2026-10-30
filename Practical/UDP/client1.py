import socket

client_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

message = input("Enter a lowercase string :")

client_socket.sendto(
    message.encode(),
    ('127.0.0.1',12345)
)

data , server_address = client_socket.recvfrom(1024)

uppercase = message.decode()

print("Uppercase received from Server :",uppercase)

client_socket.close()