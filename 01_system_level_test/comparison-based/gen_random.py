import random

# Tạo 10,000 số nguyên ngẫu nhiên trong khoảng từ 0 đến 99,999
large_dataset = [str(random.randint(0, 99999)) for _ in range(10)]

# Ghi vào file với cùng định dạng: một dòng, các số cách nhau bằng dấu cách
file_path = "./unsorted.txt"
with open(file_path, "w") as f:
    f.write(" ".join(large_dataset))

file_path
