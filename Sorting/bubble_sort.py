import time
start=time.clock()
def bubble_sort(a):
 for i in range(n-1):
    s=False
    for j in range(n-1-i):
      if a[j]>a[j+1]:
            
            a[j],a[j+1]=a[j+1],a[j]
            s=True
    if s==False:
        print(s)
        break
    
 return a
a=input('enter list:')
s=1
a=list(map(int,a.split()))
n=len(a)
ans=bubble_sort(a)
print(ans)            
elapsed=(time.clock()-start)
print(elapsed)

