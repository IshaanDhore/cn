import socket

server_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server_socket.bind(('127.0.0.1',12345))

print("UDP server waiting for client message")

while True:

    data, client_address = server_socket.recvfrom(1024)

    message = data.decode()
    print("Recieved from client :",message)

    uppercase = message.upper()

    server_socket.sendto(
        uppercase.encode(),
        client_address
    )

    print("Sent to Client :",uppercase)