import sys
import os

# Check if we are running locally by checking the existence of 'input.txt'
if os.path.exists("input.txt"):
    sys.stdout=open("output.txt",'w')
    sys.stdin=open("input.txt",'r')

def solve():
    n,p,l,t=map(int,input().split())
    # print(n, l, l, t)
    dayfort=n/7+1 if n%7>0 else n/7
    point=0
    if(t>l):
        point=int(p/t)*t
        p-=point

    

def main():
    T=int(input())
    while(T>0):
        solve()
        T-=1

if __name__ == "__main__":
    main()
