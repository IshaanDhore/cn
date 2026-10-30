
import socket

Host = "127.0.0.1"
Port = 5000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((Host, Port))

# Enter two numbers and operator
num1 = input("Enter first number: ")
operator = input("Enter operator (+, -, *, /): ")
num2 = input("Enter second number: ")

# Send calculation request
message = num1 + " " + operator + " " + num2

client_socket.send(message.encode())

print("Request sent to server!")

# Receive result from server
result = client_socket.recv(1024).decode()

print("Result received from server:", result)

client_socket.close()
