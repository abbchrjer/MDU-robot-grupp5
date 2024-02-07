import socket, struct, time, turtle

# host = "192.168.1.88"
# host = "192.168.68.53"
# host = "192.168.1.77"
host = "192.168.1.18"
port = 80

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))

previous_time = time.time()
previous_angle= 0

car = turtle.Turtle()
car.setheading(90)

while True:
    try:
        data = client.recv(8)  # Assuming each float value is 4 bytes (32 bits)

        if not data:
            print("Server disconnected")
            break

        # Unpack the binary data into two float values
        current_angle, velocity = struct.unpack('ff', data)

        current_time = time.time()
        current_angle -= 90
        current_angle /= 5
        delta_time = current_time - previous_time

        delta_angle = current_angle - previous_angle

        # print(f"Received values: {current_angle}, {velocity}, Used values: {current_angle}, {velocity / 2}, {velocity /2 * delta_time}")
        if(delta_angle>0):
            car.right(delta_angle)
        if(delta_angle<0):
            car.left(abs(delta_angle))
        car.speed(velocity /5 )
        car.forward(velocity /5 * delta_time)

        previous_time = current_time
        previous_angle = current_angle

    except KeyboardInterrupt:
        break
    except ConnectionRefusedError:
        print("Connection refused. Make sure the server is running and the IP address is correct.")
    except Exception as e:
        print(f"An error occurred: {str(e)}")