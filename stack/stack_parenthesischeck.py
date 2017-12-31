from pythonds.basic.stack import Stack
s=Stack()

string=input()

for i in range(len(string)):
    if(string[i]=='[' or string[i]=='{' or string[i]== '('):
        s.push(string[i])
    elif(string[i]=='}' or string[i]==']' or string[i]== ')'):
        if (s.isEmpty()):
            print('Unbalanced')
            break
        if (s.peek()=='[' and (string[i]=='}' or string[i]==')')):
            print('Unbalanced')
            break
        if (s.peek()=='{' and (string[i]==']' or string[i]==')')):
            print('Unbalanced')
            break
        if (s.peek()=='(' and (string[i]==']' or string[i]=='}')):
            print('Unbalanced')
            break
        else:
            s.pop()
if(s.isEmpty()):
    print('balanced')

        
