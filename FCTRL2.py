
# coding: utf-8

# In[6]:

def fact(i):
    if i==0 or i==1:
        return 1
    return fact(i-1)*i
num_cases=int(raw_input())
for i in range(num_cases):
    inp=int(raw_input())
    print fact(inp)

