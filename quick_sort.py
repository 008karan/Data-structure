def Quick_Sort(alist, low,high):
  if low<high:
    print(alist)  
    pivot=alist[high]
    print('pivot %d'%pivot)
    pivotindex=low
    for i in range(low,high):
        if alist[i]<pivot:
            
            alist[i],alist[pivotindex]=alist[pivotindex], alist[i]
            pivotindex +=1
    alist[pivotindex],alist[high] = alist[high], alist[pivotindex]
   
    Quick_Sort(alist,low,pivotindex-1)
    Quick_Sort(alist,pivotindex+1 ,high)

alist =input('enter list:')
alist=list(map(int,alist.split()))

Quick_Sort(alist,0,len(alist)-1)
print(alist)






