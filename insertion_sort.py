def insertion_sort(a):
    for i in range(1,n):
        value=a[i]
        hole=i
        while(hole>0 and a[hole-1]> value):
            a[hole]=a[hole-1]
            hole=hole-1
        a[hole]=value
        
    return a  
a=input('enter the list:')
a=list(map(int,a.split()))
n=len(a)
ans=insertion_sort(a)
print(ans)
