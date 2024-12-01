def total_distance(list1, list2):
    ans = sum(abs(x-y) for x, y in zip(list1, list2))
    print(ans)
    
def similarity_score(list1, list2):
    ans = sum(i * list2.count(i) for i in list1)
    print(ans)
    


file_path = 'input.txt'

list1 = []
list2 = []

with open(file_path, 'r') as file:
    for line in file:
        l1, l2 = line.strip().split()
        list1.append(int(l1))
        list2.append(int(l2))
        
list1 = sorted(list1)
list2 = sorted(list2)

a = 0

total_distance(list1, list2)
similarity_score(list1, list2)