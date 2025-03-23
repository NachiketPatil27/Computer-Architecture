import sys

# Open input and output files
file = open('input.mc', 'r')
sys.stdout = open('test_case.mc', 'w')

i = 0
for each in file:
    each = each.strip()  # Remove newline and extra spaces
    if each:  # Only process non-empty lines
        print(f"{hex(i)} {each}")
        i += 4

# Print termination instruction at the next address
print(f"{hex(i)} 0x00000073")

