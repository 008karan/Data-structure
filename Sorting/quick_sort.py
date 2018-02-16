def Quick_Sort(alist, low,high):
  if low<high:
    print(alist)
    pivotindex = partition(alist,low,high)
    Quick_Sort(alist,low,pivotindex-1)
    Quick_Sort(alist,pivotindex+1 ,high)

def partition(alist,low,high):
    pivot=alist[high]
    print('pivot %d'%pivot)
    pivotindex=low
    for i in range(low,high):
        if alist[i]<pivot:
            
            alist[i],alist[pivotindex]=alist[pivotindex], alist[i]
            pivotindex +=1
    alist[pivotindex],alist[high] = alist[high], alist[pivotindex]
    return pivotindex
  
#Randomised quick sort
def random_partition(lst, a ,b):
    random_index = random.randint(a,b)  # pick random index, its value will be our pivot val
    lst[b], lst[random_index] = lst[random_index], lst[b]   # swap the value with lst[b]

    pivot = a        # run the rest of the partition code as it was in the original version
    for i in range(a,b):
        if lst[i] < lst[b]:
            lst[i],lst[pivot] = lst[pivot],lst[i]
            pivot += 1
    lst[pivot],lst[b] = lst[b],lst[pivot]
    return pivot
  
alist =input('enter list:')
alist=list(map(int,alist.split()))

Quick_Sort(alist,0,len(alist)-1)
print(alist)






