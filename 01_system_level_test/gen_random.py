import random

number = int(input("Enter the number of random integers to generate: "))

large_dataset = [str(random.randint(0, 10)) for _ in range(number)]

# Ghi vào file với cùng định dạng: một dòng, các số cách nhau bằng dấu cách
file_path = "./unsorted.txt"
with open(file_path, "w") as f:
    f.write(" ".join(large_dataset))

file_path
