import random

# Set seed for reproducibility
random.seed(10)

# Generate 8 random numbers (0 to 99)
N = 8
numbers = [random.randint(0, 99) for _ in range(N)]

# Write to unsort.txt
with open("unsort.txt", "w") as f:
    for num in numbers:
        f.write(f"{num}\n")

print(f"Generated unsort.txt with {N} random numbers: {numbers}")