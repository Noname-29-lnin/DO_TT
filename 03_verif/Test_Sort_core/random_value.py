import random

number = int(input("Enter the number of random hex values to generate: "))

# Sinh danh sách số hex có 2 chữ số, VD: '1A', '0F', 'FF'
large_dataset = [f"{random.randint(0, 255):02X}" for _ in range(number)]

# Ghi vào file: mỗi dòng là một giá trị hex
file_path = "./unsorted.txt"
with open(file_path, "w") as f:
    f.write("\n".join(large_dataset))

print(f"Hex values written to: {file_path}")
