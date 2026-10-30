
import socket

# Create UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind server to IP address and port
server_socket.bind(('127.0.0.1', 12345))

print("UDP Server is waiting for client...")

while True:
    # Receive data from client
    data, client_address = server_socket.recvfrom(1024)

    # Convert received bytes into string
    message = data.decode()

    print("Received from client:", message)

    # Convert lowercase to uppercase
    uppercase_message = message.upper()

    # Send converted string back to client
    server_socket.sendto(
        uppercase_message.encode(),
        client_address
    )

    print("Sent to client:", uppercase_message)
