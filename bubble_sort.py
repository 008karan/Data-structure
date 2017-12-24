def bubble_sort(a):
 for i in range(n-1):
    swap=False
    for j in range(n-1-i):
      if a[j]>a[j+1]:
            
            a[j],a[j+1]=a[j+1],a[j]
            swap=True
    if swap==False:
     break
 return a
a=input('enter list:')
a=list(map(int,a.split()))
n=len(a)
ans=bubble_sort(a)
print(ans)            
        
