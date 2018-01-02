def Binary_search(list,l,r,key):
    if(r>=l):
        mid=l+(r-l)//2
        if(list[mid]==key):
            return mid
        if(list[mid]>key):
        
        
            return Binary_search(list,l,mid-1,key)
        if(list[mid]<key):
           
           
            return Binary_search(list,mid+1,r,key)
    else:
        return -1
    
list=[1,2,3,4,5,6,7,8,9]

ans=Binary_search(list,0,len(list)-1,15)
if(ans!=-1):
 print("Index where key is found is " ,ans)
else:
    print("given key is not present in list")
    
    
