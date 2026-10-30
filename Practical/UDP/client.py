
import socket

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Enter string
message = input("Enter a lowercase string: ")

# Send string to server
client_socket.sendto(
    message.encode(),
    ('127.0.0.1', 12345)
)

# Receive converted string
data, server_address = client_socket.recvfrom(1024)

# Display uppercase string
uppercase_message = data.decode()

print("Uppercase string received from server:",
      uppercase_message)

# Close socket
client_socket.close()
