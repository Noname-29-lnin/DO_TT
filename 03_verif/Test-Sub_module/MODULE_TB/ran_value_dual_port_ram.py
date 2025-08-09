import random

DATA_WIDTH = 8
ADDR_WIDTH = 6
DEPTH = 2**ADDR_WIDTH

with open("mem_init.hex", "w") as f:
    for _ in range(DEPTH):
        value = random.randint(0, (1 << DATA_WIDTH) - 1)
        f.write(f"{value:02X}\n")
