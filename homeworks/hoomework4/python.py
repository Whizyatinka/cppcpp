print('--- Working with arrays ---')
print('Enter elements of array A (5 elements): ', end = '')
A = list(map(int, input().split()))
print('Enter elements of array B (5 elements): ', end = '')
B = list(map(int, input().split()))
print('Enter value t: ', end = '')
t = int(input())
countA = 0
countB = 0
for i in range(5):
    if A[i] < t:
        countA += 1
    if B[i] < t:
        countB += 1

print(f"number of elements less than {t}: " + str(countA), 'in array A')
print(f"number of elements less than {t}: " + str(countB), 'in array B')

if countB < countA:
    print('array B: ', end = '')
    print(*B)
    print('array A: ', end = '')
    print(*A)
else:
    print('array A: ', end='')
    print(*A)
    print('array B: ', end='')
    print(*B)

print()
print('--- Working with sets')
#Не буду задавать длину множества, чтоб упросить код и сделать возможным(более простым) ввод в строчку
print('Enter elems of set A: ', end='')
A = set(list(map(int, input().split())))
print('Enter elems of set B: ', end='')
B = set(list(map(int, input().split())))
symDiff = (A^B)
print('symmetric difference of sets: ', end = '')
print(*symDiff)
print('Mathematical expectation: ' + str(sum(symDiff)/len(symDiff)))