import numpy as np
from PIL import Image
# Load and preprocess the image
input_image = Image.open('C:/Users/sbmpc.student/Pictures/download.jpg').convert('L')
input_image = input_image.resize((512, 512))
input_array = np.array(input_image)
# Message to be embedded
message = 'geeksforgeeks'
len_message = len(message) * 8
# Convert message to binary
ascii_values = [ord(c) for c in message]
bin_message = ''.join([format(value, '08b') for value in ascii_values])
# Convert binary message to numpy array of integers (0 or 1)
bin_num_message = np.array([int(b) for b in bin_message])
# Prepare output image
output_array = input_array.copy()
height, width = input_array.shape
embed_counter = 0
# Embed the message into the image
for i in range(height):
    for j in range(width):
        if embed_counter < len_message:
            LSB = input_array[i, j] % 2
            temp = (LSB ^ bin_num_message[embed_counter])
            output_array[i, j] = input_array[i, j] + temp
            embed_counter += 1
# Save images
print(output_array)
Image.fromarray(input_array).save('C:/Users/sbmpc.student/Pictures/originalsteg.jpg')
Image.fromarray(output_array).save('C:/Users/sbmpc.student/Pictures/outputsteg.png')
