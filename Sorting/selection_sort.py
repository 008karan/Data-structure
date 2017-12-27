def selection_sort(a):
 for i in range(n-1):#no need of last no.
    min=i
 
    for j in range(i+1,n):
        if a[min]>a[j]:
            min=j
    a[min],a[i]=a[i],a[min]
    return a
a=input('enter list:')
a=list(map(int,a.split()))
n=len(a)
ans=selection_sort(a)
print(ans)            
        
