def is_increasing(v):
    for i in range(len(v) - 1):
        if v[i] > v[i + 1]:
            return False
    return True

def is_decreasing(v):
    for i in range(len(v) - 1):
        if v[i] < v[i + 1]:
            return False
    return True

def check_differences(v):
    for i in range(len(v) - 1):
        diff = abs(v[i] - v[i + 1])
        if diff < 1 or diff > 3:
            return False
    return True

def is_safe(v):
    return (is_increasing(v) or is_decreasing(v)) and check_differences(v)

def is_safe_with_dampener(v):
    if is_safe(v):
        return True
    for i in range(len(v)):
        temp = v[:i] + v[i+1:]
        
        if is_safe(temp):
            return True
    return False

safe_count = 0
safe_count_with_dampener_count = 0

with open('input.txt') as f:
    for line in f:
        v = list(map(int, line.split()))
        if is_safe(v):
            safe_count += 1
        if is_safe_with_dampener(v):
            safe_count_with_dampener_count += 1
            
print(safe_count)
print(safe_count_with_dampener_count)