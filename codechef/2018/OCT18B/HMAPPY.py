N, M = map(int,input().split())
A =list(map(int,input().split()))
B = list(map(int,input().split()))

def merge(arr1,arr2, l, m, r): 
    n1 = m - l + 1
    n2 = r- m 
  
    L1 = [0] * (n1) 
    R1 = [0] * (n2)
    L2 = [0] * (n1)
    R2 = [0] * (n2)

  
    for i in range(0 , n1): 
        L1[i] = arr1[l + i]
        L2[i] = arr2[l + i]
  
    for j in range(0 , n2): 
        R1[j] = arr1[m + 1 + j] 
        R2[j] = arr2[m + 1 + j]
    i = 0 
    j = 0 
    k = l 
  
    while i < n1 and j < n2 : 
        if L1[i] <= R1[j]: 
            arr1[k] = L1[i]
            arr2[k] = L2[i]
            i += 1
        else: 
            arr1[k] = R1[j]
            arr2[k] = R2[j]
            j += 1
        k += 1
  
    while i < n1: 
        arr1[k] = L1[i]
        arr2[k] = L2[i]
        i += 1
        k += 1
  
    while j < n2: 
        arr1[k] = R1[j]
        arr2[k] = R2[j]
        j += 1
        k += 1
  
def mergeSort(arr1,arr2,l,r): 
    if l < r: 
        m = int((l+(r-1))/2)
        mergeSort(arr1,arr2, l, m) 
        mergeSort(arr1,arr2, m+1, r) 
        merge(arr1,arr2, l, m, r) 


mergeSort(A,B,0,N-1)
print(A)
print(B)
Cmax=0
Cn1=0
Cn2=0
for i in range(N-1,-1,-1):
    
print(Cmax)
